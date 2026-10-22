/*
 * The  information  in  this  document  is  subject  to  change
 * without  notice  and  should not be construed as a commitment
 * by Digital Equipment Corporation or by DECUS.
 *
 * Neither Digital Equipment Corporation, DECUS, nor the authors
 * assume any responsibility for the use or reliability of  this
 * document or the described software.
 *
 *      Copyright (C) 1980, DECUS
 *
 * General permission to copy or modify, but not for profit,  is
 * hereby  granted,  provided that the above copyright notice is
 * included and reference made to  the  fact  that  reproduction
 * privileges were granted by DECUS.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

var_na    *documentation[] = {
   "grep searches a file for a given pattern.  Execute by",
   "   grep [flags] regular_expression file_list\n",
   "Flags are single characters preceded by '-':",
   "   -c      Only a count of matching lines is printed",
   "   -f      Print file name for matching lines switch, see below",
   "   -n      Each line is preceded by its line number",
   "   -v      Only print non-matching lines\n",
   "The file_list is a list of files (wildcards are acceptable on RSX modes).",
   "\nThe file name is normally printed if there is a file given.",
   "The -f flag reverses this action (print name no file, not if more).\n",
   0 };

var_na    *patdoc[] = {
   "The regular_expression defines the pattern to search for.  Upper- and",
   "lower-case are always ignored.  Blank lines never match.  The expression",
   "should be quoted to prevent file-name translation.",
   "x      An ordinary character (not mentioned below) matches that character.",
   "'\\'    The backslash quotes any character.  \"\\$\" matches a dollar-sign.",
   "'^'    A circumflex at the beginning of an expression matches the",
   "       beginning of a line.",
   "'$'    A dollar-sign at the end of an expression matches the end of a line.",
   "'.'    A period matches any character except \"new-line\".",
   "':a'   A colon matches a class of characters described by the following",
   "':d'     character.  \":a\" matches any alphabetic, \":d\" matches digits,",
   "':n'     \":n\" matches alphanumerics, \": \" matches spaces, tabs, and",
   "': '     other control characters, such as new-line.",
   "'*'    An expression followed by an asterisk matches zero or more",
   "       occurrences of that expression: \"fo*\" matches \"f\", \"fo\"",
   "       \"foo\", etc.",
   "'+'    An expression followed by a plus sign matches one or more",
   "       occurrences of that expression: \"fo+\" matches \"fo\", etc.",
   "'-'    An expression followed by a minus sign optionally matches",
   "       the expression.",
   "'[]'   A string enclosed in square brackets matches any character in",
   "       that string, but no others.  If the first character in the",
   "       string is a circumflex, the expression matches any character",
   "       except \"new-line\" and the characters in the string.  For",
   "       example, \"[xyz]\" matches \"xx\" and \"zyx\", while \"[^xyz]\"",
   "       matches \"abc\" but not \"axb\".  A range of characters may be",
   "       specified by two characters separated by \"-\".  Note that,",
   "       [a-z] matches alphabetics, while [z-a] never matches.",
   "The concatenation of regular expressions is a regular expression.",
   0};

#define LMAX    512
#define PMAX    256

#define CHAR    1
#define BOL     2
#define EOL     3
#define ANY     4
#define CLASS   5
#define NCLASS  6
#define STAR    7
#define PLUS    8
#define MINUS   9
#define ALPHA   10
#define DIGIT   11
#define NALPHA  12
#define PUNCT   13
#define RANGE   14
#define ENDPAT  15

ကိန်းပြည့် cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

var_na *pp, lbuf[LMAX], pbuf[PMAX];

var_na *cclass();
var_na *pmatch();
void store(ကိန်းပြည့်);
void error(var_na *);
void badpat(var_na *, var_na *, var_na *);
ကိန်းပြည့် match(void);


/*** Display a file name *******************************/
void file(var_na *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
void cant(var_na *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
void help(var_na **hp)
{
   var_na   **dp;

   အတွက် (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
void usage(var_na *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
void compile(var_na *source)
{
   var_na  *s;         /* Source string pointer     */
   var_na  *lp;        /* Last pattern pointer      */
   ကိန်းပြည့်   c;          /* Current character         */
   ကိန်းပြည့်            o;          /* Temp                      */
   var_na           *spp;       /* Save beginning of pattern */

   s = source;
   အကယ်၍ (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   နေစဉ် (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      အကယ်၍ (c == '*' || c == '+' || c == '-') {
         အကယ်၍ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         နေစဉ် (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         continue;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      switch(c) {

         pak_sa '^':
            store(BOL);
            bha_nga;

         pak_sa '$':
            store(EOL);
            bha_nga;

         pak_sa '.':
            store(ANY);
            bha_nga;

         pak_sa '[':
            s = cclass(source, s);
            bha_nga;

         pak_sa ':':
            အကယ်၍ (*s) {
               switch(tolower(c = *s++)) {

                  pak_sa 'a':
                  pak_sa 'A':
                     store(ALPHA);
                     bha_nga;

                  pak_sa 'd':
                  pak_sa 'D':
                     store(DIGIT);
                     bha_nga;

                  pak_sa 'n':
                  pak_sa 'N':
                     store(NALPHA);
                     bha_nga;

                  pak_sa ' ':
                     store(PUNCT);
                     bha_nga;

                  default:
                     badpat("Unknown : type", source, s);

               }
               bha_nga;
            }
            မဟုတ်ပါက    badpat("No : type", source, s);

         pak_sa '\\':
            အကယ်၍ (*s)
               c = *s++;

         default:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   အကယ်၍ (debug) {
      အတွက် (lp = pbuf; lp < pp;) {
         အကယ်၍ ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         မဟုတ်ပါက    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
var_na *cclass(var_na *source, var_na *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   var_na   *s;        /* Source pointer    */
   var_na   *cp;       /* Pattern start     */
   ကိန်းပြည့်    c;         /* Current character */
   ကိန်းပြည့်             o;         /* Temp              */

   s = src;
   o = CLASS;
   အကယ်၍ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   နေစဉ် ((c = *s++) && c!=']') {
      အကယ်၍ (c == '\\') {                /* Store quoted char    */
         အကယ်၍ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         မဟုတ်ပါက    store(tolower(c));
      }
      မဟုတ်ပါက အကယ်၍ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      မဟုတ်ပါက {
         store(tolower(c));      /* Store normal char */
      }
   }
   အကယ်၍ (c != ']')
      badpat("Unterminated class", source, s);
   အကယ်၍ ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   အကယ်၍ (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   ပြန်ပေး(s);
}

/*** Store an entry in the pattern buffer **************/
void store(ကိန်းပြည့် op)
{
   အကယ်၍ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
void badpat(var_na *message, var_na *source, var_na *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", message, source);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-source, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
void grep(FILE *fp, var_na *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   ကိန်းပြည့် lno, count, m;

   lno = 0;
   count = 0;
   နေစဉ် (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      အကယ်၍ ((m && !vflag) || (!m && vflag)) {
         ++count;
         အကယ်၍ (!cflag) {
            အကယ်၍ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            အကယ်၍ (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   အကယ်၍ (cflag) {
      အကယ်၍ (fflag && fn)
         file(fn);
      printf("%d\n", count);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
ကိန်းပြည့် match()
{
   var_na   *l;        /* Line pointer       */

   အတွက် (l = lbuf; *l; ++l) {
      အကယ်၍ (pmatch(l, pbuf))
         ပြန်ပေး(1);
   }
   ပြန်ပေး(0);
}

/*** Match partial line with pattern *******************/
var_na *pmatch(var_na *line, var_na *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   var_na   *l;        /* Current line pointer         */
   var_na   *p;        /* Current pattern pointer      */
   var_na   c;         /* Current character            */
   var_na            *e;        /* End for STAR and PLUS match  */
   ကိန်းပြည့်             op;        /* Pattern operation            */
   ကိန်းပြည့်             n;         /* Class counter                */
   var_na            *are;      /* Start of STAR match          */

   l = line;
   အကယ်၍ (debug > 1)
      printf("pmatch(\"%s\")\n", line);
   p = pattern;
   နေစဉ် ((op = *p++) != ENDPAT) {
      အကယ်၍ (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-line, *l, *l, op);
      switch(op) {

         pak_sa CHAR:
            အကယ်၍ (tolower(*l++) != *p++)
               ပြန်ပေး(0);
            bha_nga;

         pak_sa BOL:
            အကယ်၍ (l != lbuf)
               ပြန်ပေး(0);
            bha_nga;

         pak_sa EOL:
            အကယ်၍ (*l != '\0')
               ပြန်ပေး(0);
            bha_nga;

         pak_sa ANY:
            အကယ်၍ (*l++ == '\0')
               ပြန်ပေး(0);
            bha_nga;

         pak_sa DIGIT:
            အကယ်၍ ((c = *l++) < '0' || (c > '9'))
               ပြန်ပေး(0);
            bha_nga;

         pak_sa ALPHA:
            c = tolower(*l++);
            အကယ်၍ (c < 'a' || c > 'z')
               ပြန်ပေး(0);
            bha_nga;

         pak_sa NALPHA:
            c = tolower(*l++);
            အကယ်၍ (c >= 'a' && c <= 'z')
               bha_nga;
            မဟုတ်ပါက အကယ်၍ (c < '0' || c > '9')
               ပြန်ပေး(0);
            bha_nga;

         pak_sa PUNCT:
            c = *l++;
            အကယ်၍ (c == 0 || c > ' ')
               ပြန်ပေး(0);
            bha_nga;

         pak_sa CLASS:
         pak_sa NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            do {
               အကယ်၍ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  အကယ်၍ (c >= p[-2] && c <= p[-1])
                     bha_nga;
               }
               မဟုတ်ပါက အကယ်၍ (c == *p++)
                  bha_nga;
            } နေစဉ် (--n > 1);
            အကယ်၍ ((op == CLASS) == (n <= 1))
               ပြန်ပေး(0);
            အကယ်၍ (op == CLASS)
               p += n - 2;
            bha_nga;

         pak_sa MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            နေစဉ် (*p++ != ENDPAT); /* Skip over pattern   */
            အကယ်၍ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            bha_nga;                  /* Always succeeds     */

         pak_sa PLUS:                 /* One or more ...     */
            အကယ်၍ ((l = pmatch(l, p)) == 0)
               ပြန်ပေး(0);           /* Gotta have a match  */
         pak_sa STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            နေစဉ် (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            နေစဉ် (*p++ != ENDPAT); /* Skip over pattern   */
            နေစဉ် (l > are) {       /* Try to match rest   */
               အကယ်၍ (e = pmatch(l, p))
                  ပြန်ပေး(e);
               --l;                 /* Nope, try earlier   */
            }
            အကယ်၍ (e = pmatch(l, p))
               ပြန်ပေး(e);
            ပြန်ပေး(0);              /* Nothing else worked */

         default:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ပြန်ပေး(l);
}

/*** Report an error ***********************************/
void error(var_na *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
   var_na   *p;
   ကိန်းပြည့်    c, i;
   ကိန်းပြည့်             gotpattern;

   FILE            *f;

   အကယ်၍ (argc <= 1)
      usage("No arguments");
   အကယ်၍ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ပြန်ပေး 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   အတွက် (i=1; i < argc; ++i) {
      p = argv[i];
      အကယ်၍ (*p == '-') {
         ++p;
         နေစဉ် (c = *p++) {
            switch(tolower(c)) {

               pak_sa '?':
                  help(documentation);
                  bha_nga;

               pak_sa 'C':
               pak_sa 'c':
                  ++cflag;
                  bha_nga;

               pak_sa 'D':
               pak_sa 'd':
                  ++debug;
                  bha_nga;

               pak_sa 'F':
               pak_sa 'f':
                  ++fflag;
                  bha_nga;

               pak_sa 'n':
               pak_sa 'N':
                  ++nflag;
                  bha_nga;

               pak_sa 'v':
               pak_sa 'V':
                  ++vflag;
                  bha_nga;

               default:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } မဟုတ်ပါက အကယ်၍ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   အကယ်၍ (!gotpattern)
      usage("No pattern");
   အကယ်၍ (nfile == 0)
      grep(stdin, 0);
   မဟုတ်ပါက {
      fflag = fflag ^ (nfile > 0);
      အတွက် (i=1; i < argc; ++i) {
         အကယ်၍ (p = argv[i]) {
            အကယ်၍ ((f=fopen(p, "r")) == NULL)
               cant(p);
            မဟုတ်ပါက {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

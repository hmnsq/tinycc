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

char    *documentation[] = {
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

char    *patdoc[] = {
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

số_nguyên cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

char *pp, lbuf[LMAX], pbuf[PMAX];

char *cclass();
char *pmatch();
void store(số_nguyên);
void error(char *);
void badpat(char *, char *, char *);
số_nguyên match(void);


/*** Display a file name *******************************/
void file(char *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
void cant(char *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
void help(char **hp)
{
   char   **dp;

   cho (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
void usage(char *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
void compile(char *source)
{
   char  *s;         /* Source string pointer     */
   char  *lp;        /* Last pattern pointer      */
   số_nguyên   c;          /* Current character         */
   số_nguyên            o;          /* Temp                      */
   char           *spp;       /* Save beginning of pattern */

   s = source;
   nếu (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   trong_khi (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      nếu (c == '*' || c == '+' || c == '-') {
         nếu (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         trong_khi (--pp > lp)       /* Move pattern down    */
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

         case '^':
            store(BOL);
            break;

         case '$':
            store(EOL);
            break;

         case '.':
            store(ANY);
            break;

         case '[':
            s = cclass(source, s);
            break;

         case ':':
            nếu (*s) {
               switch(tolower(c = *s++)) {

                  case 'a':
                  case 'A':
                     store(ALPHA);
                     break;

                  case 'd':
                  case 'D':
                     store(DIGIT);
                     break;

                  case 'n':
                  case 'N':
                     store(NALPHA);
                     break;

                  case ' ':
                     store(PUNCT);
                     break;

                  default:
                     badpat("Unknown : type", source, s);

               }
               break;
            }
            không_thì    badpat("No : type", source, s);

         case '\\':
            nếu (*s)
               c = *s++;

         default:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   nếu (debug) {
      cho (lp = pbuf; lp < pp;) {
         nếu ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         không_thì    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
char *cclass(char *source, char *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   char   *s;        /* Source pointer    */
   char   *cp;       /* Pattern start     */
   số_nguyên    c;         /* Current character */
   số_nguyên             o;         /* Temp              */

   s = src;
   o = CLASS;
   nếu (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   trong_khi ((c = *s++) && c!=']') {
      nếu (c == '\\') {                /* Store quoted char    */
         nếu ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         không_thì    store(tolower(c));
      }
      không_thì nếu (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      không_thì {
         store(tolower(c));      /* Store normal char */
      }
   }
   nếu (c != ']')
      badpat("Unterminated class", source, s);
   nếu ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   nếu (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   trả_về(s);
}

/*** Store an entry in the pattern buffer **************/
void store(số_nguyên op)
{
   nếu (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
void badpat(char *message, char *source, char *stop)
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
void grep(FILE *fp, char *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   số_nguyên lno, count, m;

   lno = 0;
   count = 0;
   trong_khi (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      nếu ((m && !vflag) || (!m && vflag)) {
         ++count;
         nếu (!cflag) {
            nếu (fflag && fn) {
               file(fn);
               fn = 0;
            }
            nếu (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   nếu (cflag) {
      nếu (fflag && fn)
         file(fn);
      printf("%d\n", count);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
số_nguyên match()
{
   char   *l;        /* Line pointer       */

   cho (l = lbuf; *l; ++l) {
      nếu (pmatch(l, pbuf))
         trả_về(1);
   }
   trả_về(0);
}

/*** Match partial line with pattern *******************/
char *pmatch(char *line, char *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   char   *l;        /* Current line pointer         */
   char   *p;        /* Current pattern pointer      */
   char   c;         /* Current character            */
   char            *e;        /* End for STAR and PLUS match  */
   số_nguyên             op;        /* Pattern operation            */
   số_nguyên             n;         /* Class counter                */
   char            *are;      /* Start of STAR match          */

   l = line;
   nếu (debug > 1)
      printf("pmatch(\"%s\")\n", line);
   p = pattern;
   trong_khi ((op = *p++) != ENDPAT) {
      nếu (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-line, *l, *l, op);
      switch(op) {

         case CHAR:
            nếu (tolower(*l++) != *p++)
               trả_về(0);
            break;

         case BOL:
            nếu (l != lbuf)
               trả_về(0);
            break;

         case EOL:
            nếu (*l != '\0')
               trả_về(0);
            break;

         case ANY:
            nếu (*l++ == '\0')
               trả_về(0);
            break;

         case DIGIT:
            nếu ((c = *l++) < '0' || (c > '9'))
               trả_về(0);
            break;

         case ALPHA:
            c = tolower(*l++);
            nếu (c < 'a' || c > 'z')
               trả_về(0);
            break;

         case NALPHA:
            c = tolower(*l++);
            nếu (c >= 'a' && c <= 'z')
               break;
            không_thì nếu (c < '0' || c > '9')
               trả_về(0);
            break;

         case PUNCT:
            c = *l++;
            nếu (c == 0 || c > ' ')
               trả_về(0);
            break;

         case CLASS:
         case NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            do {
               nếu (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  nếu (c >= p[-2] && c <= p[-1])
                     break;
               }
               không_thì nếu (c == *p++)
                  break;
            } trong_khi (--n > 1);
            nếu ((op == CLASS) == (n <= 1))
               trả_về(0);
            nếu (op == CLASS)
               p += n - 2;
            break;

         case MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            trong_khi (*p++ != ENDPAT); /* Skip over pattern   */
            nếu (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            break;                  /* Always succeeds     */

         case PLUS:                 /* One or more ...     */
            nếu ((l = pmatch(l, p)) == 0)
               trả_về(0);           /* Gotta have a match  */
         case STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            trong_khi (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            trong_khi (*p++ != ENDPAT); /* Skip over pattern   */
            trong_khi (l > are) {       /* Try to match rest   */
               nếu (e = pmatch(l, p))
                  trả_về(e);
               --l;                 /* Nope, try earlier   */
            }
            nếu (e = pmatch(l, p))
               trả_về(e);
            trả_về(0);              /* Nothing else worked */

         default:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   trả_về(l);
}

/*** Report an error ***********************************/
void error(char *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
số_nguyên main(số_nguyên argc, char **argv)
{
   char   *p;
   số_nguyên    c, i;
   số_nguyên             gotpattern;

   FILE            *f;

   nếu (argc <= 1)
      usage("No arguments");
   nếu (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      trả_về 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   cho (i=1; i < argc; ++i) {
      p = argv[i];
      nếu (*p == '-') {
         ++p;
         trong_khi (c = *p++) {
            switch(tolower(c)) {

               case '?':
                  help(documentation);
                  break;

               case 'C':
               case 'c':
                  ++cflag;
                  break;

               case 'D':
               case 'd':
                  ++debug;
                  break;

               case 'F':
               case 'f':
                  ++fflag;
                  break;

               case 'n':
               case 'N':
                  ++nflag;
                  break;

               case 'v':
               case 'V':
                  ++vflag;
                  break;

               default:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } không_thì nếu (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   nếu (!gotpattern)
      usage("No pattern");
   nếu (nfile == 0)
      grep(stdin, 0);
   không_thì {
      fflag = fflag ^ (nfile > 0);
      cho (i=1; i < argc; ++i) {
         nếu (p = argv[i]) {
            nếu ((f=fopen(p, "r")) == NULL)
               cant(p);
            không_thì {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

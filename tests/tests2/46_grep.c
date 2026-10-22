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
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

বর্ণ    *documentation[] = {
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

বর্ণ    *patdoc[] = {
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

পূর্ণাঙ্ক cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

বর্ণ *pp, lbuf[LMAX], pbuf[PMAX];

বর্ণ *cclass();
বর্ণ *pmatch();
শূন্য store(পূর্ণাঙ্ক);
শূন্য error(বর্ণ *);
শূন্য badpat(বর্ণ *, বর্ণ *, বর্ণ *);
পূর্ণাঙ্ক match(শূন্য);


/*** Display a file name *******************************/
শূন্য file(বর্ণ *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
শূন্য cant(বর্ণ *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
শূন্য help(বর্ণ **hp)
{
   বর্ণ   **dp;

   প্রতি (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
শূন্য usage(বর্ণ *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
শূন্য compile(বর্ণ *source)
{
   বর্ণ  *s;         /* Source string pointer     */
   বর্ণ  *lp;        /* Last pattern pointer      */
   পূর্ণাঙ্ক   c;          /* Current character         */
   পূর্ণাঙ্ক            o;          /* Temp                      */
   বর্ণ           *spp;       /* Save beginning of pattern */

   s = source;
   যদি (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   যাবত্ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      যদি (c == '*' || c == '+' || c == '-') {
         যদি (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         যাবত্ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         অনুবর্ত;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      বিকল্প(c) {

         পক্ষ '^':
            store(BOL);
            ভঙ্গ;

         পক্ষ '$':
            store(EOL);
            ভঙ্গ;

         পক্ষ '.':
            store(ANY);
            ভঙ্গ;

         পক্ষ '[':
            s = cclass(source, s);
            ভঙ্গ;

         পক্ষ ':':
            যদি (*s) {
               বিকল্প(tolower(c = *s++)) {

                  পক্ষ 'a':
                  পক্ষ 'A':
                     store(ALPHA);
                     ভঙ্গ;

                  পক্ষ 'd':
                  পক্ষ 'D':
                     store(DIGIT);
                     ভঙ্গ;

                  পক্ষ 'n':
                  পক্ষ 'N':
                     store(NALPHA);
                     ভঙ্গ;

                  পক্ষ ' ':
                     store(PUNCT);
                     ভঙ্গ;

                  স্বভাব:
                     badpat("Unknown : type", source, s);

               }
               ভঙ্গ;
            }
            অন্যথা    badpat("No : type", source, s);

         পক্ষ '\\':
            যদি (*s)
               c = *s++;

         স্বভাব:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   যদি (debug) {
      প্রতি (lp = pbuf; lp < pp;) {
         যদি ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         অন্যথা    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
বর্ণ *cclass(বর্ণ *source, বর্ণ *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   বর্ণ   *s;        /* Source pointer    */
   বর্ণ   *cp;       /* Pattern start     */
   পূর্ণাঙ্ক    c;         /* Current character */
   পূর্ণাঙ্ক             o;         /* Temp              */

   s = src;
   o = CLASS;
   যদি (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   যাবত্ ((c = *s++) && c!=']') {
      যদি (c == '\\') {                /* Store quoted char    */
         যদি ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         অন্যথা    store(tolower(c));
      }
      অন্যথা যদি (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      অন্যথা {
         store(tolower(c));      /* Store normal char */
      }
   }
   যদি (c != ']')
      badpat("Unterminated class", source, s);
   যদি ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   যদি (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   প্রত্যাগম(s);
}

/*** Store an entry in the pattern buffer **************/
শূন্য store(পূর্ণাঙ্ক op)
{
   যদি (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
শূন্য badpat(বর্ণ *message, বর্ণ *source, বর্ণ *stop)
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
শূন্য grep(FILE *fp, বর্ণ *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   পূর্ণাঙ্ক lno, গুনতি_2, m;

   lno = 0;
   গুনতি_2 = 0;
   যাবত্ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      যদি ((m && !vflag) || (!m && vflag)) {
         ++গুনতি_2;
         যদি (!cflag) {
            যদি (fflag && fn) {
               file(fn);
               fn = 0;
            }
            যদি (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   যদি (cflag) {
      যদি (fflag && fn)
         file(fn);
      printf("%d\n", গুনতি_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
পূর্ণাঙ্ক match()
{
   বর্ণ   *l;        /* Line pointer       */

   প্রতি (l = lbuf; *l; ++l) {
      যদি (pmatch(l, pbuf))
         প্রত্যাগম(1);
   }
   প্রত্যাগম(0);
}

/*** Match partial line with pattern *******************/
বর্ণ *pmatch(বর্ণ *সারি, বর্ণ *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   বর্ণ   *l;        /* Current line pointer         */
   বর্ণ   *p;        /* Current pattern pointer      */
   বর্ণ   c;         /* Current character            */
   বর্ণ            *e;        /* End for STAR and PLUS match  */
   পূর্ণাঙ্ক             op;        /* Pattern operation            */
   পূর্ণাঙ্ক             n;         /* Class counter                */
   বর্ণ            *are;      /* Start of STAR match          */

   l = সারি;
   যদি (debug > 1)
      printf("pmatch(\"%s\")\n", সারি);
   p = pattern;
   যাবত্ ((op = *p++) != ENDPAT) {
      যদি (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-সারি, *l, *l, op);
      বিকল্প(op) {

         পক্ষ CHAR:
            যদি (tolower(*l++) != *p++)
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ BOL:
            যদি (l != lbuf)
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ EOL:
            যদি (*l != '\0')
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ ANY:
            যদি (*l++ == '\0')
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ DIGIT:
            যদি ((c = *l++) < '0' || (c > '9'))
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ ALPHA:
            c = tolower(*l++);
            যদি (c < 'a' || c > 'z')
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ NALPHA:
            c = tolower(*l++);
            যদি (c >= 'a' && c <= 'z')
               ভঙ্গ;
            অন্যথা যদি (c < '0' || c > '9')
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ PUNCT:
            c = *l++;
            যদি (c == 0 || c > ' ')
               প্রত্যাগম(0);
            ভঙ্গ;

         পক্ষ CLASS:
         পক্ষ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            কুরু {
               যদি (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  যদি (c >= p[-2] && c <= p[-1])
                     ভঙ্গ;
               }
               অন্যথা যদি (c == *p++)
                  ভঙ্গ;
            } যাবত্ (--n > 1);
            যদি ((op == CLASS) == (n <= 1))
               প্রত্যাগম(0);
            যদি (op == CLASS)
               p += n - 2;
            ভঙ্গ;

         পক্ষ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            যাবত্ (*p++ != ENDPAT); /* Skip over pattern   */
            যদি (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ভঙ্গ;                  /* Always succeeds     */

         পক্ষ PLUS:                 /* One or more ...     */
            যদি ((l = pmatch(l, p)) == 0)
               প্রত্যাগম(0);           /* Gotta have a match  */
         পক্ষ STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            যাবত্ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            যাবত্ (*p++ != ENDPAT); /* Skip over pattern   */
            যাবত্ (l > are) {       /* Try to match rest   */
               যদি (e = pmatch(l, p))
                  প্রত্যাগম(e);
               --l;                 /* Nope, try earlier   */
            }
            যদি (e = pmatch(l, p))
               প্রত্যাগম(e);
            প্রত্যাগম(0);              /* Nothing else worked */

         স্বভাব:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   প্রত্যাগম(l);
}

/*** Report an error ***********************************/
শূন্য error(বর্ণ *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{
   বর্ণ   *p;
   পূর্ণাঙ্ক    c, i;
   পূর্ণাঙ্ক             gotpattern;

   FILE            *f;

   যদি (argc <= 1)
      usage("No arguments");
   যদি (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      প্রত্যাগম 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   প্রতি (i=1; i < argc; ++i) {
      p = argv[i];
      যদি (*p == '-') {
         ++p;
         যাবত্ (c = *p++) {
            বিকল্প(tolower(c)) {

               পক্ষ '?':
                  help(documentation);
                  ভঙ্গ;

               পক্ষ 'C':
               পক্ষ 'c':
                  ++cflag;
                  ভঙ্গ;

               পক্ষ 'D':
               পক্ষ 'd':
                  ++debug;
                  ভঙ্গ;

               পক্ষ 'F':
               পক্ষ 'f':
                  ++fflag;
                  ভঙ্গ;

               পক্ষ 'n':
               পক্ষ 'N':
                  ++nflag;
                  ভঙ্গ;

               পক্ষ 'v':
               পক্ষ 'V':
                  ++vflag;
                  ভঙ্গ;

               স্বভাব:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } অন্যথা যদি (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   যদি (!gotpattern)
      usage("No pattern");
   যদি (nfile == 0)
      grep(stdin, 0);
   অন্যথা {
      fflag = fflag ^ (nfile > 0);
      প্রতি (i=1; i < argc; ++i) {
         যদি (p = argv[i]) {
            যদি ((f=fopen(p, "r")) == রিক্ত)
               cant(p);
            অন্যথা {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

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

অক্ষর    *documentation[] = {
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

অক্ষর    *patdoc[] = {
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

পূর্ণসংখ্যা cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

অক্ষর *pp, lbuf[LMAX], pbuf[PMAX];

অক্ষর *cclass();
অক্ষর *pmatch();
শূন্য store(পূর্ণসংখ্যা);
শূন্য error(অক্ষর *);
শূন্য badpat(অক্ষর *, অক্ষর *, অক্ষর *);
পূর্ণসংখ্যা match(শূন্য);


/*** Display a file name *******************************/
শূন্য file(অক্ষর *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
শূন্য cant(অক্ষর *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
শূন্য help(অক্ষর **hp)
{
   অক্ষর   **dp;

   জন্য (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
শূন্য usage(অক্ষর *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
শূন্য compile(অক্ষর *source)
{
   অক্ষর  *s;         /* Source string pointer     */
   অক্ষর  *lp;        /* Last pattern pointer      */
   পূর্ণসংখ্যা   c;          /* Current character         */
   পূর্ণসংখ্যা            o;          /*অস্থায়ী*/
   অক্ষর           *spp;       /* Save beginning of pattern */

   s = source;
   যদি (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   যখন (c = *s++) {
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
         যখন (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         চালু;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      নির্বাচন(c) {

         ক্ষেত্র '^':
            store(BOL);
            বিরতি;

         ক্ষেত্র '$':
            store(EOL);
            বিরতি;

         ক্ষেত্র '.':
            store(ANY);
            বিরতি;

         ক্ষেত্র '[':
            s = cclass(source, s);
            বিরতি;

         ক্ষেত্র ':':
            যদি (*s) {
               নির্বাচন(tolower(c = *s++)) {

                  ক্ষেত্র 'a':
                  ক্ষেত্র 'A':
                     store(ALPHA);
                     বিরতি;

                  ক্ষেত্র 'd':
                  ক্ষেত্র 'D':
                     store(DIGIT);
                     বিরতি;

                  ক্ষেত্র 'n':
                  ক্ষেত্র 'N':
                     store(NALPHA);
                     বিরতি;

                  ক্ষেত্র ' ':
                     store(PUNCT);
                     বিরতি;

                  পূর্বনির্ধারিত:
                     badpat("Unknown : type", source, s);

               }
               বিরতি;
            }
            অন্যথা    badpat("No : type", source, s);

         ক্ষেত্র '\\':
            যদি (*s)
               c = *s++;

         পূর্বনির্ধারিত:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   যদি (debug) {
      জন্য (lp = pbuf; lp < pp;) {
         যদি ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         অন্যথা    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
অক্ষর *cclass(অক্ষর *source, অক্ষর *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   অক্ষর   *s;        /* Source pointer    */
   অক্ষর   *cp;       /* Pattern start     */
   পূর্ণসংখ্যা    c;         /* Current character */
   পূর্ণসংখ্যা             o;         /* Temp              */

   s = src;
   o = CLASS;
   যদি (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   যখন ((c = *s++) && c!=']') {
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
   ফেরত(s);
}

/*** Store an entry in the pattern buffer **************/
শূন্য store(পূর্ণসংখ্যা op)
{
   যদি (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
শূন্য badpat(অক্ষর *message, অক্ষর *source, অক্ষর *stop)
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
শূন্য grep(FILE *fp, অক্ষর *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   পূর্ণসংখ্যা lno, গুনতি_2, m;

   lno = 0;
   গুনতি_2 = 0;
   যখন (fgets(lbuf, LMAX, fp)) {
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
পূর্ণসংখ্যা match()
{
   অক্ষর   *l;        /* Line pointer       */

   জন্য (l = lbuf; *l; ++l) {
      যদি (pmatch(l, pbuf))
         ফেরত(1);
   }
   ফেরত(0);
}

/*** Match partial line with pattern *******************/
অক্ষর *pmatch(অক্ষর *সারি, অক্ষর *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   অক্ষর   *l;        /* Current line pointer         */
   অক্ষর   *p;        /* Current pattern pointer      */
   অক্ষর   c;         /* Current character            */
   অক্ষর            *e;        /* End for STAR and PLUS match  */
   পূর্ণসংখ্যা             op;        /* Pattern operation            */
   পূর্ণসংখ্যা             n;         /* Class counter                */
   অক্ষর            *are;      /* Start of STAR match          */

   l = সারি;
   যদি (debug > 1)
      printf("pmatch(\"%s\")\n", সারি);
   p = pattern;
   যখন ((op = *p++) != ENDPAT) {
      যদি (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-সারি, *l, *l, op);
      নির্বাচন(op) {

         ক্ষেত্র CHAR:
            যদি (tolower(*l++) != *p++)
               ফেরত(0);
            বিরতি;

         ক্ষেত্র BOL:
            যদি (l != lbuf)
               ফেরত(0);
            বিরতি;

         ক্ষেত্র EOL:
            যদি (*l != '\0')
               ফেরত(0);
            বিরতি;

         ক্ষেত্র ANY:
            যদি (*l++ == '\0')
               ফেরত(0);
            বিরতি;

         ক্ষেত্র DIGIT:
            যদি ((c = *l++) < '0' || (c > '9'))
               ফেরত(0);
            বিরতি;

         ক্ষেত্র ALPHA:
            c = tolower(*l++);
            যদি (c < 'a' || c > 'z')
               ফেরত(0);
            বিরতি;

         ক্ষেত্র NALPHA:
            c = tolower(*l++);
            যদি (c >= 'a' && c <= 'z')
               বিরতি;
            অন্যথা যদি (c < '0' || c > '9')
               ফেরত(0);
            বিরতি;

         ক্ষেত্র PUNCT:
            c = *l++;
            যদি (c == 0 || c > ' ')
               ফেরত(0);
            বিরতি;

         ক্ষেত্র CLASS:
         ক্ষেত্র NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            করো {
               যদি (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  যদি (c >= p[-2] && c <= p[-1])
                     বিরতি;
               }
               অন্যথা যদি (c == *p++)
                  বিরতি;
            } যখন (--n > 1);
            যদি ((op == CLASS) == (n <= 1))
               ফেরত(0);
            যদি (op == CLASS)
               p += n - 2;
            বিরতি;

         ক্ষেত্র MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            যখন (*p++ != ENDPAT); /* Skip over pattern   */
            যদি (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            বিরতি;                  /* Always succeeds     */

         ক্ষেত্র PLUS:                 /* One or more ...     */
            যদি ((l = pmatch(l, p)) == 0)
               ফেরত(0);           /* Gotta have a match  */
         ক্ষেত্র STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            যখন (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            যখন (*p++ != ENDPAT); /* Skip over pattern   */
            যখন (l > are) {       /* Try to match rest   */
               যদি (e = pmatch(l, p))
                  ফেরত(e);
               --l;                 /* Nope, try earlier   */
            }
            যদি (e = pmatch(l, p))
               ফেরত(e);
            ফেরত(0);              /* Nothing else worked */

         পূর্বনির্ধারিত:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ফেরত(l);
}

/*** Report an error ***********************************/
শূন্য error(অক্ষর *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
   অক্ষর   *p;
   পূর্ণসংখ্যা    c, i;
   পূর্ণসংখ্যা             gotpattern;

   FILE            *f;

   যদি (argc <= 1)
      usage("No arguments");
   যদি (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ফেরত 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   জন্য (i=1; i < argc; ++i) {
      p = argv[i];
      যদি (*p == '-') {
         ++p;
         যখন (c = *p++) {
            নির্বাচন(tolower(c)) {

               ক্ষেত্র '?':
                  help(documentation);
                  বিরতি;

               ক্ষেত্র 'C':
               ক্ষেত্র 'c':
                  ++cflag;
                  বিরতি;

               ক্ষেত্র 'D':
               ক্ষেত্র 'd':
                  ++debug;
                  বিরতি;

               ক্ষেত্র 'F':
               ক্ষেত্র 'f':
                  ++fflag;
                  বিরতি;

               ক্ষেত্র 'n':
               ক্ষেত্র 'N':
                  ++nflag;
                  বিরতি;

               ক্ষেত্র 'v':
               ক্ষেত্র 'V':
                  ++vflag;
                  বিরতি;

               পূর্বনির্ধারিত:
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
      জন্য (i=1; i < argc; ++i) {
         যদি (p = argv[i]) {
            যদি ((f=fopen(p, "r")) == ফাঁকা)
               cant(p);
            অন্যথা {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

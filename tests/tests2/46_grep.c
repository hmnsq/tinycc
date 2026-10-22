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
#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

حرف    *documentation[] = {
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

حرف    *patdoc[] = {
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

صحيح cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

حرف *pp, lbuf[LMAX], pbuf[PMAX];

حرف *cclass();
حرف *pmatch();
فراغ store(صحيح);
فراغ error(حرف *);
فراغ badpat(حرف *, حرف *, حرف *);
صحيح match(فراغ);


/*** Display a file name *******************************/
فراغ file(حرف *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
فراغ cant(حرف *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
فراغ help(حرف **hp)
{
   حرف   **dp;

   لكل (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
فراغ usage(حرف *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
فراغ compile(حرف *source)
{
   حرف  *s;         /* Source string pointer     */
   حرف  *lp;        /* Last pattern pointer      */
   صحيح   c;          /* Current character         */
   صحيح            o;          /* Temp                      */
   حرف           *spp;       /* Save beginning of pattern */

   s = source;
   إذا (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   طالما (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      إذا (c == '*' || c == '+' || c == '-') {
         إذا (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         طالما (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         استمر;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      بدل(c) {

         حالة '^':
            store(BOL);
            اكسر;

         حالة '$':
            store(EOL);
            اكسر;

         حالة '.':
            store(ANY);
            اكسر;

         حالة '[':
            s = cclass(source, s);
            اكسر;

         حالة ':':
            إذا (*s) {
               بدل(tolower(c = *s++)) {

                  حالة 'a':
                  حالة 'A':
                     store(ALPHA);
                     اكسر;

                  حالة 'd':
                  حالة 'D':
                     store(DIGIT);
                     اكسر;

                  حالة 'n':
                  حالة 'N':
                     store(NALPHA);
                     اكسر;

                  حالة ' ':
                     store(PUNCT);
                     اكسر;

                  افتراضي:
                     badpat("Unknown : type", source, s);

               }
               اكسر;
            }
            وإلا    badpat("No : type", source, s);

         حالة '\\':
            إذا (*s)
               c = *s++;

         افتراضي:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   إذا (debug) {
      لكل (lp = pbuf; lp < pp;) {
         إذا ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         وإلا    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
حرف *cclass(حرف *source, حرف *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   حرف   *s;        /* Source pointer    */
   حرف   *cp;       /* Pattern start     */
   صحيح    c;         /* Current character */
   صحيح             o;         /* Temp              */

   s = src;
   o = CLASS;
   إذا (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   طالما ((c = *s++) && c!=']') {
      إذا (c == '\\') {                /* Store quoted char    */
         إذا ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         وإلا    store(tolower(c));
      }
      وإلا إذا (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      وإلا {
         store(tolower(c));      /* Store normal char */
      }
   }
   إذا (c != ']')
      badpat("Unterminated class", source, s);
   إذا ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   إذا (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   أرجع(s);
}

/*** Store an entry in the pattern buffer **************/
فراغ store(صحيح op)
{
   إذا (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
فراغ badpat(حرف *message, حرف *source, حرف *stop)
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
فراغ grep(FILE *fp, حرف *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   صحيح lno, عدد_2, m;

   lno = 0;
   عدد_2 = 0;
   طالما (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      إذا ((m && !vflag) || (!m && vflag)) {
         ++عدد_2;
         إذا (!cflag) {
            إذا (fflag && fn) {
               file(fn);
               fn = 0;
            }
            إذا (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   إذا (cflag) {
      إذا (fflag && fn)
         file(fn);
      printf("%d\n", عدد_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
صحيح match()
{
   حرف   *l;        /* Line pointer       */

   لكل (l = lbuf; *l; ++l) {
      إذا (pmatch(l, pbuf))
         أرجع(1);
   }
   أرجع(0);
}

/*** Match partial line with pattern *******************/
حرف *pmatch(حرف *سطر, حرف *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   حرف   *l;        /* Current line pointer         */
   حرف   *p;        /* Current pattern pointer      */
   حرف   c;         /* Current character            */
   حرف            *e;        /* End for STAR and PLUS match  */
   صحيح             op;        /* Pattern operation            */
   صحيح             n;         /* Class counter                */
   حرف            *are;      /* Start of STAR match          */

   l = سطر;
   إذا (debug > 1)
      printf("pmatch(\"%s\")\n", سطر);
   p = pattern;
   طالما ((op = *p++) != ENDPAT) {
      إذا (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-سطر, *l, *l, op);
      بدل(op) {

         حالة CHAR:
            إذا (tolower(*l++) != *p++)
               أرجع(0);
            اكسر;

         حالة BOL:
            إذا (l != lbuf)
               أرجع(0);
            اكسر;

         حالة EOL:
            إذا (*l != '\0')
               أرجع(0);
            اكسر;

         حالة ANY:
            إذا (*l++ == '\0')
               أرجع(0);
            اكسر;

         حالة DIGIT:
            إذا ((c = *l++) < '0' || (c > '9'))
               أرجع(0);
            اكسر;

         حالة ALPHA:
            c = tolower(*l++);
            إذا (c < 'a' || c > 'z')
               أرجع(0);
            اكسر;

         حالة NALPHA:
            c = tolower(*l++);
            إذا (c >= 'a' && c <= 'z')
               اكسر;
            وإلا إذا (c < '0' || c > '9')
               أرجع(0);
            اكسر;

         حالة PUNCT:
            c = *l++;
            إذا (c == 0 || c > ' ')
               أرجع(0);
            اكسر;

         حالة CLASS:
         حالة NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            افعل {
               إذا (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  إذا (c >= p[-2] && c <= p[-1])
                     اكسر;
               }
               وإلا إذا (c == *p++)
                  اكسر;
            } طالما (--n > 1);
            إذا ((op == CLASS) == (n <= 1))
               أرجع(0);
            إذا (op == CLASS)
               p += n - 2;
            اكسر;

         حالة MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            طالما (*p++ != ENDPAT); /* Skip over pattern   */
            إذا (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            اكسر;                  /* Always succeeds     */

         حالة PLUS:                 /* One or more ...     */
            إذا ((l = pmatch(l, p)) == 0)
               أرجع(0);           /* Gotta have a match  */
         حالة STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            طالما (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            طالما (*p++ != ENDPAT); /* Skip over pattern   */
            طالما (l > are) {       /* Try to match rest   */
               إذا (e = pmatch(l, p))
                  أرجع(e);
               --l;                 /* Nope, try earlier   */
            }
            إذا (e = pmatch(l, p))
               أرجع(e);
            أرجع(0);              /* Nothing else worked */

         افتراضي:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   أرجع(l);
}

/*** Report an error ***********************************/
فراغ error(حرف *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
صحيح main(صحيح argc, حرف **argv)
{
   حرف   *p;
   صحيح    c, i;
   صحيح             gotpattern;

   FILE            *f;

   إذا (argc <= 1)
      usage("No arguments");
   إذا (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      أرجع 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   لكل (i=1; i < argc; ++i) {
      p = argv[i];
      إذا (*p == '-') {
         ++p;
         طالما (c = *p++) {
            بدل(tolower(c)) {

               حالة '?':
                  help(documentation);
                  اكسر;

               حالة 'C':
               حالة 'c':
                  ++cflag;
                  اكسر;

               حالة 'D':
               حالة 'd':
                  ++debug;
                  اكسر;

               حالة 'F':
               حالة 'f':
                  ++fflag;
                  اكسر;

               حالة 'n':
               حالة 'N':
                  ++nflag;
                  اكسر;

               حالة 'v':
               حالة 'V':
                  ++vflag;
                  اكسر;

               افتراضي:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } وإلا إذا (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   إذا (!gotpattern)
      usage("No pattern");
   إذا (nfile == 0)
      grep(stdin, 0);
   وإلا {
      fflag = fflag ^ (nfile > 0);
      لكل (i=1; i < argc; ++i) {
         إذا (p = argv[i]) {
            إذا ((f=fopen(p, "r")) == عدم)
               cant(p);
            وإلا {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

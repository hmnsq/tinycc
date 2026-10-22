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

#تعریف_کن LMAX    512
#تعریف_کن PMAX    256

#تعریف_کن CHAR    1
#تعریف_کن BOL     2
#تعریف_کن EOL     3
#تعریف_کن ANY     4
#تعریف_کن CLASS   5
#تعریف_کن NCLASS  6
#تعریف_کن ستاره_2    7
#تعریف_کن PLUS    8
#تعریف_کن MINUS   9
#تعریف_کن ALPHA   10
#تعریف_کن DIGIT   11
#تعریف_کن NALPHA  12
#تعریف_کن PUNCT   13
#تعریف_کن RANGE   14
#تعریف_کن ENDPAT  15

صحيح cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

حرف *pp, lbuf[LMAX], pbuf[PMAX];

حرف *cclass();
حرف *pmatch();
فراغ store(صحيح);
فراغ error(حرف *);
فراغ badpat(حرف *, حرف *, حرف *);
صحيح تطابق(فراغ);


/*** Display a file name *******************************/
فراغ file(حرف *s)
{
   چاپ_کن("File %s:\n", s);
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
      چاپ_کن("%s\n", *dp);
}

/*** Display usage summary *****************************/
فراغ usage(حرف *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   خروج(1);
}

/*** Compile the pattern into global pbuf[] ************/
فراغ compile(حرف *منبع)
{
   حرف  *s;         /* Source string pointer     */
   حرف  *lp;        /* Last pattern pointer      */
   صحيح   c;          /* Current character         */
   صحيح            o;          /*موقت*/
   حرف           *spp;       /* Save beginning of pattern */

   s = منبع;
   إذا (debug)
      چاپ_کن("Pattern = \"%s\"\n", s);
   pp = pbuf;
   طالما (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      إذا (c == '*' || c == '+' || c == '-') {
         إذا (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == ستاره_2 ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", منبع, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         طالما (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? ستاره_2 :
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
            s = cclass(منبع, s);
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
                     badpat("Unknown : type", منبع, s);

               }
               اكسر;
            }
            وإلا    badpat("No : type", منبع, s);

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
            چاپ_کن("\\%o ", c);
         وإلا    چاپ_کن("%c ", c);
      }
      چاپ_کن("\n");
   }
}

/*** Compile a class (within []) ***********************/
حرف *cclass(حرف *منبع, حرف *src)
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
            badpat("Class terminates badly", منبع, s);
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
      badpat("Unterminated class", منبع, s);
   إذا ((c = (pp - cp)) >= 256)
      badpat("Class too large", منبع, s);
   إذا (c == 0)
      badpat("Empty class", منبع, s);
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
فراغ badpat(حرف *پیام_2, حرف *منبع, حرف *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", پیام_2, منبع);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-منبع, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
فراغ grep(FILE *fp, حرف *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   صحيح lno, شمار_2, m;

   lno = 0;
   شمار_2 = 0;
   طالما (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = تطابق();
      إذا ((m && !vflag) || (!m && vflag)) {
         ++شمار_2;
         إذا (!cflag) {
            إذا (fflag && fn) {
               file(fn);
               fn = 0;
            }
            إذا (nflag)
               چاپ_کن("%d\t", lno);
            چاپ_کن("%s\n", lbuf);
         }
      }
   }
   إذا (cflag) {
      إذا (fflag && fn)
         file(fn);
      چاپ_کن("%d\n", شمار_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
صحيح تطابق()
{
   حرف   *l;        /* Line pointer       */

   لكل (l = lbuf; *l; ++l) {
      إذا (pmatch(l, pbuf))
         أرجع(1);
   }
   أرجع(0);
}

/*** Match partial line with pattern *******************/
حرف *pmatch(حرف *سطر, حرف *الگو)
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
      چاپ_کن("pmatch(\"%s\")\n", سطر);
   p = الگو;
   طالما ((op = *p++) != ENDPAT) {
      إذا (debug > 1)
         چاپ_کن("byte[%ld] = 0%o, '%c', op = 0%o\n",
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
         حالة ستاره_2:                 /* Zero or more ...    */
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
            چاپ_کن("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   أرجع(l);
}

/*** Report an error ***********************************/
فراغ error(حرف *s)
{
   fprintf(stderr, "%s", s);
   خروج(1);
}

/*** Main program - parse arguments & grep *************/
صحيح اصلی(صحيح argc, حرف **argv)
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

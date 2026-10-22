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
   ܐܢ (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ܟܡܐ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ܐܢ (c == '*' || c == '+' || c == '-') {
         ܐܢ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ܟܡܐ (--pp > lp)       /* Move pattern down    */
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
            ܐܢ (*s) {
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
            ܐܚܪܢܐ    badpat("No : type", source, s);

         حالة '\\':
            ܐܢ (*s)
               c = *s++;

         افتراضي:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ܐܢ (debug) {
      لكل (lp = pbuf; lp < pp;) {
         ܐܢ ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         ܐܚܪܢܐ    printf("%c ", c);
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
   ܐܢ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ܟܡܐ ((c = *s++) && c!=']') {
      ܐܢ (c == '\\') {                /* Store quoted char    */
         ܐܢ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         ܐܚܪܢܐ    store(tolower(c));
      }
      ܐܚܪܢܐ ܐܢ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ܐܚܪܢܐ {
         store(tolower(c));      /* Store normal char */
      }
   }
   ܐܢ (c != ']')
      badpat("Unterminated class", source, s);
   ܐܢ ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   ܐܢ (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   ܦܢܐ(s);
}

/*** Store an entry in the pattern buffer **************/
فراغ store(صحيح op)
{
   ܐܢ (pp >= &pbuf[PMAX])
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
   صحيح lno, count, m;

   lno = 0;
   count = 0;
   ܟܡܐ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      ܐܢ ((m && !vflag) || (!m && vflag)) {
         ++count;
         ܐܢ (!cflag) {
            ܐܢ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ܐܢ (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   ܐܢ (cflag) {
      ܐܢ (fflag && fn)
         file(fn);
      printf("%d\n", count);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
صحيح match()
{
   حرف   *l;        /* Line pointer       */

   لكل (l = lbuf; *l; ++l) {
      ܐܢ (pmatch(l, pbuf))
         ܦܢܐ(1);
   }
   ܦܢܐ(0);
}

/*** Match partial line with pattern *******************/
حرف *pmatch(حرف *line, حرف *pattern)
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

   l = line;
   ܐܢ (debug > 1)
      printf("pmatch(\"%s\")\n", line);
   p = pattern;
   ܟܡܐ ((op = *p++) != ENDPAT) {
      ܐܢ (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-line, *l, *l, op);
      بدل(op) {

         حالة CHAR:
            ܐܢ (tolower(*l++) != *p++)
               ܦܢܐ(0);
            اكسر;

         حالة BOL:
            ܐܢ (l != lbuf)
               ܦܢܐ(0);
            اكسر;

         حالة EOL:
            ܐܢ (*l != '\0')
               ܦܢܐ(0);
            اكسر;

         حالة ANY:
            ܐܢ (*l++ == '\0')
               ܦܢܐ(0);
            اكسر;

         حالة DIGIT:
            ܐܢ ((c = *l++) < '0' || (c > '9'))
               ܦܢܐ(0);
            اكسر;

         حالة ALPHA:
            c = tolower(*l++);
            ܐܢ (c < 'a' || c > 'z')
               ܦܢܐ(0);
            اكسر;

         حالة NALPHA:
            c = tolower(*l++);
            ܐܢ (c >= 'a' && c <= 'z')
               اكسر;
            ܐܚܪܢܐ ܐܢ (c < '0' || c > '9')
               ܦܢܐ(0);
            اكسر;

         حالة PUNCT:
            c = *l++;
            ܐܢ (c == 0 || c > ' ')
               ܦܢܐ(0);
            اكسر;

         حالة CLASS:
         حالة NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            ܥܒܕ {
               ܐܢ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ܐܢ (c >= p[-2] && c <= p[-1])
                     اكسر;
               }
               ܐܚܪܢܐ ܐܢ (c == *p++)
                  اكسر;
            } ܟܡܐ (--n > 1);
            ܐܢ ((op == CLASS) == (n <= 1))
               ܦܢܐ(0);
            ܐܢ (op == CLASS)
               p += n - 2;
            اكسر;

         حالة MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ܟܡܐ (*p++ != ENDPAT); /* Skip over pattern   */
            ܐܢ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            اكسر;                  /* Always succeeds     */

         حالة PLUS:                 /* One or more ...     */
            ܐܢ ((l = pmatch(l, p)) == 0)
               ܦܢܐ(0);           /* Gotta have a match  */
         حالة STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ܟܡܐ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ܟܡܐ (*p++ != ENDPAT); /* Skip over pattern   */
            ܟܡܐ (l > are) {       /* Try to match rest   */
               ܐܢ (e = pmatch(l, p))
                  ܦܢܐ(e);
               --l;                 /* Nope, try earlier   */
            }
            ܐܢ (e = pmatch(l, p))
               ܦܢܐ(e);
            ܦܢܐ(0);              /* Nothing else worked */

         افتراضي:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ܦܢܐ(l);
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

   ܐܢ (argc <= 1)
      usage("No arguments");
   ܐܢ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ܦܢܐ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   لكل (i=1; i < argc; ++i) {
      p = argv[i];
      ܐܢ (*p == '-') {
         ++p;
         ܟܡܐ (c = *p++) {
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
      } ܐܚܪܢܐ ܐܢ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ܐܢ (!gotpattern)
      usage("No pattern");
   ܐܢ (nfile == 0)
      grep(stdin, 0);
   ܐܚܪܢܐ {
      fflag = fflag ^ (nfile > 0);
      لكل (i=1; i < argc; ++i) {
         ܐܢ (p = argv[i]) {
            ܐܢ ((f=fopen(p, "r")) == عدم)
               cant(p);
            ܐܚܪܢܐ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ܦܢܐ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

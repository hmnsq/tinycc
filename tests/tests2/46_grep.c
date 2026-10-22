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
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

ଅକ୍ଷର    *documentation[] = {
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

ଅକ୍ଷର    *patdoc[] = {
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

ଅକ୍ଷର *pp, lbuf[LMAX], pbuf[PMAX];

ଅକ୍ଷର *cclass();
ଅକ୍ଷର *pmatch();
ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ଶୂନ୍ୟ error(ଅକ୍ଷର *);
ଶୂନ୍ୟ badpat(ଅକ୍ଷର *, ଅକ୍ଷର *, ଅକ୍ଷର *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା match(ଶୂନ୍ୟ);


/*** Display a file name *******************************/
ଶୂନ୍ୟ file(ଅକ୍ଷର *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
ଶୂନ୍ୟ cant(ଅକ୍ଷର *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
ଶୂନ୍ୟ help(ଅକ୍ଷର **hp)
{
   ଅକ୍ଷର   **dp;

   ପାଇଁ (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
ଶୂନ୍ୟ usage(ଅକ୍ଷର *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
ଶୂନ୍ୟ compile(ଅକ୍ଷର *source)
{
   ଅକ୍ଷର  *s;         /* Source string pointer     */
   ଅକ୍ଷର  *lp;        /* Last pattern pointer      */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା   c;          /* Current character         */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା            o;          /* Temp                      */
   ଅକ୍ଷର           *spp;       /* Save beginning of pattern */

   s = source;
   ଯଦି (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ଯେତେବେଳେ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ଯଦି (c == '*' || c == '+' || c == '-') {
         ଯଦି (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ଯେତେବେଳେ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ଜାରି;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      ବାଛ(c) {

         ସ୍ଥିତି '^':
            store(BOL);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି '$':
            store(EOL);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି '.':
            store(ANY);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି '[':
            s = cclass(source, s);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି ':':
            ଯଦି (*s) {
               ବାଛ(tolower(c = *s++)) {

                  ସ୍ଥିତି 'a':
                  ସ୍ଥିତି 'A':
                     store(ALPHA);
                     ଭାଙ୍ଗ;

                  ସ୍ଥିତି 'd':
                  ସ୍ଥିତି 'D':
                     store(DIGIT);
                     ଭାଙ୍ଗ;

                  ସ୍ଥିତି 'n':
                  ସ୍ଥିତି 'N':
                     store(NALPHA);
                     ଭାଙ୍ଗ;

                  ସ୍ଥିତି ' ':
                     store(PUNCT);
                     ଭାଙ୍ଗ;

                  ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                     badpat("Unknown : type", source, s);

               }
               ଭାଙ୍ଗ;
            }
            ଅନ୍ୟଥା    badpat("No : type", source, s);

         ସ୍ଥିତି '\\':
            ଯଦି (*s)
               c = *s++;

         ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ଯଦି (debug) {
      ପାଇଁ (lp = pbuf; lp < pp;) {
         ଯଦି ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         ଅନ୍ୟଥା    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
ଅକ୍ଷର *cclass(ଅକ୍ଷର *source, ଅକ୍ଷର *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   ଅକ୍ଷର   *s;        /* Source pointer    */
   ଅକ୍ଷର   *cp;       /* Pattern start     */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା    c;         /* Current character */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା             o;         /* Temp              */

   s = src;
   o = CLASS;
   ଯଦି (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ଯେତେବେଳେ ((c = *s++) && c!=']') {
      ଯଦି (c == '\\') {                /* Store quoted char    */
         ଯଦି ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         ଅନ୍ୟଥା    store(tolower(c));
      }
      ଅନ୍ୟଥା ଯଦି (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ଅନ୍ୟଥା {
         store(tolower(c));      /* Store normal char */
      }
   }
   ଯଦି (c != ']')
      badpat("Unterminated class", source, s);
   ଯଦି ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   ଯଦି (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   ଫେରନ୍ତୁ(s);
}

/*** Store an entry in the pattern buffer **************/
ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
   ଯଦି (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
ଶୂନ୍ୟ badpat(ଅକ୍ଷର *message, ଅକ୍ଷର *source, ଅକ୍ଷର *stop)
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
ଶୂନ୍ୟ grep(FILE *fp, ଅକ୍ଷର *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା lno, ଗଣନା_3, m;

   lno = 0;
   ଗଣନା_3 = 0;
   ଯେତେବେଳେ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      ଯଦି ((m && !vflag) || (!m && vflag)) {
         ++ଗଣନା_3;
         ଯଦି (!cflag) {
            ଯଦି (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ଯଦି (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   ଯଦି (cflag) {
      ଯଦି (fflag && fn)
         file(fn);
      printf("%d\n", ଗଣନା_3);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
ପୂର୍ଣ୍ଣସଂଖ୍ୟା match()
{
   ଅକ୍ଷର   *l;        /* Line pointer       */

   ପାଇଁ (l = lbuf; *l; ++l) {
      ଯଦି (pmatch(l, pbuf))
         ଫେରନ୍ତୁ(1);
   }
   ଫେରନ୍ତୁ(0);
}

/*** Match partial line with pattern *******************/
ଅକ୍ଷର *pmatch(ଅକ୍ଷର *ଧାଡ଼ି, ଅକ୍ଷର *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   ଅକ୍ଷର   *l;        /* Current line pointer         */
   ଅକ୍ଷର   *p;        /* Current pattern pointer      */
   ଅକ୍ଷର   c;         /* Current character            */
   ଅକ୍ଷର            *e;        /* End for STAR and PLUS match  */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା             op;        /* Pattern operation            */
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା             n;         /* Class counter                */
   ଅକ୍ଷର            *are;      /* Start of STAR match          */

   l = ଧାଡ଼ି;
   ଯଦି (debug > 1)
      printf("pmatch(\"%s\")\n", ଧାଡ଼ି);
   p = pattern;
   ଯେତେବେଳେ ((op = *p++) != ENDPAT) {
      ଯଦି (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-ଧାଡ଼ି, *l, *l, op);
      ବାଛ(op) {

         ସ୍ଥିତି CHAR:
            ଯଦି (tolower(*l++) != *p++)
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି BOL:
            ଯଦି (l != lbuf)
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି EOL:
            ଯଦି (*l != '\0')
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି ANY:
            ଯଦି (*l++ == '\0')
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି DIGIT:
            ଯଦି ((c = *l++) < '0' || (c > '9'))
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି ALPHA:
            c = tolower(*l++);
            ଯଦି (c < 'a' || c > 'z')
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି NALPHA:
            c = tolower(*l++);
            ଯଦି (c >= 'a' && c <= 'z')
               ଭାଙ୍ଗ;
            ଅନ୍ୟଥା ଯଦି (c < '0' || c > '9')
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି PUNCT:
            c = *l++;
            ଯଦି (c == 0 || c > ' ')
               ଫେରନ୍ତୁ(0);
            ଭାଙ୍ଗ;

         ସ୍ଥିତି CLASS:
         ସ୍ଥିତି NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            କର {
               ଯଦି (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ଯଦି (c >= p[-2] && c <= p[-1])
                     ଭାଙ୍ଗ;
               }
               ଅନ୍ୟଥା ଯଦି (c == *p++)
                  ଭାଙ୍ଗ;
            } ଯେତେବେଳେ (--n > 1);
            ଯଦି ((op == CLASS) == (n <= 1))
               ଫେରନ୍ତୁ(0);
            ଯଦି (op == CLASS)
               p += n - 2;
            ଭାଙ୍ଗ;

         ସ୍ଥିତି MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ଯେତେବେଳେ (*p++ != ENDPAT); /* Skip over pattern   */
            ଯଦି (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ଭାଙ୍ଗ;                  /* Always succeeds     */

         ସ୍ଥିତି PLUS:                 /* One or more ...     */
            ଯଦି ((l = pmatch(l, p)) == 0)
               ଫେରନ୍ତୁ(0);           /* Gotta have a match  */
         ସ୍ଥିତି STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ଯେତେବେଳେ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ଯେତେବେଳେ (*p++ != ENDPAT); /* Skip over pattern   */
            ଯେତେବେଳେ (l > are) {       /* Try to match rest   */
               ଯଦି (e = pmatch(l, p))
                  ଫେରନ୍ତୁ(e);
               --l;                 /* Nope, try earlier   */
            }
            ଯଦି (e = pmatch(l, p))
               ଫେରନ୍ତୁ(e);
            ଫେରନ୍ତୁ(0);              /* Nothing else worked */

         ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ଫେରନ୍ତୁ(l);
}

/*** Report an error ***********************************/
ଶୂନ୍ୟ error(ଅକ୍ଷର *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
   ଅକ୍ଷର   *p;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା    c, i;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା             gotpattern;

   FILE            *f;

   ଯଦି (argc <= 1)
      usage("No arguments");
   ଯଦି (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ଫେରନ୍ତୁ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   ପାଇଁ (i=1; i < argc; ++i) {
      p = argv[i];
      ଯଦି (*p == '-') {
         ++p;
         ଯେତେବେଳେ (c = *p++) {
            ବାଛ(tolower(c)) {

               ସ୍ଥିତି '?':
                  help(documentation);
                  ଭାଙ୍ଗ;

               ସ୍ଥିତି 'C':
               ସ୍ଥିତି 'c':
                  ++cflag;
                  ଭାଙ୍ଗ;

               ସ୍ଥିତି 'D':
               ସ୍ଥିତି 'd':
                  ++debug;
                  ଭାଙ୍ଗ;

               ସ୍ଥିତି 'F':
               ସ୍ଥିତି 'f':
                  ++fflag;
                  ଭାଙ୍ଗ;

               ସ୍ଥିତି 'n':
               ସ୍ଥିତି 'N':
                  ++nflag;
                  ଭାଙ୍ଗ;

               ସ୍ଥିତି 'v':
               ସ୍ଥିତି 'V':
                  ++vflag;
                  ଭାଙ୍ଗ;

               ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } ଅନ୍ୟଥା ଯଦି (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ଯଦି (!gotpattern)
      usage("No pattern");
   ଯଦି (nfile == 0)
      grep(stdin, 0);
   ଅନ୍ୟଥା {
      fflag = fflag ^ (nfile > 0);
      ପାଇଁ (i=1; i < argc; ++i) {
         ଯଦି (p = argv[i]) {
            ଯଦି ((f=fopen(p, "r")) == ଖାଲି)
               cant(p);
            ଅନ୍ୟଥା {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

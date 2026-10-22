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
#شامل <stdio.h>
#شامل <stdlib.h>
#شامل <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

نویسه    *documentation[] = {
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

نویسه    *patdoc[] = {
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

صحیح cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

نویسه *pp, lbuf[LMAX], pbuf[PMAX];

نویسه *cclass();
نویسه *pmatch();
تهی store(صحیح);
تهی error(نویسه *);
تهی badpat(نویسه *, نویسه *, نویسه *);
صحیح match(تهی);


/*** Display a file name *******************************/
تهی file(نویسه *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
تهی cant(نویسه *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
تهی help(نویسه **hp)
{
   نویسه   **dp;

   برای (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
تهی usage(نویسه *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
تهی compile(نویسه *source)
{
   نویسه  *s;         /* Source string pointer     */
   نویسه  *lp;        /* Last pattern pointer      */
   صحیح   c;          /* Current character         */
   صحیح            o;          /* Temp                      */
   نویسه           *spp;       /* Save beginning of pattern */

   s = source;
   اگر (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   وقتی (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      اگر (c == '*' || c == '+' || c == '-') {
         اگر (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         وقتی (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ادامه;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      انتخاب(c) {

         حالت '^':
            store(BOL);
            بشکن;

         حالت '$':
            store(EOL);
            بشکن;

         حالت '.':
            store(ANY);
            بشکن;

         حالت '[':
            s = cclass(source, s);
            بشکن;

         حالت ':':
            اگر (*s) {
               انتخاب(tolower(c = *s++)) {

                  حالت 'a':
                  حالت 'A':
                     store(ALPHA);
                     بشکن;

                  حالت 'd':
                  حالت 'D':
                     store(DIGIT);
                     بشکن;

                  حالت 'n':
                  حالت 'N':
                     store(NALPHA);
                     بشکن;

                  حالت ' ':
                     store(PUNCT);
                     بشکن;

                  پیشفرض:
                     badpat("Unknown : type", source, s);

               }
               بشکن;
            }
            وگرنه    badpat("No : type", source, s);

         حالت '\\':
            اگر (*s)
               c = *s++;

         پیشفرض:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   اگر (debug) {
      برای (lp = pbuf; lp < pp;) {
         اگر ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         وگرنه    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
نویسه *cclass(نویسه *source, نویسه *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   نویسه   *s;        /* Source pointer    */
   نویسه   *cp;       /* Pattern start     */
   صحیح    c;         /* Current character */
   صحیح             o;         /* Temp              */

   s = src;
   o = CLASS;
   اگر (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   وقتی ((c = *s++) && c!=']') {
      اگر (c == '\\') {                /* Store quoted char    */
         اگر ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         وگرنه    store(tolower(c));
      }
      وگرنه اگر (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      وگرنه {
         store(tolower(c));      /* Store normal char */
      }
   }
   اگر (c != ']')
      badpat("Unterminated class", source, s);
   اگر ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   اگر (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   بازگشت(s);
}

/*** Store an entry in the pattern buffer **************/
تهی store(صحیح op)
{
   اگر (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
تهی badpat(نویسه *message, نویسه *source, نویسه *stop)
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
تهی grep(FILE *fp, نویسه *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   صحیح lno, شمار_2, m;

   lno = 0;
   شمار_2 = 0;
   وقتی (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      اگر ((m && !vflag) || (!m && vflag)) {
         ++شمار_2;
         اگر (!cflag) {
            اگر (fflag && fn) {
               file(fn);
               fn = 0;
            }
            اگر (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   اگر (cflag) {
      اگر (fflag && fn)
         file(fn);
      printf("%d\n", شمار_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
صحیح match()
{
   نویسه   *l;        /* Line pointer       */

   برای (l = lbuf; *l; ++l) {
      اگر (pmatch(l, pbuf))
         بازگشت(1);
   }
   بازگشت(0);
}

/*** Match partial line with pattern *******************/
نویسه *pmatch(نویسه *سطر, نویسه *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   نویسه   *l;        /* Current line pointer         */
   نویسه   *p;        /* Current pattern pointer      */
   نویسه   c;         /* Current character            */
   نویسه            *e;        /* End for STAR and PLUS match  */
   صحیح             op;        /* Pattern operation            */
   صحیح             n;         /* Class counter                */
   نویسه            *are;      /* Start of STAR match          */

   l = سطر;
   اگر (debug > 1)
      printf("pmatch(\"%s\")\n", سطر);
   p = pattern;
   وقتی ((op = *p++) != ENDPAT) {
      اگر (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-سطر, *l, *l, op);
      انتخاب(op) {

         حالت CHAR:
            اگر (tolower(*l++) != *p++)
               بازگشت(0);
            بشکن;

         حالت BOL:
            اگر (l != lbuf)
               بازگشت(0);
            بشکن;

         حالت EOL:
            اگر (*l != '\0')
               بازگشت(0);
            بشکن;

         حالت ANY:
            اگر (*l++ == '\0')
               بازگشت(0);
            بشکن;

         حالت DIGIT:
            اگر ((c = *l++) < '0' || (c > '9'))
               بازگشت(0);
            بشکن;

         حالت ALPHA:
            c = tolower(*l++);
            اگر (c < 'a' || c > 'z')
               بازگشت(0);
            بشکن;

         حالت NALPHA:
            c = tolower(*l++);
            اگر (c >= 'a' && c <= 'z')
               بشکن;
            وگرنه اگر (c < '0' || c > '9')
               بازگشت(0);
            بشکن;

         حالت PUNCT:
            c = *l++;
            اگر (c == 0 || c > ' ')
               بازگشت(0);
            بشکن;

         حالت CLASS:
         حالت NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            انجامبده {
               اگر (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  اگر (c >= p[-2] && c <= p[-1])
                     بشکن;
               }
               وگرنه اگر (c == *p++)
                  بشکن;
            } وقتی (--n > 1);
            اگر ((op == CLASS) == (n <= 1))
               بازگشت(0);
            اگر (op == CLASS)
               p += n - 2;
            بشکن;

         حالت MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            وقتی (*p++ != ENDPAT); /* Skip over pattern   */
            اگر (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            بشکن;                  /* Always succeeds     */

         حالت PLUS:                 /* One or more ...     */
            اگر ((l = pmatch(l, p)) == 0)
               بازگشت(0);           /* Gotta have a match  */
         حالت STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            وقتی (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            وقتی (*p++ != ENDPAT); /* Skip over pattern   */
            وقتی (l > are) {       /* Try to match rest   */
               اگر (e = pmatch(l, p))
                  بازگشت(e);
               --l;                 /* Nope, try earlier   */
            }
            اگر (e = pmatch(l, p))
               بازگشت(e);
            بازگشت(0);              /* Nothing else worked */

         پیشفرض:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   بازگشت(l);
}

/*** Report an error ***********************************/
تهی error(نویسه *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
صحیح اصلی(صحیح argc, نویسه **argv)
{
   نویسه   *p;
   صحیح    c, i;
   صحیح             gotpattern;

   FILE            *f;

   اگر (argc <= 1)
      usage("No arguments");
   اگر (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      بازگشت 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   برای (i=1; i < argc; ++i) {
      p = argv[i];
      اگر (*p == '-') {
         ++p;
         وقتی (c = *p++) {
            انتخاب(tolower(c)) {

               حالت '?':
                  help(documentation);
                  بشکن;

               حالت 'C':
               حالت 'c':
                  ++cflag;
                  بشکن;

               حالت 'D':
               حالت 'd':
                  ++debug;
                  بشکن;

               حالت 'F':
               حالت 'f':
                  ++fflag;
                  بشکن;

               حالت 'n':
               حالت 'N':
                  ++nflag;
                  بشکن;

               حالت 'v':
               حالت 'V':
                  ++vflag;
                  بشکن;

               پیشفرض:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } وگرنه اگر (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   اگر (!gotpattern)
      usage("No pattern");
   اگر (nfile == 0)
      grep(stdin, 0);
   وگرنه {
      fflag = fflag ^ (nfile > 0);
      برای (i=1; i < argc; ++i) {
         اگر (p = argv[i]) {
            اگر ((f=fopen(p, "r")) == پوچ)
               cant(p);
            وگرنه {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

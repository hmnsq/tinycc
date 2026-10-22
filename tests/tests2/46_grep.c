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
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

वर्ण    *documentation[] = {
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

वर्ण    *patdoc[] = {
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

पूर्णाङ्क cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

वर्ण *pp, lbuf[LMAX], pbuf[PMAX];

वर्ण *cclass();
वर्ण *pmatch();
शून्य store(पूर्णाङ्क);
शून्य error(वर्ण *);
शून्य badpat(वर्ण *, वर्ण *, वर्ण *);
पूर्णाङ्क match(शून्य);


/*** Display a file name *******************************/
शून्य file(वर्ण *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
शून्य cant(वर्ण *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
शून्य help(वर्ण **hp)
{
   वर्ण   **dp;

   अत्थाय (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
शून्य usage(वर्ण *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
शून्य compile(वर्ण *source)
{
   वर्ण  *s;         /* Source string pointer     */
   वर्ण  *lp;        /* Last pattern pointer      */
   पूर्णाङ्क   c;          /* Current character         */
   पूर्णाङ्क            o;          /* Temp                      */
   वर्ण           *spp;       /* Save beginning of pattern */

   s = source;
   सचे (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   याव (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      सचे (c == '*' || c == '+' || c == '-') {
         सचे (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         याव (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         अनुवर्त;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      विकल्प(c) {

         पक्ष '^':
            store(BOL);
            भङ्ग;

         पक्ष '$':
            store(EOL);
            भङ्ग;

         पक्ष '.':
            store(ANY);
            भङ्ग;

         पक्ष '[':
            s = cclass(source, s);
            भङ्ग;

         पक्ष ':':
            सचे (*s) {
               विकल्प(tolower(c = *s++)) {

                  पक्ष 'a':
                  पक्ष 'A':
                     store(ALPHA);
                     भङ्ग;

                  पक्ष 'd':
                  पक्ष 'D':
                     store(DIGIT);
                     भङ्ग;

                  पक्ष 'n':
                  पक्ष 'N':
                     store(NALPHA);
                     भङ्ग;

                  पक्ष ' ':
                     store(PUNCT);
                     भङ्ग;

                  स्वभाव:
                     badpat("Unknown : type", source, s);

               }
               भङ्ग;
            }
            अञ्ञथा    badpat("No : type", source, s);

         पक्ष '\\':
            सचे (*s)
               c = *s++;

         स्वभाव:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   सचे (debug) {
      अत्थाय (lp = pbuf; lp < pp;) {
         सचे ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         अञ्ञथा    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
वर्ण *cclass(वर्ण *source, वर्ण *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   वर्ण   *s;        /* Source pointer    */
   वर्ण   *cp;       /* Pattern start     */
   पूर्णाङ्क    c;         /* Current character */
   पूर्णाङ्क             o;         /* Temp              */

   s = src;
   o = CLASS;
   सचे (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   याव ((c = *s++) && c!=']') {
      सचे (c == '\\') {                /* Store quoted char    */
         सचे ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         अञ्ञथा    store(tolower(c));
      }
      अञ्ञथा सचे (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      अञ्ञथा {
         store(tolower(c));      /* Store normal char */
      }
   }
   सचे (c != ']')
      badpat("Unterminated class", source, s);
   सचे ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   सचे (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   पटिनिवत्त(s);
}

/*** Store an entry in the pattern buffer **************/
शून्य store(पूर्णाङ्क op)
{
   सचे (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
शून्य badpat(वर्ण *message, वर्ण *source, वर्ण *stop)
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
शून्य grep(FILE *fp, वर्ण *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   पूर्णाङ्क lno, गणनम्_2, m;

   lno = 0;
   गणनम्_2 = 0;
   याव (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      सचे ((m && !vflag) || (!m && vflag)) {
         ++गणनम्_2;
         सचे (!cflag) {
            सचे (fflag && fn) {
               file(fn);
               fn = 0;
            }
            सचे (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   सचे (cflag) {
      सचे (fflag && fn)
         file(fn);
      printf("%d\n", गणनम्_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
पूर्णाङ्क match()
{
   वर्ण   *l;        /* Line pointer       */

   अत्थाय (l = lbuf; *l; ++l) {
      सचे (pmatch(l, pbuf))
         पटिनिवत्त(1);
   }
   पटिनिवत्त(0);
}

/*** Match partial line with pattern *******************/
वर्ण *pmatch(वर्ण *पङ्क्तिः, वर्ण *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   वर्ण   *l;        /* Current line pointer         */
   वर्ण   *p;        /* Current pattern pointer      */
   वर्ण   c;         /* Current character            */
   वर्ण            *e;        /* End for STAR and PLUS match  */
   पूर्णाङ्क             op;        /* Pattern operation            */
   पूर्णाङ्क             n;         /* Class counter                */
   वर्ण            *are;      /* Start of STAR match          */

   l = पङ्क्तिः;
   सचे (debug > 1)
      printf("pmatch(\"%s\")\n", पङ्क्तिः);
   p = pattern;
   याव ((op = *p++) != ENDPAT) {
      सचे (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-पङ्क्तिः, *l, *l, op);
      विकल्प(op) {

         पक्ष CHAR:
            सचे (tolower(*l++) != *p++)
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष BOL:
            सचे (l != lbuf)
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष EOL:
            सचे (*l != '\0')
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष ANY:
            सचे (*l++ == '\0')
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष DIGIT:
            सचे ((c = *l++) < '0' || (c > '9'))
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष ALPHA:
            c = tolower(*l++);
            सचे (c < 'a' || c > 'z')
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष NALPHA:
            c = tolower(*l++);
            सचे (c >= 'a' && c <= 'z')
               भङ्ग;
            अञ्ञथा सचे (c < '0' || c > '9')
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष PUNCT:
            c = *l++;
            सचे (c == 0 || c > ' ')
               पटिनिवत्त(0);
            भङ्ग;

         पक्ष CLASS:
         पक्ष NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            करोहि {
               सचे (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  सचे (c >= p[-2] && c <= p[-1])
                     भङ्ग;
               }
               अञ्ञथा सचे (c == *p++)
                  भङ्ग;
            } याव (--n > 1);
            सचे ((op == CLASS) == (n <= 1))
               पटिनिवत्त(0);
            सचे (op == CLASS)
               p += n - 2;
            भङ्ग;

         पक्ष MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            याव (*p++ != ENDPAT); /* Skip over pattern   */
            सचे (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            भङ्ग;                  /* Always succeeds     */

         पक्ष PLUS:                 /* One or more ...     */
            सचे ((l = pmatch(l, p)) == 0)
               पटिनिवत्त(0);           /* Gotta have a match  */
         पक्ष STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            याव (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            याव (*p++ != ENDPAT); /* Skip over pattern   */
            याव (l > are) {       /* Try to match rest   */
               सचे (e = pmatch(l, p))
                  पटिनिवत्त(e);
               --l;                 /* Nope, try earlier   */
            }
            सचे (e = pmatch(l, p))
               पटिनिवत्त(e);
            पटिनिवत्त(0);              /* Nothing else worked */

         स्वभाव:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   पटिनिवत्त(l);
}

/*** Report an error ***********************************/
शून्य error(वर्ण *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   वर्ण   *p;
   पूर्णाङ्क    c, i;
   पूर्णाङ्क             gotpattern;

   FILE            *f;

   सचे (argc <= 1)
      usage("No arguments");
   सचे (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      पटिनिवत्त 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   अत्थाय (i=1; i < argc; ++i) {
      p = argv[i];
      सचे (*p == '-') {
         ++p;
         याव (c = *p++) {
            विकल्प(tolower(c)) {

               पक्ष '?':
                  help(documentation);
                  भङ्ग;

               पक्ष 'C':
               पक्ष 'c':
                  ++cflag;
                  भङ्ग;

               पक्ष 'D':
               पक्ष 'd':
                  ++debug;
                  भङ्ग;

               पक्ष 'F':
               पक्ष 'f':
                  ++fflag;
                  भङ्ग;

               पक्ष 'n':
               पक्ष 'N':
                  ++nflag;
                  भङ्ग;

               पक्ष 'v':
               पक्ष 'V':
                  ++vflag;
                  भङ्ग;

               स्वभाव:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } अञ्ञथा सचे (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   सचे (!gotpattern)
      usage("No pattern");
   सचे (nfile == 0)
      grep(stdin, 0);
   अञ्ञथा {
      fflag = fflag ^ (nfile > 0);
      अत्थाय (i=1; i < argc; ++i) {
         सचे (p = argv[i]) {
            सचे ((f=fopen(p, "r")) == रिक्त)
               cant(p);
            अञ्ञथा {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

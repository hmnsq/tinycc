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
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

అక్షరం    *documentation[] = {
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

అక్షరం    *patdoc[] = {
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

#నిర్వచించు LMAX    512
#నిర్వచించు PMAX    256

#నిర్వచించు CHAR    1
#నిర్వచించు BOL     2
#నిర్వచించు EOL     3
#నిర్వచించు ANY     4
#నిర్వచించు CLASS   5
#నిర్వచించు NCLASS  6
#నిర్వచించు నక్షత్రం_2    7
#నిర్వచించు PLUS    8
#నిర్వచించు MINUS   9
#నిర్వచించు ALPHA   10
#నిర్వచించు DIGIT   11
#నిర్వచించు NALPHA  12
#నిర్వచించు PUNCT   13
#నిర్వచించు RANGE   14
#నిర్వచించు ENDPAT  15

పూర్ణాంకం cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

అక్షరం *pp, lbuf[LMAX], pbuf[PMAX];

అక్షరం *cclass();
అక్షరం *pmatch();
శూన్య store(పూర్ణాంకం);
శూన్య error(అక్షరం *);
శూన్య badpat(అక్షరం *, అక్షరం *, అక్షరం *);
పూర్ణాంకం సరిపోలిక(శూన్య);


/*** Display a file name *******************************/
శూన్య file(అక్షరం *s)
{
   రాయి("File %s:\n", s);
}

/*** Report unopenable file ****************************/
శూన్య cant(అక్షరం *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
శూన్య help(అక్షరం **hp)
{
   అక్షరం   **dp;

   కొరకు (dp = hp; *dp; ++dp)
      రాయి("%s\n", *dp);
}

/*** Display usage summary *****************************/
శూన్య usage(అక్షరం *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   నిష్క్రమించు(1);
}

/*** Compile the pattern into global pbuf[] ************/
శూన్య compile(అక్షరం *ఆధారం)
{
   అక్షరం  *s;         /* Source string pointer     */
   అక్షరం  *lp;        /* Last pattern pointer      */
   పూర్ణాంకం   c;          /* Current character         */
   పూర్ణాంకం            o;          /*తాత్కాలిక*/
   అక్షరం           *spp;       /* Save beginning of pattern */

   s = ఆధారం;
   ఒకవేళ (debug)
      రాయి("Pattern = \"%s\"\n", s);
   pp = pbuf;
   అయితే (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ఒకవేళ (c == '*' || c == '+' || c == '-') {
         ఒకవేళ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == నక్షత్రం_2 ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", ఆధారం, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         అయితే (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? నక్షత్రం_2 :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         కొనసాగు;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      ఎంపిక(c) {

         స్థితి '^':
            store(BOL);
            ఆపు;

         స్థితి '$':
            store(EOL);
            ఆపు;

         స్థితి '.':
            store(ANY);
            ఆపు;

         స్థితి '[':
            s = cclass(ఆధారం, s);
            ఆపు;

         స్థితి ':':
            ఒకవేళ (*s) {
               ఎంపిక(tolower(c = *s++)) {

                  స్థితి 'a':
                  స్థితి 'A':
                     store(ALPHA);
                     ఆపు;

                  స్థితి 'd':
                  స్థితి 'D':
                     store(DIGIT);
                     ఆపు;

                  స్థితి 'n':
                  స్థితి 'N':
                     store(NALPHA);
                     ఆపు;

                  స్థితి ' ':
                     store(PUNCT);
                     ఆపు;

                  అప్రమేయ:
                     badpat("Unknown : type", ఆధారం, s);

               }
               ఆపు;
            }
            లేకపోతే    badpat("No : type", ఆధారం, s);

         స్థితి '\\':
            ఒకవేళ (*s)
               c = *s++;

         అప్రమేయ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ఒకవేళ (debug) {
      కొరకు (lp = pbuf; lp < pp;) {
         ఒకవేళ ((c = (*lp++ & 0377)) < ' ')
            రాయి("\\%o ", c);
         లేకపోతే    రాయి("%c ", c);
      }
      రాయి("\n");
   }
}

/*** Compile a class (within []) ***********************/
అక్షరం *cclass(అక్షరం *ఆధారం, అక్షరం *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   అక్షరం   *s;        /* Source pointer    */
   అక్షరం   *cp;       /* Pattern start     */
   పూర్ణాంకం    c;         /* Current character */
   పూర్ణాంకం             o;         /* Temp              */

   s = src;
   o = CLASS;
   ఒకవేళ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   అయితే ((c = *s++) && c!=']') {
      ఒకవేళ (c == '\\') {                /* Store quoted char    */
         ఒకవేళ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", ఆధారం, s);
         లేకపోతే    store(tolower(c));
      }
      లేకపోతే ఒకవేళ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      లేకపోతే {
         store(tolower(c));      /* Store normal char */
      }
   }
   ఒకవేళ (c != ']')
      badpat("Unterminated class", ఆధారం, s);
   ఒకవేళ ((c = (pp - cp)) >= 256)
      badpat("Class too large", ఆధారం, s);
   ఒకవేళ (c == 0)
      badpat("Empty class", ఆధారం, s);
   *cp = c;
   తిరిగి(s);
}

/*** Store an entry in the pattern buffer **************/
శూన్య store(పూర్ణాంకం op)
{
   ఒకవేళ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
శూన్య badpat(అక్షరం *సందేశం_2, అక్షరం *ఆధారం, అక్షరం *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", సందేశం_2, ఆధారం);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-ఆధారం, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
శూన్య grep(FILE *fp, అక్షరం *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   పూర్ణాంకం lno, లెక్క_2, m;

   lno = 0;
   లెక్క_2 = 0;
   అయితే (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = సరిపోలిక();
      ఒకవేళ ((m && !vflag) || (!m && vflag)) {
         ++లెక్క_2;
         ఒకవేళ (!cflag) {
            ఒకవేళ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ఒకవేళ (nflag)
               రాయి("%d\t", lno);
            రాయి("%s\n", lbuf);
         }
      }
   }
   ఒకవేళ (cflag) {
      ఒకవేళ (fflag && fn)
         file(fn);
      రాయి("%d\n", లెక్క_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
పూర్ణాంకం సరిపోలిక()
{
   అక్షరం   *l;        /* Line pointer       */

   కొరకు (l = lbuf; *l; ++l) {
      ఒకవేళ (pmatch(l, pbuf))
         తిరిగి(1);
   }
   తిరిగి(0);
}

/*** Match partial line with pattern *******************/
అక్షరం *pmatch(అక్షరం *పంక్తి, అక్షరం *నమూనా)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   అక్షరం   *l;        /* Current line pointer         */
   అక్షరం   *p;        /* Current pattern pointer      */
   అక్షరం   c;         /* Current character            */
   అక్షరం            *e;        /* End for STAR and PLUS match  */
   పూర్ణాంకం             op;        /* Pattern operation            */
   పూర్ణాంకం             n;         /* Class counter                */
   అక్షరం            *are;      /* Start of STAR match          */

   l = పంక్తి;
   ఒకవేళ (debug > 1)
      రాయి("pmatch(\"%s\")\n", పంక్తి);
   p = నమూనా;
   అయితే ((op = *p++) != ENDPAT) {
      ఒకవేళ (debug > 1)
         రాయి("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-పంక్తి, *l, *l, op);
      ఎంపిక(op) {

         స్థితి CHAR:
            ఒకవేళ (tolower(*l++) != *p++)
               తిరిగి(0);
            ఆపు;

         స్థితి BOL:
            ఒకవేళ (l != lbuf)
               తిరిగి(0);
            ఆపు;

         స్థితి EOL:
            ఒకవేళ (*l != '\0')
               తిరిగి(0);
            ఆపు;

         స్థితి ANY:
            ఒకవేళ (*l++ == '\0')
               తిరిగి(0);
            ఆపు;

         స్థితి DIGIT:
            ఒకవేళ ((c = *l++) < '0' || (c > '9'))
               తిరిగి(0);
            ఆపు;

         స్థితి ALPHA:
            c = tolower(*l++);
            ఒకవేళ (c < 'a' || c > 'z')
               తిరిగి(0);
            ఆపు;

         స్థితి NALPHA:
            c = tolower(*l++);
            ఒకవేళ (c >= 'a' && c <= 'z')
               ఆపు;
            లేకపోతే ఒకవేళ (c < '0' || c > '9')
               తిరిగి(0);
            ఆపు;

         స్థితి PUNCT:
            c = *l++;
            ఒకవేళ (c == 0 || c > ' ')
               తిరిగి(0);
            ఆపు;

         స్థితి CLASS:
         స్థితి NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            చేయి {
               ఒకవేళ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ఒకవేళ (c >= p[-2] && c <= p[-1])
                     ఆపు;
               }
               లేకపోతే ఒకవేళ (c == *p++)
                  ఆపు;
            } అయితే (--n > 1);
            ఒకవేళ ((op == CLASS) == (n <= 1))
               తిరిగి(0);
            ఒకవేళ (op == CLASS)
               p += n - 2;
            ఆపు;

         స్థితి MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            అయితే (*p++ != ENDPAT); /* Skip over pattern   */
            ఒకవేళ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ఆపు;                  /* Always succeeds     */

         స్థితి PLUS:                 /* One or more ...     */
            ఒకవేళ ((l = pmatch(l, p)) == 0)
               తిరిగి(0);           /* Gotta have a match  */
         స్థితి నక్షత్రం_2:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            అయితే (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            అయితే (*p++ != ENDPAT); /* Skip over pattern   */
            అయితే (l > are) {       /* Try to match rest   */
               ఒకవేళ (e = pmatch(l, p))
                  తిరిగి(e);
               --l;                 /* Nope, try earlier   */
            }
            ఒకవేళ (e = pmatch(l, p))
               తిరిగి(e);
            తిరిగి(0);              /* Nothing else worked */

         అప్రమేయ:
            రాయి("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   తిరిగి(l);
}

/*** Report an error ***********************************/
శూన్య error(అక్షరం *s)
{
   fprintf(stderr, "%s", s);
   నిష్క్రమించు(1);
}

/*** Main program - parse arguments & grep *************/
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
   అక్షరం   *p;
   పూర్ణాంకం    c, i;
   పూర్ణాంకం             gotpattern;

   FILE            *f;

   ఒకవేళ (argc <= 1)
      usage("No arguments");
   ఒకవేళ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      తిరిగి 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   కొరకు (i=1; i < argc; ++i) {
      p = argv[i];
      ఒకవేళ (*p == '-') {
         ++p;
         అయితే (c = *p++) {
            ఎంపిక(tolower(c)) {

               స్థితి '?':
                  help(documentation);
                  ఆపు;

               స్థితి 'C':
               స్థితి 'c':
                  ++cflag;
                  ఆపు;

               స్థితి 'D':
               స్థితి 'd':
                  ++debug;
                  ఆపు;

               స్థితి 'F':
               స్థితి 'f':
                  ++fflag;
                  ఆపు;

               స్థితి 'n':
               స్థితి 'N':
                  ++nflag;
                  ఆపు;

               స్థితి 'v':
               స్థితి 'V':
                  ++vflag;
                  ఆపు;

               అప్రమేయ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } లేకపోతే ఒకవేళ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ఒకవేళ (!gotpattern)
      usage("No pattern");
   ఒకవేళ (nfile == 0)
      grep(stdin, 0);
   లేకపోతే {
      fflag = fflag ^ (nfile > 0);
      కొరకు (i=1; i < argc; ++i) {
         ఒకవేళ (p = argv[i]) {
            ఒకవేళ ((f=fopen(p, "r")) == ఖాళీ)
               cant(p);
            లేకపోతే {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

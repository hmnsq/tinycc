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
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

અક્ષર    *documentation[] = {
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

અક્ષર    *patdoc[] = {
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

પૂર્ણાંક cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

અક્ષર *pp, lbuf[LMAX], pbuf[PMAX];

અક્ષર *cclass();
અક્ષર *pmatch();
શૂન્ય store(પૂર્ણાંક);
શૂન્ય error(અક્ષર *);
શૂન્ય badpat(અક્ષર *, અક્ષર *, અક્ષર *);
પૂર્ણાંક match(શૂન્ય);


/*** Display a file name *******************************/
શૂન્ય file(અક્ષર *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
શૂન્ય cant(અક્ષર *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
શૂન્ય help(અક્ષર **hp)
{
   અક્ષર   **dp;

   માટે (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
શૂન્ય usage(અક્ષર *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
શૂન્ય compile(અક્ષર *source)
{
   અક્ષર  *s;         /* Source string pointer     */
   અક્ષર  *lp;        /* Last pattern pointer      */
   પૂર્ણાંક   c;          /* Current character         */
   પૂર્ણાંક            o;          /* Temp                      */
   અક્ષર           *spp;       /* Save beginning of pattern */

   s = source;
   જો (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   જ્યારે (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      જો (c == '*' || c == '+' || c == '-') {
         જો (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         જ્યારે (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ચાલુ;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      પસંદગી(c) {

         સ્થિતિ '^':
            store(BOL);
            તોડો;

         સ્થિતિ '$':
            store(EOL);
            તોડો;

         સ્થિતિ '.':
            store(ANY);
            તોડો;

         સ્થિતિ '[':
            s = cclass(source, s);
            તોડો;

         સ્થિતિ ':':
            જો (*s) {
               પસંદગી(tolower(c = *s++)) {

                  સ્થિતિ 'a':
                  સ્થિતિ 'A':
                     store(ALPHA);
                     તોડો;

                  સ્થિતિ 'd':
                  સ્થિતિ 'D':
                     store(DIGIT);
                     તોડો;

                  સ્થિતિ 'n':
                  સ્થિતિ 'N':
                     store(NALPHA);
                     તોડો;

                  સ્થિતિ ' ':
                     store(PUNCT);
                     તોડો;

                  મૂળભૂત:
                     badpat("Unknown : type", source, s);

               }
               તોડો;
            }
            નહીંતર    badpat("No : type", source, s);

         સ્થિતિ '\\':
            જો (*s)
               c = *s++;

         મૂળભૂત:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   જો (debug) {
      માટે (lp = pbuf; lp < pp;) {
         જો ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         નહીંતર    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
અક્ષર *cclass(અક્ષર *source, અક્ષર *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   અક્ષર   *s;        /* Source pointer    */
   અક્ષર   *cp;       /* Pattern start     */
   પૂર્ણાંક    c;         /* Current character */
   પૂર્ણાંક             o;         /* Temp              */

   s = src;
   o = CLASS;
   જો (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   જ્યારે ((c = *s++) && c!=']') {
      જો (c == '\\') {                /* Store quoted char    */
         જો ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         નહીંતર    store(tolower(c));
      }
      નહીંતર જો (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      નહીંતર {
         store(tolower(c));      /* Store normal char */
      }
   }
   જો (c != ']')
      badpat("Unterminated class", source, s);
   જો ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   જો (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   પાછા(s);
}

/*** Store an entry in the pattern buffer **************/
શૂન્ય store(પૂર્ણાંક op)
{
   જો (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
શૂન્ય badpat(અક્ષર *message, અક્ષર *source, અક્ષર *stop)
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
શૂન્ય grep(FILE *fp, અક્ષર *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   પૂર્ણાંક lno, ગણતરી_2, m;

   lno = 0;
   ગણતરી_2 = 0;
   જ્યારે (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      જો ((m && !vflag) || (!m && vflag)) {
         ++ગણતરી_2;
         જો (!cflag) {
            જો (fflag && fn) {
               file(fn);
               fn = 0;
            }
            જો (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   જો (cflag) {
      જો (fflag && fn)
         file(fn);
      printf("%d\n", ગણતરી_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
પૂર્ણાંક match()
{
   અક્ષર   *l;        /* Line pointer       */

   માટે (l = lbuf; *l; ++l) {
      જો (pmatch(l, pbuf))
         પાછા(1);
   }
   પાછા(0);
}

/*** Match partial line with pattern *******************/
અક્ષર *pmatch(અક્ષર *લીટી, અક્ષર *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   અક્ષર   *l;        /* Current line pointer         */
   અક્ષર   *p;        /* Current pattern pointer      */
   અક્ષર   c;         /* Current character            */
   અક્ષર            *e;        /* End for STAR and PLUS match  */
   પૂર્ણાંક             op;        /* Pattern operation            */
   પૂર્ણાંક             n;         /* Class counter                */
   અક્ષર            *are;      /* Start of STAR match          */

   l = લીટી;
   જો (debug > 1)
      printf("pmatch(\"%s\")\n", લીટી);
   p = pattern;
   જ્યારે ((op = *p++) != ENDPAT) {
      જો (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-લીટી, *l, *l, op);
      પસંદગી(op) {

         સ્થિતિ CHAR:
            જો (tolower(*l++) != *p++)
               પાછા(0);
            તોડો;

         સ્થિતિ BOL:
            જો (l != lbuf)
               પાછા(0);
            તોડો;

         સ્થિતિ EOL:
            જો (*l != '\0')
               પાછા(0);
            તોડો;

         સ્થિતિ ANY:
            જો (*l++ == '\0')
               પાછા(0);
            તોડો;

         સ્થિતિ DIGIT:
            જો ((c = *l++) < '0' || (c > '9'))
               પાછા(0);
            તોડો;

         સ્થિતિ ALPHA:
            c = tolower(*l++);
            જો (c < 'a' || c > 'z')
               પાછા(0);
            તોડો;

         સ્થિતિ NALPHA:
            c = tolower(*l++);
            જો (c >= 'a' && c <= 'z')
               તોડો;
            નહીંતર જો (c < '0' || c > '9')
               પાછા(0);
            તોડો;

         સ્થિતિ PUNCT:
            c = *l++;
            જો (c == 0 || c > ' ')
               પાછા(0);
            તોડો;

         સ્થિતિ CLASS:
         સ્થિતિ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            કરો {
               જો (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  જો (c >= p[-2] && c <= p[-1])
                     તોડો;
               }
               નહીંતર જો (c == *p++)
                  તોડો;
            } જ્યારે (--n > 1);
            જો ((op == CLASS) == (n <= 1))
               પાછા(0);
            જો (op == CLASS)
               p += n - 2;
            તોડો;

         સ્થિતિ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            જ્યારે (*p++ != ENDPAT); /* Skip over pattern   */
            જો (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            તોડો;                  /* Always succeeds     */

         સ્થિતિ PLUS:                 /* One or more ...     */
            જો ((l = pmatch(l, p)) == 0)
               પાછા(0);           /* Gotta have a match  */
         સ્થિતિ STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            જ્યારે (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            જ્યારે (*p++ != ENDPAT); /* Skip over pattern   */
            જ્યારે (l > are) {       /* Try to match rest   */
               જો (e = pmatch(l, p))
                  પાછા(e);
               --l;                 /* Nope, try earlier   */
            }
            જો (e = pmatch(l, p))
               પાછા(e);
            પાછા(0);              /* Nothing else worked */

         મૂળભૂત:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   પાછા(l);
}

/*** Report an error ***********************************/
શૂન્ય error(અક્ષર *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
   અક્ષર   *p;
   પૂર્ણાંક    c, i;
   પૂર્ણાંક             gotpattern;

   FILE            *f;

   જો (argc <= 1)
      usage("No arguments");
   જો (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      પાછા 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   માટે (i=1; i < argc; ++i) {
      p = argv[i];
      જો (*p == '-') {
         ++p;
         જ્યારે (c = *p++) {
            પસંદગી(tolower(c)) {

               સ્થિતિ '?':
                  help(documentation);
                  તોડો;

               સ્થિતિ 'C':
               સ્થિતિ 'c':
                  ++cflag;
                  તોડો;

               સ્થિતિ 'D':
               સ્થિતિ 'd':
                  ++debug;
                  તોડો;

               સ્થિતિ 'F':
               સ્થિતિ 'f':
                  ++fflag;
                  તોડો;

               સ્થિતિ 'n':
               સ્થિતિ 'N':
                  ++nflag;
                  તોડો;

               સ્થિતિ 'v':
               સ્થિતિ 'V':
                  ++vflag;
                  તોડો;

               મૂળભૂત:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } નહીંતર જો (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   જો (!gotpattern)
      usage("No pattern");
   જો (nfile == 0)
      grep(stdin, 0);
   નહીંતર {
      fflag = fflag ^ (nfile > 0);
      માટે (i=1; i < argc; ++i) {
         જો (p = argv[i]) {
            જો ((f=fopen(p, "r")) == ખાલી)
               cant(p);
            નહીંતર {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

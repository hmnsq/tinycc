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
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

ಅಕ್ಷರ    *documentation[] = {
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

ಅಕ್ಷರ    *patdoc[] = {
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

#ವ್ಯಾಖ್ಯಾನಿಸು LMAX    512
#ವ್ಯಾಖ್ಯಾನಿಸು PMAX    256

#ವ್ಯಾಖ್ಯಾನಿಸು CHAR    1
#ವ್ಯಾಖ್ಯಾನಿಸು BOL     2
#ವ್ಯಾಖ್ಯಾನಿಸು EOL     3
#ವ್ಯಾಖ್ಯಾನಿಸು ANY     4
#ವ್ಯಾಖ್ಯಾನಿಸು CLASS   5
#ವ್ಯಾಖ್ಯಾನಿಸು NCLASS  6
#ವ್ಯಾಖ್ಯಾನಿಸು ನಕ್ಷತ್ರ_2    7
#ವ್ಯಾಖ್ಯಾನಿಸು PLUS    8
#ವ್ಯಾಖ್ಯಾನಿಸು MINUS   9
#ವ್ಯಾಖ್ಯಾನಿಸು ALPHA   10
#ವ್ಯಾಖ್ಯಾನಿಸು DIGIT   11
#ವ್ಯಾಖ್ಯಾನಿಸು NALPHA  12
#ವ್ಯಾಖ್ಯಾನಿಸು PUNCT   13
#ವ್ಯಾಖ್ಯಾನಿಸು RANGE   14
#ವ್ಯಾಖ್ಯಾನಿಸು ENDPAT  15

ಪೂರ್ಣಾಂಕ cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

ಅಕ್ಷರ *pp, lbuf[LMAX], pbuf[PMAX];

ಅಕ್ಷರ *cclass();
ಅಕ್ಷರ *pmatch();
ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ);
ಶೂನ್ಯ error(ಅಕ್ಷರ *);
ಶೂನ್ಯ badpat(ಅಕ್ಷರ *, ಅಕ್ಷರ *, ಅಕ್ಷರ *);
ಪೂರ್ಣಾಂಕ ಹೊಂದಿಕೆ(ಶೂನ್ಯ);


/*** Display a file name *******************************/
ಶೂನ್ಯ file(ಅಕ್ಷರ *s)
{
   ಬರೆ("File %s:\n", s);
}

/*** Report unopenable file ****************************/
ಶೂನ್ಯ cant(ಅಕ್ಷರ *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
ಶೂನ್ಯ help(ಅಕ್ಷರ **hp)
{
   ಅಕ್ಷರ   **dp;

   ಗಾಗಿ (dp = hp; *dp; ++dp)
      ಬರೆ("%s\n", *dp);
}

/*** Display usage summary *****************************/
ಶೂನ್ಯ usage(ಅಕ್ಷರ *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   ನಿರ್ಗಮಿಸು(1);
}

/*** Compile the pattern into global pbuf[] ************/
ಶೂನ್ಯ compile(ಅಕ್ಷರ *ಮೂಲ)
{
   ಅಕ್ಷರ  *s;         /* Source string pointer     */
   ಅಕ್ಷರ  *lp;        /* Last pattern pointer      */
   ಪೂರ್ಣಾಂಕ   c;          /* Current character         */
   ಪೂರ್ಣಾಂಕ            o;          /*ತಾತ್ಕಾಲಿಕ*/
   ಅಕ್ಷರ           *spp;       /* Save beginning of pattern */

   s = ಮೂಲ;
   ಆದರೆ (debug)
      ಬರೆ("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ಆಗ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ಆದರೆ (c == '*' || c == '+' || c == '-') {
         ಆದರೆ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == ನಕ್ಷತ್ರ_2 ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", ಮೂಲ, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ಆಗ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? ನಕ್ಷತ್ರ_2 :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ಮುಂದುವರಿ;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      ಆಯ್ಕೆ(c) {

         ಸ್ಥಿತಿ '^':
            store(BOL);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ '$':
            store(EOL);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ '.':
            store(ANY);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ '[':
            s = cclass(ಮೂಲ, s);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ ':':
            ಆದರೆ (*s) {
               ಆಯ್ಕೆ(tolower(c = *s++)) {

                  ಸ್ಥಿತಿ 'a':
                  ಸ್ಥಿತಿ 'A':
                     store(ALPHA);
                     ನಿಲ್ಲಿಸು;

                  ಸ್ಥಿತಿ 'd':
                  ಸ್ಥಿತಿ 'D':
                     store(DIGIT);
                     ನಿಲ್ಲಿಸು;

                  ಸ್ಥಿತಿ 'n':
                  ಸ್ಥಿತಿ 'N':
                     store(NALPHA);
                     ನಿಲ್ಲಿಸು;

                  ಸ್ಥಿತಿ ' ':
                     store(PUNCT);
                     ನಿಲ್ಲಿಸು;

                  ಪೂರ್ವನಿಯೋಜಿತ:
                     badpat("Unknown : type", ಮೂಲ, s);

               }
               ನಿಲ್ಲಿಸು;
            }
            ಇಲ್ಲದಿದ್ದರೆ    badpat("No : type", ಮೂಲ, s);

         ಸ್ಥಿತಿ '\\':
            ಆದರೆ (*s)
               c = *s++;

         ಪೂರ್ವನಿಯೋಜಿತ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ಆದರೆ (debug) {
      ಗಾಗಿ (lp = pbuf; lp < pp;) {
         ಆದರೆ ((c = (*lp++ & 0377)) < ' ')
            ಬರೆ("\\%o ", c);
         ಇಲ್ಲದಿದ್ದರೆ    ಬರೆ("%c ", c);
      }
      ಬರೆ("\n");
   }
}

/*** Compile a class (within []) ***********************/
ಅಕ್ಷರ *cclass(ಅಕ್ಷರ *ಮೂಲ, ಅಕ್ಷರ *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   ಅಕ್ಷರ   *s;        /* Source pointer    */
   ಅಕ್ಷರ   *cp;       /* Pattern start     */
   ಪೂರ್ಣಾಂಕ    c;         /* Current character */
   ಪೂರ್ಣಾಂಕ             o;         /* Temp              */

   s = src;
   o = CLASS;
   ಆದರೆ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ಆಗ ((c = *s++) && c!=']') {
      ಆದರೆ (c == '\\') {                /* Store quoted char    */
         ಆದರೆ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", ಮೂಲ, s);
         ಇಲ್ಲದಿದ್ದರೆ    store(tolower(c));
      }
      ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ಇಲ್ಲದಿದ್ದರೆ {
         store(tolower(c));      /* Store normal char */
      }
   }
   ಆದರೆ (c != ']')
      badpat("Unterminated class", ಮೂಲ, s);
   ಆದರೆ ((c = (pp - cp)) >= 256)
      badpat("Class too large", ಮೂಲ, s);
   ಆದರೆ (c == 0)
      badpat("Empty class", ಮೂಲ, s);
   *cp = c;
   ಹಿಂತಿರುಗಿ(s);
}

/*** Store an entry in the pattern buffer **************/
ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ op)
{
   ಆದರೆ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
ಶೂನ್ಯ badpat(ಅಕ್ಷರ *ಸಂದೇಶ_2, ಅಕ್ಷರ *ಮೂಲ, ಅಕ್ಷರ *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", ಸಂದೇಶ_2, ಮೂಲ);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-ಮೂಲ, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
ಶೂನ್ಯ grep(FILE *fp, ಅಕ್ಷರ *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   ಪೂರ್ಣಾಂಕ lno, ಎಣಿಕೆ_3, m;

   lno = 0;
   ಎಣಿಕೆ_3 = 0;
   ಆಗ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = ಹೊಂದಿಕೆ();
      ಆದರೆ ((m && !vflag) || (!m && vflag)) {
         ++ಎಣಿಕೆ_3;
         ಆದರೆ (!cflag) {
            ಆದರೆ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ಆದರೆ (nflag)
               ಬರೆ("%d\t", lno);
            ಬರೆ("%s\n", lbuf);
         }
      }
   }
   ಆದರೆ (cflag) {
      ಆದರೆ (fflag && fn)
         file(fn);
      ಬರೆ("%d\n", ಎಣಿಕೆ_3);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
ಪೂರ್ಣಾಂಕ ಹೊಂದಿಕೆ()
{
   ಅಕ್ಷರ   *l;        /* Line pointer       */

   ಗಾಗಿ (l = lbuf; *l; ++l) {
      ಆದರೆ (pmatch(l, pbuf))
         ಹಿಂತಿರುಗಿ(1);
   }
   ಹಿಂತಿರುಗಿ(0);
}

/*** Match partial line with pattern *******************/
ಅಕ್ಷರ *pmatch(ಅಕ್ಷರ *ಸಾಲು, ಅಕ್ಷರ *ನಮೂನೆ)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   ಅಕ್ಷರ   *l;        /* Current line pointer         */
   ಅಕ್ಷರ   *p;        /* Current pattern pointer      */
   ಅಕ್ಷರ   c;         /* Current character            */
   ಅಕ್ಷರ            *e;        /* End for STAR and PLUS match  */
   ಪೂರ್ಣಾಂಕ             op;        /* Pattern operation            */
   ಪೂರ್ಣಾಂಕ             n;         /* Class counter                */
   ಅಕ್ಷರ            *are;      /* Start of STAR match          */

   l = ಸಾಲು;
   ಆದರೆ (debug > 1)
      ಬರೆ("pmatch(\"%s\")\n", ಸಾಲು);
   p = ನಮೂನೆ;
   ಆಗ ((op = *p++) != ENDPAT) {
      ಆದರೆ (debug > 1)
         ಬರೆ("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-ಸಾಲು, *l, *l, op);
      ಆಯ್ಕೆ(op) {

         ಸ್ಥಿತಿ CHAR:
            ಆದರೆ (tolower(*l++) != *p++)
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ BOL:
            ಆದರೆ (l != lbuf)
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ EOL:
            ಆದರೆ (*l != '\0')
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ ANY:
            ಆದರೆ (*l++ == '\0')
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ DIGIT:
            ಆದರೆ ((c = *l++) < '0' || (c > '9'))
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ ALPHA:
            c = tolower(*l++);
            ಆದರೆ (c < 'a' || c > 'z')
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ NALPHA:
            c = tolower(*l++);
            ಆದರೆ (c >= 'a' && c <= 'z')
               ನಿಲ್ಲಿಸು;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c < '0' || c > '9')
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ PUNCT:
            c = *l++;
            ಆದರೆ (c == 0 || c > ' ')
               ಹಿಂತಿರುಗಿ(0);
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ CLASS:
         ಸ್ಥಿತಿ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            ಮಾಡು {
               ಆದರೆ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ಆದರೆ (c >= p[-2] && c <= p[-1])
                     ನಿಲ್ಲಿಸು;
               }
               ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == *p++)
                  ನಿಲ್ಲಿಸು;
            } ಆಗ (--n > 1);
            ಆದರೆ ((op == CLASS) == (n <= 1))
               ಹಿಂತಿರುಗಿ(0);
            ಆದರೆ (op == CLASS)
               p += n - 2;
            ನಿಲ್ಲಿಸು;

         ಸ್ಥಿತಿ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ಆಗ (*p++ != ENDPAT); /* Skip over pattern   */
            ಆದರೆ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ನಿಲ್ಲಿಸು;                  /* Always succeeds     */

         ಸ್ಥಿತಿ PLUS:                 /* One or more ...     */
            ಆದರೆ ((l = pmatch(l, p)) == 0)
               ಹಿಂತಿರುಗಿ(0);           /* Gotta have a match  */
         ಸ್ಥಿತಿ ನಕ್ಷತ್ರ_2:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ಆಗ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ಆಗ (*p++ != ENDPAT); /* Skip over pattern   */
            ಆಗ (l > are) {       /* Try to match rest   */
               ಆದರೆ (e = pmatch(l, p))
                  ಹಿಂತಿರುಗಿ(e);
               --l;                 /* Nope, try earlier   */
            }
            ಆದರೆ (e = pmatch(l, p))
               ಹಿಂತಿರುಗಿ(e);
            ಹಿಂತಿರುಗಿ(0);              /* Nothing else worked */

         ಪೂರ್ವನಿಯೋಜಿತ:
            ಬರೆ("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ಹಿಂತಿರುಗಿ(l);
}

/*** Report an error ***********************************/
ಶೂನ್ಯ error(ಅಕ್ಷರ *s)
{
   fprintf(stderr, "%s", s);
   ನಿರ್ಗಮಿಸು(1);
}

/*** Main program - parse arguments & grep *************/
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
   ಅಕ್ಷರ   *p;
   ಪೂರ್ಣಾಂಕ    c, i;
   ಪೂರ್ಣಾಂಕ             gotpattern;

   FILE            *f;

   ಆದರೆ (argc <= 1)
      usage("No arguments");
   ಆದರೆ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ಹಿಂತಿರುಗಿ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   ಗಾಗಿ (i=1; i < argc; ++i) {
      p = argv[i];
      ಆದರೆ (*p == '-') {
         ++p;
         ಆಗ (c = *p++) {
            ಆಯ್ಕೆ(tolower(c)) {

               ಸ್ಥಿತಿ '?':
                  help(documentation);
                  ನಿಲ್ಲಿಸು;

               ಸ್ಥಿತಿ 'C':
               ಸ್ಥಿತಿ 'c':
                  ++cflag;
                  ನಿಲ್ಲಿಸು;

               ಸ್ಥಿತಿ 'D':
               ಸ್ಥಿತಿ 'd':
                  ++debug;
                  ನಿಲ್ಲಿಸು;

               ಸ್ಥಿತಿ 'F':
               ಸ್ಥಿತಿ 'f':
                  ++fflag;
                  ನಿಲ್ಲಿಸು;

               ಸ್ಥಿತಿ 'n':
               ಸ್ಥಿತಿ 'N':
                  ++nflag;
                  ನಿಲ್ಲಿಸು;

               ಸ್ಥಿತಿ 'v':
               ಸ್ಥಿತಿ 'V':
                  ++vflag;
                  ನಿಲ್ಲಿಸು;

               ಪೂರ್ವನಿಯೋಜಿತ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ಆದರೆ (!gotpattern)
      usage("No pattern");
   ಆದರೆ (nfile == 0)
      grep(stdin, 0);
   ಇಲ್ಲದಿದ್ದರೆ {
      fflag = fflag ^ (nfile > 0);
      ಗಾಗಿ (i=1; i < argc; ++i) {
         ಆದರೆ (p = argv[i]) {
            ಆದರೆ ((f=fopen(p, "r")) == ಖಾಲಿ)
               cant(p);
            ಇಲ್ಲದಿದ್ದರೆ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

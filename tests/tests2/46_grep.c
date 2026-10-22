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

ವರ್ಣ    *documentation[] = {
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

ವರ್ಣ    *patdoc[] = {
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

ಪೂರ್ಣಾಙ್ಕ cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

ವರ್ಣ *pp, lbuf[LMAX], pbuf[PMAX];

ವರ್ಣ *cclass();
ವರ್ಣ *pmatch();
ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ);
ಶೂನ್ಯ error(ವರ್ಣ *);
ಶೂನ್ಯ badpat(ವರ್ಣ *, ವರ್ಣ *, ವರ್ಣ *);
ಪೂರ್ಣಾಙ್ಕ match(ಶೂನ್ಯ);


/*** Display a file name *******************************/
ಶೂನ್ಯ file(ವರ್ಣ *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
ಶೂನ್ಯ cant(ವರ್ಣ *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
ಶೂನ್ಯ help(ವರ್ಣ **hp)
{
   ವರ್ಣ   **dp;

   ಪ್ರತಿ (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
ಶೂನ್ಯ usage(ವರ್ಣ *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
ಶೂನ್ಯ compile(ವರ್ಣ *source)
{
   ವರ್ಣ  *s;         /* Source string pointer     */
   ವರ್ಣ  *lp;        /* Last pattern pointer      */
   ಪೂರ್ಣಾಙ್ಕ   c;          /* Current character         */
   ಪೂರ್ಣಾಙ್ಕ            o;          /* Temp                      */
   ವರ್ಣ           *spp;       /* Save beginning of pattern */

   s = source;
   ಯದಿ (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ಯಾವತ್ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ಯದಿ (c == '*' || c == '+' || c == '-') {
         ಯದಿ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ಯಾವತ್ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ಅನುವರ್ತ;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      ವಿಕಲ್ಪ(c) {

         ಪಕ್ಷ '^':
            store(BOL);
            ಭಙ್ಗ;

         ಪಕ್ಷ '$':
            store(EOL);
            ಭಙ್ಗ;

         ಪಕ್ಷ '.':
            store(ANY);
            ಭಙ್ಗ;

         ಪಕ್ಷ '[':
            s = cclass(source, s);
            ಭಙ್ಗ;

         ಪಕ್ಷ ':':
            ಯದಿ (*s) {
               ವಿಕಲ್ಪ(tolower(c = *s++)) {

                  ಪಕ್ಷ 'a':
                  ಪಕ್ಷ 'A':
                     store(ALPHA);
                     ಭಙ್ಗ;

                  ಪಕ್ಷ 'd':
                  ಪಕ್ಷ 'D':
                     store(DIGIT);
                     ಭಙ್ಗ;

                  ಪಕ್ಷ 'n':
                  ಪಕ್ಷ 'N':
                     store(NALPHA);
                     ಭಙ್ಗ;

                  ಪಕ್ಷ ' ':
                     store(PUNCT);
                     ಭಙ್ಗ;

                  ಸ್ವಭಾವ:
                     badpat("Unknown : type", source, s);

               }
               ಭಙ್ಗ;
            }
            ಅನ್ಯಥಾ    badpat("No : type", source, s);

         ಪಕ್ಷ '\\':
            ಯದಿ (*s)
               c = *s++;

         ಸ್ವಭಾವ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ಯದಿ (debug) {
      ಪ್ರತಿ (lp = pbuf; lp < pp;) {
         ಯದಿ ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         ಅನ್ಯಥಾ    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
ವರ್ಣ *cclass(ವರ್ಣ *source, ವರ್ಣ *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   ವರ್ಣ   *s;        /* Source pointer    */
   ವರ್ಣ   *cp;       /* Pattern start     */
   ಪೂರ್ಣಾಙ್ಕ    c;         /* Current character */
   ಪೂರ್ಣಾಙ್ಕ             o;         /* Temp              */

   s = src;
   o = CLASS;
   ಯದಿ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ಯಾವತ್ ((c = *s++) && c!=']') {
      ಯದಿ (c == '\\') {                /* Store quoted char    */
         ಯದಿ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         ಅನ್ಯಥಾ    store(tolower(c));
      }
      ಅನ್ಯಥಾ ಯದಿ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ಅನ್ಯಥಾ {
         store(tolower(c));      /* Store normal char */
      }
   }
   ಯದಿ (c != ']')
      badpat("Unterminated class", source, s);
   ಯದಿ ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   ಯದಿ (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   ಪ್ರತ್ಯಾಗಮ(s);
}

/*** Store an entry in the pattern buffer **************/
ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ op)
{
   ಯದಿ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
ಶೂನ್ಯ badpat(ವರ್ಣ *message, ವರ್ಣ *source, ವರ್ಣ *stop)
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
ಶೂನ್ಯ grep(FILE *fp, ವರ್ಣ *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   ಪೂರ್ಣಾಙ್ಕ lno, ಎಣಿಕೆ_2, m;

   lno = 0;
   ಎಣಿಕೆ_2 = 0;
   ಯಾವತ್ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      ಯದಿ ((m && !vflag) || (!m && vflag)) {
         ++ಎಣಿಕೆ_2;
         ಯದಿ (!cflag) {
            ಯದಿ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ಯದಿ (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   ಯದಿ (cflag) {
      ಯದಿ (fflag && fn)
         file(fn);
      printf("%d\n", ಎಣಿಕೆ_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
ಪೂರ್ಣಾಙ್ಕ match()
{
   ವರ್ಣ   *l;        /* Line pointer       */

   ಪ್ರತಿ (l = lbuf; *l; ++l) {
      ಯದಿ (pmatch(l, pbuf))
         ಪ್ರತ್ಯಾಗಮ(1);
   }
   ಪ್ರತ್ಯಾಗಮ(0);
}

/*** Match partial line with pattern *******************/
ವರ್ಣ *pmatch(ವರ್ಣ *ಸಾಲು, ವರ್ಣ *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   ವರ್ಣ   *l;        /* Current line pointer         */
   ವರ್ಣ   *p;        /* Current pattern pointer      */
   ವರ್ಣ   c;         /* Current character            */
   ವರ್ಣ            *e;        /* End for STAR and PLUS match  */
   ಪೂರ್ಣಾಙ್ಕ             op;        /* Pattern operation            */
   ಪೂರ್ಣಾಙ್ಕ             n;         /* Class counter                */
   ವರ್ಣ            *are;      /* Start of STAR match          */

   l = ಸಾಲು;
   ಯದಿ (debug > 1)
      printf("pmatch(\"%s\")\n", ಸಾಲು);
   p = pattern;
   ಯಾವತ್ ((op = *p++) != ENDPAT) {
      ಯದಿ (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-ಸಾಲು, *l, *l, op);
      ವಿಕಲ್ಪ(op) {

         ಪಕ್ಷ CHAR:
            ಯದಿ (tolower(*l++) != *p++)
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ BOL:
            ಯದಿ (l != lbuf)
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ EOL:
            ಯದಿ (*l != '\0')
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ ANY:
            ಯದಿ (*l++ == '\0')
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ DIGIT:
            ಯದಿ ((c = *l++) < '0' || (c > '9'))
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ ALPHA:
            c = tolower(*l++);
            ಯದಿ (c < 'a' || c > 'z')
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ NALPHA:
            c = tolower(*l++);
            ಯದಿ (c >= 'a' && c <= 'z')
               ಭಙ್ಗ;
            ಅನ್ಯಥಾ ಯದಿ (c < '0' || c > '9')
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ PUNCT:
            c = *l++;
            ಯದಿ (c == 0 || c > ' ')
               ಪ್ರತ್ಯಾಗಮ(0);
            ಭಙ್ಗ;

         ಪಕ್ಷ CLASS:
         ಪಕ್ಷ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            ಕುರು {
               ಯದಿ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ಯದಿ (c >= p[-2] && c <= p[-1])
                     ಭಙ್ಗ;
               }
               ಅನ್ಯಥಾ ಯದಿ (c == *p++)
                  ಭಙ್ಗ;
            } ಯಾವತ್ (--n > 1);
            ಯದಿ ((op == CLASS) == (n <= 1))
               ಪ್ರತ್ಯಾಗಮ(0);
            ಯದಿ (op == CLASS)
               p += n - 2;
            ಭಙ್ಗ;

         ಪಕ್ಷ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ಯಾವತ್ (*p++ != ENDPAT); /* Skip over pattern   */
            ಯದಿ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ಭಙ್ಗ;                  /* Always succeeds     */

         ಪಕ್ಷ PLUS:                 /* One or more ...     */
            ಯದಿ ((l = pmatch(l, p)) == 0)
               ಪ್ರತ್ಯಾಗಮ(0);           /* Gotta have a match  */
         ಪಕ್ಷ STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ಯಾವತ್ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ಯಾವತ್ (*p++ != ENDPAT); /* Skip over pattern   */
            ಯಾವತ್ (l > are) {       /* Try to match rest   */
               ಯದಿ (e = pmatch(l, p))
                  ಪ್ರತ್ಯಾಗಮ(e);
               --l;                 /* Nope, try earlier   */
            }
            ಯದಿ (e = pmatch(l, p))
               ಪ್ರತ್ಯಾಗಮ(e);
            ಪ್ರತ್ಯಾಗಮ(0);              /* Nothing else worked */

         ಸ್ವಭಾವ:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ಪ್ರತ್ಯಾಗಮ(l);
}

/*** Report an error ***********************************/
ಶೂನ್ಯ error(ವರ್ಣ *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
   ವರ್ಣ   *p;
   ಪೂರ್ಣಾಙ್ಕ    c, i;
   ಪೂರ್ಣಾಙ್ಕ             gotpattern;

   FILE            *f;

   ಯದಿ (argc <= 1)
      usage("No arguments");
   ಯದಿ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ಪ್ರತ್ಯಾಗಮ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   ಪ್ರತಿ (i=1; i < argc; ++i) {
      p = argv[i];
      ಯದಿ (*p == '-') {
         ++p;
         ಯಾವತ್ (c = *p++) {
            ವಿಕಲ್ಪ(tolower(c)) {

               ಪಕ್ಷ '?':
                  help(documentation);
                  ಭಙ್ಗ;

               ಪಕ್ಷ 'C':
               ಪಕ್ಷ 'c':
                  ++cflag;
                  ಭಙ್ಗ;

               ಪಕ್ಷ 'D':
               ಪಕ್ಷ 'd':
                  ++debug;
                  ಭಙ್ಗ;

               ಪಕ್ಷ 'F':
               ಪಕ್ಷ 'f':
                  ++fflag;
                  ಭಙ್ಗ;

               ಪಕ್ಷ 'n':
               ಪಕ್ಷ 'N':
                  ++nflag;
                  ಭಙ್ಗ;

               ಪಕ್ಷ 'v':
               ಪಕ್ಷ 'V':
                  ++vflag;
                  ಭಙ್ಗ;

               ಸ್ವಭಾವ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } ಅನ್ಯಥಾ ಯದಿ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ಯದಿ (!gotpattern)
      usage("No pattern");
   ಯದಿ (nfile == 0)
      grep(stdin, 0);
   ಅನ್ಯಥಾ {
      fflag = fflag ^ (nfile > 0);
      ಪ್ರತಿ (i=1; i < argc; ++i) {
         ಯದಿ (p = argv[i]) {
            ಯದಿ ((f=fopen(p, "r")) == ರಿಕ್ತ)
               cant(p);
            ಅನ್ಯಥಾ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

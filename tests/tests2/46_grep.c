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
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

ਅੱਖਰ    *documentation[] = {
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

ਅੱਖਰ    *patdoc[] = {
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMAX    512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PMAX    256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR    1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOL     2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EOL     3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANY     4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLASS   5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NCLASS  6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਾਰਾ_2    7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PLUS    8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINUS   9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALPHA   10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIGIT   11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NALPHA  12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PUNCT   13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RANGE   14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENDPAT  15

ਪੂਰਨ cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

ਅੱਖਰ *pp, lbuf[LMAX], pbuf[PMAX];

ਅੱਖਰ *cclass();
ਅੱਖਰ *pmatch();
ਖਾਲੀ store(ਪੂਰਨ);
ਖਾਲੀ error(ਅੱਖਰ *);
ਖਾਲੀ badpat(ਅੱਖਰ *, ਅੱਖਰ *, ਅੱਖਰ *);
ਪੂਰਨ ਮੇਲ(ਖਾਲੀ);


/*** Display a file name *******************************/
ਖਾਲੀ file(ਅੱਖਰ *s)
{
   ਲਿਖੋ("File %s:\n", s);
}

/*** Report unopenable file ****************************/
ਖਾਲੀ cant(ਅੱਖਰ *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
ਖਾਲੀ help(ਅੱਖਰ **hp)
{
   ਅੱਖਰ   **dp;

   ਲਈ (dp = hp; *dp; ++dp)
      ਲਿਖੋ("%s\n", *dp);
}

/*** Display usage summary *****************************/
ਖਾਲੀ usage(ਅੱਖਰ *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   ਬਾਹਰ_ਨਿਕਲੋ(1);
}

/*** Compile the pattern into global pbuf[] ************/
ਖਾਲੀ compile(ਅੱਖਰ *ਸਰੋਤ)
{
   ਅੱਖਰ  *s;         /* Source string pointer     */
   ਅੱਖਰ  *lp;        /* Last pattern pointer      */
   ਪੂਰਨ   c;          /* Current character         */
   ਪੂਰਨ            o;          /*ਆਰਜ਼ੀ*/
   ਅੱਖਰ           *spp;       /* Save beginning of pattern */

   s = ਸਰੋਤ;
   ਜੇ (debug)
      ਲਿਖੋ("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ਜਦੋਂ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      ਜੇ (c == '*' || c == '+' || c == '-') {
         ਜੇ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == ਤਾਰਾ_2 ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", ਸਰੋਤ, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ਜਦੋਂ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? ਤਾਰਾ_2 :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         ਜਾਰੀ;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      ਚੋਣ(c) {

         ਹਾਲਤ '^':
            store(BOL);
            ਰੋਕੋ;

         ਹਾਲਤ '$':
            store(EOL);
            ਰੋਕੋ;

         ਹਾਲਤ '.':
            store(ANY);
            ਰੋਕੋ;

         ਹਾਲਤ '[':
            s = cclass(ਸਰੋਤ, s);
            ਰੋਕੋ;

         ਹਾਲਤ ':':
            ਜੇ (*s) {
               ਚੋਣ(tolower(c = *s++)) {

                  ਹਾਲਤ 'a':
                  ਹਾਲਤ 'A':
                     store(ALPHA);
                     ਰੋਕੋ;

                  ਹਾਲਤ 'd':
                  ਹਾਲਤ 'D':
                     store(DIGIT);
                     ਰੋਕੋ;

                  ਹਾਲਤ 'n':
                  ਹਾਲਤ 'N':
                     store(NALPHA);
                     ਰੋਕੋ;

                  ਹਾਲਤ ' ':
                     store(PUNCT);
                     ਰੋਕੋ;

                  ਮੂਲ:
                     badpat("Unknown : type", ਸਰੋਤ, s);

               }
               ਰੋਕੋ;
            }
            ਨਹੀਂਤਾਂ    badpat("No : type", ਸਰੋਤ, s);

         ਹਾਲਤ '\\':
            ਜੇ (*s)
               c = *s++;

         ਮੂਲ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   ਜੇ (debug) {
      ਲਈ (lp = pbuf; lp < pp;) {
         ਜੇ ((c = (*lp++ & 0377)) < ' ')
            ਲਿਖੋ("\\%o ", c);
         ਨਹੀਂਤਾਂ    ਲਿਖੋ("%c ", c);
      }
      ਲਿਖੋ("\n");
   }
}

/*** Compile a class (within []) ***********************/
ਅੱਖਰ *cclass(ਅੱਖਰ *ਸਰੋਤ, ਅੱਖਰ *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   ਅੱਖਰ   *s;        /* Source pointer    */
   ਅੱਖਰ   *cp;       /* Pattern start     */
   ਪੂਰਨ    c;         /* Current character */
   ਪੂਰਨ             o;         /* Temp              */

   s = src;
   o = CLASS;
   ਜੇ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ਜਦੋਂ ((c = *s++) && c!=']') {
      ਜੇ (c == '\\') {                /* Store quoted char    */
         ਜੇ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", ਸਰੋਤ, s);
         ਨਹੀਂਤਾਂ    store(tolower(c));
      }
      ਨਹੀਂਤਾਂ ਜੇ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ਨਹੀਂਤਾਂ {
         store(tolower(c));      /* Store normal char */
      }
   }
   ਜੇ (c != ']')
      badpat("Unterminated class", ਸਰੋਤ, s);
   ਜੇ ((c = (pp - cp)) >= 256)
      badpat("Class too large", ਸਰੋਤ, s);
   ਜੇ (c == 0)
      badpat("Empty class", ਸਰੋਤ, s);
   *cp = c;
   ਵਾਪਸ(s);
}

/*** Store an entry in the pattern buffer **************/
ਖਾਲੀ store(ਪੂਰਨ op)
{
   ਜੇ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
ਖਾਲੀ badpat(ਅੱਖਰ *ਸੁਨੇਹਾ_2, ਅੱਖਰ *ਸਰੋਤ, ਅੱਖਰ *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", ਸੁਨੇਹਾ_2, ਸਰੋਤ);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-ਸਰੋਤ, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
ਖਾਲੀ grep(FILE *fp, ਅੱਖਰ *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   ਪੂਰਨ lno, ਗਿਣਤੀ_3, m;

   lno = 0;
   ਗਿਣਤੀ_3 = 0;
   ਜਦੋਂ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = ਮੇਲ();
      ਜੇ ((m && !vflag) || (!m && vflag)) {
         ++ਗਿਣਤੀ_3;
         ਜੇ (!cflag) {
            ਜੇ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            ਜੇ (nflag)
               ਲਿਖੋ("%d\t", lno);
            ਲਿਖੋ("%s\n", lbuf);
         }
      }
   }
   ਜੇ (cflag) {
      ਜੇ (fflag && fn)
         file(fn);
      ਲਿਖੋ("%d\n", ਗਿਣਤੀ_3);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
ਪੂਰਨ ਮੇਲ()
{
   ਅੱਖਰ   *l;        /* Line pointer       */

   ਲਈ (l = lbuf; *l; ++l) {
      ਜੇ (pmatch(l, pbuf))
         ਵਾਪਸ(1);
   }
   ਵਾਪਸ(0);
}

/*** Match partial line with pattern *******************/
ਅੱਖਰ *pmatch(ਅੱਖਰ *ਸਤਰ, ਅੱਖਰ *ਨਮੂਨਾ)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   ਅੱਖਰ   *l;        /* Current line pointer         */
   ਅੱਖਰ   *p;        /* Current pattern pointer      */
   ਅੱਖਰ   c;         /* Current character            */
   ਅੱਖਰ            *e;        /* End for STAR and PLUS match  */
   ਪੂਰਨ             op;        /* Pattern operation            */
   ਪੂਰਨ             n;         /* Class counter                */
   ਅੱਖਰ            *are;      /* Start of STAR match          */

   l = ਸਤਰ;
   ਜੇ (debug > 1)
      ਲਿਖੋ("pmatch(\"%s\")\n", ਸਤਰ);
   p = ਨਮੂਨਾ;
   ਜਦੋਂ ((op = *p++) != ENDPAT) {
      ਜੇ (debug > 1)
         ਲਿਖੋ("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-ਸਤਰ, *l, *l, op);
      ਚੋਣ(op) {

         ਹਾਲਤ CHAR:
            ਜੇ (tolower(*l++) != *p++)
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ BOL:
            ਜੇ (l != lbuf)
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ EOL:
            ਜੇ (*l != '\0')
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ ANY:
            ਜੇ (*l++ == '\0')
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ DIGIT:
            ਜੇ ((c = *l++) < '0' || (c > '9'))
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ ALPHA:
            c = tolower(*l++);
            ਜੇ (c < 'a' || c > 'z')
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ NALPHA:
            c = tolower(*l++);
            ਜੇ (c >= 'a' && c <= 'z')
               ਰੋਕੋ;
            ਨਹੀਂਤਾਂ ਜੇ (c < '0' || c > '9')
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ PUNCT:
            c = *l++;
            ਜੇ (c == 0 || c > ' ')
               ਵਾਪਸ(0);
            ਰੋਕੋ;

         ਹਾਲਤ CLASS:
         ਹਾਲਤ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            ਕਰੋ {
               ਜੇ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  ਜੇ (c >= p[-2] && c <= p[-1])
                     ਰੋਕੋ;
               }
               ਨਹੀਂਤਾਂ ਜੇ (c == *p++)
                  ਰੋਕੋ;
            } ਜਦੋਂ (--n > 1);
            ਜੇ ((op == CLASS) == (n <= 1))
               ਵਾਪਸ(0);
            ਜੇ (op == CLASS)
               p += n - 2;
            ਰੋਕੋ;

         ਹਾਲਤ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ਜਦੋਂ (*p++ != ENDPAT); /* Skip over pattern   */
            ਜੇ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            ਰੋਕੋ;                  /* Always succeeds     */

         ਹਾਲਤ PLUS:                 /* One or more ...     */
            ਜੇ ((l = pmatch(l, p)) == 0)
               ਵਾਪਸ(0);           /* Gotta have a match  */
         ਹਾਲਤ ਤਾਰਾ_2:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ਜਦੋਂ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ਜਦੋਂ (*p++ != ENDPAT); /* Skip over pattern   */
            ਜਦੋਂ (l > are) {       /* Try to match rest   */
               ਜੇ (e = pmatch(l, p))
                  ਵਾਪਸ(e);
               --l;                 /* Nope, try earlier   */
            }
            ਜੇ (e = pmatch(l, p))
               ਵਾਪਸ(e);
            ਵਾਪਸ(0);              /* Nothing else worked */

         ਮੂਲ:
            ਲਿਖੋ("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   ਵਾਪਸ(l);
}

/*** Report an error ***********************************/
ਖਾਲੀ error(ਅੱਖਰ *s)
{
   fprintf(stderr, "%s", s);
   ਬਾਹਰ_ਨਿਕਲੋ(1);
}

/*** Main program - parse arguments & grep *************/
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
   ਅੱਖਰ   *p;
   ਪੂਰਨ    c, i;
   ਪੂਰਨ             gotpattern;

   FILE            *f;

   ਜੇ (argc <= 1)
      usage("No arguments");
   ਜੇ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      ਵਾਪਸ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   ਲਈ (i=1; i < argc; ++i) {
      p = argv[i];
      ਜੇ (*p == '-') {
         ++p;
         ਜਦੋਂ (c = *p++) {
            ਚੋਣ(tolower(c)) {

               ਹਾਲਤ '?':
                  help(documentation);
                  ਰੋਕੋ;

               ਹਾਲਤ 'C':
               ਹਾਲਤ 'c':
                  ++cflag;
                  ਰੋਕੋ;

               ਹਾਲਤ 'D':
               ਹਾਲਤ 'd':
                  ++debug;
                  ਰੋਕੋ;

               ਹਾਲਤ 'F':
               ਹਾਲਤ 'f':
                  ++fflag;
                  ਰੋਕੋ;

               ਹਾਲਤ 'n':
               ਹਾਲਤ 'N':
                  ++nflag;
                  ਰੋਕੋ;

               ਹਾਲਤ 'v':
               ਹਾਲਤ 'V':
                  ++vflag;
                  ਰੋਕੋ;

               ਮੂਲ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } ਨਹੀਂਤਾਂ ਜੇ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   ਜੇ (!gotpattern)
      usage("No pattern");
   ਜੇ (nfile == 0)
      grep(stdin, 0);
   ਨਹੀਂਤਾਂ {
      fflag = fflag ^ (nfile > 0);
      ਲਈ (i=1; i < argc; ++i) {
         ਜੇ (p = argv[i]) {
            ਜੇ ((f=fopen(p, "r")) == ਨਿਰਾ)
               cant(p);
            ਨਹੀਂਤਾਂ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

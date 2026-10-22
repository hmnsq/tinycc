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
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

எழுத்து    *documentation[] = {
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

எழுத்து    *patdoc[] = {
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

முழு cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

எழுத்து *pp, lbuf[LMAX], pbuf[PMAX];

எழுத்து *cclass();
எழுத்து *pmatch();
வெறுமை store(முழு);
வெறுமை error(எழுத்து *);
வெறுமை badpat(எழுத்து *, எழுத்து *, எழுத்து *);
முழு match(வெறுமை);


/*** Display a file name *******************************/
வெறுமை file(எழுத்து *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
வெறுமை cant(எழுத்து *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
வெறுமை help(எழுத்து **hp)
{
   எழுத்து   **dp;

   க்கு (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
வெறுமை usage(எழுத்து *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
வெறுமை compile(எழுத்து *source)
{
   எழுத்து  *s;         /* Source string pointer     */
   எழுத்து  *lp;        /* Last pattern pointer      */
   முழு   c;          /* Current character         */
   முழு            o;          /* Temp                      */
   எழுத்து           *spp;       /* Save beginning of pattern */

   s = source;
   எனில் (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   போது (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      எனில் (c == '*' || c == '+' || c == '-') {
         எனில் (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         போது (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         தொடர்;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      தேர்வு(c) {

         நிலை '^':
            store(BOL);
            நிறுத்து;

         நிலை '$':
            store(EOL);
            நிறுத்து;

         நிலை '.':
            store(ANY);
            நிறுத்து;

         நிலை '[':
            s = cclass(source, s);
            நிறுத்து;

         நிலை ':':
            எனில் (*s) {
               தேர்வு(tolower(c = *s++)) {

                  நிலை 'a':
                  நிலை 'A':
                     store(ALPHA);
                     நிறுத்து;

                  நிலை 'd':
                  நிலை 'D':
                     store(DIGIT);
                     நிறுத்து;

                  நிலை 'n':
                  நிலை 'N':
                     store(NALPHA);
                     நிறுத்து;

                  நிலை ' ':
                     store(PUNCT);
                     நிறுத்து;

                  இயல்பு:
                     badpat("Unknown : type", source, s);

               }
               நிறுத்து;
            }
            இல்லையெனில்    badpat("No : type", source, s);

         நிலை '\\':
            எனில் (*s)
               c = *s++;

         இயல்பு:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   எனில் (debug) {
      க்கு (lp = pbuf; lp < pp;) {
         எனில் ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         இல்லையெனில்    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
எழுத்து *cclass(எழுத்து *source, எழுத்து *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   எழுத்து   *s;        /* Source pointer    */
   எழுத்து   *cp;       /* Pattern start     */
   முழு    c;         /* Current character */
   முழு             o;         /* Temp              */

   s = src;
   o = CLASS;
   எனில் (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   போது ((c = *s++) && c!=']') {
      எனில் (c == '\\') {                /* Store quoted char    */
         எனில் ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         இல்லையெனில்    store(tolower(c));
      }
      இல்லையெனில் எனில் (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      இல்லையெனில் {
         store(tolower(c));      /* Store normal char */
      }
   }
   எனில் (c != ']')
      badpat("Unterminated class", source, s);
   எனில் ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   எனில் (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   திரும்பு(s);
}

/*** Store an entry in the pattern buffer **************/
வெறுமை store(முழு op)
{
   எனில் (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
வெறுமை badpat(எழுத்து *message, எழுத்து *source, எழுத்து *stop)
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
வெறுமை grep(FILE *fp, எழுத்து *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   முழு lno, மொத்தம்_2, m;

   lno = 0;
   மொத்தம்_2 = 0;
   போது (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      எனில் ((m && !vflag) || (!m && vflag)) {
         ++மொத்தம்_2;
         எனில் (!cflag) {
            எனில் (fflag && fn) {
               file(fn);
               fn = 0;
            }
            எனில் (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   எனில் (cflag) {
      எனில் (fflag && fn)
         file(fn);
      printf("%d\n", மொத்தம்_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
முழு match()
{
   எழுத்து   *l;        /* Line pointer       */

   க்கு (l = lbuf; *l; ++l) {
      எனில் (pmatch(l, pbuf))
         திரும்பு(1);
   }
   திரும்பு(0);
}

/*** Match partial line with pattern *******************/
எழுத்து *pmatch(எழுத்து *வரி, எழுத்து *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   எழுத்து   *l;        /* Current line pointer         */
   எழுத்து   *p;        /* Current pattern pointer      */
   எழுத்து   c;         /* Current character            */
   எழுத்து            *e;        /* End for STAR and PLUS match  */
   முழு             op;        /* Pattern operation            */
   முழு             n;         /* Class counter                */
   எழுத்து            *are;      /* Start of STAR match          */

   l = வரி;
   எனில் (debug > 1)
      printf("pmatch(\"%s\")\n", வரி);
   p = pattern;
   போது ((op = *p++) != ENDPAT) {
      எனில் (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-வரி, *l, *l, op);
      தேர்வு(op) {

         நிலை CHAR:
            எனில் (tolower(*l++) != *p++)
               திரும்பு(0);
            நிறுத்து;

         நிலை BOL:
            எனில் (l != lbuf)
               திரும்பு(0);
            நிறுத்து;

         நிலை EOL:
            எனில் (*l != '\0')
               திரும்பு(0);
            நிறுத்து;

         நிலை ANY:
            எனில் (*l++ == '\0')
               திரும்பு(0);
            நிறுத்து;

         நிலை DIGIT:
            எனில் ((c = *l++) < '0' || (c > '9'))
               திரும்பு(0);
            நிறுத்து;

         நிலை ALPHA:
            c = tolower(*l++);
            எனில் (c < 'a' || c > 'z')
               திரும்பு(0);
            நிறுத்து;

         நிலை NALPHA:
            c = tolower(*l++);
            எனில் (c >= 'a' && c <= 'z')
               நிறுத்து;
            இல்லையெனில் எனில் (c < '0' || c > '9')
               திரும்பு(0);
            நிறுத்து;

         நிலை PUNCT:
            c = *l++;
            எனில் (c == 0 || c > ' ')
               திரும்பு(0);
            நிறுத்து;

         நிலை CLASS:
         நிலை NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            செய் {
               எனில் (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  எனில் (c >= p[-2] && c <= p[-1])
                     நிறுத்து;
               }
               இல்லையெனில் எனில் (c == *p++)
                  நிறுத்து;
            } போது (--n > 1);
            எனில் ((op == CLASS) == (n <= 1))
               திரும்பு(0);
            எனில் (op == CLASS)
               p += n - 2;
            நிறுத்து;

         நிலை MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            போது (*p++ != ENDPAT); /* Skip over pattern   */
            எனில் (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            நிறுத்து;                  /* Always succeeds     */

         நிலை PLUS:                 /* One or more ...     */
            எனில் ((l = pmatch(l, p)) == 0)
               திரும்பு(0);           /* Gotta have a match  */
         நிலை STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            போது (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            போது (*p++ != ENDPAT); /* Skip over pattern   */
            போது (l > are) {       /* Try to match rest   */
               எனில் (e = pmatch(l, p))
                  திரும்பு(e);
               --l;                 /* Nope, try earlier   */
            }
            எனில் (e = pmatch(l, p))
               திரும்பு(e);
            திரும்பு(0);              /* Nothing else worked */

         இயல்பு:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   திரும்பு(l);
}

/*** Report an error ***********************************/
வெறுமை error(எழுத்து *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
   எழுத்து   *p;
   முழு    c, i;
   முழு             gotpattern;

   FILE            *f;

   எனில் (argc <= 1)
      usage("No arguments");
   எனில் (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      திரும்பு 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   க்கு (i=1; i < argc; ++i) {
      p = argv[i];
      எனில் (*p == '-') {
         ++p;
         போது (c = *p++) {
            தேர்வு(tolower(c)) {

               நிலை '?':
                  help(documentation);
                  நிறுத்து;

               நிலை 'C':
               நிலை 'c':
                  ++cflag;
                  நிறுத்து;

               நிலை 'D':
               நிலை 'd':
                  ++debug;
                  நிறுத்து;

               நிலை 'F':
               நிலை 'f':
                  ++fflag;
                  நிறுத்து;

               நிலை 'n':
               நிலை 'N':
                  ++nflag;
                  நிறுத்து;

               நிலை 'v':
               நிலை 'V':
                  ++vflag;
                  நிறுத்து;

               இயல்பு:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } இல்லையெனில் எனில் (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   எனில் (!gotpattern)
      usage("No pattern");
   எனில் (nfile == 0)
      grep(stdin, 0);
   இல்லையெனில் {
      fflag = fflag ^ (nfile > 0);
      க்கு (i=1; i < argc; ++i) {
         எனில் (p = argv[i]) {
            எனில் ((f=fopen(p, "r")) == வெற்று)
               cant(p);
            இல்லையெனில் {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

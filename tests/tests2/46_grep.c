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

#تعریف_کرو LMAX    512
#تعریف_کرو PMAX    256

#تعریف_کرو CHAR    1
#تعریف_کرو BOL     2
#تعریف_کرو EOL     3
#تعریف_کرو ANY     4
#تعریف_کرو CLASS   5
#تعریف_کرو NCLASS  6
#تعریف_کرو ستارہ_2    7
#تعریف_کرو PLUS    8
#تعریف_کرو MINUS   9
#تعریف_کرو ALPHA   10
#تعریف_کرو DIGIT   11
#تعریف_کرو NALPHA  12
#تعریف_کرو PUNCT   13
#تعریف_کرو RANGE   14
#تعریف_کرو ENDPAT  15

صحیح cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

حرف *pp, lbuf[LMAX], pbuf[PMAX];

حرف *cclass();
حرف *pmatch();
خالی store(صحیح);
خالی error(حرف *);
خالی badpat(حرف *, حرف *, حرف *);
صحیح مطابقت(خالی);


/*** Display a file name *******************************/
خالی file(حرف *s)
{
   لکھو("File %s:\n", s);
}

/*** Report unopenable file ****************************/
خالی cant(حرف *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
خالی help(حرف **hp)
{
   حرف   **dp;

   برائے (dp = hp; *dp; ++dp)
      لکھو("%s\n", *dp);
}

/*** Display usage summary *****************************/
خالی usage(حرف *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   باہر_نکلو(1);
}

/*** Compile the pattern into global pbuf[] ************/
خالی compile(حرف *ماخذ)
{
   حرف  *s;         /* Source string pointer     */
   حرف  *lp;        /* Last pattern pointer      */
   صحیح   c;          /* Current character         */
   صحیح            o;          /*عارضی*/
   حرف           *spp;       /* Save beginning of pattern */

   s = ماخذ;
   اگر (debug)
      لکھو("Pattern = \"%s\"\n", s);
   pp = pbuf;
   جب (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      اگر (c == '*' || c == '+' || c == '-') {
         اگر (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == ستارہ_2 ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", ماخذ, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         جب (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? ستارہ_2 :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         جاری;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      انتخاب(c) {

         حالت '^':
            store(BOL);
            توڑو;

         حالت '$':
            store(EOL);
            توڑو;

         حالت '.':
            store(ANY);
            توڑو;

         حالت '[':
            s = cclass(ماخذ, s);
            توڑو;

         حالت ':':
            اگر (*s) {
               انتخاب(tolower(c = *s++)) {

                  حالت 'a':
                  حالت 'A':
                     store(ALPHA);
                     توڑو;

                  حالت 'd':
                  حالت 'D':
                     store(DIGIT);
                     توڑو;

                  حالت 'n':
                  حالت 'N':
                     store(NALPHA);
                     توڑو;

                  حالت ' ':
                     store(PUNCT);
                     توڑو;

                  طےشدہ:
                     badpat("Unknown : type", ماخذ, s);

               }
               توڑو;
            }
            ورنہ    badpat("No : type", ماخذ, s);

         حالت '\\':
            اگر (*s)
               c = *s++;

         طےشدہ:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   اگر (debug) {
      برائے (lp = pbuf; lp < pp;) {
         اگر ((c = (*lp++ & 0377)) < ' ')
            لکھو("\\%o ", c);
         ورنہ    لکھو("%c ", c);
      }
      لکھو("\n");
   }
}

/*** Compile a class (within []) ***********************/
حرف *cclass(حرف *ماخذ, حرف *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   حرف   *s;        /* Source pointer    */
   حرف   *cp;       /* Pattern start     */
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
   جب ((c = *s++) && c!=']') {
      اگر (c == '\\') {                /* Store quoted char    */
         اگر ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", ماخذ, s);
         ورنہ    store(tolower(c));
      }
      ورنہ اگر (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      ورنہ {
         store(tolower(c));      /* Store normal char */
      }
   }
   اگر (c != ']')
      badpat("Unterminated class", ماخذ, s);
   اگر ((c = (pp - cp)) >= 256)
      badpat("Class too large", ماخذ, s);
   اگر (c == 0)
      badpat("Empty class", ماخذ, s);
   *cp = c;
   واپس(s);
}

/*** Store an entry in the pattern buffer **************/
خالی store(صحیح op)
{
   اگر (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
خالی badpat(حرف *پیغام_2, حرف *ماخذ, حرف *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   fprintf(stderr, "-GREP-E-%s, pattern is\"%s\"\n", پیغام_2, ماخذ);
   fprintf(stderr, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-ماخذ, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
خالی grep(FILE *fp, حرف *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   صحیح lno, گنتی_2, m;

   lno = 0;
   گنتی_2 = 0;
   جب (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = مطابقت();
      اگر ((m && !vflag) || (!m && vflag)) {
         ++گنتی_2;
         اگر (!cflag) {
            اگر (fflag && fn) {
               file(fn);
               fn = 0;
            }
            اگر (nflag)
               لکھو("%d\t", lno);
            لکھو("%s\n", lbuf);
         }
      }
   }
   اگر (cflag) {
      اگر (fflag && fn)
         file(fn);
      لکھو("%d\n", گنتی_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
صحیح مطابقت()
{
   حرف   *l;        /* Line pointer       */

   برائے (l = lbuf; *l; ++l) {
      اگر (pmatch(l, pbuf))
         واپس(1);
   }
   واپس(0);
}

/*** Match partial line with pattern *******************/
حرف *pmatch(حرف *سطر, حرف *نمونہ)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   حرف   *l;        /* Current line pointer         */
   حرف   *p;        /* Current pattern pointer      */
   حرف   c;         /* Current character            */
   حرف            *e;        /* End for STAR and PLUS match  */
   صحیح             op;        /* Pattern operation            */
   صحیح             n;         /* Class counter                */
   حرف            *are;      /* Start of STAR match          */

   l = سطر;
   اگر (debug > 1)
      لکھو("pmatch(\"%s\")\n", سطر);
   p = نمونہ;
   جب ((op = *p++) != ENDPAT) {
      اگر (debug > 1)
         لکھو("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-سطر, *l, *l, op);
      انتخاب(op) {

         حالت CHAR:
            اگر (tolower(*l++) != *p++)
               واپس(0);
            توڑو;

         حالت BOL:
            اگر (l != lbuf)
               واپس(0);
            توڑو;

         حالت EOL:
            اگر (*l != '\0')
               واپس(0);
            توڑو;

         حالت ANY:
            اگر (*l++ == '\0')
               واپس(0);
            توڑو;

         حالت DIGIT:
            اگر ((c = *l++) < '0' || (c > '9'))
               واپس(0);
            توڑو;

         حالت ALPHA:
            c = tolower(*l++);
            اگر (c < 'a' || c > 'z')
               واپس(0);
            توڑو;

         حالت NALPHA:
            c = tolower(*l++);
            اگر (c >= 'a' && c <= 'z')
               توڑو;
            ورنہ اگر (c < '0' || c > '9')
               واپس(0);
            توڑو;

         حالت PUNCT:
            c = *l++;
            اگر (c == 0 || c > ' ')
               واپس(0);
            توڑو;

         حالت CLASS:
         حالت NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            کرو {
               اگر (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  اگر (c >= p[-2] && c <= p[-1])
                     توڑو;
               }
               ورنہ اگر (c == *p++)
                  توڑو;
            } جب (--n > 1);
            اگر ((op == CLASS) == (n <= 1))
               واپس(0);
            اگر (op == CLASS)
               p += n - 2;
            توڑو;

         حالت MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            جب (*p++ != ENDPAT); /* Skip over pattern   */
            اگر (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            توڑو;                  /* Always succeeds     */

         حالت PLUS:                 /* One or more ...     */
            اگر ((l = pmatch(l, p)) == 0)
               واپس(0);           /* Gotta have a match  */
         حالت ستارہ_2:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            جب (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            جب (*p++ != ENDPAT); /* Skip over pattern   */
            جب (l > are) {       /* Try to match rest   */
               اگر (e = pmatch(l, p))
                  واپس(e);
               --l;                 /* Nope, try earlier   */
            }
            اگر (e = pmatch(l, p))
               واپس(e);
            واپس(0);              /* Nothing else worked */

         طےشدہ:
            لکھو("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   واپس(l);
}

/*** Report an error ***********************************/
خالی error(حرف *s)
{
   fprintf(stderr, "%s", s);
   باہر_نکلو(1);
}

/*** Main program - parse arguments & grep *************/
صحیح مین(صحیح argc, حرف **argv)
{
   حرف   *p;
   صحیح    c, i;
   صحیح             gotpattern;

   FILE            *f;

   اگر (argc <= 1)
      usage("No arguments");
   اگر (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      واپس 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   برائے (i=1; i < argc; ++i) {
      p = argv[i];
      اگر (*p == '-') {
         ++p;
         جب (c = *p++) {
            انتخاب(tolower(c)) {

               حالت '?':
                  help(documentation);
                  توڑو;

               حالت 'C':
               حالت 'c':
                  ++cflag;
                  توڑو;

               حالت 'D':
               حالت 'd':
                  ++debug;
                  توڑو;

               حالت 'F':
               حالت 'f':
                  ++fflag;
                  توڑو;

               حالت 'n':
               حالت 'N':
                  ++nflag;
                  توڑو;

               حالت 'v':
               حالت 'V':
                  ++vflag;
                  توڑو;

               طےشدہ:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } ورنہ اگر (!gotpattern) {
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
   ورنہ {
      fflag = fflag ^ (nfile > 0);
      برائے (i=1; i < argc; ++i) {
         اگر (p = argv[i]) {
            اگر ((f=fopen(p, "r")) == تہی)
               cant(p);
            ورنہ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

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
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <ctype.h>	// tolower()

/*
 * grep
 *
 * Runs on the Decus compiler or on vms, On vms, define as:
 *      grep :== "$disk:[account]grep"      (native)
 *      grep :== "$disk:[account]grep grep" (Decus)
 * See below for more information.
 */

അക്ഷരം    *documentation[] = {
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

അക്ഷരം    *patdoc[] = {
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

പൂർണ്ണസംഖ്യ cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

അക്ഷരം *pp, lbuf[LMAX], pbuf[PMAX];

അക്ഷരം *cclass();
അക്ഷരം *pmatch();
ശൂന്യം store(പൂർണ്ണസംഖ്യ);
ശൂന്യം error(അക്ഷരം *);
ശൂന്യം badpat(അക്ഷരം *, അക്ഷരം *, അക്ഷരം *);
പൂർണ്ണസംഖ്യ match(ശൂന്യം);


/*** Display a file name *******************************/
ശൂന്യം file(അക്ഷരം *s)
{
   printf("File %s:\n", s);
}

/*** Report unopenable file ****************************/
ശൂന്യം cant(അക്ഷരം *s)
{
   fprintf(stderr, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
ശൂന്യം help(അക്ഷരം **hp)
{
   അക്ഷരം   **dp;

   വേണ്ടി (dp = hp; *dp; ++dp)
      printf("%s\n", *dp);
}

/*** Display usage summary *****************************/
ശൂന്യം usage(അക്ഷരം *s)
{
   fprintf(stderr, "?GREP-E-%s\n", s);
   fprintf(stderr,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   exit(1);
}

/*** Compile the pattern into global pbuf[] ************/
ശൂന്യം compile(അക്ഷരം *source)
{
   അക്ഷരം  *s;         /* Source string pointer     */
   അക്ഷരം  *lp;        /* Last pattern pointer      */
   പൂർണ്ണസംഖ്യ   c;          /* Current character         */
   പൂർണ്ണസംഖ്യ            o;          /* Temp                      */
   അക്ഷരം           *spp;       /* Save beginning of pattern */

   s = source;
   എങ്കിൽ (debug)
      printf("Pattern = \"%s\"\n", s);
   pp = pbuf;
   ആകുമ്പോൾ (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      എങ്കിൽ (c == '*' || c == '+' || c == '-') {
         എങ്കിൽ (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         ആകുമ്പോൾ (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         തുടരുക;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      തിരഞ്ഞെടുപ്പ്(c) {

         അവസ്ഥ '^':
            store(BOL);
            നിർത്തുക;

         അവസ്ഥ '$':
            store(EOL);
            നിർത്തുക;

         അവസ്ഥ '.':
            store(ANY);
            നിർത്തുക;

         അവസ്ഥ '[':
            s = cclass(source, s);
            നിർത്തുക;

         അവസ്ഥ ':':
            എങ്കിൽ (*s) {
               തിരഞ്ഞെടുപ്പ്(tolower(c = *s++)) {

                  അവസ്ഥ 'a':
                  അവസ്ഥ 'A':
                     store(ALPHA);
                     നിർത്തുക;

                  അവസ്ഥ 'd':
                  അവസ്ഥ 'D':
                     store(DIGIT);
                     നിർത്തുക;

                  അവസ്ഥ 'n':
                  അവസ്ഥ 'N':
                     store(NALPHA);
                     നിർത്തുക;

                  അവസ്ഥ ' ':
                     store(PUNCT);
                     നിർത്തുക;

                  സ്ഥിരസ്ഥിതി:
                     badpat("Unknown : type", source, s);

               }
               നിർത്തുക;
            }
            അല്ലെങ്കിൽ    badpat("No : type", source, s);

         അവസ്ഥ '\\':
            എങ്കിൽ (*s)
               c = *s++;

         സ്ഥിരസ്ഥിതി:
            store(CHAR);
            store(tolower(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   എങ്കിൽ (debug) {
      വേണ്ടി (lp = pbuf; lp < pp;) {
         എങ്കിൽ ((c = (*lp++ & 0377)) < ' ')
            printf("\\%o ", c);
         അല്ലെങ്കിൽ    printf("%c ", c);
      }
      printf("\n");
   }
}

/*** Compile a class (within []) ***********************/
അക്ഷരം *cclass(അക്ഷരം *source, അക്ഷരം *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   അക്ഷരം   *s;        /* Source pointer    */
   അക്ഷരം   *cp;       /* Pattern start     */
   പൂർണ്ണസംഖ്യ    c;         /* Current character */
   പൂർണ്ണസംഖ്യ             o;         /* Temp              */

   s = src;
   o = CLASS;
   എങ്കിൽ (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   ആകുമ്പോൾ ((c = *s++) && c!=']') {
      എങ്കിൽ (c == '\\') {                /* Store quoted char    */
         എങ്കിൽ ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         അല്ലെങ്കിൽ    store(tolower(c));
      }
      അല്ലെങ്കിൽ എങ്കിൽ (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(tolower(c));      /* Store it        */
      }
      അല്ലെങ്കിൽ {
         store(tolower(c));      /* Store normal char */
      }
   }
   എങ്കിൽ (c != ']')
      badpat("Unterminated class", source, s);
   എങ്കിൽ ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   എങ്കിൽ (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   തിരികെ(s);
}

/*** Store an entry in the pattern buffer **************/
ശൂന്യം store(പൂർണ്ണസംഖ്യ op)
{
   എങ്കിൽ (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
ശൂന്യം badpat(അക്ഷരം *message, അക്ഷരം *source, അക്ഷരം *stop)
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
ശൂന്യം grep(FILE *fp, അക്ഷരം *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   പൂർണ്ണസംഖ്യ lno, എണ്ണം_2, m;

   lno = 0;
   എണ്ണം_2 = 0;
   ആകുമ്പോൾ (fgets(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      എങ്കിൽ ((m && !vflag) || (!m && vflag)) {
         ++എണ്ണം_2;
         എങ്കിൽ (!cflag) {
            എങ്കിൽ (fflag && fn) {
               file(fn);
               fn = 0;
            }
            എങ്കിൽ (nflag)
               printf("%d\t", lno);
            printf("%s\n", lbuf);
         }
      }
   }
   എങ്കിൽ (cflag) {
      എങ്കിൽ (fflag && fn)
         file(fn);
      printf("%d\n", എണ്ണം_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
പൂർണ്ണസംഖ്യ match()
{
   അക്ഷരം   *l;        /* Line pointer       */

   വേണ്ടി (l = lbuf; *l; ++l) {
      എങ്കിൽ (pmatch(l, pbuf))
         തിരികെ(1);
   }
   തിരികെ(0);
}

/*** Match partial line with pattern *******************/
അക്ഷരം *pmatch(അക്ഷരം *വരി, അക്ഷരം *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   അക്ഷരം   *l;        /* Current line pointer         */
   അക്ഷരം   *p;        /* Current pattern pointer      */
   അക്ഷരം   c;         /* Current character            */
   അക്ഷരം            *e;        /* End for STAR and PLUS match  */
   പൂർണ്ണസംഖ്യ             op;        /* Pattern operation            */
   പൂർണ്ണസംഖ്യ             n;         /* Class counter                */
   അക്ഷരം            *are;      /* Start of STAR match          */

   l = വരി;
   എങ്കിൽ (debug > 1)
      printf("pmatch(\"%s\")\n", വരി);
   p = pattern;
   ആകുമ്പോൾ ((op = *p++) != ENDPAT) {
      എങ്കിൽ (debug > 1)
         printf("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-വരി, *l, *l, op);
      തിരഞ്ഞെടുപ്പ്(op) {

         അവസ്ഥ CHAR:
            എങ്കിൽ (tolower(*l++) != *p++)
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ BOL:
            എങ്കിൽ (l != lbuf)
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ EOL:
            എങ്കിൽ (*l != '\0')
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ ANY:
            എങ്കിൽ (*l++ == '\0')
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ DIGIT:
            എങ്കിൽ ((c = *l++) < '0' || (c > '9'))
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ ALPHA:
            c = tolower(*l++);
            എങ്കിൽ (c < 'a' || c > 'z')
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ NALPHA:
            c = tolower(*l++);
            എങ്കിൽ (c >= 'a' && c <= 'z')
               നിർത്തുക;
            അല്ലെങ്കിൽ എങ്കിൽ (c < '0' || c > '9')
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ PUNCT:
            c = *l++;
            എങ്കിൽ (c == 0 || c > ' ')
               തിരികെ(0);
            നിർത്തുക;

         അവസ്ഥ CLASS:
         അവസ്ഥ NCLASS:
            c = tolower(*l++);
            n = *p++ & 0377;
            ചെയ്യുക {
               എങ്കിൽ (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  എങ്കിൽ (c >= p[-2] && c <= p[-1])
                     നിർത്തുക;
               }
               അല്ലെങ്കിൽ എങ്കിൽ (c == *p++)
                  നിർത്തുക;
            } ആകുമ്പോൾ (--n > 1);
            എങ്കിൽ ((op == CLASS) == (n <= 1))
               തിരികെ(0);
            എങ്കിൽ (op == CLASS)
               p += n - 2;
            നിർത്തുക;

         അവസ്ഥ MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            ആകുമ്പോൾ (*p++ != ENDPAT); /* Skip over pattern   */
            എങ്കിൽ (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            നിർത്തുക;                  /* Always succeeds     */

         അവസ്ഥ PLUS:                 /* One or more ...     */
            എങ്കിൽ ((l = pmatch(l, p)) == 0)
               തിരികെ(0);           /* Gotta have a match  */
         അവസ്ഥ STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            ആകുമ്പോൾ (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            ആകുമ്പോൾ (*p++ != ENDPAT); /* Skip over pattern   */
            ആകുമ്പോൾ (l > are) {       /* Try to match rest   */
               എങ്കിൽ (e = pmatch(l, p))
                  തിരികെ(e);
               --l;                 /* Nope, try earlier   */
            }
            എങ്കിൽ (e = pmatch(l, p))
               തിരികെ(e);
            തിരികെ(0);              /* Nothing else worked */

         സ്ഥിരസ്ഥിതി:
            printf("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   തിരികെ(l);
}

/*** Report an error ***********************************/
ശൂന്യം error(അക്ഷരം *s)
{
   fprintf(stderr, "%s", s);
   exit(1);
}

/*** Main program - parse arguments & grep *************/
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
   അക്ഷരം   *p;
   പൂർണ്ണസംഖ്യ    c, i;
   പൂർണ്ണസംഖ്യ             gotpattern;

   FILE            *f;

   എങ്കിൽ (argc <= 1)
      usage("No arguments");
   എങ്കിൽ (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      തിരികെ 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   വേണ്ടി (i=1; i < argc; ++i) {
      p = argv[i];
      എങ്കിൽ (*p == '-') {
         ++p;
         ആകുമ്പോൾ (c = *p++) {
            തിരഞ്ഞെടുപ്പ്(tolower(c)) {

               അവസ്ഥ '?':
                  help(documentation);
                  നിർത്തുക;

               അവസ്ഥ 'C':
               അവസ്ഥ 'c':
                  ++cflag;
                  നിർത്തുക;

               അവസ്ഥ 'D':
               അവസ്ഥ 'd':
                  ++debug;
                  നിർത്തുക;

               അവസ്ഥ 'F':
               അവസ്ഥ 'f':
                  ++fflag;
                  നിർത്തുക;

               അവസ്ഥ 'n':
               അവസ്ഥ 'N':
                  ++nflag;
                  നിർത്തുക;

               അവസ്ഥ 'v':
               അവസ്ഥ 'V':
                  ++vflag;
                  നിർത്തുക;

               സ്ഥിരസ്ഥിതി:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } അല്ലെങ്കിൽ എങ്കിൽ (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   എങ്കിൽ (!gotpattern)
      usage("No pattern");
   എങ്കിൽ (nfile == 0)
      grep(stdin, 0);
   അല്ലെങ്കിൽ {
      fflag = fflag ^ (nfile > 0);
      വേണ്ടി (i=1; i < argc; ++i) {
         എങ്കിൽ (p = argv[i]) {
            എങ്കിൽ ((f=fopen(p, "r")) == ശൂന്യ)
               cant(p);
            അല്ലെങ്കിൽ {
               grep(f, p);
               fclose(f);
            }
         }
      }
   }
   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

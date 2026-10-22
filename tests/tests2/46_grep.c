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
   म_लिखो("File %s:\n", s);
}

/*** Report unopenable file ****************************/
शून्य cant(वर्ण *s)
{
   ख_लिखो(मानक_त्रुटि, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
शून्य help(वर्ण **hp)
{
   वर्ण   **dp;

   प्रति (dp = hp; *dp; ++dp)
      म_लिखो("%s\n", *dp);
}

/*** Display usage summary *****************************/
शून्य usage(वर्ण *s)
{
   ख_लिखो(मानक_त्रुटि, "?GREP-E-%s\n", s);
   ख_लिखो(मानक_त्रुटि,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   निकास(1);
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
   यदि (debug)
      म_लिखो("Pattern = \"%s\"\n", s);
   pp = pbuf;
   यावत् (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      यदि (c == '*' || c == '+' || c == '-') {
         यदि (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         यावत् (--pp > lp)       /* Move pattern down    */
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
            यदि (*s) {
               विकल्प(छोटे(c = *s++)) {

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
            अन्यथा    badpat("No : type", source, s);

         पक्ष '\\':
            यदि (*s)
               c = *s++;

         स्वभाव:
            store(CHAR);
            store(छोटे(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   यदि (debug) {
      प्रति (lp = pbuf; lp < pp;) {
         यदि ((c = (*lp++ & 0377)) < ' ')
            म_लिखो("\\%o ", c);
         अन्यथा    म_लिखो("%c ", c);
      }
      म_लिखो("\n");
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
   यदि (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   यावत् ((c = *s++) && c!=']') {
      यदि (c == '\\') {                /* Store quoted char    */
         यदि ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         अन्यथा    store(छोटे(c));
      }
      अन्यथा यदि (c == '-' &&
            (pp - cp) > 1 && *s != ']' && *s != '\0') {
         c = pp[-1];             /* Range start     */
         pp[-1] = RANGE;         /* Range signal    */
         store(c);               /* Re-store start  */
         c = *s++;               /* Get end char and*/
         store(छोटे(c));      /* Store it        */
      }
      अन्यथा {
         store(छोटे(c));      /* Store normal char */
      }
   }
   यदि (c != ']')
      badpat("Unterminated class", source, s);
   यदि ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   यदि (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   प्रत्यागम(s);
}

/*** Store an entry in the pattern buffer **************/
शून्य store(पूर्णाङ्क op)
{
   यदि (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
शून्य badpat(वर्ण *message, वर्ण *source, वर्ण *stop)
   /* char  *message;       // Error message */
   /* char  *source;        // Pattern start */
   /* char  *stop;          // Pattern end   */
{
   ख_लिखो(मानक_त्रुटि, "-GREP-E-%s, pattern is\"%s\"\n", message, source);
   ख_लिखो(मानक_त्रुटि, "-GREP-E-Stopped at byte %ld, '%c'\n",
         stop-source, stop[-1]);
   error("?GREP-E-Bad pattern\n");
}

/*** Scan the file for the pattern in pbuf[] ***********/
शून्य grep(खाता *fp, वर्ण *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   पूर्णाङ्क lno, गिनती_2, m;

   lno = 0;
   गिनती_2 = 0;
   यावत् (ख_माला_लो(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      यदि ((m && !vflag) || (!m && vflag)) {
         ++गिनती_2;
         यदि (!cflag) {
            यदि (fflag && fn) {
               file(fn);
               fn = 0;
            }
            यदि (nflag)
               म_लिखो("%d\t", lno);
            म_लिखो("%s\n", lbuf);
         }
      }
   }
   यदि (cflag) {
      यदि (fflag && fn)
         file(fn);
      म_लिखो("%d\n", गिनती_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
पूर्णाङ्क match()
{
   वर्ण   *l;        /* Line pointer       */

   प्रति (l = lbuf; *l; ++l) {
      यदि (pmatch(l, pbuf))
         प्रत्यागम(1);
   }
   प्रत्यागम(0);
}

/*** Match partial line with pattern *******************/
वर्ण *pmatch(वर्ण *पंक्ति, वर्ण *pattern)
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

   l = पंक्ति;
   यदि (debug > 1)
      म_लिखो("pmatch(\"%s\")\n", पंक्ति);
   p = pattern;
   यावत् ((op = *p++) != ENDPAT) {
      यदि (debug > 1)
         म_लिखो("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-पंक्ति, *l, *l, op);
      विकल्प(op) {

         पक्ष CHAR:
            यदि (छोटे(*l++) != *p++)
               प्रत्यागम(0);
            भङ्ग;

         पक्ष BOL:
            यदि (l != lbuf)
               प्रत्यागम(0);
            भङ्ग;

         पक्ष EOL:
            यदि (*l != '\0')
               प्रत्यागम(0);
            भङ्ग;

         पक्ष ANY:
            यदि (*l++ == '\0')
               प्रत्यागम(0);
            भङ्ग;

         पक्ष DIGIT:
            यदि ((c = *l++) < '0' || (c > '9'))
               प्रत्यागम(0);
            भङ्ग;

         पक्ष ALPHA:
            c = छोटे(*l++);
            यदि (c < 'a' || c > 'z')
               प्रत्यागम(0);
            भङ्ग;

         पक्ष NALPHA:
            c = छोटे(*l++);
            यदि (c >= 'a' && c <= 'z')
               भङ्ग;
            अन्यथा यदि (c < '0' || c > '9')
               प्रत्यागम(0);
            भङ्ग;

         पक्ष PUNCT:
            c = *l++;
            यदि (c == 0 || c > ' ')
               प्रत्यागम(0);
            भङ्ग;

         पक्ष CLASS:
         पक्ष NCLASS:
            c = छोटे(*l++);
            n = *p++ & 0377;
            कुरु {
               यदि (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  यदि (c >= p[-2] && c <= p[-1])
                     भङ्ग;
               }
               अन्यथा यदि (c == *p++)
                  भङ्ग;
            } यावत् (--n > 1);
            यदि ((op == CLASS) == (n <= 1))
               प्रत्यागम(0);
            यदि (op == CLASS)
               p += n - 2;
            भङ्ग;

         पक्ष MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            यावत् (*p++ != ENDPAT); /* Skip over pattern   */
            यदि (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            भङ्ग;                  /* Always succeeds     */

         पक्ष PLUS:                 /* One or more ...     */
            यदि ((l = pmatch(l, p)) == 0)
               प्रत्यागम(0);           /* Gotta have a match  */
         पक्ष STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            यावत् (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            यावत् (*p++ != ENDPAT); /* Skip over pattern   */
            यावत् (l > are) {       /* Try to match rest   */
               यदि (e = pmatch(l, p))
                  प्रत्यागम(e);
               --l;                 /* Nope, try earlier   */
            }
            यदि (e = pmatch(l, p))
               प्रत्यागम(e);
            प्रत्यागम(0);              /* Nothing else worked */

         स्वभाव:
            म_लिखो("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   प्रत्यागम(l);
}

/*** Report an error ***********************************/
शून्य error(वर्ण *s)
{
   ख_लिखो(मानक_त्रुटि, "%s", s);
   निकास(1);
}

/*** Main program - parse arguments & grep *************/
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   वर्ण   *p;
   पूर्णाङ्क    c, i;
   पूर्णाङ्क             gotpattern;

   खाता            *f;

   यदि (argc <= 1)
      usage("No arguments");
   यदि (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      प्रत्यागम 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   प्रति (i=1; i < argc; ++i) {
      p = argv[i];
      यदि (*p == '-') {
         ++p;
         यावत् (c = *p++) {
            विकल्प(छोटे(c)) {

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
      } अन्यथा यदि (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   यदि (!gotpattern)
      usage("No pattern");
   यदि (nfile == 0)
      grep(मानक_निवेश, 0);
   अन्यथा {
      fflag = fflag ^ (nfile > 0);
      प्रति (i=1; i < argc; ++i) {
         यदि (p = argv[i]) {
            यदि ((f=ख_खोलो(p, "r")) == रिक्त)
               cant(p);
            अन्यथा {
               grep(f, p);
               ख_बंद(f);
            }
         }
      }
   }
   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

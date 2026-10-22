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

अक्षर    *documentation[] = {
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

अक्षर    *patdoc[] = {
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

पूर्णांक cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

अक्षर *pp, lbuf[LMAX], pbuf[PMAX];

अक्षर *cclass();
अक्षर *pmatch();
शून्य store(पूर्णांक);
शून्य error(अक्षर *);
शून्य badpat(अक्षर *, अक्षर *, अक्षर *);
पूर्णांक match(शून्य);


/*** Display a file name *******************************/
शून्य file(अक्षर *s)
{
   म_लिखो("File %s:\n", s);
}

/*** Report unopenable file ****************************/
शून्य cant(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
शून्य help(अक्षर **hp)
{
   अक्षर   **dp;

   साठी (dp = hp; *dp; ++dp)
      म_लिखो("%s\n", *dp);
}

/*** Display usage summary *****************************/
शून्य usage(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "?GREP-E-%s\n", s);
   ख_लिखो(मानक_त्रुटि,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   निकास(1);
}

/*** Compile the pattern into global pbuf[] ************/
शून्य compile(अक्षर *source)
{
   अक्षर  *s;         /* Source string pointer     */
   अक्षर  *lp;        /* Last pattern pointer      */
   पूर्णांक   c;          /* Current character         */
   पूर्णांक            o;          /* Temp                      */
   अक्षर           *spp;       /* Save beginning of pattern */

   s = source;
   जर (debug)
      म_लिखो("Pattern = \"%s\"\n", s);
   pp = pbuf;
   पर्यंत (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      जर (c == '*' || c == '+' || c == '-') {
         जर (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         पर्यंत (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         सुरूठेवा;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      निवड(c) {

         स्थिती '^':
            store(BOL);
            थांबा;

         स्थिती '$':
            store(EOL);
            थांबा;

         स्थिती '.':
            store(ANY);
            थांबा;

         स्थिती '[':
            s = cclass(source, s);
            थांबा;

         स्थिती ':':
            जर (*s) {
               निवड(छोटे(c = *s++)) {

                  स्थिती 'a':
                  स्थिती 'A':
                     store(ALPHA);
                     थांबा;

                  स्थिती 'd':
                  स्थिती 'D':
                     store(DIGIT);
                     थांबा;

                  स्थिती 'n':
                  स्थिती 'N':
                     store(NALPHA);
                     थांबा;

                  स्थिती ' ':
                     store(PUNCT);
                     थांबा;

                  पूर्वनिर्धारित:
                     badpat("Unknown : type", source, s);

               }
               थांबा;
            }
            अन्यथा    badpat("No : type", source, s);

         स्थिती '\\':
            जर (*s)
               c = *s++;

         पूर्वनिर्धारित:
            store(CHAR);
            store(छोटे(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   जर (debug) {
      साठी (lp = pbuf; lp < pp;) {
         जर ((c = (*lp++ & 0377)) < ' ')
            म_लिखो("\\%o ", c);
         अन्यथा    म_लिखो("%c ", c);
      }
      म_लिखो("\n");
   }
}

/*** Compile a class (within []) ***********************/
अक्षर *cclass(अक्षर *source, अक्षर *src)
   /* char       *source;   // Pattern start -- for error msg. */
   /* char       *src;      // Class start */
{
   अक्षर   *s;        /* Source pointer    */
   अक्षर   *cp;       /* Pattern start     */
   पूर्णांक    c;         /* Current character */
   पूर्णांक             o;         /* Temp              */

   s = src;
   o = CLASS;
   जर (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   पर्यंत ((c = *s++) && c!=']') {
      जर (c == '\\') {                /* Store quoted char    */
         जर ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         अन्यथा    store(छोटे(c));
      }
      अन्यथा जर (c == '-' &&
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
   जर (c != ']')
      badpat("Unterminated class", source, s);
   जर ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   जर (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   परत(s);
}

/*** Store an entry in the pattern buffer **************/
शून्य store(पूर्णांक op)
{
   जर (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
शून्य badpat(अक्षर *message, अक्षर *source, अक्षर *stop)
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
शून्य grep(खाता *fp, अक्षर *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   पूर्णांक lno, मोजणी_2, m;

   lno = 0;
   मोजणी_2 = 0;
   पर्यंत (ख_माला_लो(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      जर ((m && !vflag) || (!m && vflag)) {
         ++मोजणी_2;
         जर (!cflag) {
            जर (fflag && fn) {
               file(fn);
               fn = 0;
            }
            जर (nflag)
               म_लिखो("%d\t", lno);
            म_लिखो("%s\n", lbuf);
         }
      }
   }
   जर (cflag) {
      जर (fflag && fn)
         file(fn);
      म_लिखो("%d\n", मोजणी_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
पूर्णांक match()
{
   अक्षर   *l;        /* Line pointer       */

   साठी (l = lbuf; *l; ++l) {
      जर (pmatch(l, pbuf))
         परत(1);
   }
   परत(0);
}

/*** Match partial line with pattern *******************/
अक्षर *pmatch(अक्षर *ओळ, अक्षर *pattern)
   /* char               *line;     // (partial) line to match      */
   /* char               *pattern;  // (partial) pattern to match   */
{
   अक्षर   *l;        /* Current line pointer         */
   अक्षर   *p;        /* Current pattern pointer      */
   अक्षर   c;         /* Current character            */
   अक्षर            *e;        /* End for STAR and PLUS match  */
   पूर्णांक             op;        /* Pattern operation            */
   पूर्णांक             n;         /* Class counter                */
   अक्षर            *are;      /* Start of STAR match          */

   l = ओळ;
   जर (debug > 1)
      म_लिखो("pmatch(\"%s\")\n", ओळ);
   p = pattern;
   पर्यंत ((op = *p++) != ENDPAT) {
      जर (debug > 1)
         म_लिखो("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-ओळ, *l, *l, op);
      निवड(op) {

         स्थिती CHAR:
            जर (छोटे(*l++) != *p++)
               परत(0);
            थांबा;

         स्थिती BOL:
            जर (l != lbuf)
               परत(0);
            थांबा;

         स्थिती EOL:
            जर (*l != '\0')
               परत(0);
            थांबा;

         स्थिती ANY:
            जर (*l++ == '\0')
               परत(0);
            थांबा;

         स्थिती DIGIT:
            जर ((c = *l++) < '0' || (c > '9'))
               परत(0);
            थांबा;

         स्थिती ALPHA:
            c = छोटे(*l++);
            जर (c < 'a' || c > 'z')
               परत(0);
            थांबा;

         स्थिती NALPHA:
            c = छोटे(*l++);
            जर (c >= 'a' && c <= 'z')
               थांबा;
            अन्यथा जर (c < '0' || c > '9')
               परत(0);
            थांबा;

         स्थिती PUNCT:
            c = *l++;
            जर (c == 0 || c > ' ')
               परत(0);
            थांबा;

         स्थिती CLASS:
         स्थिती NCLASS:
            c = छोटे(*l++);
            n = *p++ & 0377;
            करा {
               जर (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  जर (c >= p[-2] && c <= p[-1])
                     थांबा;
               }
               अन्यथा जर (c == *p++)
                  थांबा;
            } पर्यंत (--n > 1);
            जर ((op == CLASS) == (n <= 1))
               परत(0);
            जर (op == CLASS)
               p += n - 2;
            थांबा;

         स्थिती MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            पर्यंत (*p++ != ENDPAT); /* Skip over pattern   */
            जर (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            थांबा;                  /* Always succeeds     */

         स्थिती PLUS:                 /* One or more ...     */
            जर ((l = pmatch(l, p)) == 0)
               परत(0);           /* Gotta have a match  */
         स्थिती STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            पर्यंत (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            पर्यंत (*p++ != ENDPAT); /* Skip over pattern   */
            पर्यंत (l > are) {       /* Try to match rest   */
               जर (e = pmatch(l, p))
                  परत(e);
               --l;                 /* Nope, try earlier   */
            }
            जर (e = pmatch(l, p))
               परत(e);
            परत(0);              /* Nothing else worked */

         पूर्वनिर्धारित:
            म_लिखो("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   परत(l);
}

/*** Report an error ***********************************/
शून्य error(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "%s", s);
   निकास(1);
}

/*** Main program - parse arguments & grep *************/
पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
   अक्षर   *p;
   पूर्णांक    c, i;
   पूर्णांक             gotpattern;

   खाता            *f;

   जर (argc <= 1)
      usage("No arguments");
   जर (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      परत 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   साठी (i=1; i < argc; ++i) {
      p = argv[i];
      जर (*p == '-') {
         ++p;
         पर्यंत (c = *p++) {
            निवड(छोटे(c)) {

               स्थिती '?':
                  help(documentation);
                  थांबा;

               स्थिती 'C':
               स्थिती 'c':
                  ++cflag;
                  थांबा;

               स्थिती 'D':
               स्थिती 'd':
                  ++debug;
                  थांबा;

               स्थिती 'F':
               स्थिती 'f':
                  ++fflag;
                  थांबा;

               स्थिती 'n':
               स्थिती 'N':
                  ++nflag;
                  थांबा;

               स्थिती 'v':
               स्थिती 'V':
                  ++vflag;
                  थांबा;

               पूर्वनिर्धारित:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } अन्यथा जर (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   जर (!gotpattern)
      usage("No pattern");
   जर (nfile == 0)
      grep(मानक_निवेश, 0);
   अन्यथा {
      fflag = fflag ^ (nfile > 0);
      साठी (i=1; i < argc; ++i) {
         जर (p = argv[i]) {
            जर ((f=ख_खोलो(p, "r")) == रिक्त)
               cant(p);
            अन्यथा {
               grep(f, p);
               ख_बंद(f);
            }
         }
      }
   }
   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

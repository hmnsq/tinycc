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
#समावेश <stdio.h>
#समावेश <stdlib.h>
#समावेश <ctype.h>	// tolower()

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

#घोषणा LMAX    512
#घोषणा PMAX    256

#घोषणा CHAR    1
#घोषणा BOL     2
#घोषणा EOL     3
#घोषणा ANY     4
#घोषणा CLASS   5
#घोषणा NCLASS  6
#घोषणा STAR    7
#घोषणा PLUS    8
#घोषणा MINUS   9
#घोषणा ALPHA   10
#घोषणा DIGIT   11
#घोषणा NALPHA  12
#घोषणा PUNCT   13
#घोषणा RANGE   14
#घोषणा ENDPAT  15

पूर्णांक cflag=0, fflag=0, nflag=0, vflag=0, nfile=0, debug=0;

अक्षर *pp, lbuf[LMAX], pbuf[PMAX];

अक्षर *cclass();
अक्षर *pmatch();
व्योम store(पूर्णांक);
व्योम error(अक्षर *);
व्योम badpat(अक्षर *, अक्षर *, अक्षर *);
पूर्णांक match(व्योम);


/*** Display a file name *******************************/
व्योम file(अक्षर *s)
{
   म_लिखो("File %s:\n", s);
}

/*** Report unopenable file ****************************/
व्योम cant(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "%s: cannot open\n", s);
}

/*** Give good help ************************************/
व्योम help(अक्षर **hp)
{
   अक्षर   **dp;

   क्रम (dp = hp; *dp; ++dp)
      म_लिखो("%s\n", *dp);
}

/*** Display usage summary *****************************/
व्योम usage(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "?GREP-E-%s\n", s);
   ख_लिखो(मानक_त्रुटि,
         "Usage: grep [-cfnv] pattern [file ...].  grep ? for help\n");
   निकास(1);
}

/*** Compile the pattern into global pbuf[] ************/
व्योम compile(अक्षर *source)
{
   अक्षर  *s;         /* Source string pointer     */
   अक्षर  *lp;        /* Last pattern pointer      */
   पूर्णांक   c;          /* Current character         */
   पूर्णांक            o;          /*अस्थायी*/
   अक्षर           *spp;       /* Save beginning of pattern */

   s = source;
   अगर (debug)
      म_लिखो("Pattern = \"%s\"\n", s);
   pp = pbuf;
   जबतक (c = *s++) {
      /*
       * STAR, PLUS and MINUS are special.
       */
      अगर (c == '*' || c == '+' || c == '-') {
         अगर (pp == pbuf ||
               (o=pp[-1]) == BOL ||
               o == EOL ||
               o == STAR ||
               o == PLUS ||
               o == MINUS)
            badpat("Illegal occurrence op.", source, s);
         store(ENDPAT);
         store(ENDPAT);
         spp = pp;               /* Save pattern end     */
         जबतक (--pp > lp)       /* Move pattern down    */
            *pp = pp[-1];        /* one byte             */
         *pp =   (c == '*') ? STAR :
            (c == '-') ? MINUS : PLUS;
         pp = spp;               /* Restore pattern end  */
         जारी;
      }
      /*
       * All the rest.
       */
      lp = pp;         /* Remember start       */
      चयन(c) {

         हाल '^':
            store(BOL);
            अवरोध;

         हाल '$':
            store(EOL);
            अवरोध;

         हाल '.':
            store(ANY);
            अवरोध;

         हाल '[':
            s = cclass(source, s);
            अवरोध;

         हाल ':':
            अगर (*s) {
               चयन(छोटे(c = *s++)) {

                  हाल 'a':
                  हाल 'A':
                     store(ALPHA);
                     अवरोध;

                  हाल 'd':
                  हाल 'D':
                     store(DIGIT);
                     अवरोध;

                  हाल 'n':
                  हाल 'N':
                     store(NALPHA);
                     अवरोध;

                  हाल ' ':
                     store(PUNCT);
                     अवरोध;

                  शेष:
                     badpat("Unknown : type", source, s);

               }
               अवरोध;
            }
            अन्यथा    badpat("No : type", source, s);

         हाल '\\':
            अगर (*s)
               c = *s++;

         शेष:
            store(CHAR);
            store(छोटे(c));
      }
   }
   store(ENDPAT);
   store(0);                /* Terminate string     */
   अगर (debug) {
      क्रम (lp = pbuf; lp < pp;) {
         अगर ((c = (*lp++ & 0377)) < ' ')
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
   अगर (*s == '^') {
      ++s;
      o = NCLASS;
   }
   store(o);
   cp = pp;
   store(0);                          /* Byte count      */
   जबतक ((c = *s++) && c!=']') {
      अगर (c == '\\') {                /* Store quoted char    */
         अगर ((c = *s++) == '\0')      /* Gotta get something  */
            badpat("Class terminates badly", source, s);
         अन्यथा    store(छोटे(c));
      }
      अन्यथा अगर (c == '-' &&
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
   अगर (c != ']')
      badpat("Unterminated class", source, s);
   अगर ((c = (pp - cp)) >= 256)
      badpat("Class too large", source, s);
   अगर (c == 0)
      badpat("Empty class", source, s);
   *cp = c;
   वापस(s);
}

/*** Store an entry in the pattern buffer **************/
व्योम store(पूर्णांक op)
{
   अगर (pp >= &pbuf[PMAX])
      error("Pattern too complex\n");
   *pp++ = op;
}

/*** Report a bad pattern specification ****************/
व्योम badpat(अक्षर *message, अक्षर *source, अक्षर *stop)
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
व्योम grep(खाता *fp, अक्षर *fn)
   /* FILE       *fp;       // File to process            */
   /* char       *fn;       // File name (for -f option)  */
{
   पूर्णांक lno, गिनती_2, m;

   lno = 0;
   गिनती_2 = 0;
   जबतक (ख_माला_लो(lbuf, LMAX, fp)) {
      ++lno;
      m = match();
      अगर ((m && !vflag) || (!m && vflag)) {
         ++गिनती_2;
         अगर (!cflag) {
            अगर (fflag && fn) {
               file(fn);
               fn = 0;
            }
            अगर (nflag)
               म_लिखो("%d\t", lno);
            म_लिखो("%s\n", lbuf);
         }
      }
   }
   अगर (cflag) {
      अगर (fflag && fn)
         file(fn);
      म_लिखो("%d\n", गिनती_2);
   }
}

/*** Match line (lbuf) with pattern (pbuf) return 1 if match ***/
पूर्णांक match()
{
   अक्षर   *l;        /* Line pointer       */

   क्रम (l = lbuf; *l; ++l) {
      अगर (pmatch(l, pbuf))
         वापस(1);
   }
   वापस(0);
}

/*** Match partial line with pattern *******************/
अक्षर *pmatch(अक्षर *पंक्ति_2, अक्षर *pattern)
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

   l = पंक्ति_2;
   अगर (debug > 1)
      म_लिखो("pmatch(\"%s\")\n", पंक्ति_2);
   p = pattern;
   जबतक ((op = *p++) != ENDPAT) {
      अगर (debug > 1)
         म_लिखो("byte[%ld] = 0%o, '%c', op = 0%o\n",
               l-पंक्ति_2, *l, *l, op);
      चयन(op) {

         हाल CHAR:
            अगर (छोटे(*l++) != *p++)
               वापस(0);
            अवरोध;

         हाल BOL:
            अगर (l != lbuf)
               वापस(0);
            अवरोध;

         हाल EOL:
            अगर (*l != '\0')
               वापस(0);
            अवरोध;

         हाल ANY:
            अगर (*l++ == '\0')
               वापस(0);
            अवरोध;

         हाल DIGIT:
            अगर ((c = *l++) < '0' || (c > '9'))
               वापस(0);
            अवरोध;

         हाल ALPHA:
            c = छोटे(*l++);
            अगर (c < 'a' || c > 'z')
               वापस(0);
            अवरोध;

         हाल NALPHA:
            c = छोटे(*l++);
            अगर (c >= 'a' && c <= 'z')
               अवरोध;
            अन्यथा अगर (c < '0' || c > '9')
               वापस(0);
            अवरोध;

         हाल PUNCT:
            c = *l++;
            अगर (c == 0 || c > ' ')
               वापस(0);
            अवरोध;

         हाल CLASS:
         हाल NCLASS:
            c = छोटे(*l++);
            n = *p++ & 0377;
            करो {
               अगर (*p == RANGE) {
                  p += 3;
                  n -= 2;
                  अगर (c >= p[-2] && c <= p[-1])
                     अवरोध;
               }
               अन्यथा अगर (c == *p++)
                  अवरोध;
            } जबतक (--n > 1);
            अगर ((op == CLASS) == (n <= 1))
               वापस(0);
            अगर (op == CLASS)
               p += n - 2;
            अवरोध;

         हाल MINUS:
            e = pmatch(l, p);       /* Look for a match    */
            जबतक (*p++ != ENDPAT); /* Skip over pattern   */
            अगर (e)                  /* Got a match?        */
               l = e;               /* Yes, update string  */
            अवरोध;                  /* Always succeeds     */

         हाल PLUS:                 /* One or more ...     */
            अगर ((l = pmatch(l, p)) == 0)
               वापस(0);           /* Gotta have a match  */
         हाल STAR:                 /* Zero or more ...    */
            are = l;                /* Remember line start */
            जबतक (*l && (e = pmatch(l, p)))
               l = e;               /* Get longest match   */
            जबतक (*p++ != ENDPAT); /* Skip over pattern   */
            जबतक (l > are) {       /* Try to match rest   */
               अगर (e = pmatch(l, p))
                  वापस(e);
               --l;                 /* Nope, try earlier   */
            }
            अगर (e = pmatch(l, p))
               वापस(e);
            वापस(0);              /* Nothing else worked */

         शेष:
            म_लिखो("Bad op code %d\n", op);
            error("Cannot happen -- match\n");
      }
   }
   वापस(l);
}

/*** Report an error ***********************************/
व्योम error(अक्षर *s)
{
   ख_लिखो(मानक_त्रुटि, "%s", s);
   निकास(1);
}

/*** Main program - parse arguments & grep *************/
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
   अक्षर   *p;
   पूर्णांक    c, i;
   पूर्णांक             gotpattern;

   खाता            *f;

   अगर (argc <= 1)
      usage("No arguments");
   अगर (argc == 2 && argv[1][0] == '?' && argv[1][1] == 0) {
      help(documentation);
      help(patdoc);
      वापस 0;
   }
   nfile = argc-1;
   gotpattern = 0;
   क्रम (i=1; i < argc; ++i) {
      p = argv[i];
      अगर (*p == '-') {
         ++p;
         जबतक (c = *p++) {
            चयन(छोटे(c)) {

               हाल '?':
                  help(documentation);
                  अवरोध;

               हाल 'C':
               हाल 'c':
                  ++cflag;
                  अवरोध;

               हाल 'D':
               हाल 'd':
                  ++debug;
                  अवरोध;

               हाल 'F':
               हाल 'f':
                  ++fflag;
                  अवरोध;

               हाल 'n':
               हाल 'N':
                  ++nflag;
                  अवरोध;

               हाल 'v':
               हाल 'V':
                  ++vflag;
                  अवरोध;

               शेष:
                  usage("Unknown flag");
            }
         }
         argv[i] = 0;
         --nfile;
      } अन्यथा अगर (!gotpattern) {
         compile(p);
         argv[i] = 0;
         ++gotpattern;
         --nfile;
      }
   }
   अगर (!gotpattern)
      usage("No pattern");
   अगर (nfile == 0)
      grep(मानक_निवेश, 0);
   अन्यथा {
      fflag = fflag ^ (nfile > 0);
      क्रम (i=1; i < argc; ++i) {
         अगर (p = argv[i]) {
            अगर ((f=ख_खोलो(p, "r")) == शून्य)
               cant(p);
            अन्यथा {
               grep(f, p);
               ख_बंद(f);
            }
         }
      }
   }
   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

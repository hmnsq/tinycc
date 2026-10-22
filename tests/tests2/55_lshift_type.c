/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#अन्तर्भाव <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (पूर्णांक) आकार((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) करा { CHECK(X,T); CHECK(X,अचिन्हित T); } पर्यंत (0)
#define TEST2(X)                 \
  करा                             \
    {                            \
      TEST1((X),लघु);          \
      TEST1((X),पूर्णांक);            \
      TEST1((X),दीर्घ);           \
      TEST1((X),दीर्घ दीर्घ);      \
    }                            \
  पर्यंत (0)
#define TEST3(X,T) करा { TEST2((T)(X)); TEST2((अचिन्हित T)(X)); } पर्यंत (0)
#define TEST4(X)                 \
  करा                             \
    {                            \
      TEST3((X),लघु);          \
      TEST3((X),पूर्णांक);            \
      TEST3((X),दीर्घ);           \
      TEST3((X),दीर्घ दीर्घ);      \
    }                            \
 पर्यंत (0)

स्थिर पूर्णांक debug, nfailed = 0;

स्थिर शून्य check (स्थिरांक अक्षर *s, पूर्णांक arg1, पूर्णांक shift)
{
  पूर्णांक failed = arg1 != shift;
  जर (debug || failed)
    म_लिखो ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

पूर्णांक main (पूर्णांक argc, अक्षर **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  म_लिखो ("%d test(s) failed\n", nfailed);
  परत nfailed != 0;
}

/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#समावेश <stdio.h>

#घोषणा PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (पूर्णांक) माप((M)+0)
#घोषणा CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#घोषणा TEST1(X,T) करो { CHECK(X,T); CHECK(X,अचिन्हित T); } जबतक (0)
#घोषणा TEST2(X)                 \
  करो                             \
    {                            \
      TEST1((X),लघु);          \
      TEST1((X),पूर्णांक);            \
      TEST1((X),दीर्घ);           \
      TEST1((X),दीर्घ दीर्घ);      \
    }                            \
  जबतक (0)
#घोषणा TEST3(X,T) करो { TEST2((T)(X)); TEST2((अचिन्हित T)(X)); } जबतक (0)
#घोषणा TEST4(X)                 \
  करो                             \
    {                            \
      TEST3((X),लघु);          \
      TEST3((X),पूर्णांक);            \
      TEST3((X),दीर्घ);           \
      TEST3((X),दीर्घ दीर्घ);      \
    }                            \
 जबतक (0)

अटल पूर्णांक debug, nfailed = 0;

अटल व्योम check (स्थिर अक्षर *s, पूर्णांक arg1, पूर्णांक shift)
{
  पूर्णांक failed = arg1 != shift;
  अगर (debug || failed)
    म_लिखो ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

पूर्णांक मुख्य (पूर्णांक argc, अक्षर **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  म_लिखो ("%d test(s) failed\n", nfailed);
  वापस nfailed != 0;
}

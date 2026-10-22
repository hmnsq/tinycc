/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ضمن <stdio.h>

#تعریف_کن PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحيح) حجم((M)+0)
#تعریف_کن CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#تعریف_کن TEST1(X,T) افعل { CHECK(X,T); CHECK(X,بیعلامت T); } طالما (0)
#تعریف_کن TEST2(X)                 \
  افعل                             \
    {                            \
      TEST1((X),کوتاه);          \
      TEST1((X),صحيح);            \
      TEST1((X),دراز);           \
      TEST1((X),دراز دراز);      \
    }                            \
  طالما (0)
#تعریف_کن TEST3(X,T) افعل { TEST2((T)(X)); TEST2((بیعلامت T)(X)); } طالما (0)
#تعریف_کن TEST4(X)                 \
  افعل                             \
    {                            \
      TEST3((X),کوتاه);          \
      TEST3((X),صحيح);            \
      TEST3((X),دراز);           \
      TEST3((X),دراز دراز);      \
    }                            \
 طالما (0)

ساكن صحيح debug, nfailed = 0;

ساكن فراغ check (ثابت حرف *s, صحيح arg1, صحيح لغزش)
{
  صحيح failed = arg1 != لغزش;
  إذا (debug || failed)
    چاپ_کن ("%s %d %d\n", s, arg1, لغزش);
  nfailed += failed;
}

صحيح اصلی (صحيح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  چاپ_کن ("%d test(s) failed\n", nfailed);
  أرجع nfailed != 0;
}

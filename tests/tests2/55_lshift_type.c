/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ضمن <stdio.h>

#تعریف_کرو PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحيح) حجم((M)+0)
#تعریف_کرو CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#تعریف_کرو TEST1(X,T) افعل { CHECK(X,T); CHECK(X,بنانشانی T); } طالما (0)
#تعریف_کرو TEST2(X)                 \
  افعل                             \
    {                            \
      TEST1((X),چھوٹا);          \
      TEST1((X),صحيح);            \
      TEST1((X),لما);           \
      TEST1((X),لما لما);      \
    }                            \
  طالما (0)
#تعریف_کرو TEST3(X,T) افعل { TEST2((T)(X)); TEST2((بنانشانی T)(X)); } طالما (0)
#تعریف_کرو TEST4(X)                 \
  افعل                             \
    {                            \
      TEST3((X),چھوٹا);          \
      TEST3((X),صحيح);            \
      TEST3((X),لما);           \
      TEST3((X),لما لما);      \
    }                            \
 طالما (0)

ساكن صحيح debug, nfailed = 0;

ساكن فراغ check (ثابت حرف *s, صحيح arg1, صحيح کھسکاؤ)
{
  صحيح failed = arg1 != کھسکاؤ;
  إذا (debug || failed)
    لکھو ("%s %d %d\n", s, arg1, کھسکاؤ);
  nfailed += failed;
}

صحيح مکھ (صحيح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  لکھو ("%d test(s) failed\n", nfailed);
  أرجع nfailed != 0;
}

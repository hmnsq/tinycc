/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ضمن <stdio.h>

#تعریف_کړه PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحيح) حجم((M)+0)
#تعریف_کړه CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#تعریف_کړه TEST1(X,T) افعل { CHECK(X,T); CHECK(X,بینښه T); } طالما (0)
#تعریف_کړه TEST2(X)                 \
  افعل                             \
    {                            \
      TEST1((X),لنډ);          \
      TEST1((X),صحيح);            \
      TEST1((X),اوږد);           \
      TEST1((X),اوږد اوږد);      \
    }                            \
  طالما (0)
#تعریف_کړه TEST3(X,T) افعل { TEST2((T)(X)); TEST2((بینښه T)(X)); } طالما (0)
#تعریف_کړه TEST4(X)                 \
  افعل                             \
    {                            \
      TEST3((X),لنډ);          \
      TEST3((X),صحيح);            \
      TEST3((X),اوږد);           \
      TEST3((X),اوږد اوږد);      \
    }                            \
 طالما (0)

ساكن صحيح debug, nfailed = 0;

ساكن فراغ check (ثابت حرف *s, صحيح arg1, صحيح ښويدنه)
{
  صحيح failed = arg1 != ښويدنه;
  إذا (debug || failed)
    چاپ_کړه ("%s %d %d\n", s, arg1, ښويدنه);
  nfailed += failed;
}

صحيح اصلي (صحيح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  چاپ_کړه ("%d test(s) failed\n", nfailed);
  أرجع nfailed != 0;
}

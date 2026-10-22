/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ضمن <stdio.h>

#وصف_ڪريو PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحيح) حجم((M)+0)
#وصف_ڪريو CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#وصف_ڪريو TEST1(X,T) افعل { CHECK(X,T); CHECK(X,بنانشان T); } طالما (0)
#وصف_ڪريو TEST2(X)                 \
  افعل                             \
    {                            \
      TEST1((X),ننڍو);          \
      TEST1((X),صحيح);            \
      TEST1((X),ڊگهو);           \
      TEST1((X),ڊگهو ڊگهو);      \
    }                            \
  طالما (0)
#وصف_ڪريو TEST3(X,T) افعل { TEST2((T)(X)); TEST2((بنانشان T)(X)); } طالما (0)
#وصف_ڪريو TEST4(X)                 \
  افعل                             \
    {                            \
      TEST3((X),ننڍو);          \
      TEST3((X),صحيح);            \
      TEST3((X),ڊگهو);           \
      TEST3((X),ڊگهو ڊگهو);      \
    }                            \
 طالما (0)

ساكن صحيح debug, nfailed = 0;

ساكن فراغ check (ثابت حرف *s, صحيح arg1, صحيح سرڪايو)
{
  صحيح failed = arg1 != سرڪايو;
  إذا (debug || failed)
    لکو ("%s %d %d\n", s, arg1, سرڪايو);
  nfailed += failed;
}

صحيح مکيه (صحيح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  لکو ("%d test(s) failed\n", nfailed);
  أرجع nfailed != 0;
}

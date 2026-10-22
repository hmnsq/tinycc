/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ضمن <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحيح) حجم((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) 𐡏𐡁𐡃 { CHECK(X,T); CHECK(X,unsigned T); } طالما (0)
#define TEST2(X)                 \
  𐡏𐡁𐡃                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),صحيح);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  طالما (0)
#define TEST3(X,T) 𐡏𐡁𐡃 { TEST2((T)(X)); TEST2((unsigned T)(X)); } طالما (0)
#define TEST4(X)                 \
  𐡏𐡁𐡃                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),صحيح);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 طالما (0)

ساكن صحيح debug, nfailed = 0;

ساكن فراغ check (ثابت حرف *s, صحيح arg1, صحيح shift)
{
  صحيح failed = arg1 != shift;
  𐡄𐡍 (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

صحيح main (صحيح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  أرجع nfailed != 0;
}

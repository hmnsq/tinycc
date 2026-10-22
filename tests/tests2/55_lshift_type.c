/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#شامل <stdio.h>

#تعریف_کرو PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحیح) حجم((M)+0)
#تعریف_کرو CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#تعریف_کرو TEST1(X,T) کرو { CHECK(X,T); CHECK(X,غیرعلامتی T); } جب (0)
#تعریف_کرو TEST2(X)                 \
  کرو                             \
    {                            \
      TEST1((X),مختصر);          \
      TEST1((X),صحیح);            \
      TEST1((X),طویل);           \
      TEST1((X),طویل طویل);      \
    }                            \
  جب (0)
#تعریف_کرو TEST3(X,T) کرو { TEST2((T)(X)); TEST2((غیرعلامتی T)(X)); } جب (0)
#تعریف_کرو TEST4(X)                 \
  کرو                             \
    {                            \
      TEST3((X),مختصر);          \
      TEST3((X),صحیح);            \
      TEST3((X),طویل);           \
      TEST3((X),طویل طویل);      \
    }                            \
 جب (0)

ساکن صحیح debug, nfailed = 0;

ساکن خالی check (ثابت حرف *s, صحیح arg1, صحیح سرکاؤ)
{
  صحیح failed = arg1 != سرکاؤ;
  اگر (debug || failed)
    لکھو ("%s %d %d\n", s, arg1, سرکاؤ);
  nfailed += failed;
}

صحیح مین (صحیح argc, حرف **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  لکھو ("%d test(s) failed\n", nfailed);
  واپس nfailed != 0;
}

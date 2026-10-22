/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#شامل <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (صحیح) اندازه((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) انجامبده { CHECK(X,T); CHECK(X,unsigned T); } وقتی (0)
#define TEST2(X)                 \
  انجامبده                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),صحیح);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  وقتی (0)
#define TEST3(X,T) انجامبده { TEST2((T)(X)); TEST2((unsigned T)(X)); } وقتی (0)
#define TEST4(X)                 \
  انجامبده                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),صحیح);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 وقتی (0)

ایستا صحیح debug, nfailed = 0;

ایستا تهی check (ثابت نویسه *s, صحیح arg1, صحیح shift)
{
  صحیح failed = arg1 != shift;
  اگر (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

صحیح اصلی (صحیح argc, نویسه **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  بازگشت nfailed != 0;
}

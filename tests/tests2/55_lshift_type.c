/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#অন্তর্ভাব <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (পূর্ণাঙ্ক) পরিমাণ((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) কুরু { CHECK(X,T); CHECK(X,unsigned T); } যাবত্ (0)
#define TEST2(X)                 \
  কুরু                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),পূর্ণাঙ্ক);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  যাবত্ (0)
#define TEST3(X,T) কুরু { TEST2((T)(X)); TEST2((unsigned T)(X)); } যাবত্ (0)
#define TEST4(X)                 \
  কুরু                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),পূর্ণাঙ্ক);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 যাবত্ (0)

স্থির পূর্ণাঙ্ক debug, nfailed = 0;

স্থির শূন্য check (ধ্রুব বর্ণ *s, পূর্ণাঙ্ক arg1, পূর্ণাঙ্ক shift)
{
  পূর্ণাঙ্ক failed = arg1 != shift;
  যদি (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

পূর্ণাঙ্ক main (পূর্ণাঙ্ক argc, বর্ণ **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  প্রত্যাগম nfailed != 0;
}

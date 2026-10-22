/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#অন্তর্ভাব <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (পূর্ণসংখ্যা) আকার((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) করো { CHECK(X,T); CHECK(X,unsigned T); } যখন (0)
#define TEST2(X)                 \
  করো                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),পূর্ণসংখ্যা);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  যখন (0)
#define TEST3(X,T) করো { TEST2((T)(X)); TEST2((unsigned T)(X)); } যখন (0)
#define TEST4(X)                 \
  করো                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),পূর্ণসংখ্যা);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 যখন (0)

স্থির পূর্ণসংখ্যা debug, nfailed = 0;

স্থির শূন্য check (ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা arg1, পূর্ণসংখ্যা shift)
{
  পূর্ণসংখ্যা failed = arg1 != shift;
  যদি (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

পূর্ণসংখ্যা প্রধান (পূর্ণসংখ্যা argc, অক্ষর **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  ফেরত nfailed != 0;
}

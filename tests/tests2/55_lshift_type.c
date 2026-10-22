/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#include <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ចំនួនគត់) parimaa_na((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) do { CHECK(X,T); CHECK(X,unsigned T); } ខណៈពេល (0)
#define TEST2(X)                 \
  do                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),ចំនួនគត់);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  ខណៈពេល (0)
#define TEST3(X,T) do { TEST2((T)(X)); TEST2((unsigned T)(X)); } ខណៈពេល (0)
#define TEST4(X)                 \
  do                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),ចំនួនគត់);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 ខណៈពេល (0)

static ចំនួនគត់ debug, nfailed = 0;

static void check (const var_na *s, ចំនួនគត់ arg1, ចំនួនគត់ shift)
{
  ចំនួនគត់ failed = arg1 != shift;
  ប្រសិនបើ (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

ចំនួនគត់ main (ចំនួនគត់ argc, var_na **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  ត្រឡប់ nfailed != 0;
}

/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#include <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ціле) sizeof((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) do { CHECK(X,T); CHECK(X,unsigned T); } поки (0)
#define TEST2(X)                 \
  do                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),ціле);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  поки (0)
#define TEST3(X,T) do { TEST2((T)(X)); TEST2((unsigned T)(X)); } поки (0)
#define TEST4(X)                 \
  do                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),ціле);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 поки (0)

static ціле debug, nfailed = 0;

static void check (const char *s, ціле arg1, ціле shift)
{
  ціле failed = arg1 != shift;
  якщо (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

ціле main (ціле argc, char **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  повернути nfailed != 0;
}

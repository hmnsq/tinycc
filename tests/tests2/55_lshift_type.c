/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#அந்தர்பாவ <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (முழு) அளவு((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) செய் { CHECK(X,T); CHECK(X,unsigned T); } போது (0)
#define TEST2(X)                 \
  செய்                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),முழு);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  போது (0)
#define TEST3(X,T) செய் { TEST2((T)(X)); TEST2((unsigned T)(X)); } போது (0)
#define TEST4(X)                 \
  செய்                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),முழு);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 போது (0)

நிலையான முழு debug, nfailed = 0;

நிலையான வெறுமை check (மாறிலி எழுத்து *s, முழு arg1, முழு shift)
{
  முழு failed = arg1 != shift;
  எனில் (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

முழு முதன்மை (முழு argc, எழுத்து **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  திரும்பு nfailed != 0;
}

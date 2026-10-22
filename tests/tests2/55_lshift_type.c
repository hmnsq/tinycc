/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#അന്തര്ഭാവ <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (പൂർണ്ണസംഖ്യ) വലുപ്പം((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) ചെയ്യുക { CHECK(X,T); CHECK(X,unsigned T); } ആകുമ്പോൾ (0)
#define TEST2(X)                 \
  ചെയ്യുക                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),പൂർണ്ണസംഖ്യ);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  ആകുമ്പോൾ (0)
#define TEST3(X,T) ചെയ്യുക { TEST2((T)(X)); TEST2((unsigned T)(X)); } ആകുമ്പോൾ (0)
#define TEST4(X)                 \
  ചെയ്യുക                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),പൂർണ്ണസംഖ്യ);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 ആകുമ്പോൾ (0)

സ്ഥിതം പൂർണ്ണസംഖ്യ debug, nfailed = 0;

സ്ഥിതം ശൂന്യം check (സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ arg1, പൂർണ്ണസംഖ്യ shift)
{
  പൂർണ്ണസംഖ്യ failed = arg1 != shift;
  എങ്കിൽ (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

പൂർണ്ണസംഖ്യ പ്രധാന (പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  തിരികെ nfailed != 0;
}

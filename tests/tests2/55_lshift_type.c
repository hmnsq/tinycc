/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ଅନ୍ତର୍ଭାଵ <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) ଆକାର((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) କର { CHECK(X,T); CHECK(X,unsigned T); } ଯେତେବେଳେ (0)
#define TEST2(X)                 \
  କର                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),ପୂର୍ଣ୍ଣସଂଖ୍ୟା);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  ଯେତେବେଳେ (0)
#define TEST3(X,T) କର { TEST2((T)(X)); TEST2((unsigned T)(X)); } ଯେତେବେଳେ (0)
#define TEST4(X)                 \
  କର                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),ପୂର୍ଣ୍ଣସଂଖ୍ୟା);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 ଯେତେବେଳେ (0)

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା debug, nfailed = 0;

ସ୍ଥିର ଶୂନ୍ୟ check (ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shift)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା failed = arg1 != shift;
  ଯଦି (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  ଫେରନ୍ତୁ nfailed != 0;
}

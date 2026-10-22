/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#अन्तर्भाव <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (पूर्णाङ्क) परिमाण((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) कुरु { CHECK(X,T); CHECK(X,unsigned T); } यावत् (0)
#define TEST2(X)                 \
  कुरु                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),पूर्णाङ्क);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  यावत् (0)
#define TEST3(X,T) कुरु { TEST2((T)(X)); TEST2((unsigned T)(X)); } यावत् (0)
#define TEST4(X)                 \
  कुरु                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),पूर्णाङ्क);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 यावत् (0)

स्थिर पूर्णाङ्क debug, nfailed = 0;

स्थिर शून्य check (ध्रुव वर्ण *s, पूर्णाङ्क arg1, पूर्णाङ्क shift)
{
  पूर्णाङ्क failed = arg1 != shift;
  यदि (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

पूर्णाङ्क main (पूर्णाङ्क argc, वर्ण **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  प्रत्यागम nfailed != 0;
}

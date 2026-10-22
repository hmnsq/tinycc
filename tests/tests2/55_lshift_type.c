/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ಅನ್ತರ್ಭಾವ <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ಪೂರ್ಣಾಙ್ಕ) ಪರಿಮಾಣ((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) ಕುರು { CHECK(X,T); CHECK(X,unsigned T); } ಯಾವತ್ (0)
#define TEST2(X)                 \
  ಕುರು                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),ಪೂರ್ಣಾಙ್ಕ);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  ಯಾವತ್ (0)
#define TEST3(X,T) ಕುರು { TEST2((T)(X)); TEST2((unsigned T)(X)); } ಯಾವತ್ (0)
#define TEST4(X)                 \
  ಕುರು                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),ಪೂರ್ಣಾಙ್ಕ);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 ಯಾವತ್ (0)

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ debug, nfailed = 0;

ಸ್ಥಿರ ಶೂನ್ಯ check (ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ arg1, ಪೂರ್ಣಾಙ್ಕ shift)
{
  ಪೂರ್ಣಾಙ್ಕ failed = arg1 != shift;
  ಯದಿ (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

ಪೂರ್ಣಾಙ್ಕ main (ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  ಪ್ರತ್ಯಾಗಮ nfailed != 0;
}

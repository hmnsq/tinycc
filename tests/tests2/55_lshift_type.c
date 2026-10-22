/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ಅನ್ತರ್ಭಾವ <stdio.h>

#ವ್ಯಾಖ್ಯಾನಿಸು PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ಪೂರ್ಣಾಂಕ) ಗಾತ್ರ((M)+0)
#ವ್ಯಾಖ್ಯಾನಿಸು CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#ವ್ಯಾಖ್ಯಾನಿಸು TEST1(X,T) ಮಾಡು { CHECK(X,T); CHECK(X,ಚಿಹ್ನೆರಹಿತ T); } ಆಗ (0)
#ವ್ಯಾಖ್ಯಾನಿಸು TEST2(X)                 \
  ಮಾಡು                             \
    {                            \
      TEST1((X),ಗಿಡ್ಡ);          \
      TEST1((X),ಪೂರ್ಣಾಂಕ);            \
      TEST1((X),ದೀರ್ಘ);           \
      TEST1((X),ದೀರ್ಘ ದೀರ್ಘ);      \
    }                            \
  ಆಗ (0)
#ವ್ಯಾಖ್ಯಾನಿಸು TEST3(X,T) ಮಾಡು { TEST2((T)(X)); TEST2((ಚಿಹ್ನೆರಹಿತ T)(X)); } ಆಗ (0)
#ವ್ಯಾಖ್ಯಾನಿಸು TEST4(X)                 \
  ಮಾಡು                             \
    {                            \
      TEST3((X),ಗಿಡ್ಡ);          \
      TEST3((X),ಪೂರ್ಣಾಂಕ);            \
      TEST3((X),ದೀರ್ಘ);           \
      TEST3((X),ದೀರ್ಘ ದೀರ್ಘ);      \
    }                            \
 ಆಗ (0)

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ debug, nfailed = 0;

ಸ್ಥಿರ ಶೂನ್ಯ check (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ arg1, ಪೂರ್ಣಾಂಕ ಸರಿಸು)
{
  ಪೂರ್ಣಾಂಕ failed = arg1 != ಸರಿಸು;
  ಆದರೆ (debug || failed)
    ಬರೆ ("%s %d %d\n", s, arg1, ಸರಿಸು);
  nfailed += failed;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ (ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  ಬರೆ ("%d test(s) failed\n", nfailed);
  ಹಿಂತಿರುಗಿ nfailed != 0;
}

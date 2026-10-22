/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (ਪੂਰਨ) ਆਕਾਰ((M)+0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST1(X,T) ਕਰੋ { CHECK(X,T); CHECK(X,ਬਿਨਾਨਿਸ਼ਾਨੀ T); } ਜਦੋਂ (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST2(X)                 \
  ਕਰੋ                             \
    {                            \
      TEST1((X),ਛੋਟਾ);          \
      TEST1((X),ਪੂਰਨ);            \
      TEST1((X),ਲੰਮਾ);           \
      TEST1((X),ਲੰਮਾ ਲੰਮਾ);      \
    }                            \
  ਜਦੋਂ (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST3(X,T) ਕਰੋ { TEST2((T)(X)); TEST2((ਬਿਨਾਨਿਸ਼ਾਨੀ T)(X)); } ਜਦੋਂ (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST4(X)                 \
  ਕਰੋ                             \
    {                            \
      TEST3((X),ਛੋਟਾ);          \
      TEST3((X),ਪੂਰਨ);            \
      TEST3((X),ਲੰਮਾ);           \
      TEST3((X),ਲੰਮਾ ਲੰਮਾ);      \
    }                            \
 ਜਦੋਂ (0)

ਸਥਿਰ ਪੂਰਨ debug, nfailed = 0;

ਸਥਿਰ ਖਾਲੀ check (ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ arg1, ਪੂਰਨ ਖਿਸਕਾਓ)
{
  ਪੂਰਨ failed = arg1 != ਖਿਸਕਾਓ;
  ਜੇ (debug || failed)
    ਲਿਖੋ ("%s %d %d\n", s, arg1, ਖਿਸਕਾਓ);
  nfailed += failed;
}

ਪੂਰਨ ਮੁੱਖ (ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  ਲਿਖੋ ("%d test(s) failed\n", nfailed);
  ਵਾਪਸ nfailed != 0;
}

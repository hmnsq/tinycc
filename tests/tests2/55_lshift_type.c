/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#అన్తర్భావ <stdio.h>

#నిర్వచించు PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (పూర్ణాంకం) పరిమాణం((M)+0)
#నిర్వచించు CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#నిర్వచించు TEST1(X,T) చేయి { CHECK(X,T); CHECK(X,గుర్తులేని T); } అయితే (0)
#నిర్వచించు TEST2(X)                 \
  చేయి                             \
    {                            \
      TEST1((X),పొట్టి);          \
      TEST1((X),పూర్ణాంకం);            \
      TEST1((X),దీర్ఘ);           \
      TEST1((X),దీర్ఘ దీర్ఘ);      \
    }                            \
  అయితే (0)
#నిర్వచించు TEST3(X,T) చేయి { TEST2((T)(X)); TEST2((గుర్తులేని T)(X)); } అయితే (0)
#నిర్వచించు TEST4(X)                 \
  చేయి                             \
    {                            \
      TEST3((X),పొట్టి);          \
      TEST3((X),పూర్ణాంకం);            \
      TEST3((X),దీర్ఘ);           \
      TEST3((X),దీర్ఘ దీర్ఘ);      \
    }                            \
 అయితే (0)

స్థిర పూర్ణాంకం debug, nfailed = 0;

స్థిర శూన్య check (స్థిరరాశి అక్షరం *s, పూర్ణాంకం arg1, పూర్ణాంకం జరుపు)
{
  పూర్ణాంకం failed = arg1 != జరుపు;
  ఒకవేళ (debug || failed)
    రాయి ("%s %d %d\n", s, arg1, జరుపు);
  nfailed += failed;
}

పూర్ణాంకం ప్రధాన (పూర్ణాంకం argc, అక్షరం **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  రాయి ("%d test(s) failed\n", nfailed);
  తిరిగి nfailed != 0;
}

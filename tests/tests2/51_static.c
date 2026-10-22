#అన్తర్భావ <stdio.h>

స్థిర పూర్ణాంకం fred = 1234;
స్థిర పూర్ణాంకం joe;

శూన్య henry()
{
   స్థిర పూర్ణాంకం fred = 4567;

   రాయి("%d\n", fred);
   fred++;
}

పూర్ణాంకం ప్రధాన()
{
   రాయి("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   రాయి("%d\n", fred);
   fred = 8901;
   joe = 2345;
   రాయి("%d\n", fred);
   రాయి("%d\n", joe);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

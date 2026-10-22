బాహ్య పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం*, ...);

నిర్మాణం fred;

శూన్య fred$(నిర్మాణం fred* this)
{
    రాయి("~fred()\n");
}

నిర్మాణం __attribute__((__cleanup__(fred$))) fred
{
   పూర్ణాంకం boris;
   పూర్ణాంకం natasha;
};

పూర్ణాంకం ప్రధాన()
{
    నిర్మాణం fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   రాయి("%d\n", bloggs.boris);
   రాయి("%d\n", bloggs.natasha);

   నిర్మాణం fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   రాయి("%d\n", jones[0].boris);
   రాయి("%d\n", jones[0].natasha);
   రాయి("%d\n", jones[1].boris);
   రాయి("%d\n", jones[1].natasha);

   తిరిగి 0;
}

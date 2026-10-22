ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);

ସଂରଚନା fred;

ଶୂନ୍ୟ fred$(ସଂରଚନା fred* this)
{
    printf("~fred()\n");
}

ସଂରଚନା __attribute__((__cleanup__(fred$))) fred
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା boris;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା natasha;
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ସଂରଚନା fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   ସଂରଚନା fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   ଫେରନ୍ତୁ 0;
}

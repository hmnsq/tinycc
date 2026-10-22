बाह्य पूर्णाङ्क printf(ध्रुव वर्ण*, ...);

संरचना fred;

शून्य fred$(संरचना fred* this)
{
    printf("~fred()\n");
}

संरचना __attribute__((__cleanup__(fred$))) fred
{
   पूर्णाङ्क boris;
   पूर्णाङ्क natasha;
};

पूर्णाङ्क main()
{
    संरचना fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   संरचना fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   प्रत्यागम 0;
}

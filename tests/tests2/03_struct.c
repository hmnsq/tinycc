ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);

ಸಂರಚನಾ fred;

ಶೂನ್ಯ fred$(ಸಂರಚನಾ fred* this)
{
    printf("~fred()\n");
}

ಸಂರಚನಾ __attribute__((__cleanup__(fred$))) fred
{
   ಪೂರ್ಣಾಙ್ಕ boris;
   ಪೂರ್ಣಾಙ್ಕ natasha;
};

ಪೂರ್ಣಾಙ್ಕ main()
{
    ಸಂರಚನಾ fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   ಸಂರಚನಾ fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   ಪ್ರತ್ಯಾಗಮ 0;
}

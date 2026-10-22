বাহ্য পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ*, ...);

সংরচনা fred;

শূন্য fred$(সংরচনা fred* this)
{
    printf("~fred()\n");
}

সংরচনা __attribute__((__cleanup__(fred$))) fred
{
   পূর্ণাঙ্ক boris;
   পূর্ণাঙ্ক natasha;
};

পূর্ণাঙ্ক main()
{
    সংরচনা fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   সংরচনা fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   ঘূৰাই 0;
}

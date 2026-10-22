বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);

কাঠামো fred;

শূন্য fred$(কাঠামো fred* this)
{
    printf("~fred()\n");
}

কাঠামো __attribute__((__cleanup__(fred$))) fred
{
   পূর্ণসংখ্যা boris;
   পূর্ণসংখ্যা natasha;
};

পূর্ণসংখ্যা প্রধান()
{
    কাঠামো fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   কাঠামো fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   ফেরত 0;
}

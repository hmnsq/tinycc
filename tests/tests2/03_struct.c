خارجي صحيح printf(ثابت حرف*, ...);

بنية fred;

فراغ fred$(بنية fred* this)
{
    printf("~fred()\n");
}

بنية __attribute__((__cleanup__(fred$))) fred
{
   صحيح boris;
   صحيح natasha;
};

صحيح main()
{
    بنية fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   بنية fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   החזר 0;
}

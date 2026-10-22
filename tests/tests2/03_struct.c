بیرونی صحیح printf(ثابت نویسه*, ...);

ساختار fred;

تهی fred$(ساختار fred* this)
{
    printf("~fred()\n");
}

ساختار __attribute__((__cleanup__(fred$))) fred
{
   صحیح boris;
   صحیح natasha;
};

صحیح اصلی()
{
    ساختار fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   ساختار fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   بازگشت 0;
}

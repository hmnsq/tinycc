خارجي صحيح لکو(ثابت حرف*, ...);

بنية fred;

فراغ fred$(بنية fred* this)
{
    لکو("~fred()\n");
}

بنية __attribute__((__cleanup__(fred$))) fred
{
   صحيح boris;
   صحيح natasha;
};

صحيح مکيه()
{
    بنية fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   لکو("%d\n", bloggs.boris);
   لکو("%d\n", bloggs.natasha);

   بنية fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   لکو("%d\n", jones[0].boris);
   لکو("%d\n", jones[0].natasha);
   لکو("%d\n", jones[1].boris);
   لکو("%d\n", jones[1].natasha);

   أرجع 0;
}

خارجي صحيح لکھو(ثابت حرف*, ...);

بنية fred;

فراغ fred$(بنية fred* this)
{
    لکھو("~fred()\n");
}

بنية __attribute__((__cleanup__(fred$))) fred
{
   صحيح boris;
   صحيح natasha;
};

صحيح مکھ()
{
    بنية fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   لکھو("%d\n", bloggs.boris);
   لکھو("%d\n", bloggs.natasha);

   بنية fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   لکھو("%d\n", jones[0].boris);
   لکھو("%d\n", jones[0].natasha);
   لکھو("%d\n", jones[1].boris);
   لکھو("%d\n", jones[1].natasha);

   أرجع 0;
}

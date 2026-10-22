خارجی صحیح لکھو(ثابت حرف*, ...);

ساخت fred;

خالی fred$(ساخت fred* this)
{
    لکھو("~fred()\n");
}

ساخت __attribute__((__cleanup__(fred$))) fred
{
   صحیح boris;
   صحیح natasha;
};

صحیح مین()
{
    ساخت fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   لکھو("%d\n", bloggs.boris);
   لکھو("%d\n", bloggs.natasha);

   ساخت fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   لکھو("%d\n", jones[0].boris);
   لکھو("%d\n", jones[0].natasha);
   لکھو("%d\n", jones[1].boris);
   لکھو("%d\n", jones[1].natasha);

   واپس 0;
}

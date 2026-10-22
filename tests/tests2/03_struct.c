خارجي صحيح چاپ_کړه(ثابت حرف*, ...);

بنية fred;

فراغ fred$(بنية fred* this)
{
    چاپ_کړه("~fred()\n");
}

بنية __attribute__((__cleanup__(fred$))) fred
{
   صحيح boris;
   صحيح natasha;
};

صحيح اصلي()
{
    بنية fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   چاپ_کړه("%d\n", bloggs.boris);
   چاپ_کړه("%d\n", bloggs.natasha);

   بنية fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   چاپ_کړه("%d\n", jones[0].boris);
   چاپ_کړه("%d\n", jones[0].natasha);
   چاپ_کړه("%d\n", jones[1].boris);
   چاپ_کړه("%d\n", jones[1].natasha);

   أرجع 0;
}

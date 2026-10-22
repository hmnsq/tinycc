બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર*, ...);

સંરચના fred;

શૂન્ય fred$(સંરચના fred* this)
{
    printf("~fred()\n");
}

સંરચના __attribute__((__cleanup__(fred$))) fred
{
   પૂર્ણાંક boris;
   પૂર્ણાંક natasha;
};

પૂર્ણાંક મુખ્ય()
{
    સંરચના fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   સંરચના fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   પાછા 0;
}

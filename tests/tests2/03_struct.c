ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);

ഘടന fred;

ശൂന്യം fred$(ഘടന fred* this)
{
    printf("~fred()\n");
}

ഘടന __attribute__((__cleanup__(fred$))) fred
{
   പൂർണ്ണസംഖ്യ boris;
   പൂർണ്ണസംഖ്യ natasha;
};

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    ഘടന fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   ഘടന fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   തിരികെ 0;
}

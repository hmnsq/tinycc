வெளி முழு printf(மாறிலி எழுத்து*, ...);

கட்டமைப்பு fred;

வெறுமை fred$(கட்டமைப்பு fred* this)
{
    printf("~fred()\n");
}

கட்டமைப்பு __attribute__((__cleanup__(fred$))) fred
{
   முழு boris;
   முழு natasha;
};

முழு முதன்மை()
{
    கட்டமைப்பு fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   கட்டமைப்பு fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   திரும்பு 0;
}

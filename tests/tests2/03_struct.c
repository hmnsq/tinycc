extern puur_naa_nka printf(const var_na*, ...);

sa_nracanaa fred;

void fred$(sa_nracanaa fred* this)
{
    printf("~fred()\n");
}

sa_nracanaa __attribute__((__cleanup__(fred$))) fred
{
   puur_naa_nka boris;
   puur_naa_nka natasha;
};

puur_naa_nka main()
{
    sa_nracanaa fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   sa_nracanaa fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   ᬯᬮᬶ 0;
}

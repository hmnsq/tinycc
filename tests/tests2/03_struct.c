ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*, ...);

ਬਣਤਰ fred;

ਖਾਲੀ fred$(ਬਣਤਰ fred* this)
{
    ਲਿਖੋ("~fred()\n");
}

ਬਣਤਰ __attribute__((__cleanup__(fred$))) fred
{
   ਪੂਰਨ boris;
   ਪੂਰਨ natasha;
};

ਪੂਰਨ ਮੁੱਖ()
{
    ਬਣਤਰ fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   ਲਿਖੋ("%d\n", bloggs.boris);
   ਲਿਖੋ("%d\n", bloggs.natasha);

   ਬਣਤਰ fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   ਲਿਖੋ("%d\n", jones[0].boris);
   ਲਿਖੋ("%d\n", jones[0].natasha);
   ਲਿਖੋ("%d\n", jones[1].boris);
   ਲਿਖੋ("%d\n", jones[1].natasha);

   ਵਾਪਸ 0;
}

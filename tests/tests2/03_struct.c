बाह्य पूर्णांक म_लिखो(स्थिरांक अक्षर*, ...);

संरचना fred;

शून्य fred$(संरचना fred* this)
{
    म_लिखो("~fred()\n");
}

संरचना __attribute__((__cleanup__(fred$))) fred
{
   पूर्णांक boris;
   पूर्णांक natasha;
};

पूर्णांक main()
{
    संरचना fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   म_लिखो("%d\n", bloggs.boris);
   म_लिखो("%d\n", bloggs.natasha);

   संरचना fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   म_लिखो("%d\n", jones[0].boris);
   म_लिखो("%d\n", jones[0].natasha);
   म_लिखो("%d\n", jones[1].boris);
   म_लिखो("%d\n", jones[1].natasha);

   परत 0;
}

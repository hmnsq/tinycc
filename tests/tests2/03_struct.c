बाह्य पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण*, ...);

संरचना fred;

शून्य fred$(संरचना fred* this)
{
    प्रारूप_लिख("~fred()\n");
}

संरचना __attribute__((__cleanup__(fred$))) fred
{
   पूर्णाङ्क boris;
   पूर्णाङ्क natasha;
};

पूर्णाङ्क मुख्यम्()
{
    संरचना fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   प्रारूप_लिख("%d\n", bloggs.boris);
   प्रारूप_लिख("%d\n", bloggs.natasha);

   संरचना fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   प्रारूप_लिख("%d\n", jones[0].boris);
   प्रारूप_लिख("%d\n", jones[0].natasha);
   प्रारूप_लिख("%d\n", jones[1].boris);
   प्रारूप_लिख("%d\n", jones[1].natasha);

   प्रत्यागम 0;
}

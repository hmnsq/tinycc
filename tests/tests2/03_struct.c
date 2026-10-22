बाह्य पूर्णांक म_लिखो(स्थिर अक्षर*, ...);

काष्ठा fred;

व्योम fred$(काष्ठा fred* this)
{
    म_लिखो("~fred()\n");
}

काष्ठा __attribute__((__cleanup__(fred$))) fred
{
   पूर्णांक boris;
   पूर्णांक natasha;
};

पूर्णांक मुख्य()
{
    काष्ठा fred  __attribute__((__cleanup__(fred$))) bloggs;

   bloggs.boris = 12;
   bloggs.natasha = 34;

   म_लिखो("%d\n", bloggs.boris);
   म_लिखो("%d\n", bloggs.natasha);

   काष्ठा fred jones[2];
   jones[0].boris = 12;
   jones[0].natasha = 34;
   jones[1].boris = 56;
   jones[1].natasha = 78;

   म_लिखो("%d\n", jones[0].boris);
   म_लिखो("%d\n", jones[0].natasha);
   म_लिखो("%d\n", jones[1].boris);
   म_लिखो("%d\n", jones[1].natasha);

   वापस 0;
}

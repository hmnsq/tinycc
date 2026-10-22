#समावेश <stdio.h>

पूर्णांक मुख्य()
{
   खाता *f = ख_खोलो("fred.txt", "w");
   ख_डालो("hello\nhello\n", 1, 12, f);
   ख_बंद(f);

   अक्षर freddy[7];
   f = ख_खोलो("fred.txt", "r");
   अगर (ख_पढ़ो(freddy, 1, 6, f) != 6)
      म_लिखो("couldn't read fred.txt\n");

   freddy[6] = '\0';
   ख_बंद(f);

   म_लिखो("%s", freddy);

   पूर्णांक InChar;
   अक्षर ShowChar;
   f = ख_खोलो("fred.txt", "r");
   जबतक ( (InChar = ख_अक्षर_लो(f)) != खातापूर्ण)
   {
      ShowChar = InChar;
      अगर (ShowChar < ' ')
         ShowChar = '.';

      म_लिखो("ch: %d '%c'\n", InChar, ShowChar);
   }
   ख_बंद(f);

   f = ख_खोलो("fred.txt", "r");
   जबतक ( (InChar = अ_लो(f)) != खातापूर्ण)
   {
      ShowChar = InChar;
      अगर (ShowChar < ' ')
         ShowChar = '.';

      म_लिखो("ch: %d '%c'\n", InChar, ShowChar);
   }
   ख_बंद(f);

   f = ख_खोलो("fred.txt", "r");
   जबतक (ख_माला_लो(freddy, माप(freddy), f) != शून्य)
      म_लिखो("x: %s", freddy);

   ख_बंद(f);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

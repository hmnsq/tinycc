#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
   खाता *f = ख_खोलो("fred.txt", "w");
   ख_डालो("hello\nhello\n", 1, 12, f);
   ख_बंद(f);

   अक्षर freddy[7];
   f = ख_खोलो("fred.txt", "r");
   जर (ख_पढ़ो(freddy, 1, 6, f) != 6)
      म_लिखो("couldn't read fred.txt\n");

   freddy[6] = '\0';
   ख_बंद(f);

   म_लिखो("%s", freddy);

   पूर्णांक InChar;
   अक्षर ShowChar;
   f = ख_खोलो("fred.txt", "r");
   पर्यंत ( (InChar = ख_अक्षर_लो(f)) != खातापूर्ण)
   {
      ShowChar = InChar;
      जर (ShowChar < ' ')
         ShowChar = '.';

      म_लिखो("ch: %d '%c'\n", InChar, ShowChar);
   }
   ख_बंद(f);

   f = ख_खोलो("fred.txt", "r");
   पर्यंत ( (InChar = अ_लो(f)) != खातापूर्ण)
   {
      ShowChar = InChar;
      जर (ShowChar < ' ')
         ShowChar = '.';

      म_लिखो("ch: %d '%c'\n", InChar, ShowChar);
   }
   ख_बंद(f);

   f = ख_खोलो("fred.txt", "r");
   पर्यंत (ख_माला_लो(freddy, आकार(freddy), f) != रिक्त)
      म_लिखो("x: %s", freddy);

   ख_बंद(f);

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

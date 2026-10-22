#अन्तर्भाव <stdio.h>

पूर्णाङ्क मुख्यम्()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   वर्ण freddy[7];
   f = fopen("fred.txt", "r");
   यदि (fread(freddy, 1, 6, f) != 6)
      प्रारूप_लिख("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   प्रारूप_लिख("%s", freddy);

   पूर्णाङ्क अन्तर्_Char;
   वर्ण ShowChar;
   f = fopen("fred.txt", "r");
   यावत् ( (अन्तर्_Char = fgetc(f)) != EOF)
   {
      ShowChar = अन्तर्_Char;
      यदि (ShowChar < ' ')
         ShowChar = '.';

      प्रारूप_लिख("ch: %d '%c'\n", अन्तर्_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   यावत् ( (अन्तर्_Char = getc(f)) != EOF)
   {
      ShowChar = अन्तर्_Char;
      यदि (ShowChar < ' ')
         ShowChar = '.';

      प्रारूप_लिख("ch: %d '%c'\n", अन्तर्_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   यावत् (fgets(freddy, परिमाण(freddy), f) != रिक्त)
      प्रारूप_लिख("x: %s", freddy);

   fclose(f);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   वर्ण freddy[7];
   f = fopen("fred.txt", "r");
   सचे (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   पूर्णाङ्क InChar;
   वर्ण ShowChar;
   f = fopen("fred.txt", "r");
   याव ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      सचे (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   याव ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      सचे (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   याव (fgets(freddy, परिमाण(freddy), f) != रिक्त)
      printf("x: %s", freddy);

   fclose(f);

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

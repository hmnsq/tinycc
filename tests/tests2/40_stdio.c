#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   ವರ್ಣ freddy[7];
   f = fopen("fred.txt", "r");
   ಯದಿ (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   ಪೂರ್ಣಾಙ್ಕ InChar;
   ವರ್ಣ ShowChar;
   f = fopen("fred.txt", "r");
   ಯಾವತ್ ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      ಯದಿ (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ಯಾವತ್ ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      ಯದಿ (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ಯಾವತ್ (fgets(freddy, ಪರಿಮಾಣ(freddy), f) != ರಿಕ್ತ)
      printf("x: %s", freddy);

   fclose(f);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

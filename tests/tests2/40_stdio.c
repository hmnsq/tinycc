#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   അക്ഷരം freddy[7];
   f = fopen("fred.txt", "r");
   എങ്കിൽ (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   പൂർണ്ണസംഖ്യ InChar;
   അക്ഷരം ShowChar;
   f = fopen("fred.txt", "r");
   ആകുമ്പോൾ ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      എങ്കിൽ (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ആകുമ്പോൾ ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      എങ്കിൽ (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ആകുമ്പോൾ (fgets(freddy, വലുപ്പം(freddy), f) != ശൂന്യ)
      printf("x: %s", freddy);

   fclose(f);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

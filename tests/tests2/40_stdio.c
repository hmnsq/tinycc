#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   અક્ષર freddy[7];
   f = fopen("fred.txt", "r");
   જો (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   પૂર્ણાંક InChar;
   અક્ષર ShowChar;
   f = fopen("fred.txt", "r");
   જ્યારે ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      જો (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   જ્યારે ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      જો (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   જ્યારે (fgets(freddy, કદ(freddy), f) != ખાલી)
      printf("x: %s", freddy);

   fclose(f);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#ضمن <stdio.h>

صحيح main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   إذا (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   صحيح InChar;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   طالما ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما (fgets(freddy, حجم(freddy), f) != عدم)
      printf("x: %s", freddy);

   fclose(f);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

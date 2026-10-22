#ضمن <stdio.h>

صحيح اصلی()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   إذا (fread(freddy, 1, 6, f) != 6)
      چاپ_کن("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   چاپ_کن("%s", freddy);

   صحيح درون_Char;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   طالما ( (درون_Char = fgetc(f)) != EOF)
   {
      ShowChar = درون_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      چاپ_کن("ch: %d '%c'\n", درون_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما ( (درون_Char = getc(f)) != EOF)
   {
      ShowChar = درون_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      چاپ_کن("ch: %d '%c'\n", درون_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما (fgets(freddy, حجم(freddy), f) != عدم)
      چاپ_کن("x: %s", freddy);

   fclose(f);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

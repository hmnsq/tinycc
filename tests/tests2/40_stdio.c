#ضمن <stdio.h>

صحيح اصلي()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   إذا (fread(freddy, 1, 6, f) != 6)
      چاپ_کړه("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   چاپ_کړه("%s", freddy);

   صحيح دننه_Char;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   طالما ( (دننه_Char = fgetc(f)) != EOF)
   {
      ShowChar = دننه_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      چاپ_کړه("ch: %d '%c'\n", دننه_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما ( (دننه_Char = getc(f)) != EOF)
   {
      ShowChar = دننه_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      چاپ_کړه("ch: %d '%c'\n", دننه_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما (fgets(freddy, حجم(freddy), f) != عدم)
      چاپ_کړه("x: %s", freddy);

   fclose(f);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

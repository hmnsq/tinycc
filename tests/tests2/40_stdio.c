#ضمن <stdio.h>

صحيح مکيه()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   إذا (fread(freddy, 1, 6, f) != 6)
      لکو("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   لکو("%s", freddy);

   صحيح اندريون_Char;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   طالما ( (اندريون_Char = fgetc(f)) != EOF)
   {
      ShowChar = اندريون_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      لکو("ch: %d '%c'\n", اندريون_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما ( (اندريون_Char = getc(f)) != EOF)
   {
      ShowChar = اندريون_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      لکو("ch: %d '%c'\n", اندريون_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما (fgets(freddy, حجم(freddy), f) != عدم)
      لکو("x: %s", freddy);

   fclose(f);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

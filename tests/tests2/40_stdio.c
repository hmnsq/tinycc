#ضمن <stdio.h>

صحيح مکھ()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   إذا (fread(freddy, 1, 6, f) != 6)
      لکھو("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   لکھو("%s", freddy);

   صحيح وچ_Char;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   طالما ( (وچ_Char = fgetc(f)) != EOF)
   {
      ShowChar = وچ_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      لکھو("ch: %d '%c'\n", وچ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما ( (وچ_Char = getc(f)) != EOF)
   {
      ShowChar = وچ_Char;
      إذا (ShowChar < ' ')
         ShowChar = '.';

      لکھو("ch: %d '%c'\n", وچ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   طالما (fgets(freddy, حجم(freddy), f) != عدم)
      لکھو("x: %s", freddy);

   fclose(f);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#شامل <stdio.h>

صحیح مین()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   حرف freddy[7];
   f = fopen("fred.txt", "r");
   اگر (fread(freddy, 1, 6, f) != 6)
      لکھو("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   لکھو("%s", freddy);

   صحیح اندر_Char;
   حرف ShowChar;
   f = fopen("fred.txt", "r");
   جب ( (اندر_Char = fgetc(f)) != EOF)
   {
      ShowChar = اندر_Char;
      اگر (ShowChar < ' ')
         ShowChar = '.';

      لکھو("ch: %d '%c'\n", اندر_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   جب ( (اندر_Char = getc(f)) != EOF)
   {
      ShowChar = اندر_Char;
      اگر (ShowChar < ' ')
         ShowChar = '.';

      لکھو("ch: %d '%c'\n", اندر_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   جب (fgets(freddy, حجم(freddy), f) != تہی)
      لکھو("x: %s", freddy);

   fclose(f);

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

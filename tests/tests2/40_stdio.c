#include <stdio.h>

ཧྲིལ main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   var_na freddy[7];
   f = fopen("fred.txt", "r");
   གལ་སྲིད (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   ཧྲིལ InChar;
   var_na ShowChar;
   f = fopen("fred.txt", "r");
   སྐབས ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      གལ་སྲིད (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   སྐབས ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      གལ་སྲིད (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   སྐབས (fgets(freddy, parimaa_na(freddy), f) != NULL)
      printf("x: %s", freddy);

   fclose(f);

   ལོག 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

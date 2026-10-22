#include <stdio.h>

целое основной()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   char freddy[7];
   f = fopen("fred.txt", "r");
   если (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   целое InChar;
   char ShowChar;
   f = fopen("fred.txt", "r");
   пока ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      если (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   пока ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      если (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   пока (fgets(freddy, sizeof(freddy), f) != NULL)
      printf("x: %s", freddy);

   fclose(f);

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

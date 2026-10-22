#include <stdio.h>

цео main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   char freddy[7];
   f = fopen("fred.txt", "r");
   ако (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   цео InChar;
   char ShowChar;
   f = fopen("fred.txt", "r");
   док ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      ако (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   док ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      ако (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   док (fgets(freddy, sizeof(freddy), f) != NULL)
      printf("x: %s", freddy);

   fclose(f);

   врати 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

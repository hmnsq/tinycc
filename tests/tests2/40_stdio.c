#include <stdio.h>

정수 main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   char freddy[7];
   f = fopen("fred.txt", "r");
   만약 (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   정수 InChar;
   char ShowChar;
   f = fopen("fred.txt", "r");
   동안 ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      만약 (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   동안 ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      만약 (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   동안 (fgets(freddy, sizeof(freddy), f) != NULL)
      printf("x: %s", freddy);

   fclose(f);

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

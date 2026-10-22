#شامل <stdio.h>

صحیح اصلی()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   نویسه freddy[7];
   f = fopen("fred.txt", "r");
   اگر (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   صحیح InChar;
   نویسه ShowChar;
   f = fopen("fred.txt", "r");
   وقتی ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      اگر (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   وقتی ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      اگر (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   وقتی (fgets(freddy, اندازه(freddy), f) != پوچ)
      printf("x: %s", freddy);

   fclose(f);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   অক্ষর freddy[7];
   f = fopen("fred.txt", "r");
   যদি (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   পূর্ণসংখ্যা InChar;
   অক্ষর ShowChar;
   f = fopen("fred.txt", "r");
   যখন ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      যদি (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   যখন ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      যদি (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   যখন (fgets(freddy, আকার(freddy), f) != ফাঁকা)
      printf("x: %s", freddy);

   fclose(f);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

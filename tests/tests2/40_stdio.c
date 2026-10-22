#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   ৱর্ণ freddy[7];
   f = fopen("fred.txt", "r");
   যদি (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   পূর্ণাঙ্ক InChar;
   ৱর্ণ ShowChar;
   f = fopen("fred.txt", "r");
   যেতিয়ালৈ ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      যদি (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   যেতিয়ালৈ ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      যদি (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   যেতিয়ালৈ (fgets(freddy, পরিমাণ(freddy), f) != রিক্ত)
      printf("x: %s", freddy);

   fclose(f);

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

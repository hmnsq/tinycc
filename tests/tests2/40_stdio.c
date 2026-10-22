#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   ଅକ୍ଷର freddy[7];
   f = fopen("fred.txt", "r");
   ଯଦି (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା InChar;
   ଅକ୍ଷର ShowChar;
   f = fopen("fred.txt", "r");
   ଯେତେବେଳେ ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      ଯଦି (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ଯେତେବେଳେ ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      ଯଦି (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ଯେତେବେଳେ (fgets(freddy, ଆକାର(freddy), f) != ଖାଲି)
      printf("x: %s", freddy);

   fclose(f);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

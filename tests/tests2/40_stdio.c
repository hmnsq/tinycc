#అన్తర్భావ <stdio.h>

పూర్ణాంకం ప్రధాన()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   అక్షరం freddy[7];
   f = fopen("fred.txt", "r");
   ఒకవేళ (fread(freddy, 1, 6, f) != 6)
      రాయి("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   రాయి("%s", freddy);

   పూర్ణాంకం లోపల_Char;
   అక్షరం ShowChar;
   f = fopen("fred.txt", "r");
   అయితే ( (లోపల_Char = fgetc(f)) != EOF)
   {
      ShowChar = లోపల_Char;
      ఒకవేళ (ShowChar < ' ')
         ShowChar = '.';

      రాయి("ch: %d '%c'\n", లోపల_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   అయితే ( (లోపల_Char = getc(f)) != EOF)
   {
      ShowChar = లోపల_Char;
      ఒకవేళ (ShowChar < ' ')
         ShowChar = '.';

      రాయి("ch: %d '%c'\n", లోపల_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   అయితే (fgets(freddy, పరిమాణం(freddy), f) != ఖాళీ)
      రాయి("x: %s", freddy);

   fclose(f);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

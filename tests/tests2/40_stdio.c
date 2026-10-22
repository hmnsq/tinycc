#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   ಅಕ್ಷರ freddy[7];
   f = fopen("fred.txt", "r");
   ಆದರೆ (fread(freddy, 1, 6, f) != 6)
      ಬರೆ("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   ಬರೆ("%s", freddy);

   ಪೂರ್ಣಾಂಕ ಒಳ_Char;
   ಅಕ್ಷರ ShowChar;
   f = fopen("fred.txt", "r");
   ಆಗ ( (ಒಳ_Char = fgetc(f)) != EOF)
   {
      ShowChar = ಒಳ_Char;
      ಆದರೆ (ShowChar < ' ')
         ShowChar = '.';

      ಬರೆ("ch: %d '%c'\n", ಒಳ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ಆಗ ( (ಒಳ_Char = getc(f)) != EOF)
   {
      ShowChar = ಒಳ_Char;
      ಆದರೆ (ShowChar < ' ')
         ShowChar = '.';

      ಬರೆ("ch: %d '%c'\n", ಒಳ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ಆಗ (fgets(freddy, ಗಾತ್ರ(freddy), f) != ಖಾಲಿ)
      ಬರೆ("x: %s", freddy);

   fclose(f);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

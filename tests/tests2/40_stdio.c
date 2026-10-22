#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   ਅੱਖਰ freddy[7];
   f = fopen("fred.txt", "r");
   ਜੇ (fread(freddy, 1, 6, f) != 6)
      ਲਿਖੋ("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   ਲਿਖੋ("%s", freddy);

   ਪੂਰਨ ਵਿੱਚ_Char;
   ਅੱਖਰ ShowChar;
   f = fopen("fred.txt", "r");
   ਜਦੋਂ ( (ਵਿੱਚ_Char = fgetc(f)) != EOF)
   {
      ShowChar = ਵਿੱਚ_Char;
      ਜੇ (ShowChar < ' ')
         ShowChar = '.';

      ਲਿਖੋ("ch: %d '%c'\n", ਵਿੱਚ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ਜਦੋਂ ( (ਵਿੱਚ_Char = getc(f)) != EOF)
   {
      ShowChar = ਵਿੱਚ_Char;
      ਜੇ (ShowChar < ' ')
         ShowChar = '.';

      ਲਿਖੋ("ch: %d '%c'\n", ਵਿੱਚ_Char, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   ਜਦੋਂ (fgets(freddy, ਆਕਾਰ(freddy), f) != ਨਿਰਾ)
      ਲਿਖੋ("x: %s", freddy);

   fclose(f);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

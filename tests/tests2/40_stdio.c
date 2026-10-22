#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   FILE *f = fopen("fred.txt", "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   எழுத்து freddy[7];
   f = fopen("fred.txt", "r");
   எனில் (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read fred.txt\n");

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   முழு InChar;
   எழுத்து ShowChar;
   f = fopen("fred.txt", "r");
   போது ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      எனில் (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   போது ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      எனில் (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen("fred.txt", "r");
   போது (fgets(freddy, அளவு(freddy), f) != வெற்று)
      printf("x: %s", freddy);

   fclose(f);

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

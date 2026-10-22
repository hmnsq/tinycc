#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
   पूर्णाङ्क x = 'a';
   वर्ण y = x;

   वर्ण *a = "hello";

   म_लिखो("%s\n", a);

   पूर्णाङ्क c;
   c = *a;

   वर्ण *b;
   लागि (b = a; *b != 0; b++)
      म_लिखो("%c: %d\n", *b, *b);

   वर्ण destarray[10];
   वर्ण *dest = &destarray[0];
   वर्ण *src = a;

   जबसम्म (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   म_लिखो("copied string is %s\n", destarray);

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
   முழு x = 'a';
   எழுத்து y = x;

   எழுத்து *a = "hello";

   printf("%s\n", a);

   முழு c;
   c = *a;

   எழுத்து *b;
   க்கு (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   எழுத்து destarray[10];
   எழுத்து *dest = &destarray[0];
   எழுத்து *src = a;

   போது (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

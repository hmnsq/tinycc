#அந்தர்பாவ <stdio.h>

வெறுமை charfunc(எழுத்து a)
{
   printf("char: %c\n", a);
}

வெறுமை intfunc(முழு a)
{
   printf("int: %d\n", a);
}

வெறுமை floatfunc(தசம a)
{
   printf("float: %f\n", a);
}

முழு முதன்மை()
{
   charfunc('a');
   charfunc(98);
   charfunc(99.0);

   intfunc('a');
   intfunc(98);
   intfunc(99.0);

   floatfunc('a');
   floatfunc(98);
   floatfunc(99.0);

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   எழுத்து b = 97;
   எழுத்து c = 97.0;

   printf("%d %d\n", b, c);

   முழு d = 'a';
   முழு e = 97.0;

   printf("%d %d\n", d, e);

   தசம f = 'a';
   தசம g = 97;

   printf("%f %f\n", f, g);

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

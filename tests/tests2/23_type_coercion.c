#અન્તર્ભાવ <stdio.h>

શૂન્ય charfunc(અક્ષર a)
{
   printf("char: %c\n", a);
}

શૂન્ય intfunc(પૂર્ણાંક a)
{
   printf("int: %d\n", a);
}

શૂન્ય floatfunc(દશાંશ a)
{
   printf("float: %f\n", a);
}

પૂર્ણાંક મુખ્ય()
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

   અક્ષર b = 97;
   અક્ષર c = 97.0;

   printf("%d %d\n", b, c);

   પૂર્ણાંક d = 'a';
   પૂર્ણાંક e = 97.0;

   printf("%d %d\n", d, e);

   દશાંશ f = 'a';
   દશાંશ g = 97;

   printf("%f %f\n", f, g);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

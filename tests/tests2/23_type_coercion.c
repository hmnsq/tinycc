#شامل <stdio.h>

تهی charfunc(نویسه a)
{
   printf("char: %c\n", a);
}

تهی intfunc(صحیح a)
{
   printf("int: %d\n", a);
}

تهی floatfunc(اعشاری a)
{
   printf("float: %f\n", a);
}

صحیح اصلی()
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

   نویسه b = 97;
   نویسه c = 97.0;

   printf("%d %d\n", b, c);

   صحیح d = 'a';
   صحیح e = 97.0;

   printf("%d %d\n", d, e);

   اعشاری f = 'a';
   اعشاری g = 97;

   printf("%f %f\n", f, g);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

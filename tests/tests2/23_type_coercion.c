#شامل <stdio.h>

خالی charfunc(حرف a)
{
   لکھو("char: %c\n", a);
}

خالی intfunc(صحیح a)
{
   لکھو("int: %d\n", a);
}

خالی floatfunc(اعشاری a)
{
   لکھو("float: %f\n", a);
}

صحیح مین()
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

   حرف b = 97;
   حرف c = 97.0;

   لکھو("%d %d\n", b, c);

   صحیح d = 'a';
   صحیح e = 97.0;

   لکھو("%d %d\n", d, e);

   اعشاری f = 'a';
   اعشاری g = 97;

   لکھو("%f %f\n", f, g);

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

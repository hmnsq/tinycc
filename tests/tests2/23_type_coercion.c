#అన్తర్భావ <stdio.h>

శూన్య charfunc(అక్షరం a)
{
   రాయి("char: %c\n", a);
}

శూన్య intfunc(పూర్ణాంకం a)
{
   రాయి("int: %d\n", a);
}

శూన్య floatfunc(దశాంశం a)
{
   రాయి("float: %f\n", a);
}

పూర్ణాంకం ప్రధాన()
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

   అక్షరం b = 97;
   అక్షరం c = 97.0;

   రాయి("%d %d\n", b, c);

   పూర్ణాంకం d = 'a';
   పూర్ణాంకం e = 97.0;

   రాయి("%d %d\n", d, e);

   దశాంశం f = 'a';
   దశాంశం g = 97;

   రాయి("%f %f\n", f, g);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

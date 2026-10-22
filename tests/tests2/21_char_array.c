#అన్తర్భావ <stdio.h>

పూర్ణాంకం ప్రధాన()
{
   పూర్ణాంకం x = 'a';
   అక్షరం y = x;

   అక్షరం *a = "hello";

   రాయి("%s\n", a);

   పూర్ణాంకం c;
   c = *a;

   అక్షరం *b;
   కొరకు (b = a; *b != 0; b++)
      రాయి("%c: %d\n", *b, *b);

   అక్షరం destarray[10];
   అక్షరం *dest = &destarray[0];
   అక్షరం *src = a;

   అయితే (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   రాయి("copied string is %s\n", destarray);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা a;
   পূর্ণসংখ্যা *b;
   পূর্ণসংখ্যা *c;

   a = 42;
   b = &a;
   c = ফাঁকা;

   printf("%d\n", *b);

   যদি (b == ফাঁকা)
      printf("b is NULL\n");
   অন্যথা
      printf("b is not NULL\n");

   যদি (c == ফাঁকা)
      printf("c is NULL\n");
   অন্যথা
      printf("c is not NULL\n");

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

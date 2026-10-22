#include <stdio.h>

ចំនួនគត់ factorial(ចំនួនគត់ i) 
{
   ប្រសិនបើ (i < 2)
      ត្រឡប់ i;
   បើមិនដូច្នេះ
      ត្រឡប់ i * factorial(i - 1);
}

ចំនួនគត់ main()
{
   ចំនួនគត់ Count;

   សម្រាប់ (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

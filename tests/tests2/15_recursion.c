#include <stdio.h>

ကိန်းပြည့် factorial(ကိန်းပြည့် i) 
{
   အကယ်၍ (i < 2)
      ပြန်ပေး i;
   မဟုတ်ပါက
      ပြန်ပေး i * factorial(i - 1);
}

ကိန်းပြည့် main()
{
   ကိန်းပြည့် Count;

   အတွက် (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

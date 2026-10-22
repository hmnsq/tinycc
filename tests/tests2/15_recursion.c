#ضمن <stdio.h>

صحيح factorial(صحيح i) 
{
   إذا (i < 2)
      إرجاع i;
   وإلا
      إرجاع i * factorial(i - 1);
}

صحيح الرئيسية()
{
   صحيح تعداد_4;

   لكل (تعداد_4 = 1; تعداد_4 <= 10; تعداد_4++)
      printf("%d\n", factorial(تعداد_4));

   إرجاع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

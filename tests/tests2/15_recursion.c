#شامل <stdio.h>

صحیح factorial(صحیح i) 
{
   اگر (i < 2)
      بازگشت i;
   وگرنه
      بازگشت i * factorial(i - 1);
}

صحیح اصلی()
{
   صحیح شمار_3;

   برای (شمار_3 = 1; شمار_3 <= 10; شمار_3++)
      printf("%d\n", factorial(شمار_3));

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

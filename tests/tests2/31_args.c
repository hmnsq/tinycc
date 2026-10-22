#شامل <stdio.h>

صحیح اصلی(صحیح argc, نویسه **argv)
{
   صحیح شمار_3;

   printf("hello world %d\n", argc);
   برای (شمار_3 = 1; شمار_3 < argc; شمار_3++)
      printf("arg %d: %s\n", شمار_3, argv[شمار_3]);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

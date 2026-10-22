#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
   পূর্ণসংখ্যা গুনতি_3;

   printf("hello world %d\n", argc);
   জন্য (গুনতি_3 = 1; গুনতি_3 < argc; গুনতি_3++)
      printf("arg %d: %s\n", গুনতি_3, argv[গুনতি_3]);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

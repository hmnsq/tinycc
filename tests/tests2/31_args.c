#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{
   পূর্ণাঙ্ক গুনতি_3;

   printf("hello world %d\n", argc);
   প্রতি (গুনতি_3 = 1; গুনতি_3 < argc; গুনতি_3++)
      printf("arg %d: %s\n", গুনতি_3, argv[গুনতি_3]);

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

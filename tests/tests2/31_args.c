#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
   পূর্ণাঙ্ক গুনতি_3;

   printf("hello world %d\n", argc);
   বাবে (গুনতি_3 = 1; গুনতি_3 < argc; গুনতি_3++)
      printf("arg %d: %s\n", গুনতি_3, argv[গুনতি_3]);

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#অন্তর্ভাব <stdio.h>

শূন্য fred(পূর্ণসংখ্যা x)
{
   নির্বাচন (x)
   {
      ক্ষেত্র 1: printf("1\n"); ফেরত;
      ক্ষেত্র 2: printf("2\n"); বিরতি;
      ক্ষেত্র 3: printf("3\n"); ফেরত;
   }

   printf("out\n");
}

পূর্ণসংখ্যা প্রধান()
{
   fred(1);
   fred(2);
   fred(3);

   ফেরত 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

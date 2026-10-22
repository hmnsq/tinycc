#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা fred(পূর্ণসংখ্যা p)
{
   printf("yo %d\n", p);
   ফেরত 42;
}

পূর্ণসংখ্যা (*f)(পূর্ণসংখ্যা) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
পূর্ণসংখ্যা (*fprintfptr)(FILE *, ধ্রুবক অক্ষর *, ...) = &fprintf;

পূর্ণসংখ্যা প্রধান()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

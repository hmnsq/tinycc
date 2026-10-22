#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক fred(পূর্ণাঙ্ক p)
{
   printf("yo %d\n", p);
   ঘূৰাই 42;
}

পূর্ণাঙ্ক (*f)(পূর্ণাঙ্ক) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
পূর্ণাঙ্ক (*fprintfptr)(FILE *, ধ্রুৱ ৱর্ণ *, ...) = &fprintf;

পূর্ণাঙ্ক main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ঘূৰাই 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

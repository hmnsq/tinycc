#شامل <stdio.h>

صحیح fred(صحیح p)
{
   printf("yo %d\n", p);
   بازگشت 42;
}

صحیح (*f)(صحیح) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
صحیح (*fprintfptr)(FILE *, ثابت نویسه *, ...) = &fprintf;

صحیح اصلی()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#شامل <stdio.h>

صحیح fred(صحیح p)
{
   لکھو("yo %d\n", p);
   واپس 42;
}

صحیح (*f)(صحیح) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
صحیح (*fprintfptr)(FILE *, ثابت حرف *, ...) = &fprintf;

صحیح مین()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

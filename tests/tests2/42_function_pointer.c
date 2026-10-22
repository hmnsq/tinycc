#ضمن <stdio.h>

صحيح fred(صحيح p)
{
   printf("yo %d\n", p);
   أرجع 42;
}

صحيح (*f)(صحيح) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
صحيح (*fprintfptr)(FILE *, ثابت حرف *, ...) = &fprintf;

صحيح main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

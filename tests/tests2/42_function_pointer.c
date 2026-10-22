#అన్తర్భావ <stdio.h>

పూర్ణాంకం fred(పూర్ణాంకం p)
{
   రాయి("yo %d\n", p);
   తిరిగి 42;
}

పూర్ణాంకం (*f)(పూర్ణాంకం) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
పూర్ణాంకం (*fprintfptr)(FILE *, స్థిరరాశి అక్షరం *, ...) = &fprintf;

పూర్ణాంకం ప్రధాన()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

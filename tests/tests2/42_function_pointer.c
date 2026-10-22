#अन्तर्भाव <stdio.h>

पूर्णाङ्क fred(पूर्णाङ्क p)
{
   printf("yo %d\n", p);
   पटिनिवत्त 42;
}

पूर्णाङ्क (*f)(पूर्णाङ्क) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
पूर्णाङ्क (*fprintfptr)(FILE *, ध्रुव वर्ण *, ...) = &fprintf;

पूर्णाङ्क main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

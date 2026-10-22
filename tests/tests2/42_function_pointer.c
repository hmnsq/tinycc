#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ fred(ಪೂರ್ಣಾಙ್ಕ p)
{
   printf("yo %d\n", p);
   ಪ್ರತ್ಯಾಗಮ 42;
}

ಪೂರ್ಣಾಙ್ಕ (*f)(ಪೂರ್ಣಾಙ್ಕ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ಪೂರ್ಣಾಙ್ಕ (*fprintfptr)(FILE *, ಧ್ರುವ ವರ್ಣ *, ...) = &fprintf;

ಪೂರ್ಣಾಙ್ಕ main()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

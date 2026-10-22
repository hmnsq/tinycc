#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ fred(ಪೂರ್ಣಾಂಕ p)
{
   ಬರೆ("yo %d\n", p);
   ಹಿಂತಿರುಗಿ 42;
}

ಪೂರ್ಣಾಂಕ (*f)(ಪೂರ್ಣಾಂಕ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ಪೂರ್ಣಾಂಕ (*fprintfptr)(FILE *, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...) = &fprintf;

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

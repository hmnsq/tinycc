#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ fred(ਪੂਰਨ p)
{
   ਲਿਖੋ("yo %d\n", p);
   ਵਾਪਸ 42;
}

ਪੂਰਨ (*f)(ਪੂਰਨ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
ਪੂਰਨ (*fprintfptr)(FILE *, ਅਚਲ ਅੱਖਰ *, ...) = &fprintf;

ਪੂਰਨ ਮੁੱਖ()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

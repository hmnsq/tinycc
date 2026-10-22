#அந்தர்பாவ <stdio.h>

முழு fred(முழு p)
{
   printf("yo %d\n", p);
   திரும்பு 42;
}

முழு (*f)(முழு) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
முழு (*fprintfptr)(FILE *, மாறிலி எழுத்து *, ...) = &fprintf;

முழு முதன்மை()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

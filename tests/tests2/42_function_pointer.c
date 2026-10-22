#अन्तर्भाव <stdio.h>

पूर्णाङ्क fred(पूर्णाङ्क p)
{
   म_लिखो("yo %d\n", p);
   फर्काऊ 42;
}

पूर्णाङ्क (*f)(पूर्णाङ्क) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
पूर्णाङ्क (*fprintfptr)(खाता *, अचर वर्ण *, ...) = &ख_लिखो;

पूर्णाङ्क main()
{
   fprintfptr(मानक_निकास, "%d\n", (*f)(24));

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

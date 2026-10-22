#समावेश <stdio.h>

पूर्णांक fred(पूर्णांक p)
{
   म_लिखो("yo %d\n", p);
   वापस 42;
}

पूर्णांक (*f)(पूर्णांक) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
पूर्णांक (*fprintfptr)(खाता *, स्थिर अक्षर *, ...) = &ख_लिखो;

पूर्णांक मुख्य()
{
   fprintfptr(मानक_निकास, "%d\n", (*f)(24));

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

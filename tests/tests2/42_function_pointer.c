#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક fred(પૂર્ણાંક p)
{
   printf("yo %d\n", p);
   પાછા 42;
}

પૂર્ણાંક (*f)(પૂર્ણાંક) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
પૂર્ણાંક (*fprintfptr)(FILE *, અચલ અક્ષર *, ...) = &fprintf;

પૂર્ણાંક મુખ્ય()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

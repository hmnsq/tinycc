#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ fred(പൂർണ്ണസംഖ്യ p)
{
   printf("yo %d\n", p);
   തിരികെ 42;
}

പൂർണ്ണസംഖ്യ (*f)(പൂർണ്ണസംഖ്യ) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
പൂർണ്ണസംഖ്യ (*fprintfptr)(FILE *, സ്ഥിരം അക്ഷരം *, ...) = &fprintf;

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   fprintfptr(stdout, "%d\n", (*f)(24));

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

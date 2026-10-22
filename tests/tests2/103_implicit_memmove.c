/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ഘടന S { പൂർണ്ണസംഖ്യ a,b,c,d, e[1024];};
പൂർണ്ണസംഖ്യ foo (ഘടന S *a, ഘടന S *b)
{
  *a = *b;
  തിരികെ 0;
}

ശൂന്യം *memmove(ശൂന്യം*,സ്ഥിരം ശൂന്യം*,__SIZE_TYPE__);
ശൂന്യം foo2 (ഘടന S *a, ഘടന S *b)
{
  memmove(a, b, വലുപ്പം *a);
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
  തിരികെ 0;
}

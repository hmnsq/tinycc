/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
sa_nracanaa S { පූර්ණ_සංඛ්‍යා a,b,c,d, e[1024];};
පූර්ණ_සංඛ්‍යා foo (sa_nracanaa S *a, sa_nracanaa S *b)
{
  *a = *b;
  ආපසු 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (sa_nracanaa S *a, sa_nracanaa S *b)
{
  memmove(a, b, parimaa_na *a);
}

පූර්ණ_සංඛ්‍යා main()
{
  ආපසු 0;
}

/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
sa_nracanaa S { จำนวนเต็ม a,b,c,d, e[1024];};
จำนวนเต็ม foo (sa_nracanaa S *a, sa_nracanaa S *b)
{
  *a = *b;
  คืน 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (sa_nracanaa S *a, sa_nracanaa S *b)
{
  memmove(a, b, parimaa_na *a);
}

จำนวนเต็ม หลัก()
{
  คืน 0;
}

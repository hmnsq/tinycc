/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
sa_nracanaa S { ကိန်းပြည့် a,b,c,d, e[1024];};
ကိန်းပြည့် foo (sa_nracanaa S *a, sa_nracanaa S *b)
{
  *a = *b;
  ပြန်ပေး 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (sa_nracanaa S *a, sa_nracanaa S *b)
{
  memmove(a, b, parimaa_na *a);
}

ကိန်းပြည့် main()
{
  ပြန်ပေး 0;
}

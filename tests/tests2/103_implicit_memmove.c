/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
sa_nracanaa S { ཧྲིལ a,b,c,d, e[1024];};
ཧྲིལ foo (sa_nracanaa S *a, sa_nracanaa S *b)
{
  *a = *b;
  ཕྱིར 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (sa_nracanaa S *a, sa_nracanaa S *b)
{
  memmove(a, b, parimaa_na *a);
}

ཧྲིལ གཙོ()
{
  ཕྱིར 0;
}

/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
struct S { 整数 a,b,c,d, e[1024];};
整数 foo (struct S *a, struct S *b)
{
  *a = *b;
  戻る 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (struct S *a, struct S *b)
{
  memmove(a, b, sizeof *a);
}

整数 メインページ()
{
  戻る 0;
}

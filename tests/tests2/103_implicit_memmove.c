/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
struct S { 정수 a,b,c,d, e[1024];};
정수 foo (struct S *a, struct S *b)
{
  *a = *b;
  반환 0;
}

void *memmove(void*,const void*,__SIZE_TYPE__);
void foo2 (struct S *a, struct S *b)
{
  memmove(a, b, sizeof *a);
}

정수 main()
{
  반환 0;
}

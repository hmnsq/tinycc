/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ساختار S { صحیح a,b,c,d, e[1024];};
صحیح foo (ساختار S *a, ساختار S *b)
{
  *a = *b;
  بازگشت 0;
}

تهی *memmove(تهی*,ثابت تهی*,__SIZE_TYPE__);
تهی foo2 (ساختار S *a, ساختار S *b)
{
  memmove(a, b, اندازه *a);
}

صحیح اصلی()
{
  بازگشت 0;
}

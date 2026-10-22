/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ساخت S { صحیح a,b,c,d, e[1024];};
صحیح foo (ساخت S *a, ساخت S *b)
{
  *a = *b;
  واپس 0;
}

خالی *memmove(خالی*,ثابت خالی*,__SIZE_TYPE__);
خالی foo2 (ساخت S *a, ساخت S *b)
{
  memmove(a, b, حجم *a);
}

صحیح مین()
{
  واپس 0;
}

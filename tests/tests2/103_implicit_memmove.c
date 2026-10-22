/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
بنية S { صحيح a,b,c,d, e[1024];};
صحيح foo (بنية S *a, بنية S *b)
{
  *a = *b;
  أرجع 0;
}

فراغ *memmove(فراغ*,ثابت فراغ*,__SIZE_TYPE__);
فراغ foo2 (بنية S *a, بنية S *b)
{
  memmove(a, b, حجم *a);
}

صحيح main()
{
  أرجع 0;
}

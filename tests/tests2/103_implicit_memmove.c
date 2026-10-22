/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
কাঠামো S { পূর্ণসংখ্যা a,b,c,d, e[1024];};
পূর্ণসংখ্যা foo (কাঠামো S *a, কাঠামো S *b)
{
  *a = *b;
  ফেরত 0;
}

শূন্য *memmove(শূন্য*,ধ্রুবক শূন্য*,__SIZE_TYPE__);
শূন্য foo2 (কাঠামো S *a, কাঠামো S *b)
{
  memmove(a, b, আকার *a);
}

পূর্ণসংখ্যা প্রধান()
{
  ফেরত 0;
}

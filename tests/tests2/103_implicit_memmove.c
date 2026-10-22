/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
সংরচনা S { পূর্ণাঙ্ক a,b,c,d, e[1024];};
পূর্ণাঙ্ক foo (সংরচনা S *a, সংরচনা S *b)
{
  *a = *b;
  প্রত্যাগম 0;
}

শূন্য *memmove(শূন্য*,ধ্রুব শূন্য*,__SIZE_TYPE__);
শূন্য foo2 (সংরচনা S *a, সংরচনা S *b)
{
  memmove(a, b, পরিমাণ *a);
}

পূর্ণাঙ্ক main()
{
  প্রত্যাগম 0;
}

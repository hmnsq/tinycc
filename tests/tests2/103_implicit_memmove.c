/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
ਬਣਤਰ S { ਪੂਰਨ a,b,c,d, e[1024];};
ਪੂਰਨ foo (ਬਣਤਰ S *a, ਬਣਤਰ S *b)
{
  *a = *b;
  ਵਾਪਸ 0;
}

ਖਾਲੀ *memmove(ਖਾਲੀ*,ਅਚਲ ਖਾਲੀ*,__SIZE_TYPE__);
ਖਾਲੀ foo2 (ਬਣਤਰ S *a, ਬਣਤਰ S *b)
{
  memmove(a, b, ਆਕਾਰ *a);
}

ਪੂਰਨ ਮੁੱਖ()
{
  ਵਾਪਸ 0;
}

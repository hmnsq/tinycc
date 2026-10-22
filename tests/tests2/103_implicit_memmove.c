/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
સંરચના S { પૂર્ણાંક a,b,c,d, e[1024];};
પૂર્ણાંક foo (સંરચના S *a, સંરચના S *b)
{
  *a = *b;
  પાછા 0;
}

શૂન્ય *memmove(શૂન્ય*,અચલ શૂન્ય*,__SIZE_TYPE__);
શૂન્ય foo2 (સંરચના S *a, સંરચના S *b)
{
  memmove(a, b, કદ *a);
}

પૂર્ણાંક મુખ્ય()
{
  પાછા 0;
}

/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
கட்டமைப்பு S { முழு a,b,c,d, e[1024];};
முழு foo (கட்டமைப்பு S *a, கட்டமைப்பு S *b)
{
  *a = *b;
  திரும்பு 0;
}

வெறுமை *memmove(வெறுமை*,மாறிலி வெறுமை*,__SIZE_TYPE__);
வெறுமை foo2 (கட்டமைப்பு S *a, கட்டமைப்பு S *b)
{
  memmove(a, b, அளவு *a);
}

முழு முதன்மை()
{
  திரும்பு 0;
}

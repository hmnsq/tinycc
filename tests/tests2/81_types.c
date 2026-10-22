/* The following are all valid decls, even though some subtypes
   are incomplete.  */
ਗਿਣਤੀ E *e;
ਅਚਲ ਗਿਣਤੀ E *e1;
ਗਿਣਤੀ E ਅਚਲ *e2;
ਬਣਤਰ S *s;
ਅਚਲ ਬਣਤਰ S *s1;
ਬਣਤਰ S ਅਚਲ *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr1)();
ਪੂਰਨ f1 (ਪੂਰਨ (), ਪੂਰਨ);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr2)(ਪੂਰਨ x);
ਪੂਰਨ f2 (ਪੂਰਨ (ਪੂਰਨ x), ਪੂਰਨ);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr3)(ਪੂਰਨ);
ਪੂਰਨ f3 (ਪੂਰਨ (ਪੂਰਨ), ਪੂਰਨ);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr4[4])(ਪੂਰਨ);
ਪੂਰਨ f4 (ਪੂਰਨ (*[4])(ਪੂਰਨ), ਪੂਰਨ);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr5)(fptr1);
ਪੂਰਨ f5 (ਪੂਰਨ (ਪੂਰਨ()), fptr1);
ਪੂਰਨ f1 (fptr1 fp, ਪੂਰਨ i)
{
  ਵਾਪਸ (*fp)(i);
}
ਪੂਰਨ f2 (fptr2 fp, ਪੂਰਨ i)
{
  ਵਾਪਸ (*fp)(i);
}
ਪੂਰਨ f3 (fptr3 fp, ਪੂਰਨ i)
{
  ਵਾਪਸ (*fp)(i);
}
ਪੂਰਨ f4 (fptr4 fp, ਪੂਰਨ i)
{
  ਵਾਪਸ (*fp[i])(i);
}
ਪੂਰਨ f5 (fptr5 fp, fptr1 i)
{
  ਵਾਪਸ fp(i);
}
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ intx4[4];
ਪੂਰਨ f8 (intx4, ਪੂਰਨ);
ਪੂਰਨ f8 (ਪੂਰਨ ([4]), ਪੂਰਨ);
ਪੂਰਨ f8 (ਪੂਰਨ y[4], ਪੂਰਨ i)
{
  ਵਾਪਸ y[i];
}
ਪੂਰਨ f9 (ਪੂਰਨ (*)(ਪੂਰਨ), ਪੂਰਨ);
ਪੂਰਨ f9 (ਪੂਰਨ ((ਪੂਰਨ)), ਪੂਰਨ);
ਪੂਰਨ f9 (ਪੂਰਨ f(ਪੂਰਨ), ਪੂਰਨ i)
{
  ਵਾਪਸ f(i);
}
ਪੂਰਨ ਮੁੱਖ () { ਵਾਪਸ 0; }

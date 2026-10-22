/* The following are all valid decls, even though some subtypes
   are incomplete.  */
ga_nanaa E *e;
const ga_nanaa E *e1;
ga_nanaa E const *e2;
sa_nracanaa S *s;
const sa_nracanaa S *s1;
sa_nracanaa S const *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
typedef ចំនួនគត់ (*fptr1)();
ចំនួនគត់ f1 (ចំនួនគត់ (), ចំនួនគត់);
typedef ចំនួនគត់ (*fptr2)(ចំនួនគត់ x);
ចំនួនគត់ f2 (ចំនួនគត់ (ចំនួនគត់ x), ចំនួនគត់);
typedef ចំនួនគត់ (*fptr3)(ចំនួនគត់);
ចំនួនគត់ f3 (ចំនួនគត់ (ចំនួនគត់), ចំនួនគត់);
typedef ចំនួនគត់ (*fptr4[4])(ចំនួនគត់);
ចំនួនគត់ f4 (ចំនួនគត់ (*[4])(ចំនួនគត់), ចំនួនគត់);
typedef ចំនួនគត់ (*fptr5)(fptr1);
ចំនួនគត់ f5 (ចំនួនគត់ (ចំនួនគត់()), fptr1);
ចំនួនគត់ f1 (fptr1 fp, ចំនួនគត់ i)
{
  ត្រឡប់ (*fp)(i);
}
ចំនួនគត់ f2 (fptr2 fp, ចំនួនគត់ i)
{
  ត្រឡប់ (*fp)(i);
}
ចំនួនគត់ f3 (fptr3 fp, ចំនួនគត់ i)
{
  ត្រឡប់ (*fp)(i);
}
ចំនួនគត់ f4 (fptr4 fp, ចំនួនគត់ i)
{
  ត្រឡប់ (*fp[i])(i);
}
ចំនួនគត់ f5 (fptr5 fp, fptr1 i)
{
  ត្រឡប់ fp(i);
}
typedef ចំនួនគត់ intx4[4];
ចំនួនគត់ f8 (intx4, ចំនួនគត់);
ចំនួនគត់ f8 (ចំនួនគត់ ([4]), ចំនួនគត់);
ចំនួនគត់ f8 (ចំនួនគត់ y[4], ចំនួនគត់ i)
{
  ត្រឡប់ y[i];
}
ចំនួនគត់ f9 (ចំនួនគត់ (*)(ចំនួនគត់), ចំនួនគត់);
ចំនួនគត់ f9 (ចំនួនគត់ ((ចំនួនគត់)), ចំនួនគត់);
ចំនួនគត់ f9 (ចំនួនគត់ f(ចំនួនគត់), ចំនួនគត់ i)
{
  ត្រឡប់ f(i);
}
ចំនួនគត់ main () { ត្រឡប់ 0; }

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
typedef ຈຳນວນເຕັມ (*fptr1)();
ຈຳນວນເຕັມ f1 (ຈຳນວນເຕັມ (), ຈຳນວນເຕັມ);
typedef ຈຳນວນເຕັມ (*fptr2)(ຈຳນວນເຕັມ x);
ຈຳນວນເຕັມ f2 (ຈຳນວນເຕັມ (ຈຳນວນເຕັມ x), ຈຳນວນເຕັມ);
typedef ຈຳນວນເຕັມ (*fptr3)(ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f3 (ຈຳນວນເຕັມ (ຈຳນວນເຕັມ), ຈຳນວນເຕັມ);
typedef ຈຳນວນເຕັມ (*fptr4[4])(ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f4 (ຈຳນວນເຕັມ (*[4])(ຈຳນວນເຕັມ), ຈຳນວນເຕັມ);
typedef ຈຳນວນເຕັມ (*fptr5)(fptr1);
ຈຳນວນເຕັມ f5 (ຈຳນວນເຕັມ (ຈຳນວນເຕັມ()), fptr1);
ຈຳນວນເຕັມ f1 (fptr1 fp, ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ (*fp)(i);
}
ຈຳນວນເຕັມ f2 (fptr2 fp, ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ (*fp)(i);
}
ຈຳນວນເຕັມ f3 (fptr3 fp, ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ (*fp)(i);
}
ຈຳນວນເຕັມ f4 (fptr4 fp, ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ (*fp[i])(i);
}
ຈຳນວນເຕັມ f5 (fptr5 fp, fptr1 i)
{
  ສົ່ງຄືນ fp(i);
}
typedef ຈຳນວນເຕັມ intx4[4];
ຈຳນວນເຕັມ f8 (intx4, ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f8 (ຈຳນວນເຕັມ ([4]), ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f8 (ຈຳນວນເຕັມ y[4], ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ y[i];
}
ຈຳນວນເຕັມ f9 (ຈຳນວນເຕັມ (*)(ຈຳນວນເຕັມ), ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f9 (ຈຳນວນເຕັມ ((ຈຳນວນເຕັມ)), ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ f9 (ຈຳນວນເຕັມ f(ຈຳນວນເຕັມ), ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ f(i);
}
ຈຳນວນເຕັມ main () { ສົ່ງຄືນ 0; }

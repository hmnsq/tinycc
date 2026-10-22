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
typedef ཧྲིལ (*fptr1)();
ཧྲིལ f1 (ཧྲིལ (), ཧྲིལ);
typedef ཧྲིལ (*fptr2)(ཧྲིལ x);
ཧྲིལ f2 (ཧྲིལ (ཧྲིལ x), ཧྲིལ);
typedef ཧྲིལ (*fptr3)(ཧྲིལ);
ཧྲིལ f3 (ཧྲིལ (ཧྲིལ), ཧྲིལ);
typedef ཧྲིལ (*fptr4[4])(ཧྲིལ);
ཧྲིལ f4 (ཧྲིལ (*[4])(ཧྲིལ), ཧྲིལ);
typedef ཧྲིལ (*fptr5)(fptr1);
ཧྲིལ f5 (ཧྲིལ (ཧྲིལ()), fptr1);
ཧྲིལ f1 (fptr1 fp, ཧྲིལ i)
{
  ཕྱིར (*fp)(i);
}
ཧྲིལ f2 (fptr2 fp, ཧྲིལ i)
{
  ཕྱིར (*fp)(i);
}
ཧྲིལ f3 (fptr3 fp, ཧྲིལ i)
{
  ཕྱིར (*fp)(i);
}
ཧྲིལ f4 (fptr4 fp, ཧྲིལ i)
{
  ཕྱིར (*fp[i])(i);
}
ཧྲིལ f5 (fptr5 fp, fptr1 i)
{
  ཕྱིར fp(i);
}
typedef ཧྲིལ intx4[4];
ཧྲིལ f8 (intx4, ཧྲིལ);
ཧྲིལ f8 (ཧྲིལ ([4]), ཧྲིལ);
ཧྲིལ f8 (ཧྲིལ y[4], ཧྲིལ i)
{
  ཕྱིར y[i];
}
ཧྲིལ f9 (ཧྲིལ (*)(ཧྲིལ), ཧྲིལ);
ཧྲིལ f9 (ཧྲིལ ((ཧྲིལ)), ཧྲིལ);
ཧྲིལ f9 (ཧྲིལ f(ཧྲིལ), ཧྲིལ i)
{
  ཕྱིར f(i);
}
ཧྲིལ གཙོ () { ཕྱིར 0; }

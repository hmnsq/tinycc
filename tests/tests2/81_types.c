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
typedef puur_naa_nka (*fptr1)();
puur_naa_nka f1 (puur_naa_nka (), puur_naa_nka);
typedef puur_naa_nka (*fptr2)(puur_naa_nka x);
puur_naa_nka f2 (puur_naa_nka (puur_naa_nka x), puur_naa_nka);
typedef puur_naa_nka (*fptr3)(puur_naa_nka);
puur_naa_nka f3 (puur_naa_nka (puur_naa_nka), puur_naa_nka);
typedef puur_naa_nka (*fptr4[4])(puur_naa_nka);
puur_naa_nka f4 (puur_naa_nka (*[4])(puur_naa_nka), puur_naa_nka);
typedef puur_naa_nka (*fptr5)(fptr1);
puur_naa_nka f5 (puur_naa_nka (puur_naa_nka()), fptr1);
puur_naa_nka f1 (fptr1 fp, puur_naa_nka i)
{
  ပွၵ်ႈ (*fp)(i);
}
puur_naa_nka f2 (fptr2 fp, puur_naa_nka i)
{
  ပွၵ်ႈ (*fp)(i);
}
puur_naa_nka f3 (fptr3 fp, puur_naa_nka i)
{
  ပွၵ်ႈ (*fp)(i);
}
puur_naa_nka f4 (fptr4 fp, puur_naa_nka i)
{
  ပွၵ်ႈ (*fp[i])(i);
}
puur_naa_nka f5 (fptr5 fp, fptr1 i)
{
  ပွၵ်ႈ fp(i);
}
typedef puur_naa_nka intx4[4];
puur_naa_nka f8 (intx4, puur_naa_nka);
puur_naa_nka f8 (puur_naa_nka ([4]), puur_naa_nka);
puur_naa_nka f8 (puur_naa_nka y[4], puur_naa_nka i)
{
  ပွၵ်ႈ y[i];
}
puur_naa_nka f9 (puur_naa_nka (*)(puur_naa_nka), puur_naa_nka);
puur_naa_nka f9 (puur_naa_nka ((puur_naa_nka)), puur_naa_nka);
puur_naa_nka f9 (puur_naa_nka f(puur_naa_nka), puur_naa_nka i)
{
  ပွၵ်ႈ f(i);
}
puur_naa_nka main () { ပွၵ်ႈ 0; }

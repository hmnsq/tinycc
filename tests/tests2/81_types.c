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
typedef ကိန်းပြည့် (*fptr1)();
ကိန်းပြည့် f1 (ကိန်းပြည့် (), ကိန်းပြည့်);
typedef ကိန်းပြည့် (*fptr2)(ကိန်းပြည့် x);
ကိန်းပြည့် f2 (ကိန်းပြည့် (ကိန်းပြည့် x), ကိန်းပြည့်);
typedef ကိန်းပြည့် (*fptr3)(ကိန်းပြည့်);
ကိန်းပြည့် f3 (ကိန်းပြည့် (ကိန်းပြည့်), ကိန်းပြည့်);
typedef ကိန်းပြည့် (*fptr4[4])(ကိန်းပြည့်);
ကိန်းပြည့် f4 (ကိန်းပြည့် (*[4])(ကိန်းပြည့်), ကိန်းပြည့်);
typedef ကိန်းပြည့် (*fptr5)(fptr1);
ကိန်းပြည့် f5 (ကိန်းပြည့် (ကိန်းပြည့်()), fptr1);
ကိန်းပြည့် f1 (fptr1 fp, ကိန်းပြည့် i)
{
  ပြန်ပေး (*fp)(i);
}
ကိန်းပြည့် f2 (fptr2 fp, ကိန်းပြည့် i)
{
  ပြန်ပေး (*fp)(i);
}
ကိန်းပြည့် f3 (fptr3 fp, ကိန်းပြည့် i)
{
  ပြန်ပေး (*fp)(i);
}
ကိန်းပြည့် f4 (fptr4 fp, ကိန်းပြည့် i)
{
  ပြန်ပေး (*fp[i])(i);
}
ကိန်းပြည့် f5 (fptr5 fp, fptr1 i)
{
  ပြန်ပေး fp(i);
}
typedef ကိန်းပြည့် intx4[4];
ကိန်းပြည့် f8 (intx4, ကိန်းပြည့်);
ကိန်းပြည့် f8 (ကိန်းပြည့် ([4]), ကိန်းပြည့်);
ကိန်းပြည့် f8 (ကိန်းပြည့် y[4], ကိန်းပြည့် i)
{
  ပြန်ပေး y[i];
}
ကိန်းပြည့် f9 (ကိန်းပြည့် (*)(ကိန်းပြည့်), ကိန်းပြည့်);
ကိန်းပြည့် f9 (ကိန်းပြည့် ((ကိန်းပြည့်)), ကိန်းပြည့်);
ကိန်းပြည့် f9 (ကိန်းပြည့် f(ကိန်းပြည့်), ကိန်းပြည့် i)
{
  ပြန်ပေး f(i);
}
ကိန်းပြည့် main () { ပြန်ပေး 0; }

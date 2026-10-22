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
typedef จำนวนเต็ม (*fptr1)();
จำนวนเต็ม f1 (จำนวนเต็ม (), จำนวนเต็ม);
typedef จำนวนเต็ม (*fptr2)(จำนวนเต็ม x);
จำนวนเต็ม f2 (จำนวนเต็ม (จำนวนเต็ม x), จำนวนเต็ม);
typedef จำนวนเต็ม (*fptr3)(จำนวนเต็ม);
จำนวนเต็ม f3 (จำนวนเต็ม (จำนวนเต็ม), จำนวนเต็ม);
typedef จำนวนเต็ม (*fptr4[4])(จำนวนเต็ม);
จำนวนเต็ม f4 (จำนวนเต็ม (*[4])(จำนวนเต็ม), จำนวนเต็ม);
typedef จำนวนเต็ม (*fptr5)(fptr1);
จำนวนเต็ม f5 (จำนวนเต็ม (จำนวนเต็ม()), fptr1);
จำนวนเต็ม f1 (fptr1 fp, จำนวนเต็ม i)
{
  คืน (*fp)(i);
}
จำนวนเต็ม f2 (fptr2 fp, จำนวนเต็ม i)
{
  คืน (*fp)(i);
}
จำนวนเต็ม f3 (fptr3 fp, จำนวนเต็ม i)
{
  คืน (*fp)(i);
}
จำนวนเต็ม f4 (fptr4 fp, จำนวนเต็ม i)
{
  คืน (*fp[i])(i);
}
จำนวนเต็ม f5 (fptr5 fp, fptr1 i)
{
  คืน fp(i);
}
typedef จำนวนเต็ม intx4[4];
จำนวนเต็ม f8 (intx4, จำนวนเต็ม);
จำนวนเต็ม f8 (จำนวนเต็ม ([4]), จำนวนเต็ม);
จำนวนเต็ม f8 (จำนวนเต็ม y[4], จำนวนเต็ม i)
{
  คืน y[i];
}
จำนวนเต็ม f9 (จำนวนเต็ม (*)(จำนวนเต็ม), จำนวนเต็ม);
จำนวนเต็ม f9 (จำนวนเต็ม ((จำนวนเต็ม)), จำนวนเต็ม);
จำนวนเต็ม f9 (จำนวนเต็ม f(จำนวนเต็ม), จำนวนเต็ม i)
{
  คืน f(i);
}
จำนวนเต็ม หลัก () { คืน 0; }

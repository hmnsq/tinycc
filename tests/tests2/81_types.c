/* The following are all valid decls, even though some subtypes
   are incomplete.  */
تعداد E *e;
ثابت تعداد E *e1;
تعداد E ثابت *e2;
بنية S *s;
ثابت بنية S *s1;
بنية S ثابت *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
تعريفنوع صحيح (*fptr1)();
صحيح f1 (صحيح (), صحيح);
تعريفنوع صحيح (*fptr2)(صحيح x);
صحيح f2 (صحيح (صحيح x), صحيح);
تعريفنوع صحيح (*fptr3)(صحيح);
صحيح f3 (صحيح (صحيح), صحيح);
تعريفنوع صحيح (*fptr4[4])(صحيح);
صحيح f4 (صحيح (*[4])(صحيح), صحيح);
تعريفنوع صحيح (*fptr5)(fptr1);
صحيح f5 (صحيح (صحيح()), fptr1);
صحيح f1 (fptr1 fp, صحيح i)
{
  أرجع (*fp)(i);
}
صحيح f2 (fptr2 fp, صحيح i)
{
  أرجع (*fp)(i);
}
صحيح f3 (fptr3 fp, صحيح i)
{
  أرجع (*fp)(i);
}
صحيح f4 (fptr4 fp, صحيح i)
{
  أرجع (*fp[i])(i);
}
صحيح f5 (fptr5 fp, fptr1 i)
{
  أرجع fp(i);
}
تعريفنوع صحيح intx4[4];
صحيح f8 (intx4, صحيح);
صحيح f8 (صحيح ([4]), صحيح);
صحيح f8 (صحيح y[4], صحيح i)
{
  أرجع y[i];
}
صحيح f9 (صحيح (*)(صحيح), صحيح);
صحيح f9 (صحيح ((صحيح)), صحيح);
صحيح f9 (صحيح f(صحيح), صحيح i)
{
  أرجع f(i);
}
صحيح مکھ () { أرجع 0; }

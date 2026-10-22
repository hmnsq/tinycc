/* The following are all valid decls, even though some subtypes
   are incomplete.  */
شمارش E *e;
ثابت شمارش E *e1;
شمارش E ثابت *e2;
ساختار S *s;
ثابت ساختار S *s1;
ساختار S ثابت *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
تعریفنوع صحیح (*fptr1)();
صحیح f1 (صحیح (), صحیح);
تعریفنوع صحیح (*fptr2)(صحیح x);
صحیح f2 (صحیح (صحیح x), صحیح);
تعریفنوع صحیح (*fptr3)(صحیح);
صحیح f3 (صحیح (صحیح), صحیح);
تعریفنوع صحیح (*fptr4[4])(صحیح);
صحیح f4 (صحیح (*[4])(صحیح), صحیح);
تعریفنوع صحیح (*fptr5)(fptr1);
صحیح f5 (صحیح (صحیح()), fptr1);
صحیح f1 (fptr1 fp, صحیح i)
{
  بازگشت (*fp)(i);
}
صحیح f2 (fptr2 fp, صحیح i)
{
  بازگشت (*fp)(i);
}
صحیح f3 (fptr3 fp, صحیح i)
{
  بازگشت (*fp)(i);
}
صحیح f4 (fptr4 fp, صحیح i)
{
  بازگشت (*fp[i])(i);
}
صحیح f5 (fptr5 fp, fptr1 i)
{
  بازگشت fp(i);
}
تعریفنوع صحیح intx4[4];
صحیح f8 (intx4, صحیح);
صحیح f8 (صحیح ([4]), صحیح);
صحیح f8 (صحیح y[4], صحیح i)
{
  بازگشت y[i];
}
صحیح f9 (صحیح (*)(صحیح), صحیح);
صحیح f9 (صحیح ((صحیح)), صحیح);
صحیح f9 (صحیح f(صحیح), صحیح i)
{
  بازگشت f(i);
}
صحیح اصلی () { بازگشت 0; }

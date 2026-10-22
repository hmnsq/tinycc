/* The following are all valid decls, even though some subtypes
   are incomplete.  */
شمار E *e;
ثابت شمار E *e1;
شمار E ثابت *e2;
ساخت S *s;
ثابت ساخت S *s1;
ساخت S ثابت *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
قسمتعریف صحیح (*fptr1)();
صحیح f1 (صحیح (), صحیح);
قسمتعریف صحیح (*fptr2)(صحیح x);
صحیح f2 (صحیح (صحیح x), صحیح);
قسمتعریف صحیح (*fptr3)(صحیح);
صحیح f3 (صحیح (صحیح), صحیح);
قسمتعریف صحیح (*fptr4[4])(صحیح);
صحیح f4 (صحیح (*[4])(صحیح), صحیح);
قسمتعریف صحیح (*fptr5)(fptr1);
صحیح f5 (صحیح (صحیح()), fptr1);
صحیح f1 (fptr1 fp, صحیح i)
{
  واپس (*fp)(i);
}
صحیح f2 (fptr2 fp, صحیح i)
{
  واپس (*fp)(i);
}
صحیح f3 (fptr3 fp, صحیح i)
{
  واپس (*fp)(i);
}
صحیح f4 (fptr4 fp, صحیح i)
{
  واپس (*fp[i])(i);
}
صحیح f5 (fptr5 fp, fptr1 i)
{
  واپس fp(i);
}
قسمتعریف صحیح intx4[4];
صحیح f8 (intx4, صحیح);
صحیح f8 (صحیح ([4]), صحیح);
صحیح f8 (صحیح y[4], صحیح i)
{
  واپس y[i];
}
صحیح f9 (صحیح (*)(صحیح), صحیح);
صحیح f9 (صحیح ((صحیح)), صحیح);
صحیح f9 (صحیح f(صحیح), صحیح i)
{
  واپس f(i);
}
صحیح مین () { واپس 0; }

/* The following are all valid decls, even though some subtypes
   are incomplete.  */
enum E *e;
const enum E *e1;
enum E const *e2;
struct S *s;
const struct S *s1;
struct S const *s2;

/* Various strangely looking declarators, which are all valid
   and have to map to the same numbered typedefs. */
typedef số_nguyên (*fptr1)();
số_nguyên f1 (số_nguyên (), số_nguyên);
typedef số_nguyên (*fptr2)(số_nguyên x);
số_nguyên f2 (số_nguyên (số_nguyên x), số_nguyên);
typedef số_nguyên (*fptr3)(số_nguyên);
số_nguyên f3 (số_nguyên (số_nguyên), số_nguyên);
typedef số_nguyên (*fptr4[4])(số_nguyên);
số_nguyên f4 (số_nguyên (*[4])(số_nguyên), số_nguyên);
typedef số_nguyên (*fptr5)(fptr1);
số_nguyên f5 (số_nguyên (số_nguyên()), fptr1);
số_nguyên f1 (fptr1 fp, số_nguyên i)
{
  trả_về (*fp)(i);
}
số_nguyên f2 (fptr2 fp, số_nguyên i)
{
  trả_về (*fp)(i);
}
số_nguyên f3 (fptr3 fp, số_nguyên i)
{
  trả_về (*fp)(i);
}
số_nguyên f4 (fptr4 fp, số_nguyên i)
{
  trả_về (*fp[i])(i);
}
số_nguyên f5 (fptr5 fp, fptr1 i)
{
  trả_về fp(i);
}
typedef số_nguyên intx4[4];
số_nguyên f8 (intx4, số_nguyên);
số_nguyên f8 (số_nguyên ([4]), số_nguyên);
số_nguyên f8 (số_nguyên y[4], số_nguyên i)
{
  trả_về y[i];
}
số_nguyên f9 (số_nguyên (*)(số_nguyên), số_nguyên);
số_nguyên f9 (số_nguyên ((số_nguyên)), số_nguyên);
số_nguyên f9 (số_nguyên f(số_nguyên), số_nguyên i)
{
  trả_về f(i);
}
số_nguyên main () { trả_về 0; }

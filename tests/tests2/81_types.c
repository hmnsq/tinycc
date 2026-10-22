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
typedef ціле (*fptr1)();
ціле f1 (ціле (), ціле);
typedef ціле (*fptr2)(ціле x);
ціле f2 (ціле (ціле x), ціле);
typedef ціле (*fptr3)(ціле);
ціле f3 (ціле (ціле), ціле);
typedef ціле (*fptr4[4])(ціле);
ціле f4 (ціле (*[4])(ціле), ціле);
typedef ціле (*fptr5)(fptr1);
ціле f5 (ціле (ціле()), fptr1);
ціле f1 (fptr1 fp, ціле i)
{
  повернути (*fp)(i);
}
ціле f2 (fptr2 fp, ціле i)
{
  повернути (*fp)(i);
}
ціле f3 (fptr3 fp, ціле i)
{
  повернути (*fp)(i);
}
ціле f4 (fptr4 fp, ціле i)
{
  повернути (*fp[i])(i);
}
ціле f5 (fptr5 fp, fptr1 i)
{
  повернути fp(i);
}
typedef ціле intx4[4];
ціле f8 (intx4, ціле);
ціле f8 (ціле ([4]), ціле);
ціле f8 (ціле y[4], ціле i)
{
  повернути y[i];
}
ціле f9 (ціле (*)(ціле), ціле);
ціле f9 (ціле ((ціле)), ціле);
ціле f9 (ціле f(ціле), ціле i)
{
  повернути f(i);
}
ціле main () { повернути 0; }

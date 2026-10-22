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
typedef цео (*fptr1)();
цео f1 (цео (), цео);
typedef цео (*fptr2)(цео x);
цео f2 (цео (цео x), цео);
typedef цео (*fptr3)(цео);
цео f3 (цео (цео), цео);
typedef цео (*fptr4[4])(цео);
цео f4 (цео (*[4])(цео), цео);
typedef цео (*fptr5)(fptr1);
цео f5 (цео (цео()), fptr1);
цео f1 (fptr1 fp, цео i)
{
  врати (*fp)(i);
}
цео f2 (fptr2 fp, цео i)
{
  врати (*fp)(i);
}
цео f3 (fptr3 fp, цео i)
{
  врати (*fp)(i);
}
цео f4 (fptr4 fp, цео i)
{
  врати (*fp[i])(i);
}
цео f5 (fptr5 fp, fptr1 i)
{
  врати fp(i);
}
typedef цео intx4[4];
цео f8 (intx4, цео);
цео f8 (цео ([4]), цео);
цео f8 (цео y[4], цео i)
{
  врати y[i];
}
цео f9 (цео (*)(цео), цео);
цео f9 (цео ((цео)), цео);
цео f9 (цео f(цео), цео i)
{
  врати f(i);
}
цео main () { врати 0; }

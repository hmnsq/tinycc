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
typedef 정수 (*fptr1)();
정수 f1 (정수 (), 정수);
typedef 정수 (*fptr2)(정수 x);
정수 f2 (정수 (정수 x), 정수);
typedef 정수 (*fptr3)(정수);
정수 f3 (정수 (정수), 정수);
typedef 정수 (*fptr4[4])(정수);
정수 f4 (정수 (*[4])(정수), 정수);
typedef 정수 (*fptr5)(fptr1);
정수 f5 (정수 (정수()), fptr1);
정수 f1 (fptr1 fp, 정수 i)
{
  반환 (*fp)(i);
}
정수 f2 (fptr2 fp, 정수 i)
{
  반환 (*fp)(i);
}
정수 f3 (fptr3 fp, 정수 i)
{
  반환 (*fp)(i);
}
정수 f4 (fptr4 fp, 정수 i)
{
  반환 (*fp[i])(i);
}
정수 f5 (fptr5 fp, fptr1 i)
{
  반환 fp(i);
}
typedef 정수 intx4[4];
정수 f8 (intx4, 정수);
정수 f8 (정수 ([4]), 정수);
정수 f8 (정수 y[4], 정수 i)
{
  반환 y[i];
}
정수 f9 (정수 (*)(정수), 정수);
정수 f9 (정수 ((정수)), 정수);
정수 f9 (정수 f(정수), 정수 i)
{
  반환 f(i);
}
정수 main () { 반환 0; }

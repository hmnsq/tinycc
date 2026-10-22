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
typedef 整数 (*fptr1)();
整数 f1 (整数 (), 整数);
typedef 整数 (*fptr2)(整数 x);
整数 f2 (整数 (整数 x), 整数);
typedef 整数 (*fptr3)(整数);
整数 f3 (整数 (整数), 整数);
typedef 整数 (*fptr4[4])(整数);
整数 f4 (整数 (*[4])(整数), 整数);
typedef 整数 (*fptr5)(fptr1);
整数 f5 (整数 (整数()), fptr1);
整数 f1 (fptr1 fp, 整数 i)
{
  戻る (*fp)(i);
}
整数 f2 (fptr2 fp, 整数 i)
{
  戻る (*fp)(i);
}
整数 f3 (fptr3 fp, 整数 i)
{
  戻る (*fp)(i);
}
整数 f4 (fptr4 fp, 整数 i)
{
  戻る (*fp[i])(i);
}
整数 f5 (fptr5 fp, fptr1 i)
{
  戻る fp(i);
}
typedef 整数 intx4[4];
整数 f8 (intx4, 整数);
整数 f8 (整数 ([4]), 整数);
整数 f8 (整数 y[4], 整数 i)
{
  戻る y[i];
}
整数 f9 (整数 (*)(整数), 整数);
整数 f9 (整数 ((整数)), 整数);
整数 f9 (整数 f(整数), 整数 i)
{
  戻る f(i);
}
整数 メインページ () { 戻る 0; }

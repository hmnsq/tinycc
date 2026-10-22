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
typedef целое (*fptr1)();
целое f1 (целое (), целое);
typedef целое (*fptr2)(целое x);
целое f2 (целое (целое x), целое);
typedef целое (*fptr3)(целое);
целое f3 (целое (целое), целое);
typedef целое (*fptr4[4])(целое);
целое f4 (целое (*[4])(целое), целое);
typedef целое (*fptr5)(fptr1);
целое f5 (целое (целое()), fptr1);
целое f1 (fptr1 fp, целое i)
{
  вернуть (*fp)(i);
}
целое f2 (fptr2 fp, целое i)
{
  вернуть (*fp)(i);
}
целое f3 (fptr3 fp, целое i)
{
  вернуть (*fp)(i);
}
целое f4 (fptr4 fp, целое i)
{
  вернуть (*fp[i])(i);
}
целое f5 (fptr5 fp, fptr1 i)
{
  вернуть fp(i);
}
typedef целое intx4[4];
целое f8 (intx4, целое);
целое f8 (целое ([4]), целое);
целое f8 (целое y[4], целое i)
{
  вернуть y[i];
}
целое f9 (целое (*)(целое), целое);
целое f9 (целое ((целое)), целое);
целое f9 (целое f(целое), целое i)
{
  вернуть f(i);
}
целое основной () { вернуть 0; }

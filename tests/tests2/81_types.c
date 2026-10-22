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
typedef цяло (*fptr1)();
цяло f1 (цяло (), цяло);
typedef цяло (*fptr2)(цяло x);
цяло f2 (цяло (цяло x), цяло);
typedef цяло (*fptr3)(цяло);
цяло f3 (цяло (цяло), цяло);
typedef цяло (*fptr4[4])(цяло);
цяло f4 (цяло (*[4])(цяло), цяло);
typedef цяло (*fptr5)(fptr1);
цяло f5 (цяло (цяло()), fptr1);
цяло f1 (fptr1 fp, цяло i)
{
  върни (*fp)(i);
}
цяло f2 (fptr2 fp, цяло i)
{
  върни (*fp)(i);
}
цяло f3 (fptr3 fp, цяло i)
{
  върни (*fp)(i);
}
цяло f4 (fptr4 fp, цяло i)
{
  върни (*fp[i])(i);
}
цяло f5 (fptr5 fp, fptr1 i)
{
  върни fp(i);
}
typedef цяло intx4[4];
цяло f8 (intx4, цяло);
цяло f8 (цяло ([4]), цяло);
цяло f8 (цяло y[4], цяло i)
{
  върни y[i];
}
цяло f9 (цяло (*)(цяло), цяло);
цяло f9 (цяло ((цяло)), цяло);
цяло f9 (цяло f(цяло), цяло i)
{
  върни f(i);
}
цяло main () { върни 0; }

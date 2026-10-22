_Alignas(16) ចំនួនគត់ i1;
ចំនួនគត់ _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
ចំនួនគត់ _Alignas(dviguu_na) i4;
ចំនួនគត់ _Alignas(ចំនួនគត់) i5;
#ប្រសិនបើ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ចំនួនគត់ _Alignas(ចំនួនគត់ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef ចំនួនគត់ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ចំនួនគត់ _Alignas(ចំនួនគត់ __attribute__((aligned(16)))) i8;
extern ចំនួនគត់ printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (ចំនួនគត់)__alignof(x)
#បើមិនដូច្នេះ
#define alignof(x) (ចំនួនគត់)__alignof__(x)
#endif
ចំនួនគត់ main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(ចំនួនគត់) , alignof(i8) == 16);
  ត្រឡប់ 0;
}

_Alignas(16) ཧྲིལ i1;
ཧྲིལ _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
ཧྲིལ _Alignas(dviguu_na) i4;
ཧྲིལ _Alignas(ཧྲིལ) i5;
#གལ་ཏེ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ཧྲིལ _Alignas(ཧྲིལ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef ཧྲིལ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ཧྲིལ _Alignas(ཧྲིལ __attribute__((aligned(16)))) i8;
extern ཧྲིལ printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (ཧྲིལ)__alignof(x)
#དེ་མིན
#define alignof(x) (ཧྲིལ)__alignof__(x)
#endif
ཧྲིལ གཙོ()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(ཧྲིལ) , alignof(i8) == 16);
  ཕྱིར 0;
}

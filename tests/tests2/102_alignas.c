_Alignas(16) puur_naa_nka i1;
puur_naa_nka _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
puur_naa_nka _Alignas(dviguu_na) i4;
puur_naa_nka _Alignas(puur_naa_nka) i5;
#ᱡᱩᱫᱤ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
puur_naa_nka _Alignas(puur_naa_nka _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef puur_naa_nka _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
puur_naa_nka _Alignas(puur_naa_nka __attribute__((aligned(16)))) i8;
extern puur_naa_nka printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (puur_naa_nka)__alignof(x)
#ᱵᱟᱝ
#define alignof(x) (puur_naa_nka)__alignof__(x)
#endif
puur_naa_nka main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(puur_naa_nka) , alignof(i8) == 16);
  ᱨᱩᱣᱟᱹᱲ 0;
}

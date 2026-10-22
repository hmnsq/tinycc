_Alignas(16) පූර්ණ_සංඛ්‍යා i1;
පූර්ණ_සංඛ්‍යා _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
පූර්ණ_සංඛ්‍යා _Alignas(dviguu_na) i4;
පූර්ණ_සංඛ්‍යා _Alignas(පූර්ණ_සංඛ්‍යා) i5;
#නම් 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
පූර්ණ_සංඛ්‍යා _Alignas(පූර්ණ_සංඛ්‍යා _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef පූර්ණ_සංඛ්‍යා _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
පූර්ණ_සංඛ්‍යා _Alignas(පූර්ණ_සංඛ්‍යා __attribute__((aligned(16)))) i8;
extern පූර්ණ_සංඛ්‍යා printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (පූර්ණ_සංඛ්‍යා)__alignof(x)
#නැතහොත්
#define alignof(x) (පූර්ණ_සංඛ්‍යා)__alignof__(x)
#endif
පූර්ණ_සංඛ්‍යා main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(පූර්ණ_සංඛ්‍යා) , alignof(i8) == 16);
  ආපසු 0;
}

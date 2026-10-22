_Alignas(16) ကိန်းပြည့် i1;
ကိန်းပြည့် _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
ကိန်းပြည့် _Alignas(dviguu_na) i4;
ကိန်းပြည့် _Alignas(ကိန်းပြည့်) i5;
#အကယ်၍ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ကိန်းပြည့် _Alignas(ကိန်းပြည့် _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef ကိန်းပြည့် _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ကိန်းပြည့် _Alignas(ကိန်းပြည့် __attribute__((aligned(16)))) i8;
extern ကိန်းပြည့် printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (ကိန်းပြည့်)__alignof(x)
#မဟုတ်ပါက
#define alignof(x) (ကိန်းပြည့်)__alignof__(x)
#endif
ကိန်းပြည့် main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(ကိန်းပြည့်) , alignof(i8) == 16);
  ပြန်ပေး 0;
}

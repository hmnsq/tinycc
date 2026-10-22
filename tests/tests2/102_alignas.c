_Alignas(16) จำนวนเต็ม i1;
จำนวนเต็ม _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
จำนวนเต็ม _Alignas(dviguu_na) i4;
จำนวนเต็ม _Alignas(จำนวนเต็ม) i5;
#ถ้า 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
จำนวนเต็ม _Alignas(จำนวนเต็ม _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef จำนวนเต็ม _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
จำนวนเต็ม _Alignas(จำนวนเต็ม __attribute__((aligned(16)))) i8;
extern จำนวนเต็ม printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (จำนวนเต็ม)__alignof(x)
#มิฉะนั้น
#define alignof(x) (จำนวนเต็ม)__alignof__(x)
#endif
จำนวนเต็ม หลัก()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(จำนวนเต็ม) , alignof(i8) == 16);
  คืน 0;
}

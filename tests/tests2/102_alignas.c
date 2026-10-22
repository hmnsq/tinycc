_Alignas(16) ціле i1;
ціле _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
ціле _Alignas(double) i4;
ціле _Alignas(ціле) i5;
#якщо 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ціле _Alignas(ціле _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef ціле _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ціле _Alignas(ціле __attribute__((aligned(16)))) i8;
extern ціле printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (ціле)__alignof(x)
#інакше
#define alignof(x) (ціле)__alignof__(x)
#endif
ціле main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(ціле) , alignof(i8) == 16);
  повернути 0;
}

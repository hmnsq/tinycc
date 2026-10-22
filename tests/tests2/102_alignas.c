_Alignas(16) целое i1;
целое _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
целое _Alignas(double) i4;
целое _Alignas(целое) i5;
#если 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
целое _Alignas(целое _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef целое _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
целое _Alignas(целое __attribute__((aligned(16)))) i8;
extern целое printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (целое)__alignof(x)
#иначе
#define alignof(x) (целое)__alignof__(x)
#endif
целое основной()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(целое) , alignof(i8) == 16);
  вернуть 0;
}

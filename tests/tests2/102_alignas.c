_Alignas(16) 정수 i1;
정수 _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
정수 _Alignas(double) i4;
정수 _Alignas(정수) i5;
#만약 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
정수 _Alignas(정수 _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef 정수 _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
정수 _Alignas(정수 __attribute__((aligned(16)))) i8;
extern 정수 printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (정수)__alignof(x)
#아니면
#define alignof(x) (정수)__alignof__(x)
#endif
정수 main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(정수) , alignof(i8) == 16);
  반환 0;
}

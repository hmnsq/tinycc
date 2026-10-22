_Alignas(16) 整数 i1;
整数 _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
整数 _Alignas(double) i4;
整数 _Alignas(整数) i5;
#もし 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
整数 _Alignas(整数 _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef 整数 _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
整数 _Alignas(整数 __attribute__((aligned(16)))) i8;
extern 整数 printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (整数)__alignof(x)
#否则
#define alignof(x) (整数)__alignof__(x)
#endif
整数 メインページ()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(整数) , alignof(i8) == 16);
  戻る 0;
}

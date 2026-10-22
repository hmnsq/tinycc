_Alignas(16) số_nguyên i1;
số_nguyên _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
số_nguyên _Alignas(double) i4;
số_nguyên _Alignas(số_nguyên) i5;
#nếu 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
số_nguyên _Alignas(số_nguyên _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef số_nguyên _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
số_nguyên _Alignas(số_nguyên __attribute__((aligned(16)))) i8;
extern số_nguyên printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (số_nguyên)__alignof(x)
#không_thì
#define alignof(x) (số_nguyên)__alignof__(x)
#endif
số_nguyên main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(số_nguyên) , alignof(i8) == 16);
  trả_về 0;
}

_Alignas(16) цео i1;
цео _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
цео _Alignas(double) i4;
цео _Alignas(цео) i5;
#ако 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
цео _Alignas(цео _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef цео _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
цео _Alignas(цео __attribute__((aligned(16)))) i8;
extern цео printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (цео)__alignof(x)
#инако
#define alignof(x) (цео)__alignof__(x)
#endif
цео main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(цео) , alignof(i8) == 16);
  врати 0;
}

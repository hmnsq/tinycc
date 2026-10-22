_Alignas(16) цяло i1;
цяло _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
цяло _Alignas(double) i4;
цяло _Alignas(цяло) i5;
#ако 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
цяло _Alignas(цяло _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef цяло _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
цяло _Alignas(цяло __attribute__((aligned(16)))) i8;
extern цяло printf(const char*, ...);
#ifdef _MSC_VER
#define alignof(x) (цяло)__alignof(x)
#иначе
#define alignof(x) (цяло)__alignof__(x)
#endif
цяло main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(double),
         alignof(i5) == alignof(цяло) , alignof(i8) == 16);
  върни 0;
}

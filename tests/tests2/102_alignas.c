_Alignas(16) முழு i1;
முழு _Alignas(16) i2;
வெறுமை _Alignas(16) *p2;
_Alignas(16) i3;
முழு _Alignas(இரட்டை) i4;
முழு _Alignas(முழு) i5;
#எனில் 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
முழு _Alignas(முழு _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
வகைவரை முழு _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
முழு _Alignas(முழு __attribute__((aligned(16)))) i8;
வெளி முழு printf(மாறிலி எழுத்து*, ...);
#ifdef _MSC_VER
#define alignof(x) (முழு)__alignof(x)
#இல்லையெனில்
#define alignof(x) (முழு)__alignof__(x)
#endif
முழு முதன்மை()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(இரட்டை),
         alignof(i5) == alignof(முழு) , alignof(i8) == 16);
  திரும்பு 0;
}

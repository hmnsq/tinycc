_Alignas(16) صحيح i1;
صحيح _Alignas(16) i2;
فراغ _Alignas(16) *p2;
_Alignas(16) i3;
صحيح _Alignas(مزدوج) i4;
صحيح _Alignas(صحيح) i5;
#إذا 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
صحيح _Alignas(صحيح _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
تعريفنوع صحيح _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
صحيح _Alignas(صحيح __attribute__((aligned(16)))) i8;
خارجي صحيح printf(ثابت حرف*, ...);
#ifdef _MSC_VER
#define alignof(x) (صحيح)__alignof(x)
#وإلا
#define alignof(x) (صحيح)__alignof__(x)
#endif
صحيح الرئيسية()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(مزدوج),
         alignof(i5) == alignof(صحيح) , alignof(i8) == 16);
  إرجاع 0;
}

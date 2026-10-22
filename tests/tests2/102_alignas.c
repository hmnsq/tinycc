_Alignas(16) صحیح i1;
صحیح _Alignas(16) i2;
تهی _Alignas(16) *p2;
_Alignas(16) i3;
صحیح _Alignas(دوگانه) i4;
صحیح _Alignas(صحیح) i5;
#اگر 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
صحیح _Alignas(صحیح _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
تعریفنوع صحیح _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
صحیح _Alignas(صحیح __attribute__((aligned(16)))) i8;
بیرونی صحیح printf(ثابت نویسه*, ...);
#ifdef _MSC_VER
#define alignof(x) (صحیح)__alignof(x)
#وگرنه
#define alignof(x) (صحیح)__alignof__(x)
#endif
صحیح اصلی()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(دوگانه),
         alignof(i5) == alignof(صحیح) , alignof(i8) == 16);
  بازگشت 0;
}

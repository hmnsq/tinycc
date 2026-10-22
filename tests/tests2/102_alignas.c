_Alignas(16) পূর্ণসংখ্যা i1;
পূর্ণসংখ্যা _Alignas(16) i2;
শূন্য _Alignas(16) *p2;
_Alignas(16) i3;
পূর্ণসংখ্যা _Alignas(দ্বিগুণ) i4;
পূর্ণসংখ্যা _Alignas(পূর্ণসংখ্যা) i5;
#যদি 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
পূর্ণসংখ্যা _Alignas(পূর্ণসংখ্যা _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
প্রকারলেখ পূর্ণসংখ্যা _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
পূর্ণসংখ্যা _Alignas(পূর্ণসংখ্যা __attribute__((aligned(16)))) i8;
বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);
#ifdef _MSC_VER
#define alignof(x) (পূর্ণসংখ্যা)__alignof(x)
#অন্যথা
#define alignof(x) (পূর্ণসংখ্যা)__alignof__(x)
#endif
পূর্ণসংখ্যা প্রধান()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(দ্বিগুণ),
         alignof(i5) == alignof(পূর্ণসংখ্যা) , alignof(i8) == 16);
  ফেরত 0;
}

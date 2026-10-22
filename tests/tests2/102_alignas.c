_Alignas(16) पूर्णाङ्क i1;
पूर्णाङ्क _Alignas(16) i2;
शून्य _Alignas(16) *p2;
_Alignas(16) i3;
पूर्णाङ्क _Alignas(द्विगुण) i4;
पूर्णाङ्क _Alignas(पूर्णाङ्क) i5;
#जइ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
पूर्णाङ्क _Alignas(पूर्णाङ्क _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
प्रकारनिर्देश पूर्णाङ्क _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
पूर्णाङ्क _Alignas(पूर्णाङ्क __attribute__((aligned(16)))) i8;
बाह्य पूर्णाङ्क printf(ध्रुव वर्ण*, ...);
#ifdef _MSC_VER
#define alignof(x) (पूर्णाङ्क)__alignof(x)
#अण्णहा
#define alignof(x) (पूर्णाङ्क)__alignof__(x)
#endif
पूर्णाङ्क main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(द्विगुण),
         alignof(i5) == alignof(पूर्णाङ्क) , alignof(i8) == 16);
  प्रत्यागम 0;
}

_Alignas(16) पूर्णांक i1;
पूर्णांक _Alignas(16) i2;
शून्य _Alignas(16) *p2;
_Alignas(16) i3;
पूर्णांक _Alignas(द्विगुण) i4;
पूर्णांक _Alignas(पूर्णांक) i5;
#जर 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
पूर्णांक _Alignas(पूर्णांक _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
प्रकारव्याख्या पूर्णांक _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
पूर्णांक _Alignas(पूर्णांक __attribute__((aligned(16)))) i8;
बाह्य पूर्णांक म_लिखो(स्थिरांक अक्षर*, ...);
#ifdef _MSC_VER
#define alignof(x) (पूर्णांक)__alignof(x)
#अन्यथा
#define alignof(x) (पूर्णांक)__alignof__(x)
#endif
पूर्णांक main()
{
  म_लिखो("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(द्विगुण),
         alignof(i5) == alignof(पूर्णांक) , alignof(i8) == 16);
  परत 0;
}

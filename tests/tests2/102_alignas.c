_Alignas(16) पूर्णांक i1;
पूर्णांक _Alignas(16) i2;
व्योम _Alignas(16) *p2;
_Alignas(16) i3;
पूर्णांक _Alignas(द्विगुन) i4;
पूर्णांक _Alignas(पूर्णांक) i5;
#अगर 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
पूर्णांक _Alignas(पूर्णांक _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
प्रकार पूर्णांक _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#पूर्ण_अगर
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
पूर्णांक _Alignas(पूर्णांक __attribute__((aligned(16)))) i8;
बाह्य पूर्णांक म_लिखो(स्थिर अक्षर*, ...);
#अगर_घोषित _MSC_VER
#घोषणा alignof(x) (पूर्णांक)__alignof(x)
#अन्यथा
#घोषणा alignof(x) (पूर्णांक)__alignof__(x)
#पूर्ण_अगर
पूर्णांक मुख्य()
{
  म_लिखो("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(द्विगुन),
         alignof(i5) == alignof(पूर्णांक) , alignof(i8) == 16);
  वापस 0;
}

_Alignas(16) પૂર્ણાંક i1;
પૂર્ણાંક _Alignas(16) i2;
શૂન્ય _Alignas(16) *p2;
_Alignas(16) i3;
પૂર્ણાંક _Alignas(દ્વિગુણ) i4;
પૂર્ણાંક _Alignas(પૂર્ણાંક) i5;
#જો 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
પૂર્ણાંક _Alignas(પૂર્ણાંક _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
પ્રકારવ્યાખ્યા પૂર્ણાંક _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
પૂર્ણાંક _Alignas(પૂર્ણાંક __attribute__((aligned(16)))) i8;
બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર*, ...);
#ifdef _MSC_VER
#define alignof(x) (પૂર્ણાંક)__alignof(x)
#નહીંતર
#define alignof(x) (પૂર્ણાંક)__alignof__(x)
#endif
પૂર્ણાંક મુખ્ય()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(દ્વિગુણ),
         alignof(i5) == alignof(પૂર્ણાંક) , alignof(i8) == 16);
  પાછા 0;
}

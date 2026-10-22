_Alignas(16) പൂർണ്ണസംഖ്യ i1;
പൂർണ്ണസംഖ്യ _Alignas(16) i2;
ശൂന്യം _Alignas(16) *p2;
_Alignas(16) i3;
പൂർണ്ണസംഖ്യ _Alignas(ഇരട്ട) i4;
പൂർണ്ണസംഖ്യ _Alignas(പൂർണ്ണസംഖ്യ) i5;
#എങ്കിൽ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
പൂർണ്ണസംഖ്യ _Alignas(പൂർണ്ണസംഖ്യ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
തരനിർവചനം പൂർണ്ണസംഖ്യ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
പൂർണ്ണസംഖ്യ _Alignas(പൂർണ്ണസംഖ്യ __attribute__((aligned(16)))) i8;
ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);
#ifdef _MSC_VER
#define alignof(x) (പൂർണ്ണസംഖ്യ)__alignof(x)
#അല്ലെങ്കിൽ
#define alignof(x) (പൂർണ്ണസംഖ്യ)__alignof__(x)
#endif
പൂർണ്ണസംഖ്യ പ്രധാന()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ഇരട്ട),
         alignof(i5) == alignof(പൂർണ്ണസംഖ്യ) , alignof(i8) == 16);
  തിരികെ 0;
}

_Alignas(16) ਪੂਰਨ i1;
ਪੂਰਨ _Alignas(16) i2;
ਖਾਲੀ _Alignas(16) *p2;
_Alignas(16) i3;
ਪੂਰਨ _Alignas(ਦੁੱਗਣਾ) i4;
ਪੂਰਨ _Alignas(ਪੂਰਨ) i5;
#ਜੇ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ਪੂਰਨ _Alignas(ਪੂਰਨ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#ਜੇ_ਅੰਤ
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ਪੂਰਨ _Alignas(ਪੂਰਨ __attribute__((aligned(16)))) i8;
ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*, ...);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSC_VER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ alignof(x) (ਪੂਰਨ)__alignof(x)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ alignof(x) (ਪੂਰਨ)__alignof__(x)
#ਜੇ_ਅੰਤ
ਪੂਰਨ ਮੁੱਖ()
{
  ਲਿਖੋ("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ਦੁੱਗਣਾ),
         alignof(i5) == alignof(ਪੂਰਨ) , alignof(i8) == 16);
  ਵਾਪਸ 0;
}

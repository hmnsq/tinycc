_Alignas(16) ಪೂರ್ಣಾಂಕ i1;
ಪೂರ್ಣಾಂಕ _Alignas(16) i2;
ಶೂನ್ಯ _Alignas(16) *p2;
_Alignas(16) i3;
ಪೂರ್ಣಾಂಕ _Alignas(ದ್ವಿಗುಣ) i4;
ಪೂರ್ಣಾಂಕ _Alignas(ಪೂರ್ಣಾಂಕ) i5;
#ಆದರೆ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ಪೂರ್ಣಾಂಕ _Alignas(ಪೂರ್ಣಾಂಕ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#ಆದರೆ_ಅಂತ್ಯ
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ಪೂರ್ಣಾಂಕ _Alignas(ಪೂರ್ಣಾಂಕ __attribute__((aligned(16)))) i8;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSC_VER
#ವ್ಯಾಖ್ಯಾನಿಸು alignof(x) (ಪೂರ್ಣಾಂಕ)__alignof(x)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು alignof(x) (ಪೂರ್ಣಾಂಕ)__alignof__(x)
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
  ಬರೆ("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ದ್ವಿಗುಣ),
         alignof(i5) == alignof(ಪೂರ್ಣಾಂಕ) , alignof(i8) == 16);
  ಹಿಂತಿರುಗಿ 0;
}

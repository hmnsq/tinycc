_Alignas(16) ಪೂರ್ಣಾಙ್ಕ i1;
ಪೂರ್ಣಾಙ್ಕ _Alignas(16) i2;
ಶೂನ್ಯ _Alignas(16) *p2;
_Alignas(16) i3;
ಪೂರ್ಣಾಙ್ಕ _Alignas(ದ್ವಿಗುಣ) i4;
ಪೂರ್ಣಾಙ್ಕ _Alignas(ಪೂರ್ಣಾಙ್ಕ) i5;
#ಯದಿ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ಪೂರ್ಣಾಙ್ಕ _Alignas(ಪೂರ್ಣಾಙ್ಕ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ಪೂರ್ಣಾಙ್ಕ _Alignas(ಪೂರ್ಣಾಙ್ಕ __attribute__((aligned(16)))) i8;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);
#ifdef _MSC_VER
#define alignof(x) (ಪೂರ್ಣಾಙ್ಕ)__alignof(x)
#ಅನ್ಯಥಾ
#define alignof(x) (ಪೂರ್ಣಾಙ್ಕ)__alignof__(x)
#endif
ಪೂರ್ಣಾಙ್ಕ main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ದ್ವಿಗುಣ),
         alignof(i5) == alignof(ಪೂರ್ಣಾಙ್ಕ) , alignof(i8) == 16);
  ಪ್ರತ್ಯಾಗಮ 0;
}

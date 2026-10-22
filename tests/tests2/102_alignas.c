_Alignas(16) ପୂର୍ଣ୍ଣସଂଖ୍ୟା i1;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(16) i2;
ଶୂନ୍ୟ _Alignas(16) *p2;
_Alignas(16) i3;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(ଦ୍ୱିଗୁଣ) i4;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) i5;
#ଯଦି 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Alignas(ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((aligned(16)))) i8;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);
#ifdef _MSC_VER
#define alignof(x) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)__alignof(x)
#ଅନ୍ୟଥା
#define alignof(x) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)__alignof__(x)
#endif
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ଦ୍ୱିଗୁଣ),
         alignof(i5) == alignof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) , alignof(i8) == 16);
  ଫେରନ୍ତୁ 0;
}

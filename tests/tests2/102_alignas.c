_Alignas(16) పూర్ణాంకం i1;
పూర్ణాంకం _Alignas(16) i2;
శూన్య _Alignas(16) *p2;
_Alignas(16) i3;
పూర్ణాంకం _Alignas(ద్విగుణ) i4;
పూర్ణాంకం _Alignas(పూర్ణాంకం) i5;
#ఒకవేళ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
పూర్ణాంకం _Alignas(పూర్ణాంకం _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
రకనిర్వచనం పూర్ణాంకం _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#అయితే_ముగింపు
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
పూర్ణాంకం _Alignas(పూర్ణాంకం __attribute__((aligned(16)))) i8;
బాహ్య పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం*, ...);
#నిర్వచితమైతే _MSC_VER
#నిర్వచించు alignof(x) (పూర్ణాంకం)__alignof(x)
#లేకపోతే
#నిర్వచించు alignof(x) (పూర్ణాంకం)__alignof__(x)
#అయితే_ముగింపు
పూర్ణాంకం ప్రధాన()
{
  రాయి("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(ద్విగుణ),
         alignof(i5) == alignof(పూర్ణాంకం) , alignof(i8) == 16);
  తిరిగి 0;
}

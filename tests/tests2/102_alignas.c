_Alignas(16) পূর্ণাঙ্ক i1;
পূর্ণাঙ্ক _Alignas(16) i2;
শূন্য _Alignas(16) *p2;
_Alignas(16) i3;
পূর্ণাঙ্ক _Alignas(দ্ৱিগুণ) i4;
পূর্ণাঙ্ক _Alignas(পূর্ণাঙ্ক) i5;
#যদি 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
পূর্ণাঙ্ক _Alignas(পূর্ণাঙ্ক _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
প্রকারনির্দেশ পূর্ণাঙ্ক _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
পূর্ণাঙ্ক _Alignas(পূর্ণাঙ্ক __attribute__((aligned(16)))) i8;
বাহ্য পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ*, ...);
#ifdef _MSC_VER
#define alignof(x) (পূর্ণাঙ্ক)__alignof(x)
#অন্যথা
#define alignof(x) (পূর্ণাঙ্ক)__alignof__(x)
#endif
পূর্ণাঙ্ক main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(দ্ৱিগুণ),
         alignof(i5) == alignof(পূর্ণাঙ্ক) , alignof(i8) == 16);
  ঘূৰাই 0;
}

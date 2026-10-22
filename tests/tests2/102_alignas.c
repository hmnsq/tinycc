_Alignas(16) ຈຳນວນເຕັມ i1;
ຈຳນວນເຕັມ _Alignas(16) i2;
void _Alignas(16) *p2;
_Alignas(16) i3;
ຈຳນວນເຕັມ _Alignas(dviguu_na) i4;
ຈຳນວນເຕັມ _Alignas(ຈຳນວນເຕັມ) i5;
#ຖ້າ 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
ຈຳນວນເຕັມ _Alignas(ຈຳນວນເຕັມ _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
typedef ຈຳນວນເຕັມ _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#endif
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
ຈຳນວນເຕັມ _Alignas(ຈຳນວນເຕັມ __attribute__((aligned(16)))) i8;
extern ຈຳນວນເຕັມ printf(const var_na*, ...);
#ifdef _MSC_VER
#define alignof(x) (ຈຳນວນເຕັມ)__alignof(x)
#ບໍ່ດັ່ງນັ້ນ
#define alignof(x) (ຈຳນວນເຕັມ)__alignof__(x)
#endif
ຈຳນວນເຕັມ main()
{
  printf("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(dviguu_na),
         alignof(i5) == alignof(ຈຳນວນເຕັມ) , alignof(i8) == 16);
  ສົ່ງຄືນ 0;
}

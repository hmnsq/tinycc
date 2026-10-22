_Alignas(16) صحیح i1;
صحیح _Alignas(16) i2;
خالی _Alignas(16) *p2;
_Alignas(16) i3;
صحیح _Alignas(دوہرا) i4;
صحیح _Alignas(صحیح) i5;
#اگر 0
/* The following are currently wrongly accepted by TCC but really shouldn't.  */
صحیح _Alignas(صحیح _Alignas(16)) i6; //wrong, 'int _Alignas(16)' is no type-name
قسمتعریف صحیح _Alignas(16) int16aligned_t; //wrong, _Alignas invalid on typedef
int16aligned_t i7;
#اگر_ختم
/* i8 should get an alignment of 16, because unlike _Alignas the
   corresponding attribute _does_ apply to type-name, though not in
   some clang versions.  */
صحیح _Alignas(صحیح __attribute__((aligned(16)))) i8;
خارجی صحیح لکھو(ثابت حرف*, ...);
#اگر_تعریف_شدہ _MSC_VER
#تعریف_کرو alignof(x) (صحیح)__alignof(x)
#ورنہ
#تعریف_کرو alignof(x) (صحیح)__alignof__(x)
#اگر_ختم
صحیح مین()
{
  لکھو("%d %d %d %d\n",
         alignof(i1) == 16, alignof(i4) == alignof(دوہرا),
         alignof(i5) == alignof(صحیح) , alignof(i8) == 16);
  واپس 0;
}

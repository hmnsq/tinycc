تهی foo(صحیح [5]);
تهی fooc(صحیح x[ثابت 5]);
تهی foos(صحیح x[ایستا 5]);
تهی foov(صحیح x[فرار 5]);
تهی foor(صحیح x[restrict 5]);
تهی fooc(صحیح [ثابت 5]);
تهی foos(صحیح [ایستا 5]);
تهی foov(صحیح [فرار 5]);
تهی foor(صحیح [restrict 5]);
تهی fooc(صحیح (* ثابت x));
تهی foos(صحیح *x);
تهی foov(صحیح * فرار x);
تهی foor(صحیح * restrict x);
تهی fooc(صحیح x[فرار 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
تهی foovm(صحیح x[ثابت *]);
تهی foovm(صحیح * ثابت x);

تعریفنوع صحیح *pointer_array[2];
تعریفنوع صحیح *restrict restricted_pointer;
تعریفنوع restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(صحیح **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
صحیح **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
تهی wrongc(صحیح x[3][ثابت 4]);
تهی wrongvm(صحیح x[ایستا *]);
تهی foovm(صحیح x[ثابت *])
{
  x[2] = 1;
}
#endif
صحیح اصلی()
{
  بازگشت 0;
}

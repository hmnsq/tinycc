فراغ foo(صحيح [5]);
فراغ fooc(صحيح x[ثابت 5]);
فراغ foos(صحيح x[ساكن 5]);
فراغ foov(صحيح x[متطاير 5]);
فراغ foor(صحيح x[restrict 5]);
فراغ fooc(صحيح [ثابت 5]);
فراغ foos(صحيح [ساكن 5]);
فراغ foov(صحيح [متطاير 5]);
فراغ foor(صحيح [restrict 5]);
فراغ fooc(صحيح (* ثابت x));
فراغ foos(صحيح *x);
فراغ foov(صحيح * متطاير x);
فراغ foor(صحيح * restrict x);
فراغ fooc(صحيح x[متطاير 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
فراغ foovm(صحيح x[ثابت *]);
فراغ foovm(صحيح * ثابت x);

تعريفنوع صحيح *pointer_array[2];
تعريفنوع صحيح *restrict restricted_pointer;
تعريفنوع restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(صحيح **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
صحيح **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
فراغ wrongc(صحيح x[3][ثابت 4]);
فراغ wrongvm(صحيح x[ساكن *]);
فراغ foovm(صحيح x[ثابت *])
{
  x[2] = 1;
}
#endif
صحيح main()
{
  أرجع 0;
}

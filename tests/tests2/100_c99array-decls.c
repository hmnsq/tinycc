فراغ foo(صحيح [5]);
فراغ fooc(صحيح x[ثابت 5]);
فراغ foos(صحيح x[ساكن 5]);
فراغ foov(صحيح x[متطاير 5]);
فراغ foor(صحيح x[محدود 5]);
فراغ fooc(صحيح [ثابت 5]);
فراغ foos(صحيح [ساكن 5]);
فراغ foov(صحيح [متطاير 5]);
فراغ foor(صحيح [محدود 5]);
فراغ fooc(صحيح (* ثابت x));
فراغ foos(صحيح *x);
فراغ foov(صحيح * متطاير x);
فراغ foor(صحيح * محدود x);
فراغ fooc(صحيح x[متطاير 5])
{
  x[3] = 42;
#اگر_تعریف_شده INVALID
  x = 0;
#پایان_اگر
}
فراغ foovm(صحيح x[ثابت *]);
فراغ foovm(صحيح * ثابت x);

تعريفنوع صحيح *اشاره_گر_array[2];
تعريفنوع صحيح *محدود restricted_اشاره_گر;
تعريفنوع محدود اشاره_گر_array restricted_اشاره_گر_array;

_Static_assert(!__builtin_types_compatible_p(صحيح **,
                                             restricted_اشاره_گر *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_اشاره_گر_array,
                                            restricted_اشاره_گر[2]),
               "restrict can qualify an array of pointer types");

restricted_اشاره_گر *restricted_pp;
صحيح **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_اشاره_گر *),
               "conditional expression combines restrict qualifiers");

#اگر_تعریف_شده INVALID
فراغ wrongc(صحيح x[3][ثابت 4]);
فراغ wrongvm(صحيح x[ساكن *]);
فراغ foovm(صحيح x[ثابت *])
{
  x[2] = 1;
}
#پایان_اگر
صحيح اصلی()
{
  أرجع 0;
}

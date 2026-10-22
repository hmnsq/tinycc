خالی foo(صحیح [5]);
خالی fooc(صحیح x[ثابت 5]);
خالی foos(صحیح x[ساکن 5]);
خالی foov(صحیح x[متلون 5]);
خالی foor(صحیح x[محدود 5]);
خالی fooc(صحیح [ثابت 5]);
خالی foos(صحیح [ساکن 5]);
خالی foov(صحیح [متلون 5]);
خالی foor(صحیح [محدود 5]);
خالی fooc(صحیح (* ثابت x));
خالی foos(صحیح *x);
خالی foov(صحیح * متلون x);
خالی foor(صحیح * محدود x);
خالی fooc(صحیح x[متلون 5])
{
  x[3] = 42;
#اگر_تعریف_شدہ INVALID
  x = 0;
#اگر_ختم
}
خالی foovm(صحیح x[ثابت *]);
خالی foovm(صحیح * ثابت x);

قسمتعریف صحیح *اشارہ_گر_array[2];
قسمتعریف صحیح *محدود restricted_اشارہ_گر;
قسمتعریف محدود اشارہ_گر_array restricted_اشارہ_گر_array;

_Static_assert(!__builtin_types_compatible_p(صحیح **,
                                             restricted_اشارہ_گر *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_اشارہ_گر_array,
                                            restricted_اشارہ_گر[2]),
               "restrict can qualify an array of pointer types");

restricted_اشارہ_گر *restricted_pp;
صحیح **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_اشارہ_گر *),
               "conditional expression combines restrict qualifiers");

#اگر_تعریف_شدہ INVALID
خالی wrongc(صحیح x[3][ثابت 4]);
خالی wrongvm(صحیح x[ساکن *]);
خالی foovm(صحیح x[ثابت *])
{
  x[2] = 1;
}
#اگر_ختم
صحیح مین()
{
  واپس 0;
}

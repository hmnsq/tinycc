ਖਾਲੀ foo(ਪੂਰਨ [5]);
ਖਾਲੀ fooc(ਪੂਰਨ x[ਅਚਲ 5]);
ਖਾਲੀ foos(ਪੂਰਨ x[ਸਥਿਰ 5]);
ਖਾਲੀ foov(ਪੂਰਨ x[ਅਸਥਿਰ 5]);
ਖਾਲੀ foor(ਪੂਰਨ x[ਸੀਮਿਤ 5]);
ਖਾਲੀ fooc(ਪੂਰਨ [ਅਚਲ 5]);
ਖਾਲੀ foos(ਪੂਰਨ [ਸਥਿਰ 5]);
ਖਾਲੀ foov(ਪੂਰਨ [ਅਸਥਿਰ 5]);
ਖਾਲੀ foor(ਪੂਰਨ [ਸੀਮਿਤ 5]);
ਖਾਲੀ fooc(ਪੂਰਨ (* ਅਚਲ x));
ਖਾਲੀ foos(ਪੂਰਨ *x);
ਖਾਲੀ foov(ਪੂਰਨ * ਅਸਥਿਰ x);
ਖਾਲੀ foor(ਪੂਰਨ * ਸੀਮਿਤ x);
ਖਾਲੀ fooc(ਪੂਰਨ x[ਅਸਥਿਰ 5])
{
  x[3] = 42;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INVALID
  x = 0;
#ਜੇ_ਅੰਤ
}
ਖਾਲੀ foovm(ਪੂਰਨ x[ਅਚਲ *]);
ਖਾਲੀ foovm(ਪੂਰਨ * ਅਚਲ x);

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ *ਸੂਚਕ_array[2];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ *ਸੀਮਿਤ restricted_ਸੂਚਕ;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੀਮਿਤ ਸੂਚਕ_array restricted_ਸੂਚਕ_array;

_Static_assert(!__builtin_types_compatible_p(ਪੂਰਨ **,
                                             restricted_ਸੂਚਕ *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_ਸੂਚਕ_array,
                                            restricted_ਸੂਚਕ[2]),
               "restrict can qualify an array of pointer types");

restricted_ਸੂਚਕ *restricted_pp;
ਪੂਰਨ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_ਸੂਚਕ *),
               "conditional expression combines restrict qualifiers");

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INVALID
ਖਾਲੀ wrongc(ਪੂਰਨ x[3][ਅਚਲ 4]);
ਖਾਲੀ wrongvm(ਪੂਰਨ x[ਸਥਿਰ *]);
ਖਾਲੀ foovm(ਪੂਰਨ x[ਅਚਲ *])
{
  x[2] = 1;
}
#ਜੇ_ਅੰਤ
ਪੂਰਨ ਮੁੱਖ()
{
  ਵਾਪਸ 0;
}

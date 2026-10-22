শূন্য foo(পূর্ণসংখ্যা [5]);
শূন্য fooc(পূর্ণসংখ্যা x[ধ্রুবক 5]);
শূন্য foos(পূর্ণসংখ্যা x[স্থির 5]);
শূন্য foov(পূর্ণসংখ্যা x[অস্থির 5]);
শূন্য foor(পূর্ণসংখ্যা x[restrict 5]);
শূন্য fooc(পূর্ণসংখ্যা [ধ্রুবক 5]);
শূন্য foos(পূর্ণসংখ্যা [স্থির 5]);
শূন্য foov(পূর্ণসংখ্যা [অস্থির 5]);
শূন্য foor(পূর্ণসংখ্যা [restrict 5]);
শূন্য fooc(পূর্ণসংখ্যা (* ধ্রুবক x));
শূন্য foos(পূর্ণসংখ্যা *x);
শূন্য foov(পূর্ণসংখ্যা * অস্থির x);
শূন্য foor(পূর্ণসংখ্যা * restrict x);
শূন্য fooc(পূর্ণসংখ্যা x[অস্থির 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
শূন্য foovm(পূর্ণসংখ্যা x[ধ্রুবক *]);
শূন্য foovm(পূর্ণসংখ্যা * ধ্রুবক x);

প্রকারলেখ পূর্ণসংখ্যা *pointer_array[2];
প্রকারলেখ পূর্ণসংখ্যা *restrict restricted_pointer;
প্রকারলেখ restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(পূর্ণসংখ্যা **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
পূর্ণসংখ্যা **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
শূন্য wrongc(পূর্ণসংখ্যা x[3][ধ্রুবক 4]);
শূন্য wrongvm(পূর্ণসংখ্যা x[স্থির *]);
শূন্য foovm(পূর্ণসংখ্যা x[ধ্রুবক *])
{
  x[2] = 1;
}
#endif
পূর্ণসংখ্যা প্রধান()
{
  ফেরত 0;
}

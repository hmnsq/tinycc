শূন্য foo(পূর্ণাঙ্ক [5]);
শূন্য fooc(পূর্ণাঙ্ক x[ধ্রুৱ 5]);
শূন্য foos(পূর্ণাঙ্ক x[স্থির 5]);
শূন্য foov(পূর্ণাঙ্ক x[চঞ্চল 5]);
শূন্য foor(পূর্ণাঙ্ক x[restrict 5]);
শূন্য fooc(পূর্ণাঙ্ক [ধ্রুৱ 5]);
শূন্য foos(পূর্ণাঙ্ক [স্থির 5]);
শূন্য foov(পূর্ণাঙ্ক [চঞ্চল 5]);
শূন্য foor(পূর্ণাঙ্ক [restrict 5]);
শূন্য fooc(পূর্ণাঙ্ক (* ধ্রুৱ x));
শূন্য foos(পূর্ণাঙ্ক *x);
শূন্য foov(পূর্ণাঙ্ক * চঞ্চল x);
শূন্য foor(পূর্ণাঙ্ক * restrict x);
শূন্য fooc(পূর্ণাঙ্ক x[চঞ্চল 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
শূন্য foovm(পূর্ণাঙ্ক x[ধ্রুৱ *]);
শূন্য foovm(পূর্ণাঙ্ক * ধ্রুৱ x);

প্রকারনির্দেশ পূর্ণাঙ্ক *pointer_array[2];
প্রকারনির্দেশ পূর্ণাঙ্ক *restrict restricted_pointer;
প্রকারনির্দেশ restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(পূর্ণাঙ্ক **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
পূর্ণাঙ্ক **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
শূন্য wrongc(পূর্ণাঙ্ক x[3][ধ্রুৱ 4]);
শূন্য wrongvm(পূর্ণাঙ্ক x[স্থির *]);
শূন্য foovm(পূর্ণাঙ্ক x[ধ্রুৱ *])
{
  x[2] = 1;
}
#endif
পূর্ণাঙ্ক main()
{
  ঘূৰাই 0;
}

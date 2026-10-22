ଶୂନ୍ୟ foo(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [5]);
ଶୂନ୍ୟ fooc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ଅଚଳ 5]);
ଶୂନ୍ୟ foos(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ସ୍ଥିର 5]);
ଶୂନ୍ୟ foov(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ଅସ୍ଥିର 5]);
ଶୂନ୍ୟ foor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[restrict 5]);
ଶୂନ୍ୟ fooc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [ଅଚଳ 5]);
ଶୂନ୍ୟ foos(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [ସ୍ଥିର 5]);
ଶୂନ୍ୟ foov(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [ଅସ୍ଥିର 5]);
ଶୂନ୍ୟ foor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [restrict 5]);
ଶୂନ୍ୟ fooc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା (* ଅଚଳ x));
ଶୂନ୍ୟ foos(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *x);
ଶୂନ୍ୟ foov(ପୂର୍ଣ୍ଣସଂଖ୍ୟା * ଅସ୍ଥିର x);
ଶୂନ୍ୟ foor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା * restrict x);
ଶୂନ୍ୟ fooc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ଅସ୍ଥିର 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
ଶୂନ୍ୟ foovm(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ଅଚଳ *]);
ଶୂନ୍ୟ foovm(ପୂର୍ଣ୍ଣସଂଖ୍ୟା * ଅଚଳ x);

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer_array[2];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict restricted_pointer;
ପ୍ରକାରବ୍ୟାଖ୍ୟା restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ପୂର୍ଣ୍ଣସଂଖ୍ୟା **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
ଶୂନ୍ୟ wrongc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[3][ଅଚଳ 4]);
ଶୂନ୍ୟ wrongvm(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ସ୍ଥିର *]);
ଶୂନ୍ୟ foovm(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[ଅଚଳ *])
{
  x[2] = 1;
}
#endif
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  ଫେରନ୍ତୁ 0;
}

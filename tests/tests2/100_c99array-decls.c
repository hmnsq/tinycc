शून्य foo(पूर्णाङ्क [5]);
शून्य fooc(पूर्णाङ्क x[ध्रुव 5]);
शून्य foos(पूर्णाङ्क x[स्थिर 5]);
शून्य foov(पूर्णाङ्क x[चञ्चल 5]);
शून्य foor(पूर्णाङ्क x[restrict 5]);
शून्य fooc(पूर्णाङ्क [ध्रुव 5]);
शून्य foos(पूर्णाङ्क [स्थिर 5]);
शून्य foov(पूर्णाङ्क [चञ्चल 5]);
शून्य foor(पूर्णाङ्क [restrict 5]);
शून्य fooc(पूर्णाङ्क (* ध्रुव x));
शून्य foos(पूर्णाङ्क *x);
शून्य foov(पूर्णाङ्क * चञ्चल x);
शून्य foor(पूर्णाङ्क * restrict x);
शून्य fooc(पूर्णाङ्क x[चञ्चल 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
शून्य foovm(पूर्णाङ्क x[ध्रुव *]);
शून्य foovm(पूर्णाङ्क * ध्रुव x);

प्रकारनिर्देश पूर्णाङ्क *pointer_array[2];
प्रकारनिर्देश पूर्णाङ्क *restrict restricted_pointer;
प्रकारनिर्देश restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(पूर्णाङ्क **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
पूर्णाङ्क **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
शून्य wrongc(पूर्णाङ्क x[3][ध्रुव 4]);
शून्य wrongvm(पूर्णाङ्क x[स्थिर *]);
शून्य foovm(पूर्णाङ्क x[ध्रुव *])
{
  x[2] = 1;
}
#endif
पूर्णाङ्क main()
{
  पटिनिवत्त 0;
}

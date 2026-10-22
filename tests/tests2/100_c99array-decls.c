शून्य foo(पूर्णाङ्क [5]);
शून्य fooc(पूर्णाङ्क x[ध्रुव 5]);
शून्य foos(पूर्णाङ्क x[स्थिर 5]);
शून्य foov(पूर्णाङ्क x[चञ्चल 5]);
शून्य foor(पूर्णाङ्क x[सीमित 5]);
शून्य fooc(पूर्णाङ्क [ध्रुव 5]);
शून्य foos(पूर्णाङ्क [स्थिर 5]);
शून्य foov(पूर्णाङ्क [चञ्चल 5]);
शून्य foor(पूर्णाङ्क [सीमित 5]);
शून्य fooc(पूर्णाङ्क (* ध्रुव x));
शून्य foos(पूर्णाङ्क *x);
शून्य foov(पूर्णाङ्क * चञ्चल x);
शून्य foor(पूर्णाङ्क * सीमित x);
शून्य fooc(पूर्णाङ्क x[चञ्चल 5])
{
  x[3] = 42;
#यदि_परिभाषितम् INVALID
  x = 0;
#यदि_अन्तः
}
शून्य foovm(पूर्णाङ्क x[ध्रुव *]);
शून्य foovm(पूर्णाङ्क * ध्रुव x);

प्रकारनिर्देश पूर्णाङ्क *pointer_array[2];
प्रकारनिर्देश पूर्णाङ्क *सीमित restricted_pointer;
प्रकारनिर्देश सीमित pointer_array restricted_pointer_array;

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

#यदि_परिभाषितम् INVALID
शून्य wrongc(पूर्णाङ्क x[3][ध्रुव 4]);
शून्य wrongvm(पूर्णाङ्क x[स्थिर *]);
शून्य foovm(पूर्णाङ्क x[ध्रुव *])
{
  x[2] = 1;
}
#यदि_अन्तः
पूर्णाङ्क मुख्यम्()
{
  प्रत्यागम 0;
}

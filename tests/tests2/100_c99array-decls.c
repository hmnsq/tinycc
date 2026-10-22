शून्य foo(पूर्णांक [5]);
शून्य fooc(पूर्णांक x[स्थिरांक 5]);
शून्य foos(पूर्णांक x[स्थिर 5]);
शून्य foov(पूर्णांक x[अस्थिर 5]);
शून्य foor(पूर्णांक x[restrict 5]);
शून्य fooc(पूर्णांक [स्थिरांक 5]);
शून्य foos(पूर्णांक [स्थिर 5]);
शून्य foov(पूर्णांक [अस्थिर 5]);
शून्य foor(पूर्णांक [restrict 5]);
शून्य fooc(पूर्णांक (* स्थिरांक x));
शून्य foos(पूर्णांक *x);
शून्य foov(पूर्णांक * अस्थिर x);
शून्य foor(पूर्णांक * restrict x);
शून्य fooc(पूर्णांक x[अस्थिर 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
शून्य foovm(पूर्णांक x[स्थिरांक *]);
शून्य foovm(पूर्णांक * स्थिरांक x);

प्रकारव्याख्या पूर्णांक *pointer_array[2];
प्रकारव्याख्या पूर्णांक *restrict restricted_pointer;
प्रकारव्याख्या restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(पूर्णांक **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
पूर्णांक **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
शून्य wrongc(पूर्णांक x[3][स्थिरांक 4]);
शून्य wrongvm(पूर्णांक x[स्थिर *]);
शून्य foovm(पूर्णांक x[स्थिरांक *])
{
  x[2] = 1;
}
#endif
पूर्णांक main()
{
  परत 0;
}

व्योम foo(पूर्णांक [5]);
व्योम fooc(पूर्णांक x[स्थिर 5]);
व्योम foos(पूर्णांक x[अटल 5]);
व्योम foov(पूर्णांक x[अस्थिर 5]);
व्योम foor(पूर्णांक x[restrict 5]);
व्योम fooc(पूर्णांक [स्थिर 5]);
व्योम foos(पूर्णांक [अटल 5]);
व्योम foov(पूर्णांक [अस्थिर 5]);
व्योम foor(पूर्णांक [restrict 5]);
व्योम fooc(पूर्णांक (* स्थिर x));
व्योम foos(पूर्णांक *x);
व्योम foov(पूर्णांक * अस्थिर x);
व्योम foor(पूर्णांक * restrict x);
व्योम fooc(पूर्णांक x[अस्थिर 5])
{
  x[3] = 42;
#अगर_घोषित INVALID
  x = 0;
#पूर्ण_अगर
}
व्योम foovm(पूर्णांक x[स्थिर *]);
व्योम foovm(पूर्णांक * स्थिर x);

प्रकार पूर्णांक *pointer_array[2];
प्रकार पूर्णांक *restrict restricted_pointer;
प्रकार restrict pointer_array restricted_pointer_array;

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

#अगर_घोषित INVALID
व्योम wrongc(पूर्णांक x[3][स्थिर 4]);
व्योम wrongvm(पूर्णांक x[अटल *]);
व्योम foovm(पूर्णांक x[स्थिर *])
{
  x[2] = 1;
}
#पूर्ण_अगर
पूर्णांक मुख्य()
{
  वापस 0;
}

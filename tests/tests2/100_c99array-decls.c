void foo(цяло [5]);
void fooc(цяло x[const 5]);
void foos(цяло x[static 5]);
void foov(цяло x[volatile 5]);
void foor(цяло x[restrict 5]);
void fooc(цяло [const 5]);
void foos(цяло [static 5]);
void foov(цяло [volatile 5]);
void foor(цяло [restrict 5]);
void fooc(цяло (* const x));
void foos(цяло *x);
void foov(цяло * volatile x);
void foor(цяло * restrict x);
void fooc(цяло x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(цяло x[const *]);
void foovm(цяло * const x);

typedef цяло *pointer_array[2];
typedef цяло *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(цяло **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
цяло **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(цяло x[3][const 4]);
void wrongvm(цяло x[static *]);
void foovm(цяло x[const *])
{
  x[2] = 1;
}
#endif
цяло main()
{
  върни 0;
}

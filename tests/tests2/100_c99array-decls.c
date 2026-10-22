void foo(цео [5]);
void fooc(цео x[const 5]);
void foos(цео x[static 5]);
void foov(цео x[volatile 5]);
void foor(цео x[restrict 5]);
void fooc(цео [const 5]);
void foos(цео [static 5]);
void foov(цео [volatile 5]);
void foor(цео [restrict 5]);
void fooc(цео (* const x));
void foos(цео *x);
void foov(цео * volatile x);
void foor(цео * restrict x);
void fooc(цео x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(цео x[const *]);
void foovm(цео * const x);

typedef цео *pointer_array[2];
typedef цео *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(цео **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
цео **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(цео x[3][const 4]);
void wrongvm(цео x[static *]);
void foovm(цео x[const *])
{
  x[2] = 1;
}
#endif
цео main()
{
  врати 0;
}

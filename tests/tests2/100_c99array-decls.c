void foo(ціле [5]);
void fooc(ціле x[const 5]);
void foos(ціле x[static 5]);
void foov(ціле x[volatile 5]);
void foor(ціле x[restrict 5]);
void fooc(ціле [const 5]);
void foos(ціле [static 5]);
void foov(ціле [volatile 5]);
void foor(ціле [restrict 5]);
void fooc(ціле (* const x));
void foos(ціле *x);
void foov(ціле * volatile x);
void foor(ціле * restrict x);
void fooc(ціле x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(ціле x[const *]);
void foovm(ціле * const x);

typedef ціле *pointer_array[2];
typedef ціле *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ціле **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ціле **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(ціле x[3][const 4]);
void wrongvm(ціле x[static *]);
void foovm(ціле x[const *])
{
  x[2] = 1;
}
#endif
ціле main()
{
  повернути 0;
}

void foo(정수 [5]);
void fooc(정수 x[const 5]);
void foos(정수 x[static 5]);
void foov(정수 x[volatile 5]);
void foor(정수 x[restrict 5]);
void fooc(정수 [const 5]);
void foos(정수 [static 5]);
void foov(정수 [volatile 5]);
void foor(정수 [restrict 5]);
void fooc(정수 (* const x));
void foos(정수 *x);
void foov(정수 * volatile x);
void foor(정수 * restrict x);
void fooc(정수 x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(정수 x[const *]);
void foovm(정수 * const x);

typedef 정수 *pointer_array[2];
typedef 정수 *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(정수 **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
정수 **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(정수 x[3][const 4]);
void wrongvm(정수 x[static *]);
void foovm(정수 x[const *])
{
  x[2] = 1;
}
#endif
정수 main()
{
  반환 0;
}

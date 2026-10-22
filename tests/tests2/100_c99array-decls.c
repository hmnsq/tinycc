void foo(整数 [5]);
void fooc(整数 x[const 5]);
void foos(整数 x[static 5]);
void foov(整数 x[volatile 5]);
void foor(整数 x[restrict 5]);
void fooc(整数 [const 5]);
void foos(整数 [static 5]);
void foov(整数 [volatile 5]);
void foor(整数 [restrict 5]);
void fooc(整数 (* const x));
void foos(整数 *x);
void foov(整数 * volatile x);
void foor(整数 * restrict x);
void fooc(整数 x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(整数 x[const *]);
void foovm(整数 * const x);

typedef 整数 *pointer_array[2];
typedef 整数 *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(整数 **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
整数 **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(整数 x[3][const 4]);
void wrongvm(整数 x[static *]);
void foovm(整数 x[const *])
{
  x[2] = 1;
}
#endif
整数 主要()
{
  返回 0;
}

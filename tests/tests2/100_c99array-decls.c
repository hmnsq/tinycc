void foo(số_nguyên [5]);
void fooc(số_nguyên x[const 5]);
void foos(số_nguyên x[static 5]);
void foov(số_nguyên x[volatile 5]);
void foor(số_nguyên x[restrict 5]);
void fooc(số_nguyên [const 5]);
void foos(số_nguyên [static 5]);
void foov(số_nguyên [volatile 5]);
void foor(số_nguyên [restrict 5]);
void fooc(số_nguyên (* const x));
void foos(số_nguyên *x);
void foov(số_nguyên * volatile x);
void foor(số_nguyên * restrict x);
void fooc(số_nguyên x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(số_nguyên x[const *]);
void foovm(số_nguyên * const x);

typedef số_nguyên *pointer_array[2];
typedef số_nguyên *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(số_nguyên **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
số_nguyên **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(số_nguyên x[3][const 4]);
void wrongvm(số_nguyên x[static *]);
void foovm(số_nguyên x[const *])
{
  x[2] = 1;
}
#endif
số_nguyên main()
{
  trả_về 0;
}

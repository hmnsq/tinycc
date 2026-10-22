void foo(целое [5]);
void fooc(целое x[const 5]);
void foos(целое x[static 5]);
void foov(целое x[volatile 5]);
void foor(целое x[restrict 5]);
void fooc(целое [const 5]);
void foos(целое [static 5]);
void foov(целое [volatile 5]);
void foor(целое [restrict 5]);
void fooc(целое (* const x));
void foos(целое *x);
void foov(целое * volatile x);
void foor(целое * restrict x);
void fooc(целое x[volatile 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(целое x[const *]);
void foovm(целое * const x);

typedef целое *pointer_array[2];
typedef целое *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(целое **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
целое **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(целое x[3][const 4]);
void wrongvm(целое x[static *]);
void foovm(целое x[const *])
{
  x[2] = 1;
}
#endif
целое основной()
{
  вернуть 0;
}

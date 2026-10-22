void foo(จำนวนเต็ม [5]);
void fooc(จำนวนเต็ม x[const 5]);
void foos(จำนวนเต็ม x[static 5]);
void foov(จำนวนเต็ม x[ca_ncala 5]);
void foor(จำนวนเต็ม x[restrict 5]);
void fooc(จำนวนเต็ม [const 5]);
void foos(จำนวนเต็ม [static 5]);
void foov(จำนวนเต็ม [ca_ncala 5]);
void foor(จำนวนเต็ม [restrict 5]);
void fooc(จำนวนเต็ม (* const x));
void foos(จำนวนเต็ม *x);
void foov(จำนวนเต็ม * ca_ncala x);
void foor(จำนวนเต็ม * restrict x);
void fooc(จำนวนเต็ม x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(จำนวนเต็ม x[const *]);
void foovm(จำนวนเต็ม * const x);

typedef จำนวนเต็ม *pointer_array[2];
typedef จำนวนเต็ม *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(จำนวนเต็ม **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
จำนวนเต็ม **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(จำนวนเต็ม x[3][const 4]);
void wrongvm(จำนวนเต็ม x[static *]);
void foovm(จำนวนเต็ม x[const *])
{
  x[2] = 1;
}
#endif
จำนวนเต็ม หลัก()
{
  คืน 0;
}

void foo(ចំនួនគត់ [5]);
void fooc(ចំនួនគត់ x[const 5]);
void foos(ចំនួនគត់ x[static 5]);
void foov(ចំនួនគត់ x[ca_ncala 5]);
void foor(ចំនួនគត់ x[restrict 5]);
void fooc(ចំនួនគត់ [const 5]);
void foos(ចំនួនគត់ [static 5]);
void foov(ចំនួនគត់ [ca_ncala 5]);
void foor(ចំនួនគត់ [restrict 5]);
void fooc(ចំនួនគត់ (* const x));
void foos(ចំនួនគត់ *x);
void foov(ចំនួនគត់ * ca_ncala x);
void foor(ចំនួនគត់ * restrict x);
void fooc(ចំនួនគត់ x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(ចំនួនគត់ x[const *]);
void foovm(ចំនួនគត់ * const x);

typedef ចំនួនគត់ *pointer_array[2];
typedef ចំនួនគត់ *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ចំនួនគត់ **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ចំនួនគត់ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(ចំនួនគត់ x[3][const 4]);
void wrongvm(ចំនួនគត់ x[static *]);
void foovm(ចំនួនគត់ x[const *])
{
  x[2] = 1;
}
#endif
ចំនួនគត់ main()
{
  ត្រឡប់ 0;
}

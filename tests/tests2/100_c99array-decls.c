void foo(puur_naa_nka [5]);
void fooc(puur_naa_nka x[const 5]);
void foos(puur_naa_nka x[static 5]);
void foov(puur_naa_nka x[ca_ncala 5]);
void foor(puur_naa_nka x[restrict 5]);
void fooc(puur_naa_nka [const 5]);
void foos(puur_naa_nka [static 5]);
void foov(puur_naa_nka [ca_ncala 5]);
void foor(puur_naa_nka [restrict 5]);
void fooc(puur_naa_nka (* const x));
void foos(puur_naa_nka *x);
void foov(puur_naa_nka * ca_ncala x);
void foor(puur_naa_nka * restrict x);
void fooc(puur_naa_nka x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(puur_naa_nka x[const *]);
void foovm(puur_naa_nka * const x);

typedef puur_naa_nka *pointer_array[2];
typedef puur_naa_nka *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(puur_naa_nka **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
puur_naa_nka **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(puur_naa_nka x[3][const 4]);
void wrongvm(puur_naa_nka x[static *]);
void foovm(puur_naa_nka x[const *])
{
  x[2] = 1;
}
#endif
puur_naa_nka main()
{
  ᮝᮜᮤ 0;
}

void foo(ཧྲིལ [5]);
void fooc(ཧྲིལ x[const 5]);
void foos(ཧྲིལ x[static 5]);
void foov(ཧྲིལ x[ca_ncala 5]);
void foor(ཧྲིལ x[restrict 5]);
void fooc(ཧྲིལ [const 5]);
void foos(ཧྲིལ [static 5]);
void foov(ཧྲིལ [ca_ncala 5]);
void foor(ཧྲིལ [restrict 5]);
void fooc(ཧྲིལ (* const x));
void foos(ཧྲིལ *x);
void foov(ཧྲིལ * ca_ncala x);
void foor(ཧྲིལ * restrict x);
void fooc(ཧྲིལ x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(ཧྲིལ x[const *]);
void foovm(ཧྲིལ * const x);

typedef ཧྲིལ *pointer_array[2];
typedef ཧྲིལ *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ཧྲིལ **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ཧྲིལ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(ཧྲིལ x[3][const 4]);
void wrongvm(ཧྲིལ x[static *]);
void foovm(ཧྲིལ x[const *])
{
  x[2] = 1;
}
#endif
ཧྲིལ གཙོ()
{
  ཕྱིར 0;
}

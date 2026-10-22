void foo(ကိန်းပြည့် [5]);
void fooc(ကိန်းပြည့် x[const 5]);
void foos(ကိန်းပြည့် x[static 5]);
void foov(ကိန်းပြည့် x[ca_ncala 5]);
void foor(ကိန်းပြည့် x[restrict 5]);
void fooc(ကိန်းပြည့် [const 5]);
void foos(ကိန်းပြည့် [static 5]);
void foov(ကိန်းပြည့် [ca_ncala 5]);
void foor(ကိန်းပြည့် [restrict 5]);
void fooc(ကိန်းပြည့် (* const x));
void foos(ကိန်းပြည့် *x);
void foov(ကိန်းပြည့် * ca_ncala x);
void foor(ကိန်းပြည့် * restrict x);
void fooc(ကိန်းပြည့် x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(ကိန်းပြည့် x[const *]);
void foovm(ကိန်းပြည့် * const x);

typedef ကိန်းပြည့် *pointer_array[2];
typedef ကိန်းပြည့် *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ကိန်းပြည့် **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ကိန်းပြည့် **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(ကိန်းပြည့် x[3][const 4]);
void wrongvm(ကိန်းပြည့် x[static *]);
void foovm(ကိန်းပြည့် x[const *])
{
  x[2] = 1;
}
#endif
ကိန်းပြည့် main()
{
  ပြန်ပေး 0;
}

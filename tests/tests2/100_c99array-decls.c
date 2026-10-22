void foo(ຈຳນວນເຕັມ [5]);
void fooc(ຈຳນວນເຕັມ x[const 5]);
void foos(ຈຳນວນເຕັມ x[static 5]);
void foov(ຈຳນວນເຕັມ x[ca_ncala 5]);
void foor(ຈຳນວນເຕັມ x[restrict 5]);
void fooc(ຈຳນວນເຕັມ [const 5]);
void foos(ຈຳນວນເຕັມ [static 5]);
void foov(ຈຳນວນເຕັມ [ca_ncala 5]);
void foor(ຈຳນວນເຕັມ [restrict 5]);
void fooc(ຈຳນວນເຕັມ (* const x));
void foos(ຈຳນວນເຕັມ *x);
void foov(ຈຳນວນເຕັມ * ca_ncala x);
void foor(ຈຳນວນເຕັມ * restrict x);
void fooc(ຈຳນວນເຕັມ x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(ຈຳນວນເຕັມ x[const *]);
void foovm(ຈຳນວນເຕັມ * const x);

typedef ຈຳນວນເຕັມ *pointer_array[2];
typedef ຈຳນວນເຕັມ *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ຈຳນວນເຕັມ **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ຈຳນວນເຕັມ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(ຈຳນວນເຕັມ x[3][const 4]);
void wrongvm(ຈຳນວນເຕັມ x[static *]);
void foovm(ຈຳນວນເຕັມ x[const *])
{
  x[2] = 1;
}
#endif
ຈຳນວນເຕັມ main()
{
  ສົ່ງຄືນ 0;
}

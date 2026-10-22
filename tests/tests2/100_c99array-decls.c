வெறுமை foo(முழு [5]);
வெறுமை fooc(முழு x[மாறிலி 5]);
வெறுமை foos(முழு x[நிலையான 5]);
வெறுமை foov(முழு x[நிலையற்ற 5]);
வெறுமை foor(முழு x[restrict 5]);
வெறுமை fooc(முழு [மாறிலி 5]);
வெறுமை foos(முழு [நிலையான 5]);
வெறுமை foov(முழு [நிலையற்ற 5]);
வெறுமை foor(முழு [restrict 5]);
வெறுமை fooc(முழு (* மாறிலி x));
வெறுமை foos(முழு *x);
வெறுமை foov(முழு * நிலையற்ற x);
வெறுமை foor(முழு * restrict x);
வெறுமை fooc(முழு x[நிலையற்ற 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
வெறுமை foovm(முழு x[மாறிலி *]);
வெறுமை foovm(முழு * மாறிலி x);

வகைவரை முழு *pointer_array[2];
வகைவரை முழு *restrict restricted_pointer;
வகைவரை restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(முழு **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
முழு **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
வெறுமை wrongc(முழு x[3][மாறிலி 4]);
வெறுமை wrongvm(முழு x[நிலையான *]);
வெறுமை foovm(முழு x[மாறிலி *])
{
  x[2] = 1;
}
#endif
முழு முதன்மை()
{
  திரும்பு 0;
}

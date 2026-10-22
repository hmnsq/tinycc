ശൂന്യം foo(പൂർണ്ണസംഖ്യ [5]);
ശൂന്യം fooc(പൂർണ്ണസംഖ്യ x[സ്ഥിരം 5]);
ശൂന്യം foos(പൂർണ്ണസംഖ്യ x[സ്ഥിതം 5]);
ശൂന്യം foov(പൂർണ്ണസംഖ്യ x[അസ്ഥിര 5]);
ശൂന്യം foor(പൂർണ്ണസംഖ്യ x[restrict 5]);
ശൂന്യം fooc(പൂർണ്ണസംഖ്യ [സ്ഥിരം 5]);
ശൂന്യം foos(പൂർണ്ണസംഖ്യ [സ്ഥിതം 5]);
ശൂന്യം foov(പൂർണ്ണസംഖ്യ [അസ്ഥിര 5]);
ശൂന്യം foor(പൂർണ്ണസംഖ്യ [restrict 5]);
ശൂന്യം fooc(പൂർണ്ണസംഖ്യ (* സ്ഥിരം x));
ശൂന്യം foos(പൂർണ്ണസംഖ്യ *x);
ശൂന്യം foov(പൂർണ്ണസംഖ്യ * അസ്ഥിര x);
ശൂന്യം foor(പൂർണ്ണസംഖ്യ * restrict x);
ശൂന്യം fooc(പൂർണ്ണസംഖ്യ x[അസ്ഥിര 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
ശൂന്യം foovm(പൂർണ്ണസംഖ്യ x[സ്ഥിരം *]);
ശൂന്യം foovm(പൂർണ്ണസംഖ്യ * സ്ഥിരം x);

തരനിർവചനം പൂർണ്ണസംഖ്യ *pointer_array[2];
തരനിർവചനം പൂർണ്ണസംഖ്യ *restrict restricted_pointer;
തരനിർവചനം restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(പൂർണ്ണസംഖ്യ **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
പൂർണ്ണസംഖ്യ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
ശൂന്യം wrongc(പൂർണ്ണസംഖ്യ x[3][സ്ഥിരം 4]);
ശൂന്യം wrongvm(പൂർണ്ണസംഖ്യ x[സ്ഥിതം *]);
ശൂന്യം foovm(പൂർണ്ണസംഖ്യ x[സ്ഥിരം *])
{
  x[2] = 1;
}
#endif
പൂർണ്ണസംഖ്യ പ്രധാന()
{
  തിരികെ 0;
}

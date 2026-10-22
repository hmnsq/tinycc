const puur_naa_nka const_return(void);
ca_ncala puur_naa_nka volatile_return(void);
puur_naa_nka *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, puur_naa_nka *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, puur_naa_nka *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, puur_naa_nka **),
               "restrict is removed from a return type");

puur_naa_nka const_return(void)
{
   ᬯᬮᬶ 0;
}

puur_naa_nka volatile_return(void)
{
   ᬯᬮᬶ 0;
}

puur_naa_nka *restrict_return(void)
{
   ᬯᬮᬶ 0;
}

puur_naa_nka main(void)
{
   ᬯᬮᬶ 0;
}

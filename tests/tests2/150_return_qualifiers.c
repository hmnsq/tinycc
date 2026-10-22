const цяло const_return(void);
volatile цяло volatile_return(void);
цяло *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, цяло *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, цяло *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, цяло **),
               "restrict is removed from a return type");

цяло const_return(void)
{
   върни 0;
}

цяло volatile_return(void)
{
   върни 0;
}

цяло *restrict_return(void)
{
   върни 0;
}

цяло main(void)
{
   върни 0;
}

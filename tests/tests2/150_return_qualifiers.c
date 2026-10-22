const цео const_return(void);
volatile цео volatile_return(void);
цео *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, цео *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, цео *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, цео **),
               "restrict is removed from a return type");

цео const_return(void)
{
   врати 0;
}

цео volatile_return(void)
{
   врати 0;
}

цео *restrict_return(void)
{
   врати 0;
}

цео main(void)
{
   врати 0;
}

const ціле const_return(void);
volatile ціле volatile_return(void);
ціле *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ціле *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ціле *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ціле **),
               "restrict is removed from a return type");

ціле const_return(void)
{
   повернути 0;
}

ціле volatile_return(void)
{
   повернути 0;
}

ціле *restrict_return(void)
{
   повернути 0;
}

ціле main(void)
{
   повернути 0;
}

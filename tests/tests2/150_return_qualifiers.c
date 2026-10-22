const целое const_return(void);
volatile целое volatile_return(void);
целое *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, целое *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, целое *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, целое **),
               "restrict is removed from a return type");

целое const_return(void)
{
   вернуть 0;
}

целое volatile_return(void)
{
   вернуть 0;
}

целое *restrict_return(void)
{
   вернуть 0;
}

целое основной(void)
{
   вернуть 0;
}

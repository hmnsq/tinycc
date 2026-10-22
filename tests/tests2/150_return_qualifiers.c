const số_nguyên const_return(void);
volatile số_nguyên volatile_return(void);
số_nguyên *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, số_nguyên *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, số_nguyên *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, số_nguyên **),
               "restrict is removed from a return type");

số_nguyên const_return(void)
{
   trả_về 0;
}

số_nguyên volatile_return(void)
{
   trả_về 0;
}

số_nguyên *restrict_return(void)
{
   trả_về 0;
}

số_nguyên main(void)
{
   trả_về 0;
}

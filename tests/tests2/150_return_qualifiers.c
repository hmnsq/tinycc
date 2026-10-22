const 정수 const_return(void);
volatile 정수 volatile_return(void);
정수 *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, 정수 *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, 정수 *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, 정수 **),
               "restrict is removed from a return type");

정수 const_return(void)
{
   반환 0;
}

정수 volatile_return(void)
{
   반환 0;
}

정수 *restrict_return(void)
{
   반환 0;
}

정수 main(void)
{
   반환 0;
}

const 整数 const_return(void);
volatile 整数 volatile_return(void);
整数 *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, 整数 *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, 整数 *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, 整数 **),
               "restrict is removed from a return type");

整数 const_return(void)
{
   返回 0;
}

整数 volatile_return(void)
{
   返回 0;
}

整数 *restrict_return(void)
{
   返回 0;
}

整数 主要(void)
{
   返回 0;
}

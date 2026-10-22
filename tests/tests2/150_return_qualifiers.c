const จำนวนเต็ม const_return(void);
ca_ncala จำนวนเต็ม volatile_return(void);
จำนวนเต็ม *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, จำนวนเต็ม *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, จำนวนเต็ม *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, จำนวนเต็ม **),
               "restrict is removed from a return type");

จำนวนเต็ม const_return(void)
{
   คืน 0;
}

จำนวนเต็ม volatile_return(void)
{
   คืน 0;
}

จำนวนเต็ม *restrict_return(void)
{
   คืน 0;
}

จำนวนเต็ม หลัก(void)
{
   คืน 0;
}

const ចំនួនគត់ const_return(void);
ca_ncala ចំនួនគត់ volatile_return(void);
ចំនួនគត់ *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ចំនួនគត់ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ចំនួនគត់ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ចំនួនគត់ **),
               "restrict is removed from a return type");

ចំនួនគត់ const_return(void)
{
   ត្រឡប់ 0;
}

ចំនួនគត់ volatile_return(void)
{
   ត្រឡប់ 0;
}

ចំនួនគត់ *restrict_return(void)
{
   ត្រឡប់ 0;
}

ចំនួនគត់ main(void)
{
   ត្រឡប់ 0;
}

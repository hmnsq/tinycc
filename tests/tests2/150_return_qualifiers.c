const ကိန်းပြည့် const_return(void);
ca_ncala ကိန်းပြည့် volatile_return(void);
ကိန်းပြည့် *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ကိန်းပြည့် *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ကိန်းပြည့် *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ကိန်းပြည့် **),
               "restrict is removed from a return type");

ကိန်းပြည့် const_return(void)
{
   ပြန်ပေး 0;
}

ကိန်းပြည့် volatile_return(void)
{
   ပြန်ပေး 0;
}

ကိန်းပြည့် *restrict_return(void)
{
   ပြန်ပေး 0;
}

ကိန်းပြည့် main(void)
{
   ပြန်ပေး 0;
}

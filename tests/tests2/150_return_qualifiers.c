const ཧྲིལ const_return(void);
ca_ncala ཧྲིལ volatile_return(void);
ཧྲིལ *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ཧྲིལ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ཧྲིལ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ཧྲིལ **),
               "restrict is removed from a return type");

ཧྲིལ const_return(void)
{
   ལོག 0;
}

ཧྲིལ volatile_return(void)
{
   ལོག 0;
}

ཧྲིལ *restrict_return(void)
{
   ལོག 0;
}

ཧྲིལ main(void)
{
   ལོག 0;
}

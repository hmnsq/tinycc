ثابت صحيح const_return(فراغ);
متطاير صحيح volatile_return(فراغ);
صحيح *restrict restrict_return(فراغ);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, صحيح *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, صحيح *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, صحيح **),
               "restrict is removed from a return type");

صحيح const_return(فراغ)
{
   החזר 0;
}

صحيح volatile_return(فراغ)
{
   החזר 0;
}

صحيح *restrict_return(فراغ)
{
   החזר 0;
}

صحيح main(فراغ)
{
   החזר 0;
}

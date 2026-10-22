மாறிலி முழு const_return(வெறுமை);
நிலையற்ற முழு volatile_return(வெறுமை);
முழு *restrict restrict_return(வெறுமை);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, முழு *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, முழு *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, முழு **),
               "restrict is removed from a return type");

முழு const_return(வெறுமை)
{
   திரும்பு 0;
}

முழு volatile_return(வெறுமை)
{
   திரும்பு 0;
}

முழு *restrict_return(வெறுமை)
{
   திரும்பு 0;
}

முழு முதன்மை(வெறுமை)
{
   திரும்பு 0;
}

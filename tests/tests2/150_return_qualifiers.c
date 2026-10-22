स्थिर पूर्णांक const_return(व्योम);
अस्थिर पूर्णांक volatile_return(व्योम);
पूर्णांक *restrict restrict_return(व्योम);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, पूर्णांक *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, पूर्णांक *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, पूर्णांक **),
               "restrict is removed from a return type");

पूर्णांक const_return(व्योम)
{
   वापस 0;
}

पूर्णांक volatile_return(व्योम)
{
   वापस 0;
}

पूर्णांक *restrict_return(व्योम)
{
   वापस 0;
}

पूर्णांक मुख्य(व्योम)
{
   वापस 0;
}

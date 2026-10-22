स्थिरांक पूर्णांक const_return(शून्य);
अस्थिर पूर्णांक volatile_return(शून्य);
पूर्णांक *restrict restrict_return(शून्य);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, पूर्णांक *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, पूर्णांक *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, पूर्णांक **),
               "restrict is removed from a return type");

पूर्णांक const_return(शून्य)
{
   परत 0;
}

पूर्णांक volatile_return(शून्य)
{
   परत 0;
}

पूर्णांक *restrict_return(शून्य)
{
   परत 0;
}

पूर्णांक main(शून्य)
{
   परत 0;
}

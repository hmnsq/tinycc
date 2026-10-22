ध्रुव पूर्णाङ्क const_return(शून्य);
चञ्चल पूर्णाङ्क volatile_return(शून्य);
पूर्णाङ्क *restrict restrict_return(शून्य);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, पूर्णाङ्क *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, पूर्णाङ्क *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, पूर्णाङ्क **),
               "restrict is removed from a return type");

पूर्णाङ्क const_return(शून्य)
{
   पटिनिवत्त 0;
}

पूर्णाङ्क volatile_return(शून्य)
{
   पटिनिवत्त 0;
}

पूर्णाङ्क *restrict_return(शून्य)
{
   पटिनिवत्त 0;
}

पूर्णाङ्क main(शून्य)
{
   पटिनिवत्त 0;
}

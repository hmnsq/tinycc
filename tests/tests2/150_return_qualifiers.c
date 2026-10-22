ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ const_return(ಶೂನ್ಯ);
ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ volatile_return(ಶೂನ್ಯ);
ಪೂರ್ಣಾಙ್ಕ *restrict restrict_return(ಶೂನ್ಯ);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ಪೂರ್ಣಾಙ್ಕ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ಪೂರ್ಣಾಙ್ಕ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ಪೂರ್ಣಾಙ್ಕ **),
               "restrict is removed from a return type");

ಪೂರ್ಣಾಙ್ಕ const_return(ಶೂನ್ಯ)
{
   ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ volatile_return(ಶೂನ್ಯ)
{
   ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ *restrict_return(ಶೂನ್ಯ)
{
   ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
   ಪ್ರತ್ಯಾಗಮ 0;
}

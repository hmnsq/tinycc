ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ const_return(ಶೂನ್ಯ);
ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ volatile_return(ಶೂನ್ಯ);
ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ restrict_return(ಶೂನ್ಯ);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ಪೂರ್ಣಾಂಕ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ಪೂರ್ಣಾಂಕ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ಪೂರ್ಣಾಂಕ **),
               "restrict is removed from a return type");

ಪೂರ್ಣಾಂಕ const_return(ಶೂನ್ಯ)
{
   ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ volatile_return(ಶೂನ್ಯ)
{
   ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ *restrict_return(ಶೂನ್ಯ)
{
   ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
   ಹಿಂತಿರುಗಿ 0;
}

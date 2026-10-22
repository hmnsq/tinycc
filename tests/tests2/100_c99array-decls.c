ಶೂನ್ಯ foo(ಪೂರ್ಣಾಂಕ [5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಂಕ x[ಸ್ಥಿರಾಂಕ 5]);
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಂಕ x[ಸ್ಥಿರ 5]);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಂಕ x[ಅಸ್ಥಿರ 5]);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಂಕ x[ಸೀಮಿತ 5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಂಕ [ಸ್ಥಿರಾಂಕ 5]);
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಂಕ [ಸ್ಥಿರ 5]);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಂಕ [ಅಸ್ಥಿರ 5]);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಂಕ [ಸೀಮಿತ 5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಂಕ (* ಸ್ಥಿರಾಂಕ x));
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಂಕ *x);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಂಕ * ಅಸ್ಥಿರ x);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಂಕ * ಸೀಮಿತ x);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಂಕ x[ಅಸ್ಥಿರ 5])
{
  x[3] = 42;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INVALID
  x = 0;
#ಆದರೆ_ಅಂತ್ಯ
}
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಂಕ x[ಸ್ಥಿರಾಂಕ *]);
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಂಕ * ಸ್ಥಿರಾಂಕ x);

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_array[2];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ restricted_ಸೂಚಕ;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸೀಮಿತ ಸೂಚಕ_array restricted_ಸೂಚಕ_array;

_Static_assert(!__builtin_types_compatible_p(ಪೂರ್ಣಾಂಕ **,
                                             restricted_ಸೂಚಕ *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_ಸೂಚಕ_array,
                                            restricted_ಸೂಚಕ[2]),
               "restrict can qualify an array of pointer types");

restricted_ಸೂಚಕ *restricted_pp;
ಪೂರ್ಣಾಂಕ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_ಸೂಚಕ *),
               "conditional expression combines restrict qualifiers");

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INVALID
ಶೂನ್ಯ wrongc(ಪೂರ್ಣಾಂಕ x[3][ಸ್ಥಿರಾಂಕ 4]);
ಶೂನ್ಯ wrongvm(ಪೂರ್ಣಾಂಕ x[ಸ್ಥಿರ *]);
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಂಕ x[ಸ್ಥಿರಾಂಕ *])
{
  x[2] = 1;
}
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
  ಹಿಂತಿರುಗಿ 0;
}

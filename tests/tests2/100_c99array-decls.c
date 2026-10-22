ಶೂನ್ಯ foo(ಪೂರ್ಣಾಙ್ಕ [5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಙ್ಕ x[ಧ್ರುವ 5]);
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಙ್ಕ x[ಸ್ಥಿರ 5]);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಙ್ಕ x[ಚಞ್ಚಲ 5]);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಙ್ಕ x[restrict 5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಙ್ಕ [ಧ್ರುವ 5]);
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಙ್ಕ [ಸ್ಥಿರ 5]);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಙ್ಕ [ಚಞ್ಚಲ 5]);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಙ್ಕ [restrict 5]);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಙ್ಕ (* ಧ್ರುವ x));
ಶೂನ್ಯ foos(ಪೂರ್ಣಾಙ್ಕ *x);
ಶೂನ್ಯ foov(ಪೂರ್ಣಾಙ್ಕ * ಚಞ್ಚಲ x);
ಶೂನ್ಯ foor(ಪೂರ್ಣಾಙ್ಕ * restrict x);
ಶೂನ್ಯ fooc(ಪೂರ್ಣಾಙ್ಕ x[ಚಞ್ಚಲ 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಙ್ಕ x[ಧ್ರುವ *]);
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಙ್ಕ * ಧ್ರುವ x);

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *pointer_array[2];
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *restrict restricted_pointer;
ಪ್ರಕಾರನಿರ್ದೇಶ restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(ಪೂರ್ಣಾಙ್ಕ **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
ಪೂರ್ಣಾಙ್ಕ **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
ಶೂನ್ಯ wrongc(ಪೂರ್ಣಾಙ್ಕ x[3][ಧ್ರುವ 4]);
ಶೂನ್ಯ wrongvm(ಪೂರ್ಣಾಙ್ಕ x[ಸ್ಥಿರ *]);
ಶೂನ್ಯ foovm(ಪೂರ್ಣಾಙ್ಕ x[ಧ್ರುವ *])
{
  x[2] = 1;
}
#endif
ಪೂರ್ಣಾಙ್ಕ main()
{
  ಪ್ರತ್ಯಾಗಮ 0;
}

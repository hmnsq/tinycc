ಶೂನ್ಯ pointer_parameters(ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ cp, ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ vp, ಪೂರ್ಣಾಙ್ಕ *restrict rp)
{
    _Static_assert(_Generic(&cp, ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ *: 1, ಸ್ವಭಾವ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ *: 1, ಸ್ವಭಾವ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ಪೂರ್ಣಾಙ್ಕ *restrict *: 1, ಸ್ವಭಾವ: 0),
                  "restrict pointer parameter remains qualified");
}

ಶೂನ್ಯ array_parameters(ಪೂರ್ಣಾಙ್ಕ ca[ಧ್ರುವ 2], ಪೂರ್ಣಾಙ್ಕ va[ಚಞ್ಚಲ 2], ಪೂರ್ಣಾಙ್ಕ ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ *: 1, ಸ್ವಭಾವ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ *: 1, ಸ್ವಭಾವ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ಪೂರ್ಣಾಙ್ಕ *restrict *: 1, ಸ್ವಭಾವ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

ಶೂನ್ಯ declared_const(ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ pointer);
ಶೂನ್ಯ declared_const(ಪೂರ್ಣಾಙ್ಕ *pointer)
{
    _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ **: 1, ಸ್ವಭಾವ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ಶೂನ್ಯ defined_const(ಪೂರ್ಣಾಙ್ಕ *pointer);
ಶೂನ್ಯ defined_const(ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ pointer)
{
    _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ *ಧ್ರುವ *: 1, ಸ್ವಭಾವ: 0),
                   "definition retains const");
}

ಶೂನ್ಯ declared_volatile(ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ pointer);
ಶೂನ್ಯ declared_volatile(ಪೂರ್ಣಾಙ್ಕ *pointer)
{
    _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ **: 1, ಸ್ವಭಾವ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ಶೂನ್ಯ defined_volatile(ಪೂರ್ಣಾಙ್ಕ *pointer);
ಶೂನ್ಯ defined_volatile(ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ pointer)
{
    _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ *ಚಞ್ಚಲ *: 1, ಸ್ವಭಾವ: 0),
                   "definition retains volatile");
    pointer = 0;
}

ಶೂನ್ಯ declared_restrict(ಪೂರ್ಣಾಙ್ಕ *restrict pointer);
ಶೂನ್ಯ declared_restrict(ಪೂರ್ಣಾಙ್ಕ *pointer)
{
  _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ **: 1, ಸ್ವಭಾವ: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

ಶೂನ್ಯ defined_restrict(ಪೂರ್ಣಾಙ್ಕ *pointer);
ಶೂನ್ಯ defined_restrict(ಪೂರ್ಣಾಙ್ಕ *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ಪೂರ್ಣಾಙ್ಕ *restrict *: 1, ಸ್ವಭಾವ: 0),
                 "definition retains restrict");
  pointer = 0;
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ಪ್ರತ್ಯಾಗಮ 0;
}

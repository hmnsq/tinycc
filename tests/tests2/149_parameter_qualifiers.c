ಶೂನ್ಯ ಸೂಚಕ_parameters(ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ cp, ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ vp, ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ rp)
{
    _Static_assert(_Generic(&cp, ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                  "restrict pointer parameter remains qualified");
}

ಶೂನ್ಯ array_parameters(ಪೂರ್ಣಾಂಕ ca[ಸ್ಥಿರಾಂಕ 2], ಪೂರ್ಣಾಂಕ va[ಅಸ್ಥಿರ 2], ಪೂರ್ಣಾಂಕ ra[ಸೀಮಿತ 2])
{
    _Static_assert(_Generic(&ca, ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

ಶೂನ್ಯ declared_const(ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ ಸೂಚಕ_2);
ಶೂನ್ಯ declared_const(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2)
{
    _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ **: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "declaration qualifier does not affect definition");
    ಸೂಚಕ_2 = 0;
}

ಶೂನ್ಯ defined_const(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2);
ಶೂನ್ಯ defined_const(ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ ಸೂಚಕ_2)
{
    _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ *ಸ್ಥಿರಾಂಕ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "definition retains const");
}

ಶೂನ್ಯ declared_volatile(ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ ಸೂಚಕ_2);
ಶೂನ್ಯ declared_volatile(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2)
{
    _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ **: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "declaration qualifier does not affect definition");
    ಸೂಚಕ_2 = 0;
}

ಶೂನ್ಯ defined_volatile(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2);
ಶೂನ್ಯ defined_volatile(ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ ಸೂಚಕ_2)
{
    _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ *ಅಸ್ಥಿರ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                   "definition retains volatile");
    ಸೂಚಕ_2 = 0;
}

ಶೂನ್ಯ declared_restrict(ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ ಸೂಚಕ_2);
ಶೂನ್ಯ declared_restrict(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2)
{
  _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ **: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                 "declaration qualifier does not affect definition");
  ಸೂಚಕ_2 = 0;
}

ಶೂನ್ಯ defined_restrict(ಪೂರ್ಣಾಂಕ *ಸೂಚಕ_2);
ಶೂನ್ಯ defined_restrict(ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ ಸೂಚಕ_2)
{
  _Static_assert(_Generic(&ಸೂಚಕ_2, ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ *: 1, ಪೂರ್ವನಿಯೋಜಿತ: 0),
                 "definition retains restrict");
  ಸೂಚಕ_2 = 0;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಹಿಂತಿರುಗಿ 0;
}

शून्य pointer_parameters(पूर्णाङ्क *ध्रुव cp, पूर्णाङ्क *चञ्चल vp, पूर्णाङ्क *सीमित rp)
{
    _Static_assert(_Generic(&cp, पूर्णाङ्क *ध्रुव *: 1, स्वभाव: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, पूर्णाङ्क *चञ्चल *: 1, स्वभाव: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, पूर्णाङ्क *सीमित *: 1, स्वभाव: 0),
                  "restrict pointer parameter remains qualified");
}

शून्य array_parameters(पूर्णाङ्क ca[ध्रुव 2], पूर्णाङ्क va[चञ्चल 2], पूर्णाङ्क ra[सीमित 2])
{
    _Static_assert(_Generic(&ca, पूर्णाङ्क *ध्रुव *: 1, स्वभाव: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, पूर्णाङ्क *चञ्चल *: 1, स्वभाव: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, पूर्णाङ्क *सीमित *: 1, स्वभाव: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

शून्य declared_const(पूर्णाङ्क *ध्रुव pointer);
शून्य declared_const(पूर्णाङ्क *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णाङ्क **: 1, स्वभाव: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

शून्य defined_const(पूर्णाङ्क *pointer);
शून्य defined_const(पूर्णाङ्क *ध्रुव pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णाङ्क *ध्रुव *: 1, स्वभाव: 0),
                   "definition retains const");
}

शून्य declared_volatile(पूर्णाङ्क *चञ्चल pointer);
शून्य declared_volatile(पूर्णाङ्क *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णाङ्क **: 1, स्वभाव: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

शून्य defined_volatile(पूर्णाङ्क *pointer);
शून्य defined_volatile(पूर्णाङ्क *चञ्चल pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णाङ्क *चञ्चल *: 1, स्वभाव: 0),
                   "definition retains volatile");
    pointer = 0;
}

शून्य declared_restrict(पूर्णाङ्क *सीमित pointer);
शून्य declared_restrict(पूर्णाङ्क *pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णाङ्क **: 1, स्वभाव: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

शून्य defined_restrict(पूर्णाङ्क *pointer);
शून्य defined_restrict(पूर्णाङ्क *सीमित pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णाङ्क *सीमित *: 1, स्वभाव: 0),
                 "definition retains restrict");
  pointer = 0;
}

पूर्णाङ्क मुख्यम्(शून्य)
{
    प्रत्यागम 0;
}

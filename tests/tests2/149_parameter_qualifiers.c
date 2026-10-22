शून्य pointer_parameters(पूर्णांक *स्थिरांक cp, पूर्णांक *अस्थिर vp, पूर्णांक *restrict rp)
{
    _Static_assert(_Generic(&cp, पूर्णांक *स्थिरांक *: 1, पूर्वनिर्धारित: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, पूर्णांक *अस्थिर *: 1, पूर्वनिर्धारित: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, पूर्णांक *restrict *: 1, पूर्वनिर्धारित: 0),
                  "restrict pointer parameter remains qualified");
}

शून्य array_parameters(पूर्णांक ca[स्थिरांक 2], पूर्णांक va[अस्थिर 2], पूर्णांक ra[restrict 2])
{
    _Static_assert(_Generic(&ca, पूर्णांक *स्थिरांक *: 1, पूर्वनिर्धारित: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, पूर्णांक *अस्थिर *: 1, पूर्वनिर्धारित: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, पूर्णांक *restrict *: 1, पूर्वनिर्धारित: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

शून्य declared_const(पूर्णांक *स्थिरांक pointer);
शून्य declared_const(पूर्णांक *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक **: 1, पूर्वनिर्धारित: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

शून्य defined_const(पूर्णांक *pointer);
शून्य defined_const(पूर्णांक *स्थिरांक pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक *स्थिरांक *: 1, पूर्वनिर्धारित: 0),
                   "definition retains const");
}

शून्य declared_volatile(पूर्णांक *अस्थिर pointer);
शून्य declared_volatile(पूर्णांक *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक **: 1, पूर्वनिर्धारित: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

शून्य defined_volatile(पूर्णांक *pointer);
शून्य defined_volatile(पूर्णांक *अस्थिर pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक *अस्थिर *: 1, पूर्वनिर्धारित: 0),
                   "definition retains volatile");
    pointer = 0;
}

शून्य declared_restrict(पूर्णांक *restrict pointer);
शून्य declared_restrict(पूर्णांक *pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णांक **: 1, पूर्वनिर्धारित: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

शून्य defined_restrict(पूर्णांक *pointer);
शून्य defined_restrict(पूर्णांक *restrict pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णांक *restrict *: 1, पूर्वनिर्धारित: 0),
                 "definition retains restrict");
  pointer = 0;
}

पूर्णांक main(शून्य)
{
    परत 0;
}

व्योम pointer_parameters(पूर्णांक *स्थिर cp, पूर्णांक *अस्थिर vp, पूर्णांक *restrict rp)
{
    _Static_assert(_Generic(&cp, पूर्णांक *स्थिर *: 1, शेष: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, पूर्णांक *अस्थिर *: 1, शेष: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, पूर्णांक *restrict *: 1, शेष: 0),
                  "restrict pointer parameter remains qualified");
}

व्योम array_parameters(पूर्णांक ca[स्थिर 2], पूर्णांक va[अस्थिर 2], पूर्णांक ra[restrict 2])
{
    _Static_assert(_Generic(&ca, पूर्णांक *स्थिर *: 1, शेष: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, पूर्णांक *अस्थिर *: 1, शेष: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, पूर्णांक *restrict *: 1, शेष: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

व्योम declared_const(पूर्णांक *स्थिर pointer);
व्योम declared_const(पूर्णांक *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक **: 1, शेष: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

व्योम defined_const(पूर्णांक *pointer);
व्योम defined_const(पूर्णांक *स्थिर pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक *स्थिर *: 1, शेष: 0),
                   "definition retains const");
}

व्योम declared_volatile(पूर्णांक *अस्थिर pointer);
व्योम declared_volatile(पूर्णांक *pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक **: 1, शेष: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

व्योम defined_volatile(पूर्णांक *pointer);
व्योम defined_volatile(पूर्णांक *अस्थिर pointer)
{
    _Static_assert(_Generic(&pointer, पूर्णांक *अस्थिर *: 1, शेष: 0),
                   "definition retains volatile");
    pointer = 0;
}

व्योम declared_restrict(पूर्णांक *restrict pointer);
व्योम declared_restrict(पूर्णांक *pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णांक **: 1, शेष: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

व्योम defined_restrict(पूर्णांक *pointer);
व्योम defined_restrict(पूर्णांक *restrict pointer)
{
  _Static_assert(_Generic(&pointer, पूर्णांक *restrict *: 1, शेष: 0),
                 "definition retains restrict");
  pointer = 0;
}

पूर्णांक मुख्य(व्योम)
{
    वापस 0;
}

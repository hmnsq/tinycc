void pointer_parameters(целое *const cp, целое *volatile vp, целое *restrict rp)
{
    _Static_assert(_Generic(&cp, целое *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, целое *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, целое *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(целое ca[const 2], целое va[volatile 2], целое ra[restrict 2])
{
    _Static_assert(_Generic(&ca, целое *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, целое *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, целое *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(целое *const pointer);
void declared_const(целое *pointer)
{
    _Static_assert(_Generic(&pointer, целое **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(целое *pointer);
void defined_const(целое *const pointer)
{
    _Static_assert(_Generic(&pointer, целое *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(целое *volatile pointer);
void declared_volatile(целое *pointer)
{
    _Static_assert(_Generic(&pointer, целое **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(целое *pointer);
void defined_volatile(целое *volatile pointer)
{
    _Static_assert(_Generic(&pointer, целое *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(целое *restrict pointer);
void declared_restrict(целое *pointer)
{
  _Static_assert(_Generic(&pointer, целое **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(целое *pointer);
void defined_restrict(целое *restrict pointer)
{
  _Static_assert(_Generic(&pointer, целое *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

целое основной(void)
{
    вернуть 0;
}

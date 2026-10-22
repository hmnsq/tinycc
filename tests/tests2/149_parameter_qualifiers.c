void pointer_parameters(ціле *const cp, ціле *volatile vp, ціле *restrict rp)
{
    _Static_assert(_Generic(&cp, ціле *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ціле *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ціле *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(ціле ca[const 2], ціле va[volatile 2], ціле ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ціле *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ціле *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ціле *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(ціле *const pointer);
void declared_const(ціле *pointer)
{
    _Static_assert(_Generic(&pointer, ціле **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(ціле *pointer);
void defined_const(ціле *const pointer)
{
    _Static_assert(_Generic(&pointer, ціле *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(ціле *volatile pointer);
void declared_volatile(ціле *pointer)
{
    _Static_assert(_Generic(&pointer, ціле **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(ціле *pointer);
void defined_volatile(ціле *volatile pointer)
{
    _Static_assert(_Generic(&pointer, ціле *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(ціле *restrict pointer);
void declared_restrict(ціле *pointer)
{
  _Static_assert(_Generic(&pointer, ціле **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(ціле *pointer);
void defined_restrict(ціле *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ціле *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

ціле main(void)
{
    повернути 0;
}

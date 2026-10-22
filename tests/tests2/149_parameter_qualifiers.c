void pointer_parameters(цео *const cp, цео *volatile vp, цео *restrict rp)
{
    _Static_assert(_Generic(&cp, цео *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, цео *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, цео *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(цео ca[const 2], цео va[volatile 2], цео ra[restrict 2])
{
    _Static_assert(_Generic(&ca, цео *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, цео *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, цео *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(цео *const pointer);
void declared_const(цео *pointer)
{
    _Static_assert(_Generic(&pointer, цео **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(цео *pointer);
void defined_const(цео *const pointer)
{
    _Static_assert(_Generic(&pointer, цео *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(цео *volatile pointer);
void declared_volatile(цео *pointer)
{
    _Static_assert(_Generic(&pointer, цео **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(цео *pointer);
void defined_volatile(цео *volatile pointer)
{
    _Static_assert(_Generic(&pointer, цео *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(цео *restrict pointer);
void declared_restrict(цео *pointer)
{
  _Static_assert(_Generic(&pointer, цео **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(цео *pointer);
void defined_restrict(цео *restrict pointer)
{
  _Static_assert(_Generic(&pointer, цео *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

цео main(void)
{
    врати 0;
}

void pointer_parameters(số_nguyên *const cp, số_nguyên *volatile vp, số_nguyên *restrict rp)
{
    _Static_assert(_Generic(&cp, số_nguyên *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, số_nguyên *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, số_nguyên *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(số_nguyên ca[const 2], số_nguyên va[volatile 2], số_nguyên ra[restrict 2])
{
    _Static_assert(_Generic(&ca, số_nguyên *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, số_nguyên *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, số_nguyên *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(số_nguyên *const pointer);
void declared_const(số_nguyên *pointer)
{
    _Static_assert(_Generic(&pointer, số_nguyên **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(số_nguyên *pointer);
void defined_const(số_nguyên *const pointer)
{
    _Static_assert(_Generic(&pointer, số_nguyên *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(số_nguyên *volatile pointer);
void declared_volatile(số_nguyên *pointer)
{
    _Static_assert(_Generic(&pointer, số_nguyên **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(số_nguyên *pointer);
void defined_volatile(số_nguyên *volatile pointer)
{
    _Static_assert(_Generic(&pointer, số_nguyên *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(số_nguyên *restrict pointer);
void declared_restrict(số_nguyên *pointer)
{
  _Static_assert(_Generic(&pointer, số_nguyên **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(số_nguyên *pointer);
void defined_restrict(số_nguyên *restrict pointer)
{
  _Static_assert(_Generic(&pointer, số_nguyên *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

số_nguyên main(void)
{
    trả_về 0;
}

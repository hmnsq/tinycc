void pointer_parameters(정수 *const cp, 정수 *volatile vp, 정수 *restrict rp)
{
    _Static_assert(_Generic(&cp, 정수 *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, 정수 *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, 정수 *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(정수 ca[const 2], 정수 va[volatile 2], 정수 ra[restrict 2])
{
    _Static_assert(_Generic(&ca, 정수 *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, 정수 *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, 정수 *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(정수 *const pointer);
void declared_const(정수 *pointer)
{
    _Static_assert(_Generic(&pointer, 정수 **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(정수 *pointer);
void defined_const(정수 *const pointer)
{
    _Static_assert(_Generic(&pointer, 정수 *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(정수 *volatile pointer);
void declared_volatile(정수 *pointer)
{
    _Static_assert(_Generic(&pointer, 정수 **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(정수 *pointer);
void defined_volatile(정수 *volatile pointer)
{
    _Static_assert(_Generic(&pointer, 정수 *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(정수 *restrict pointer);
void declared_restrict(정수 *pointer)
{
  _Static_assert(_Generic(&pointer, 정수 **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(정수 *pointer);
void defined_restrict(정수 *restrict pointer)
{
  _Static_assert(_Generic(&pointer, 정수 *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

정수 main(void)
{
    반환 0;
}

void pointer_parameters(整数 *const cp, 整数 *volatile vp, 整数 *restrict rp)
{
    _Static_assert(_Generic(&cp, 整数 *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, 整数 *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, 整数 *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(整数 ca[const 2], 整数 va[volatile 2], 整数 ra[restrict 2])
{
    _Static_assert(_Generic(&ca, 整数 *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, 整数 *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, 整数 *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(整数 *const pointer);
void declared_const(整数 *pointer)
{
    _Static_assert(_Generic(&pointer, 整数 **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(整数 *pointer);
void defined_const(整数 *const pointer)
{
    _Static_assert(_Generic(&pointer, 整数 *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(整数 *volatile pointer);
void declared_volatile(整数 *pointer)
{
    _Static_assert(_Generic(&pointer, 整数 **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(整数 *pointer);
void defined_volatile(整数 *volatile pointer)
{
    _Static_assert(_Generic(&pointer, 整数 *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(整数 *restrict pointer);
void declared_restrict(整数 *pointer)
{
  _Static_assert(_Generic(&pointer, 整数 **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(整数 *pointer);
void defined_restrict(整数 *restrict pointer)
{
  _Static_assert(_Generic(&pointer, 整数 *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

整数 主要(void)
{
    返回 0;
}

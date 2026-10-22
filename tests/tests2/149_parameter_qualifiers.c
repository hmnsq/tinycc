void pointer_parameters(цяло *const cp, цяло *volatile vp, цяло *restrict rp)
{
    _Static_assert(_Generic(&cp, цяло *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, цяло *volatile *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, цяло *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(цяло ca[const 2], цяло va[volatile 2], цяло ra[restrict 2])
{
    _Static_assert(_Generic(&ca, цяло *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, цяло *volatile *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, цяло *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(цяло *const pointer);
void declared_const(цяло *pointer)
{
    _Static_assert(_Generic(&pointer, цяло **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(цяло *pointer);
void defined_const(цяло *const pointer)
{
    _Static_assert(_Generic(&pointer, цяло *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(цяло *volatile pointer);
void declared_volatile(цяло *pointer)
{
    _Static_assert(_Generic(&pointer, цяло **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(цяло *pointer);
void defined_volatile(цяло *volatile pointer)
{
    _Static_assert(_Generic(&pointer, цяло *volatile *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(цяло *restrict pointer);
void declared_restrict(цяло *pointer)
{
  _Static_assert(_Generic(&pointer, цяло **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(цяло *pointer);
void defined_restrict(цяло *restrict pointer)
{
  _Static_assert(_Generic(&pointer, цяло *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

цяло main(void)
{
    върни 0;
}

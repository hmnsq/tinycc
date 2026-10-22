void pointer_parameters(ཧྲིལ *const cp, ཧྲིལ *ca_ncala vp, ཧྲིལ *restrict rp)
{
    _Static_assert(_Generic(&cp, ཧྲིལ *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ཧྲིལ *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ཧྲིལ *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(ཧྲིལ ca[const 2], ཧྲིལ va[ca_ncala 2], ཧྲིལ ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ཧྲིལ *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ཧྲིལ *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ཧྲིལ *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(ཧྲིལ *const pointer);
void declared_const(ཧྲིལ *pointer)
{
    _Static_assert(_Generic(&pointer, ཧྲིལ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(ཧྲིལ *pointer);
void defined_const(ཧྲིལ *const pointer)
{
    _Static_assert(_Generic(&pointer, ཧྲིལ *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(ཧྲིལ *ca_ncala pointer);
void declared_volatile(ཧྲིལ *pointer)
{
    _Static_assert(_Generic(&pointer, ཧྲིལ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(ཧྲིལ *pointer);
void defined_volatile(ཧྲིལ *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, ཧྲིལ *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(ཧྲིལ *restrict pointer);
void declared_restrict(ཧྲིལ *pointer)
{
  _Static_assert(_Generic(&pointer, ཧྲིལ **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(ཧྲིལ *pointer);
void defined_restrict(ཧྲིལ *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ཧྲིལ *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

ཧྲིལ main(void)
{
    ལོག 0;
}

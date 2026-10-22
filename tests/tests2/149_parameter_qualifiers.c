void pointer_parameters(ចំនួនគត់ *const cp, ចំនួនគត់ *ca_ncala vp, ចំនួនគត់ *restrict rp)
{
    _Static_assert(_Generic(&cp, ចំនួនគត់ *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ចំនួនគត់ *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ចំនួនគត់ *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(ចំនួនគត់ ca[const 2], ចំនួនគត់ va[ca_ncala 2], ចំនួនគត់ ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ចំនួនគត់ *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ចំនួនគត់ *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ចំនួនគត់ *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(ចំនួនគត់ *const pointer);
void declared_const(ចំនួនគត់ *pointer)
{
    _Static_assert(_Generic(&pointer, ចំនួនគត់ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(ចំនួនគត់ *pointer);
void defined_const(ចំនួនគត់ *const pointer)
{
    _Static_assert(_Generic(&pointer, ចំនួនគត់ *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(ចំនួនគត់ *ca_ncala pointer);
void declared_volatile(ចំនួនគត់ *pointer)
{
    _Static_assert(_Generic(&pointer, ចំនួនគត់ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(ចំនួនគត់ *pointer);
void defined_volatile(ចំនួនគត់ *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, ចំនួនគត់ *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(ចំនួនគត់ *restrict pointer);
void declared_restrict(ចំនួនគត់ *pointer)
{
  _Static_assert(_Generic(&pointer, ចំនួនគត់ **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(ចំនួនគត់ *pointer);
void defined_restrict(ចំនួនគត់ *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ចំនួនគត់ *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

ចំនួនគត់ main(void)
{
    ត្រឡប់ 0;
}

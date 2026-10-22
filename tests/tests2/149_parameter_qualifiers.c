void pointer_parameters(จำนวนเต็ม *const cp, จำนวนเต็ม *ca_ncala vp, จำนวนเต็ม *restrict rp)
{
    _Static_assert(_Generic(&cp, จำนวนเต็ม *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, จำนวนเต็ม *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, จำนวนเต็ม *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(จำนวนเต็ม ca[const 2], จำนวนเต็ม va[ca_ncala 2], จำนวนเต็ม ra[restrict 2])
{
    _Static_assert(_Generic(&ca, จำนวนเต็ม *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, จำนวนเต็ม *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, จำนวนเต็ม *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(จำนวนเต็ม *const pointer);
void declared_const(จำนวนเต็ม *pointer)
{
    _Static_assert(_Generic(&pointer, จำนวนเต็ม **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(จำนวนเต็ม *pointer);
void defined_const(จำนวนเต็ม *const pointer)
{
    _Static_assert(_Generic(&pointer, จำนวนเต็ม *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(จำนวนเต็ม *ca_ncala pointer);
void declared_volatile(จำนวนเต็ม *pointer)
{
    _Static_assert(_Generic(&pointer, จำนวนเต็ม **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(จำนวนเต็ม *pointer);
void defined_volatile(จำนวนเต็ม *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, จำนวนเต็ม *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(จำนวนเต็ม *restrict pointer);
void declared_restrict(จำนวนเต็ม *pointer)
{
  _Static_assert(_Generic(&pointer, จำนวนเต็ม **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(จำนวนเต็ม *pointer);
void defined_restrict(จำนวนเต็ม *restrict pointer)
{
  _Static_assert(_Generic(&pointer, จำนวนเต็ม *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

จำนวนเต็ม หลัก(void)
{
    คืน 0;
}

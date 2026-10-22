void pointer_parameters(ကိန်းပြည့် *const cp, ကိန်းပြည့် *ca_ncala vp, ကိန်းပြည့် *restrict rp)
{
    _Static_assert(_Generic(&cp, ကိန်းပြည့် *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ကိန်းပြည့် *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ကိန်းပြည့် *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(ကိန်းပြည့် ca[const 2], ကိန်းပြည့် va[ca_ncala 2], ကိန်းပြည့် ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ကိန်းပြည့် *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ကိန်းပြည့် *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ကိန်းပြည့် *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(ကိန်းပြည့် *const pointer);
void declared_const(ကိန်းပြည့် *pointer)
{
    _Static_assert(_Generic(&pointer, ကိန်းပြည့် **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(ကိန်းပြည့် *pointer);
void defined_const(ကိန်းပြည့် *const pointer)
{
    _Static_assert(_Generic(&pointer, ကိန်းပြည့် *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(ကိန်းပြည့် *ca_ncala pointer);
void declared_volatile(ကိန်းပြည့် *pointer)
{
    _Static_assert(_Generic(&pointer, ကိန်းပြည့် **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(ကိန်းပြည့် *pointer);
void defined_volatile(ကိန်းပြည့် *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, ကိန်းပြည့် *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(ကိန်းပြည့် *restrict pointer);
void declared_restrict(ကိန်းပြည့် *pointer)
{
  _Static_assert(_Generic(&pointer, ကိန်းပြည့် **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(ကိန်းပြည့် *pointer);
void defined_restrict(ကိန်းပြည့် *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ကိန်းပြည့် *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

ကိန်းပြည့် main(void)
{
    ပြန်ပေး 0;
}

void pointer_parameters(puur_naa_nka *const cp, puur_naa_nka *ca_ncala vp, puur_naa_nka *restrict rp)
{
    _Static_assert(_Generic(&cp, puur_naa_nka *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, puur_naa_nka *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, puur_naa_nka *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(puur_naa_nka ca[const 2], puur_naa_nka va[ca_ncala 2], puur_naa_nka ra[restrict 2])
{
    _Static_assert(_Generic(&ca, puur_naa_nka *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, puur_naa_nka *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, puur_naa_nka *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(puur_naa_nka *const pointer);
void declared_const(puur_naa_nka *pointer)
{
    _Static_assert(_Generic(&pointer, puur_naa_nka **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(puur_naa_nka *pointer);
void defined_const(puur_naa_nka *const pointer)
{
    _Static_assert(_Generic(&pointer, puur_naa_nka *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(puur_naa_nka *ca_ncala pointer);
void declared_volatile(puur_naa_nka *pointer)
{
    _Static_assert(_Generic(&pointer, puur_naa_nka **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(puur_naa_nka *pointer);
void defined_volatile(puur_naa_nka *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, puur_naa_nka *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(puur_naa_nka *restrict pointer);
void declared_restrict(puur_naa_nka *pointer)
{
  _Static_assert(_Generic(&pointer, puur_naa_nka **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(puur_naa_nka *pointer);
void defined_restrict(puur_naa_nka *restrict pointer)
{
  _Static_assert(_Generic(&pointer, puur_naa_nka *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

puur_naa_nka main(void)
{
    ᨀᨘᨒ 0;
}

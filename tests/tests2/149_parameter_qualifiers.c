void pointer_parameters(පූර්ණ_සංඛ්‍යා *const cp, පූර්ණ_සංඛ්‍යා *ca_ncala vp, පූර්ණ_සංඛ්‍යා *restrict rp)
{
    _Static_assert(_Generic(&cp, පූර්ණ_සංඛ්‍යා *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, පූර්ණ_සංඛ්‍යා *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, පූර්ණ_සංඛ්‍යා *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(පූර්ණ_සංඛ්‍යා ca[const 2], පූර්ණ_සංඛ්‍යා va[ca_ncala 2], පූර්ණ_සංඛ්‍යා ra[restrict 2])
{
    _Static_assert(_Generic(&ca, පූර්ණ_සංඛ්‍යා *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, පූර්ණ_සංඛ්‍යා *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, පූර්ණ_සංඛ්‍යා *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(පූර්ණ_සංඛ්‍යා *const pointer);
void declared_const(පූර්ණ_සංඛ්‍යා *pointer)
{
    _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(පූර්ණ_සංඛ්‍යා *pointer);
void defined_const(පූර්ණ_සංඛ්‍යා *const pointer)
{
    _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(පූර්ණ_සංඛ්‍යා *ca_ncala pointer);
void declared_volatile(පූර්ණ_සංඛ්‍යා *pointer)
{
    _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(පූර්ණ_සංඛ්‍යා *pointer);
void defined_volatile(පූර්ණ_සංඛ්‍යා *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(පූර්ණ_සංඛ්‍යා *restrict pointer);
void declared_restrict(පූර්ණ_සංඛ්‍යා *pointer)
{
  _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(පූර්ණ_සංඛ්‍යා *pointer);
void defined_restrict(පූර්ණ_සංඛ්‍යා *restrict pointer)
{
  _Static_assert(_Generic(&pointer, පූර්ණ_සංඛ්‍යා *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

පූර්ණ_සංඛ්‍යා main(void)
{
    ආපසු 0;
}

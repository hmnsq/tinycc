void pointer_parameters(ຈຳນວນເຕັມ *const cp, ຈຳນວນເຕັມ *ca_ncala vp, ຈຳນວນເຕັມ *restrict rp)
{
    _Static_assert(_Generic(&cp, ຈຳນວນເຕັມ *const *: 1, default: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ຈຳນວນເຕັມ *ca_ncala *: 1, default: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ຈຳນວນເຕັມ *restrict *: 1, default: 0),
                  "restrict pointer parameter remains qualified");
}

void array_parameters(ຈຳນວນເຕັມ ca[const 2], ຈຳນວນເຕັມ va[ca_ncala 2], ຈຳນວນເຕັມ ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ຈຳນວນເຕັມ *const *: 1, default: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ຈຳນວນເຕັມ *ca_ncala *: 1, default: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ຈຳນວນເຕັມ *restrict *: 1, default: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

void declared_const(ຈຳນວນເຕັມ *const pointer);
void declared_const(ຈຳນວນເຕັມ *pointer)
{
    _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_const(ຈຳນວນເຕັມ *pointer);
void defined_const(ຈຳນວນເຕັມ *const pointer)
{
    _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ *const *: 1, default: 0),
                   "definition retains const");
}

void declared_volatile(ຈຳນວນເຕັມ *ca_ncala pointer);
void declared_volatile(ຈຳນວນເຕັມ *pointer)
{
    _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ **: 1, default: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

void defined_volatile(ຈຳນວນເຕັມ *pointer);
void defined_volatile(ຈຳນວນເຕັມ *ca_ncala pointer)
{
    _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ *ca_ncala *: 1, default: 0),
                   "definition retains volatile");
    pointer = 0;
}

void declared_restrict(ຈຳນວນເຕັມ *restrict pointer);
void declared_restrict(ຈຳນວນເຕັມ *pointer)
{
  _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ **: 1, default: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

void defined_restrict(ຈຳນວນເຕັມ *pointer);
void defined_restrict(ຈຳນວນເຕັມ *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ຈຳນວນເຕັມ *restrict *: 1, default: 0),
                 "definition retains restrict");
  pointer = 0;
}

ຈຳນວນເຕັມ main(void)
{
    ສົ່ງຄືນ 0;
}

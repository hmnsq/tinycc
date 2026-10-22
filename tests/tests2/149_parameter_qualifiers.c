வெறுமை pointer_parameters(முழு *மாறிலி cp, முழு *நிலையற்ற vp, முழு *restrict rp)
{
    _Static_assert(_Generic(&cp, முழு *மாறிலி *: 1, இயல்பு: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, முழு *நிலையற்ற *: 1, இயல்பு: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, முழு *restrict *: 1, இயல்பு: 0),
                  "restrict pointer parameter remains qualified");
}

வெறுமை array_parameters(முழு ca[மாறிலி 2], முழு va[நிலையற்ற 2], முழு ra[restrict 2])
{
    _Static_assert(_Generic(&ca, முழு *மாறிலி *: 1, இயல்பு: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, முழு *நிலையற்ற *: 1, இயல்பு: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, முழு *restrict *: 1, இயல்பு: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

வெறுமை declared_const(முழு *மாறிலி pointer);
வெறுமை declared_const(முழு *pointer)
{
    _Static_assert(_Generic(&pointer, முழு **: 1, இயல்பு: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

வெறுமை defined_const(முழு *pointer);
வெறுமை defined_const(முழு *மாறிலி pointer)
{
    _Static_assert(_Generic(&pointer, முழு *மாறிலி *: 1, இயல்பு: 0),
                   "definition retains const");
}

வெறுமை declared_volatile(முழு *நிலையற்ற pointer);
வெறுமை declared_volatile(முழு *pointer)
{
    _Static_assert(_Generic(&pointer, முழு **: 1, இயல்பு: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

வெறுமை defined_volatile(முழு *pointer);
வெறுமை defined_volatile(முழு *நிலையற்ற pointer)
{
    _Static_assert(_Generic(&pointer, முழு *நிலையற்ற *: 1, இயல்பு: 0),
                   "definition retains volatile");
    pointer = 0;
}

வெறுமை declared_restrict(முழு *restrict pointer);
வெறுமை declared_restrict(முழு *pointer)
{
  _Static_assert(_Generic(&pointer, முழு **: 1, இயல்பு: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

வெறுமை defined_restrict(முழு *pointer);
வெறுமை defined_restrict(முழு *restrict pointer)
{
  _Static_assert(_Generic(&pointer, முழு *restrict *: 1, இயல்பு: 0),
                 "definition retains restrict");
  pointer = 0;
}

முழு முதன்மை(வெறுமை)
{
    திரும்பு 0;
}

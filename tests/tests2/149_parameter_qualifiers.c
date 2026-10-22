ਖਾਲੀ ਸੂਚਕ_parameters(ਪੂਰਨ *ਅਚਲ cp, ਪੂਰਨ *ਅਸਥਿਰ vp, ਪੂਰਨ *ਸੀਮਿਤ rp)
{
    _Static_assert(_Generic(&cp, ਪੂਰਨ *ਅਚਲ *: 1, ਮੂਲ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ਪੂਰਨ *ਅਸਥਿਰ *: 1, ਮੂਲ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ਪੂਰਨ *ਸੀਮਿਤ *: 1, ਮੂਲ: 0),
                  "restrict pointer parameter remains qualified");
}

ਖਾਲੀ array_parameters(ਪੂਰਨ ca[ਅਚਲ 2], ਪੂਰਨ va[ਅਸਥਿਰ 2], ਪੂਰਨ ra[ਸੀਮਿਤ 2])
{
    _Static_assert(_Generic(&ca, ਪੂਰਨ *ਅਚਲ *: 1, ਮੂਲ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ਪੂਰਨ *ਅਸਥਿਰ *: 1, ਮੂਲ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ਪੂਰਨ *ਸੀਮਿਤ *: 1, ਮੂਲ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

ਖਾਲੀ declared_const(ਪੂਰਨ *ਅਚਲ ਸੂਚਕ);
ਖਾਲੀ declared_const(ਪੂਰਨ *ਸੂਚਕ)
{
    _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ **: 1, ਮੂਲ: 0),
                   "declaration qualifier does not affect definition");
    ਸੂਚਕ = 0;
}

ਖਾਲੀ defined_const(ਪੂਰਨ *ਸੂਚਕ);
ਖਾਲੀ defined_const(ਪੂਰਨ *ਅਚਲ ਸੂਚਕ)
{
    _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ *ਅਚਲ *: 1, ਮੂਲ: 0),
                   "definition retains const");
}

ਖਾਲੀ declared_volatile(ਪੂਰਨ *ਅਸਥਿਰ ਸੂਚਕ);
ਖਾਲੀ declared_volatile(ਪੂਰਨ *ਸੂਚਕ)
{
    _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ **: 1, ਮੂਲ: 0),
                   "declaration qualifier does not affect definition");
    ਸੂਚਕ = 0;
}

ਖਾਲੀ defined_volatile(ਪੂਰਨ *ਸੂਚਕ);
ਖਾਲੀ defined_volatile(ਪੂਰਨ *ਅਸਥਿਰ ਸੂਚਕ)
{
    _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ *ਅਸਥਿਰ *: 1, ਮੂਲ: 0),
                   "definition retains volatile");
    ਸੂਚਕ = 0;
}

ਖਾਲੀ declared_restrict(ਪੂਰਨ *ਸੀਮਿਤ ਸੂਚਕ);
ਖਾਲੀ declared_restrict(ਪੂਰਨ *ਸੂਚਕ)
{
  _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ **: 1, ਮੂਲ: 0),
                 "declaration qualifier does not affect definition");
  ਸੂਚਕ = 0;
}

ਖਾਲੀ defined_restrict(ਪੂਰਨ *ਸੂਚਕ);
ਖਾਲੀ defined_restrict(ਪੂਰਨ *ਸੀਮਿਤ ਸੂਚਕ)
{
  _Static_assert(_Generic(&ਸੂਚਕ, ਪੂਰਨ *ਸੀਮਿਤ *: 1, ਮੂਲ: 0),
                 "definition retains restrict");
  ਸੂਚਕ = 0;
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਵਾਪਸ 0;
}

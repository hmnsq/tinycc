فراغ اشارو_parameters(صحيح *ثابت cp, صحيح *متطاير vp, صحيح *محدود rp)
{
    _Static_assert(_Generic(&cp, صحيح *ثابت *: 1, افتراضي: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, صحيح *متطاير *: 1, افتراضي: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, صحيح *محدود *: 1, افتراضي: 0),
                  "restrict pointer parameter remains qualified");
}

فراغ array_parameters(صحيح ca[ثابت 2], صحيح va[متطاير 2], صحيح ra[محدود 2])
{
    _Static_assert(_Generic(&ca, صحيح *ثابت *: 1, افتراضي: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, صحيح *متطاير *: 1, افتراضي: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, صحيح *محدود *: 1, افتراضي: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

فراغ declared_const(صحيح *ثابت اشارو);
فراغ declared_const(صحيح *اشارو)
{
    _Static_assert(_Generic(&اشارو, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشارو = 0;
}

فراغ defined_const(صحيح *اشارو);
فراغ defined_const(صحيح *ثابت اشارو)
{
    _Static_assert(_Generic(&اشارو, صحيح *ثابت *: 1, افتراضي: 0),
                   "definition retains const");
}

فراغ declared_volatile(صحيح *متطاير اشارو);
فراغ declared_volatile(صحيح *اشارو)
{
    _Static_assert(_Generic(&اشارو, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشارو = 0;
}

فراغ defined_volatile(صحيح *اشارو);
فراغ defined_volatile(صحيح *متطاير اشارو)
{
    _Static_assert(_Generic(&اشارو, صحيح *متطاير *: 1, افتراضي: 0),
                   "definition retains volatile");
    اشارو = 0;
}

فراغ declared_restrict(صحيح *محدود اشارو);
فراغ declared_restrict(صحيح *اشارو)
{
  _Static_assert(_Generic(&اشارو, صحيح **: 1, افتراضي: 0),
                 "declaration qualifier does not affect definition");
  اشارو = 0;
}

فراغ defined_restrict(صحيح *اشارو);
فراغ defined_restrict(صحيح *محدود اشارو)
{
  _Static_assert(_Generic(&اشارو, صحيح *محدود *: 1, افتراضي: 0),
                 "definition retains restrict");
  اشارو = 0;
}

صحيح مکيه(فراغ)
{
    أرجع 0;
}

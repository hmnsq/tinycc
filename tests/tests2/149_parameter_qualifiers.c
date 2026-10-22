فراغ اشارہ_گر_parameters(صحيح *ثابت cp, صحيح *متطاير vp, صحيح *محدود rp)
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

فراغ declared_const(صحيح *ثابت اشارہ_گر);
فراغ declared_const(صحيح *اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشارہ_گر = 0;
}

فراغ defined_const(صحيح *اشارہ_گر);
فراغ defined_const(صحيح *ثابت اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحيح *ثابت *: 1, افتراضي: 0),
                   "definition retains const");
}

فراغ declared_volatile(صحيح *متطاير اشارہ_گر);
فراغ declared_volatile(صحيح *اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشارہ_گر = 0;
}

فراغ defined_volatile(صحيح *اشارہ_گر);
فراغ defined_volatile(صحيح *متطاير اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحيح *متطاير *: 1, افتراضي: 0),
                   "definition retains volatile");
    اشارہ_گر = 0;
}

فراغ declared_restrict(صحيح *محدود اشارہ_گر);
فراغ declared_restrict(صحيح *اشارہ_گر)
{
  _Static_assert(_Generic(&اشارہ_گر, صحيح **: 1, افتراضي: 0),
                 "declaration qualifier does not affect definition");
  اشارہ_گر = 0;
}

فراغ defined_restrict(صحيح *اشارہ_گر);
فراغ defined_restrict(صحيح *محدود اشارہ_گر)
{
  _Static_assert(_Generic(&اشارہ_گر, صحيح *محدود *: 1, افتراضي: 0),
                 "definition retains restrict");
  اشارہ_گر = 0;
}

صحيح مکھ(فراغ)
{
    أرجع 0;
}

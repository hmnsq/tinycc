فراغ اشاره_ګر_parameters(صحيح *ثابت cp, صحيح *متطاير vp, صحيح *محدود rp)
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

فراغ declared_const(صحيح *ثابت اشاره_ګر);
فراغ declared_const(صحيح *اشاره_ګر)
{
    _Static_assert(_Generic(&اشاره_ګر, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشاره_ګر = 0;
}

فراغ defined_const(صحيح *اشاره_ګر);
فراغ defined_const(صحيح *ثابت اشاره_ګر)
{
    _Static_assert(_Generic(&اشاره_ګر, صحيح *ثابت *: 1, افتراضي: 0),
                   "definition retains const");
}

فراغ declared_volatile(صحيح *متطاير اشاره_ګر);
فراغ declared_volatile(صحيح *اشاره_ګر)
{
    _Static_assert(_Generic(&اشاره_ګر, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    اشاره_ګر = 0;
}

فراغ defined_volatile(صحيح *اشاره_ګر);
فراغ defined_volatile(صحيح *متطاير اشاره_ګر)
{
    _Static_assert(_Generic(&اشاره_ګر, صحيح *متطاير *: 1, افتراضي: 0),
                   "definition retains volatile");
    اشاره_ګر = 0;
}

فراغ declared_restrict(صحيح *محدود اشاره_ګر);
فراغ declared_restrict(صحيح *اشاره_ګر)
{
  _Static_assert(_Generic(&اشاره_ګر, صحيح **: 1, افتراضي: 0),
                 "declaration qualifier does not affect definition");
  اشاره_ګر = 0;
}

فراغ defined_restrict(صحيح *اشاره_ګر);
فراغ defined_restrict(صحيح *محدود اشاره_ګر)
{
  _Static_assert(_Generic(&اشاره_ګر, صحيح *محدود *: 1, افتراضي: 0),
                 "definition retains restrict");
  اشاره_ګر = 0;
}

صحيح اصلي(فراغ)
{
    أرجع 0;
}

فراغ pointer_parameters(صحيح *ثابت cp, صحيح *متطاير vp, صحيح *restrict rp)
{
    _Static_assert(_Generic(&cp, صحيح *ثابت *: 1, افتراضي: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, صحيح *متطاير *: 1, افتراضي: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, صحيح *restrict *: 1, افتراضي: 0),
                  "restrict pointer parameter remains qualified");
}

فراغ array_parameters(صحيح ca[ثابت 2], صحيح va[متطاير 2], صحيح ra[restrict 2])
{
    _Static_assert(_Generic(&ca, صحيح *ثابت *: 1, افتراضي: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, صحيح *متطاير *: 1, افتراضي: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, صحيح *restrict *: 1, افتراضي: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

فراغ declared_const(صحيح *ثابت pointer);
فراغ declared_const(صحيح *pointer)
{
    _Static_assert(_Generic(&pointer, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

فراغ defined_const(صحيح *pointer);
فراغ defined_const(صحيح *ثابت pointer)
{
    _Static_assert(_Generic(&pointer, صحيح *ثابت *: 1, افتراضي: 0),
                   "definition retains const");
}

فراغ declared_volatile(صحيح *متطاير pointer);
فراغ declared_volatile(صحيح *pointer)
{
    _Static_assert(_Generic(&pointer, صحيح **: 1, افتراضي: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

فراغ defined_volatile(صحيح *pointer);
فراغ defined_volatile(صحيح *متطاير pointer)
{
    _Static_assert(_Generic(&pointer, صحيح *متطاير *: 1, افتراضي: 0),
                   "definition retains volatile");
    pointer = 0;
}

فراغ declared_restrict(صحيح *restrict pointer);
فراغ declared_restrict(صحيح *pointer)
{
  _Static_assert(_Generic(&pointer, صحيح **: 1, افتراضي: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

فراغ defined_restrict(صحيح *pointer);
فراغ defined_restrict(صحيح *restrict pointer)
{
  _Static_assert(_Generic(&pointer, صحيح *restrict *: 1, افتراضي: 0),
                 "definition retains restrict");
  pointer = 0;
}

صحيح main(فراغ)
{
    החזר 0;
}

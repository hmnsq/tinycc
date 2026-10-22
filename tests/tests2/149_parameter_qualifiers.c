تهی pointer_parameters(صحیح *ثابت cp, صحیح *فرار vp, صحیح *restrict rp)
{
    _Static_assert(_Generic(&cp, صحیح *ثابت *: 1, پیشفرض: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, صحیح *فرار *: 1, پیشفرض: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, صحیح *restrict *: 1, پیشفرض: 0),
                  "restrict pointer parameter remains qualified");
}

تهی array_parameters(صحیح ca[ثابت 2], صحیح va[فرار 2], صحیح ra[restrict 2])
{
    _Static_assert(_Generic(&ca, صحیح *ثابت *: 1, پیشفرض: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, صحیح *فرار *: 1, پیشفرض: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, صحیح *restrict *: 1, پیشفرض: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

تهی declared_const(صحیح *ثابت pointer);
تهی declared_const(صحیح *pointer)
{
    _Static_assert(_Generic(&pointer, صحیح **: 1, پیشفرض: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

تهی defined_const(صحیح *pointer);
تهی defined_const(صحیح *ثابت pointer)
{
    _Static_assert(_Generic(&pointer, صحیح *ثابت *: 1, پیشفرض: 0),
                   "definition retains const");
}

تهی declared_volatile(صحیح *فرار pointer);
تهی declared_volatile(صحیح *pointer)
{
    _Static_assert(_Generic(&pointer, صحیح **: 1, پیشفرض: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

تهی defined_volatile(صحیح *pointer);
تهی defined_volatile(صحیح *فرار pointer)
{
    _Static_assert(_Generic(&pointer, صحیح *فرار *: 1, پیشفرض: 0),
                   "definition retains volatile");
    pointer = 0;
}

تهی declared_restrict(صحیح *restrict pointer);
تهی declared_restrict(صحیح *pointer)
{
  _Static_assert(_Generic(&pointer, صحیح **: 1, پیشفرض: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

تهی defined_restrict(صحیح *pointer);
تهی defined_restrict(صحیح *restrict pointer)
{
  _Static_assert(_Generic(&pointer, صحیح *restrict *: 1, پیشفرض: 0),
                 "definition retains restrict");
  pointer = 0;
}

صحیح اصلی(تهی)
{
    بازگشت 0;
}

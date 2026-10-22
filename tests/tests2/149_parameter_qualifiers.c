خالی اشارہ_گر_parameters(صحیح *ثابت cp, صحیح *متلون vp, صحیح *محدود rp)
{
    _Static_assert(_Generic(&cp, صحیح *ثابت *: 1, طےشدہ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, صحیح *متلون *: 1, طےشدہ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, صحیح *محدود *: 1, طےشدہ: 0),
                  "restrict pointer parameter remains qualified");
}

خالی array_parameters(صحیح ca[ثابت 2], صحیح va[متلون 2], صحیح ra[محدود 2])
{
    _Static_assert(_Generic(&ca, صحیح *ثابت *: 1, طےشدہ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, صحیح *متلون *: 1, طےشدہ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, صحیح *محدود *: 1, طےشدہ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

خالی declared_const(صحیح *ثابت اشارہ_گر);
خالی declared_const(صحیح *اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحیح **: 1, طےشدہ: 0),
                   "declaration qualifier does not affect definition");
    اشارہ_گر = 0;
}

خالی defined_const(صحیح *اشارہ_گر);
خالی defined_const(صحیح *ثابت اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحیح *ثابت *: 1, طےشدہ: 0),
                   "definition retains const");
}

خالی declared_volatile(صحیح *متلون اشارہ_گر);
خالی declared_volatile(صحیح *اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحیح **: 1, طےشدہ: 0),
                   "declaration qualifier does not affect definition");
    اشارہ_گر = 0;
}

خالی defined_volatile(صحیح *اشارہ_گر);
خالی defined_volatile(صحیح *متلون اشارہ_گر)
{
    _Static_assert(_Generic(&اشارہ_گر, صحیح *متلون *: 1, طےشدہ: 0),
                   "definition retains volatile");
    اشارہ_گر = 0;
}

خالی declared_restrict(صحیح *محدود اشارہ_گر);
خالی declared_restrict(صحیح *اشارہ_گر)
{
  _Static_assert(_Generic(&اشارہ_گر, صحیح **: 1, طےشدہ: 0),
                 "declaration qualifier does not affect definition");
  اشارہ_گر = 0;
}

خالی defined_restrict(صحیح *اشارہ_گر);
خالی defined_restrict(صحیح *محدود اشارہ_گر)
{
  _Static_assert(_Generic(&اشارہ_گر, صحیح *محدود *: 1, طےشدہ: 0),
                 "definition retains restrict");
  اشارہ_گر = 0;
}

صحیح مین(خالی)
{
    واپس 0;
}

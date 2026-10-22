শূন্য pointer_parameters(পূর্ণসংখ্যা *ধ্রুবক cp, পূর্ণসংখ্যা *অস্থির vp, পূর্ণসংখ্যা *restrict rp)
{
    _Static_assert(_Generic(&cp, পূর্ণসংখ্যা *ধ্রুবক *: 1, পূর্বনির্ধারিত: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, পূর্ণসংখ্যা *অস্থির *: 1, পূর্বনির্ধারিত: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, পূর্ণসংখ্যা *restrict *: 1, পূর্বনির্ধারিত: 0),
                  "restrict pointer parameter remains qualified");
}

শূন্য array_parameters(পূর্ণসংখ্যা ca[ধ্রুবক 2], পূর্ণসংখ্যা va[অস্থির 2], পূর্ণসংখ্যা ra[restrict 2])
{
    _Static_assert(_Generic(&ca, পূর্ণসংখ্যা *ধ্রুবক *: 1, পূর্বনির্ধারিত: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, পূর্ণসংখ্যা *অস্থির *: 1, পূর্বনির্ধারিত: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, পূর্ণসংখ্যা *restrict *: 1, পূর্বনির্ধারিত: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

শূন্য declared_const(পূর্ণসংখ্যা *ধ্রুবক pointer);
শূন্য declared_const(পূর্ণসংখ্যা *pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা **: 1, পূর্বনির্ধারিত: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

শূন্য defined_const(পূর্ণসংখ্যা *pointer);
শূন্য defined_const(পূর্ণসংখ্যা *ধ্রুবক pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা *ধ্রুবক *: 1, পূর্বনির্ধারিত: 0),
                   "definition retains const");
}

শূন্য declared_volatile(পূর্ণসংখ্যা *অস্থির pointer);
শূন্য declared_volatile(পূর্ণসংখ্যা *pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা **: 1, পূর্বনির্ধারিত: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

শূন্য defined_volatile(পূর্ণসংখ্যা *pointer);
শূন্য defined_volatile(পূর্ণসংখ্যা *অস্থির pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা *অস্থির *: 1, পূর্বনির্ধারিত: 0),
                   "definition retains volatile");
    pointer = 0;
}

শূন্য declared_restrict(পূর্ণসংখ্যা *restrict pointer);
শূন্য declared_restrict(পূর্ণসংখ্যা *pointer)
{
  _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা **: 1, পূর্বনির্ধারিত: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

শূন্য defined_restrict(পূর্ণসংখ্যা *pointer);
শূন্য defined_restrict(পূর্ণসংখ্যা *restrict pointer)
{
  _Static_assert(_Generic(&pointer, পূর্ণসংখ্যা *restrict *: 1, পূর্বনির্ধারিত: 0),
                 "definition retains restrict");
  pointer = 0;
}

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    ফেরত 0;
}

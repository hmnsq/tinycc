শূন্য pointer_parameters(পূর্ণাঙ্ক *ধ্রুৱ cp, পূর্ণাঙ্ক *চঞ্চল vp, পূর্ণাঙ্ক *restrict rp)
{
    _Static_assert(_Generic(&cp, পূর্ণাঙ্ক *ধ্রুৱ *: 1, স্ৱভাৱ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, পূর্ণাঙ্ক *চঞ্চল *: 1, স্ৱভাৱ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, পূর্ণাঙ্ক *restrict *: 1, স্ৱভাৱ: 0),
                  "restrict pointer parameter remains qualified");
}

শূন্য array_parameters(পূর্ণাঙ্ক ca[ধ্রুৱ 2], পূর্ণাঙ্ক va[চঞ্চল 2], পূর্ণাঙ্ক ra[restrict 2])
{
    _Static_assert(_Generic(&ca, পূর্ণাঙ্ক *ধ্রুৱ *: 1, স্ৱভাৱ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, পূর্ণাঙ্ক *চঞ্চল *: 1, স্ৱভাৱ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, পূর্ণাঙ্ক *restrict *: 1, স্ৱভাৱ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

শূন্য declared_const(পূর্ণাঙ্ক *ধ্রুৱ pointer);
শূন্য declared_const(পূর্ণাঙ্ক *pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক **: 1, স্ৱভাৱ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

শূন্য defined_const(পূর্ণাঙ্ক *pointer);
শূন্য defined_const(পূর্ণাঙ্ক *ধ্রুৱ pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক *ধ্রুৱ *: 1, স্ৱভাৱ: 0),
                   "definition retains const");
}

শূন্য declared_volatile(পূর্ণাঙ্ক *চঞ্চল pointer);
শূন্য declared_volatile(পূর্ণাঙ্ক *pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক **: 1, স্ৱভাৱ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

শূন্য defined_volatile(পূর্ণাঙ্ক *pointer);
শূন্য defined_volatile(পূর্ণাঙ্ক *চঞ্চল pointer)
{
    _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক *চঞ্চল *: 1, স্ৱভাৱ: 0),
                   "definition retains volatile");
    pointer = 0;
}

শূন্য declared_restrict(পূর্ণাঙ্ক *restrict pointer);
শূন্য declared_restrict(পূর্ণাঙ্ক *pointer)
{
  _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক **: 1, স্ৱভাৱ: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

শূন্য defined_restrict(পূর্ণাঙ্ক *pointer);
শূন্য defined_restrict(পূর্ণাঙ্ক *restrict pointer)
{
  _Static_assert(_Generic(&pointer, পূর্ণাঙ্ক *restrict *: 1, স্ৱভাৱ: 0),
                 "definition retains restrict");
  pointer = 0;
}

পূর্ণাঙ্ক main(শূন্য)
{
    ঘূৰাই 0;
}

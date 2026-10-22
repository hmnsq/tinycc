ଶୂନ୍ୟ pointer_parameters(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ cp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର vp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict rp)
{
    _Static_assert(_Generic(&cp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                  "restrict pointer parameter remains qualified");
}

ଶୂନ୍ୟ array_parameters(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ca[ଅଚଳ 2], ପୂର୍ଣ୍ଣସଂଖ୍ୟା va[ଅସ୍ଥିର 2], ପୂର୍ଣ୍ଣସଂଖ୍ୟା ra[restrict 2])
{
    _Static_assert(_Generic(&ca, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

ଶୂନ୍ୟ declared_const(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ pointer);
ଶୂନ୍ୟ declared_const(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer)
{
    _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା **: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ଶୂନ୍ୟ defined_const(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer);
ଶୂନ୍ୟ defined_const(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ pointer)
{
    _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଚଳ *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "definition retains const");
}

ଶୂନ୍ୟ declared_volatile(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର pointer);
ଶୂନ୍ୟ declared_volatile(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer)
{
    _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା **: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ଶୂନ୍ୟ defined_volatile(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer);
ଶୂନ୍ୟ defined_volatile(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର pointer)
{
    _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅସ୍ଥିର *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                   "definition retains volatile");
    pointer = 0;
}

ଶୂନ୍ୟ declared_restrict(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict pointer);
ଶୂନ୍ୟ declared_restrict(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer)
{
  _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା **: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

ଶୂନ୍ୟ defined_restrict(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pointer);
ଶୂନ୍ୟ defined_restrict(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict pointer)
{
  _Static_assert(_Generic(&pointer, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict *: 1, ପୂର୍ବନିର୍ଦ୍ଧାରିତ: 0),
                 "definition retains restrict");
  pointer = 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ଫେରନ୍ତୁ 0;
}

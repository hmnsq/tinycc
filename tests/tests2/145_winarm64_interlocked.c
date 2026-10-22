#ضمن <stdio.h>
#ضمن <windows.h>

#تعریف_کن PTR(x) ((PVOID)(ULONG_PTR)(x))
#تعریف_کن CHECK(name, عبارت) چاپ_کن("%s: %s\n", name, (عبارت) ? "yes" : "no")

صحيح اصلی(فراغ)
{
    PVOID متطاير جایگاه = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_اشاره_گر(&جایگاه, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", جایگاه == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_اشاره_گر(&جایگاه,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", جایگاه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشاره_گر_Acquire(&جایگاه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", جایگاه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشاره_گر_Release(&جایگاه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", جایگاه == PTR(0xdddd111122223333ULL));

    أرجع 0;
}

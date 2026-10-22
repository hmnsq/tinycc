#ضمن <stdio.h>
#ضمن <windows.h>

#تعریف_کړه PTR(x) ((PVOID)(ULONG_PTR)(x))
#تعریف_کړه CHECK(name, بیان) چاپ_کړه("%s: %s\n", name, (بیان) ? "yes" : "no")

صحيح اصلي(فراغ)
{
    PVOID متطاير خونه = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_اشاره_ګر(&خونه, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", خونه == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_اشاره_ګر(&خونه,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", خونه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشاره_ګر_Acquire(&خونه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", خونه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشاره_ګر_Release(&خونه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", خونه == PTR(0xdddd111122223333ULL));

    أرجع 0;
}

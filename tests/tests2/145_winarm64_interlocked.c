#ضمن <stdio.h>
#ضمن <windows.h>

#وصف_ڪريو PTR(x) ((PVOID)(ULONG_PTR)(x))
#وصف_ڪريو CHECK(name, اظهار) لکو("%s: %s\n", name, (اظهار) ? "yes" : "no")

صحيح مکيه(فراغ)
{
    PVOID متطاير جڳهه = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_اشارو(&جڳهه, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", جڳهه == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_اشارو(&جڳهه,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", جڳهه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشارو_Acquire(&جڳهه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", جڳهه == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشارو_Release(&جڳهه,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", جڳهه == PTR(0xdddd111122223333ULL));

    أرجع 0;
}

#شامل <stdio.h>
#شامل <windows.h>

#تعریف_کرو PTR(x) ((PVOID)(ULONG_PTR)(x))
#تعریف_کرو CHECK(name, اظہاریہ) لکھو("%s: %s\n", name, (اظہاریہ) ? "yes" : "no")

صحیح مین(خالی)
{
    PVOID متلون خانہ = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_اشارہ_گر(&خانہ, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", خانہ == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_اشارہ_گر(&خانہ,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", خانہ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشارہ_گر_Acquire(&خانہ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", خانہ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_اشارہ_گر_Release(&خانہ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", خانہ == PTR(0xdddd111122223333ULL));

    واپس 0;
}

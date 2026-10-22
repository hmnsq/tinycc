#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <windows.h>

#ವ್ಯಾಖ್ಯಾನಿಸು PTR(x) ((PVOID)(ULONG_PTR)(x))
#ವ್ಯಾಖ್ಯಾನಿಸು CHECK(name, ಅಭಿವ್ಯಕ್ತಿ) ಬರೆ("%s: %s\n", name, (ಅಭಿವ್ಯಕ್ತಿ) ? "yes" : "no")

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    PVOID ಅಸ್ಥಿರ ಸ್ಥಾನ = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_ಸೂಚಕ(&ಸ್ಥಾನ, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", ಸ್ಥಾನ == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_ಸೂಚಕ(&ಸ್ಥಾನ,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", ಸ್ಥಾನ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire(&ಸ್ಥಾನ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", ಸ್ಥಾನ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_ಸೂಚಕ_Release(&ಸ್ಥಾನ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", ಸ್ಥಾನ == PTR(0xdddd111122223333ULL));

    ಹಿಂತಿರುಗಿ 0;
}

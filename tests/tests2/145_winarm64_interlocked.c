#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR(x) ((PVOID)(ULONG_PTR)(x))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHECK(name, ਵਿਅੰਜਕ) ਲਿਖੋ("%s: %s\n", name, (ਵਿਅੰਜਕ) ? "yes" : "no")

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    PVOID ਅਸਥਿਰ ਥਾਂ = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_ਸੂਚਕ(&ਥਾਂ, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", ਥਾਂ == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_ਸੂਚਕ(&ਥਾਂ,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", ਥਾਂ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire(&ਥਾਂ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", ਥਾਂ == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_ਸੂਚਕ_Release(&ਥਾਂ,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", ਥਾਂ == PTR(0xdddd111122223333ULL));

    ਵਾਪਸ 0;
}

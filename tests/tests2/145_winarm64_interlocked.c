#समावेश <stdio.h>
#समावेश <windows.h>

#घोषणा PTR(x) ((PVOID)(ULONG_PTR)(x))
#घोषणा CHECK(name, व्यंजक) म_लिखो("%s: %s\n", name, (व्यंजक) ? "yes" : "no")

पूर्णांक मुख्य(व्योम)
{
    PVOID अस्थिर slot = PTR(0x1111222233334444ULL);
    PVOID old;

    old = InterlockedExchangePointer(&slot, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", slot == PTR(0x5555666677778888ULL));

    old = InterlockedCompareExchangePointer(&slot,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", slot == PTR(0x9999aaaabbbbccccULL));

    old = InterlockedCompareExchangePointerAcquire(&slot,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", slot == PTR(0x9999aaaabbbbccccULL));

    old = InterlockedCompareExchangePointerRelease(&slot,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", slot == PTR(0xdddd111122223333ULL));

    वापस 0;
}

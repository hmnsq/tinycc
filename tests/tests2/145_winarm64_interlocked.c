#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <windows.h>

#define PTR(x) ((PVOID)(ULONG_PTR)(x))
#define CHECK(name, கோவை) printf("%s: %s\n", name, (கோவை) ? "yes" : "no")

முழு முதன்மை(வெறுமை)
{
    PVOID நிலையற்ற slot = PTR(0x1111222233334444ULL);
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

    திரும்பு 0;
}

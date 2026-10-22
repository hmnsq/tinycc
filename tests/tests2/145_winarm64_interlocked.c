#అన్తర్భావ <stdio.h>
#అన్తర్భావ <windows.h>

#నిర్వచించు PTR(x) ((PVOID)(ULONG_PTR)(x))
#నిర్వచించు CHECK(name, సమాసం) రాయి("%s: %s\n", name, (సమాసం) ? "yes" : "no")

పూర్ణాంకం ప్రధాన(శూన్య)
{
    PVOID అస్థిర స్థానం = PTR(0x1111222233334444ULL);
    PVOID old;

    old = Interlocked_Exchange_సూచిక(&స్థానం, PTR(0x5555666677778888ULL));
    CHECK("exchange old", old == PTR(0x1111222233334444ULL));
    CHECK("exchange stored", స్థానం == PTR(0x5555666677778888ULL));

    old = Interlocked_Compare_Exchange_సూచిక(&స్థానం,
                                            PTR(0x9999aaaabbbbccccULL),
                                            PTR(0x5555666677778888ULL));
    CHECK("compare old", old == PTR(0x5555666677778888ULL));
    CHECK("compare stored", స్థానం == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_సూచిక_Acquire(&స్థానం,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x0123456789abcdefULL));
    CHECK("acquire old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("acquire stored", స్థానం == PTR(0x9999aaaabbbbccccULL));

    old = Interlocked_Compare_Exchange_సూచిక_Release(&స్థానం,
                                                   PTR(0xdddd111122223333ULL),
                                                   PTR(0x9999aaaabbbbccccULL));
    CHECK("release old", old == PTR(0x9999aaaabbbbccccULL));
    CHECK("release stored", స్థానం == PTR(0xdddd111122223333ULL));

    తిరిగి 0;
}

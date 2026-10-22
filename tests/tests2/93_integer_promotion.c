/* integer promotion */

ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*, ...);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ promote(s) ਲਿਖੋ(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

ਪੂਰਨ ਮੁੱਖ (ਖਾਲੀ)
{
    ਬਣਤਰ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ u3:3;
        ਬਿਨਾਨਿਸ਼ਾਨੀ u31:31;
        ਬਿਨਾਨਿਸ਼ਾਨੀ u32:32;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ul31:31;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ul32:32;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ull31:31;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ull32:32;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ull33:33;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ull64:64;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
    } s = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    promote(s.u3);
    promote(s.u31);
    promote(s.u32);
    promote(s.ul31);
    promote(s.ul32);
    promote(s.ull31);
    promote(s.ull32);
    promote(s.ull33);
    promote(s.ull64);
    promote(s.c);
    ਲਿਖੋ("\n");

    promote((1 ? s.u3 : 1));
    promote((1 ? s.u31 : 1));
    promote((1 ? s.u32 : 1));
    promote((1 ? s.ul31 : 1));
    promote((1 ? s.ul32 : 1));
    promote((1 ? s.ull31 : 1));
    promote((1 ? s.ull32 : 1));
    promote((1 ? s.ull33 : 1));
    promote((1 ? s.ull64 : 1));
    promote((1 ? s.c : 1));
    ਲਿਖੋ("\n");

    promote(s.u3 << 1);
    promote(s.u31 << 1);
    promote(s.u32 << 1);
    promote(s.ul31 << 1);
    promote(s.ul32 << 1);
    promote(s.ull31 << 1);
    promote(s.ull32 << 1);
    promote(s.ull33 << 1);
    promote(s.ull64 << 1);
    promote(s.c << 1);
    ਲਿਖੋ("\n");

    promote(+s.u3);
    promote(+s.u31);
    promote(+s.u32);
    promote(+s.ul31);
    promote(+s.ul32);
    promote(+s.ull31);
    promote(+s.ull32);
    promote(+s.ull33);
    promote(+s.ull64);
    promote(+s.c);
    ਲਿਖੋ("\n");

    promote(-s.u3);
    promote(-s.u31);
    promote(-s.u32);
    promote(-s.ul31);
    promote(-s.ul32);
    promote(-s.ull31);
    promote(-s.ull32);
    promote(-s.ull33);
    promote(-s.ull64);
    promote(-s.c);
    ਲਿਖੋ("\n");

    promote(~s.u3);
    promote(~s.u31);
    promote(~s.u32);
    promote(~s.ul31);
    promote(~s.ul32);
    promote(~s.ull31);
    promote(~s.ull32);
    promote(~s.ull33);
    promote(~s.ull64);
    promote(~s.c);
    ਲਿਖੋ("\n");

    promote(!s.u3);
    promote(!s.u31);
    promote(!s.u32);
    promote(!s.ul31);
    promote(!s.ul32);
    promote(!s.ull31);
    promote(!s.ull32);
    promote(!s.ull33);
    promote(!s.ull64);
    promote(!s.c);
    ਲਿਖੋ("\n");

    promote(+(ਬਿਨਾਨਿਸ਼ਾਨੀ)s.u3);
    promote(-(ਬਿਨਾਨਿਸ਼ਾਨੀ)s.u3);
    promote(~(ਬਿਨਾਨਿਸ਼ਾਨੀ)s.u3);
    promote(!(ਬਿਨਾਨਿਸ਼ਾਨੀ)s.u3);

    ਵਾਪਸ 0;
}

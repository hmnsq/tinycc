/* integer promotion */

ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);
#ವ್ಯಾಖ್ಯಾನಿಸು promote(s) ಬರೆ(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ (ಶೂನ್ಯ)
{
    ರಚನೆ {
        ಚಿಹ್ನೆರಹಿತ u3:3;
        ಚಿಹ್ನೆರಹಿತ u31:31;
        ಚಿಹ್ನೆರಹಿತ u32:32;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ul31:31;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ul32:32;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ull31:31;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ull32:32;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ull33:33;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ull64:64;
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

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
    ಬರೆ("\n");

    promote(+(ಚಿಹ್ನೆರಹಿತ)s.u3);
    promote(-(ಚಿಹ್ನೆರಹಿತ)s.u3);
    promote(~(ಚಿಹ್ನೆರಹಿತ)s.u3);
    promote(!(ಚಿಹ್ನೆರಹಿತ)s.u3);

    ಹಿಂತಿರುಗಿ 0;
}

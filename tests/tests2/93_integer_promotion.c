/* integer promotion */

صحيح چاپ_کن(ثابت حرف*, ...);
#تعریف_کن promote(s) چاپ_کن(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

صحيح اصلی (فراغ)
{
    بنية {
        بیعلامت u3:3;
        بیعلامت u31:31;
        بیعلامت u32:32;
        بیعلامت دراز ul31:31;
        بیعلامت دراز ul32:32;
        بیعلامت دراز دراز ull31:31;
        بیعلامت دراز دراز ull32:32;
        بیعلامت دراز دراز ull33:33;
        بیعلامت دراز دراز ull64:64;
        بیعلامت حرف c;
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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

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
    چاپ_کن("\n");

    promote(+(بیعلامت)s.u3);
    promote(-(بیعلامت)s.u3);
    promote(~(بیعلامت)s.u3);
    promote(!(بیعلامت)s.u3);

    أرجع 0;
}

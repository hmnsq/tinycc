/* integer promotion */

صحيح چاپ_کړه(ثابت حرف*, ...);
#تعریف_کړه promote(s) چاپ_کړه(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

صحيح اصلي (فراغ)
{
    بنية {
        بینښه u3:3;
        بینښه u31:31;
        بینښه u32:32;
        بینښه اوږد ul31:31;
        بینښه اوږد ul32:32;
        بینښه اوږد اوږد ull31:31;
        بینښه اوږد اوږد ull32:32;
        بینښه اوږد اوږد ull33:33;
        بینښه اوږد اوږد ull64:64;
        بینښه حرف c;
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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

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
    چاپ_کړه("\n");

    promote(+(بینښه)s.u3);
    promote(-(بینښه)s.u3);
    promote(~(بینښه)s.u3);
    promote(!(بینښه)s.u3);

    أرجع 0;
}

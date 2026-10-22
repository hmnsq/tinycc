/* integer promotion */

صحيح لکو(ثابت حرف*, ...);
#وصف_ڪريو promote(s) لکو(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

صحيح مکيه (فراغ)
{
    بنية {
        بنانشان u3:3;
        بنانشان u31:31;
        بنانشان u32:32;
        بنانشان ڊگهو ul31:31;
        بنانشان ڊگهو ul32:32;
        بنانشان ڊگهو ڊگهو ull31:31;
        بنانشان ڊگهو ڊگهو ull32:32;
        بنانشان ڊگهو ڊگهو ull33:33;
        بنانشان ڊگهو ڊگهو ull64:64;
        بنانشان حرف c;
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
    لکو("\n");

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
    لکو("\n");

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
    لکو("\n");

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
    لکو("\n");

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
    لکو("\n");

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
    لکو("\n");

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
    لکو("\n");

    promote(+(بنانشان)s.u3);
    promote(-(بنانشان)s.u3);
    promote(~(بنانشان)s.u3);
    promote(!(بنانشان)s.u3);

    أرجع 0;
}

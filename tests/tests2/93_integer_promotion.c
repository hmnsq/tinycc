/* integer promotion */

صحيح لکھو(ثابت حرف*, ...);
#تعریف_کرو promote(s) لکھو(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

صحيح مکھ (فراغ)
{
    بنية {
        بنانشانی u3:3;
        بنانشانی u31:31;
        بنانشانی u32:32;
        بنانشانی لما ul31:31;
        بنانشانی لما ul32:32;
        بنانشانی لما لما ull31:31;
        بنانشانی لما لما ull32:32;
        بنانشانی لما لما ull33:33;
        بنانشانی لما لما ull64:64;
        بنانشانی حرف c;
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
    لکھو("\n");

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
    لکھو("\n");

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
    لکھو("\n");

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
    لکھو("\n");

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
    لکھو("\n");

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
    لکھو("\n");

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
    لکھو("\n");

    promote(+(بنانشانی)s.u3);
    promote(-(بنانشانی)s.u3);
    promote(~(بنانشانی)s.u3);
    promote(!(بنانشانی)s.u3);

    أرجع 0;
}

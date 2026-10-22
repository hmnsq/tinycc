/* integer promotion */

صحیح لکھو(ثابت حرف*, ...);
#تعریف_کرو promote(s) لکھو(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

صحیح مین (خالی)
{
    ساخت {
        غیرعلامتی u3:3;
        غیرعلامتی u31:31;
        غیرعلامتی u32:32;
        غیرعلامتی طویل ul31:31;
        غیرعلامتی طویل ul32:32;
        غیرعلامتی طویل طویل ull31:31;
        غیرعلامتی طویل طویل ull32:32;
        غیرعلامتی طویل طویل ull33:33;
        غیرعلامتی طویل طویل ull64:64;
        غیرعلامتی حرف c;
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

    promote(+(غیرعلامتی)s.u3);
    promote(-(غیرعلامتی)s.u3);
    promote(~(غیرعلامتی)s.u3);
    promote(!(غیرعلامتی)s.u3);

    واپس 0;
}

/* integer promotion */

पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण*, ...);
#परिभाषय promote(s) प्रारूप_लिख(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

पूर्णाङ्क मुख्यम् (शून्य)
{
    संरचना {
        अचिह्नित u3:3;
        अचिह्नित u31:31;
        अचिह्नित u32:32;
        अचिह्नित दीर्घ ul31:31;
        अचिह्नित दीर्घ ul32:32;
        अचिह्नित दीर्घ दीर्घ ull31:31;
        अचिह्नित दीर्घ दीर्घ ull32:32;
        अचिह्नित दीर्घ दीर्घ ull33:33;
        अचिह्नित दीर्घ दीर्घ ull64:64;
        अचिह्नित वर्ण c;
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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

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
    प्रारूप_लिख("\n");

    promote(+(अचिह्नित)s.u3);
    promote(-(अचिह्नित)s.u3);
    promote(~(अचिह्नित)s.u3);
    promote(!(अचिह्नित)s.u3);

    प्रत्यागम 0;
}

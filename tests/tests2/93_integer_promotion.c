/* integer promotion */

पूर्णांक म_लिखो(स्थिरांक अक्षर*, ...);
#define promote(s) म_लिखो(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

पूर्णांक main (शून्य)
{
    संरचना {
        अचिन्हित u3:3;
        अचिन्हित u31:31;
        अचिन्हित u32:32;
        अचिन्हित दीर्घ ul31:31;
        अचिन्हित दीर्घ ul32:32;
        अचिन्हित दीर्घ दीर्घ ull31:31;
        अचिन्हित दीर्घ दीर्घ ull32:32;
        अचिन्हित दीर्घ दीर्घ ull33:33;
        अचिन्हित दीर्घ दीर्घ ull64:64;
        अचिन्हित अक्षर c;
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
    म_लिखो("\n");

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
    म_लिखो("\n");

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
    म_लिखो("\n");

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
    म_लिखो("\n");

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
    म_लिखो("\n");

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
    म_लिखो("\n");

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
    म_लिखो("\n");

    promote(+(अचिन्हित)s.u3);
    promote(-(अचिन्हित)s.u3);
    promote(~(अचिन्हित)s.u3);
    promote(!(अचिन्हित)s.u3);

    परत 0;
}

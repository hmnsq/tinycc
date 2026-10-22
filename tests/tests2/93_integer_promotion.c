/* integer promotion */

పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం*, ...);
#నిర్వచించు promote(s) రాయి(" %ssigned : %s\n", (s) - 100 < 0 ? "  " : "un", #s);

పూర్ణాంకం ప్రధాన (శూన్య)
{
    నిర్మాణం {
        గుర్తులేని u3:3;
        గుర్తులేని u31:31;
        గుర్తులేని u32:32;
        గుర్తులేని దీర్ఘ ul31:31;
        గుర్తులేని దీర్ఘ ul32:32;
        గుర్తులేని దీర్ఘ దీర్ఘ ull31:31;
        గుర్తులేని దీర్ఘ దీర్ఘ ull32:32;
        గుర్తులేని దీర్ఘ దీర్ఘ ull33:33;
        గుర్తులేని దీర్ఘ దీర్ఘ ull64:64;
        గుర్తులేని అక్షరం c;
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
    రాయి("\n");

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
    రాయి("\n");

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
    రాయి("\n");

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
    రాయి("\n");

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
    రాయి("\n");

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
    రాయి("\n");

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
    రాయి("\n");

    promote(+(గుర్తులేని)s.u3);
    promote(-(గుర్తులేని)s.u3);
    promote(~(గుర్తులేని)s.u3);
    promote(!(గుర్తులేని)s.u3);

    తిరిగి 0;
}

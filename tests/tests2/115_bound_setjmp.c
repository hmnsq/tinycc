#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <setjmp.h>

#define TST   പൂർണ്ണസംഖ്യ i, a[2], b[2];                \
              വേണ്ടി (i = 0; i < 2; i++) a[i] = 0; \
              വേണ്ടി (i = 0; i < 2; i++) b[i] = 0

സ്ഥിതം jmp_buf jmp;

സ്ഥിതം ശൂന്യം tst1 (ശൂന്യം)
{
    TST;
    longjmp(jmp, 1);
}

സ്ഥിതം ശൂന്യം tst2(ശൂന്യം)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

സ്ഥിതം ശൂന്യം tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

സ്ഥിതം ശൂന്യം tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

സ്ഥിതം ശൂന്യം tst (ശൂന്യം)
{
    jmp_buf loc;
    സ്ഥിതം പൂർണ്ണസംഖ്യ cnt;

    cnt = 0;
    എങ്കിൽ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    അല്ലെങ്കിൽ {
        cnt++;
    }
    എങ്കിൽ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    അല്ലെങ്കിൽ {
        cnt++;
    }
    എങ്കിൽ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

സ്ഥിതം jmp_buf buf1;
സ്ഥിതം jmp_buf buf2;
സ്ഥിതം പൂർണ്ണസംഖ്യ *p;
സ്ഥിതം പൂർണ്ണസംഖ്യ n_x = 6;
സ്ഥിതം പൂർണ്ണസംഖ്യ g_counter;

സ്ഥിതം ശൂന്യം അട്ടി (ശൂന്യം)
{
    സ്ഥിതം പൂർണ്ണസംഖ്യ counter;
    സ്ഥിതം പൂർണ്ണസംഖ്യ way_point1;
    സ്ഥിതം പൂർണ്ണസംഖ്യ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    എങ്കിൽ (setjmp (buf1) != 101) {
        പൂർണ്ണസംഖ്യ a[n_x];
        g_counter++;
        p = &a[0];
        എങ്കിൽ (g_counter < 5)
            longjmp (buf1, 2);
        അല്ലെങ്കിൽ എങ്കിൽ (g_counter == 5)
            longjmp (buf1, 101);
        അല്ലെങ്കിൽ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    എങ്കിൽ (counter == 0) {
        counter++;
        {
            പൂർണ്ണസംഖ്യ a[n_x];
            g_counter++;
            p = &a[0];
            എങ്കിൽ (g_counter < 5)
                longjmp (buf1, 2);
            അല്ലെങ്കിൽ എങ്കിൽ (g_counter == 5)
                longjmp (buf1, 101);
            അല്ലെങ്കിൽ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    എങ്കിൽ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    എങ്കിൽ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

സ്ഥിതം jmp_buf env;
സ്ഥിതം പൂർണ്ണസംഖ്യ last_മൂല്യം;

സ്ഥിതം ശൂന്യം jump (പൂർണ്ണസംഖ്യ val)
{
    longjmp (env, val);
}

സ്ഥിതം ശൂന്യം check (ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ മൂല്യം;

    last_മൂല്യം = -1;
    മൂല്യം = setjmp (env);
    എങ്കിൽ (മൂല്യം != last_മൂല്യം + 1) {
        printf ("incorrect value %d %d\n",
                മൂല്യം, last_മൂല്യം + 1);
        തിരികെ;
    }
    last_മൂല്യം = മൂല്യം;
    തിരഞ്ഞെടുപ്പ് (മൂല്യം) {
#എങ്കിൽ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    അവസ്ഥ 0:
        jump (0);
#endif
    സ്ഥിരസ്ഥിതി:
        എങ്കിൽ (മൂല്യം < 10)
          jump (മൂല്യം + 1);
    }
}

പൂർണ്ണസംഖ്യ
പ്രധാന (ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 0; i < 10;  i++) {
        tst();
        അട്ടി();
        check();
    }
    തിരികെ 0;
}



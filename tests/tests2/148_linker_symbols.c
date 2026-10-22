صحيح لکھو(ثابت حرف *, ...);

#تعریف_کرو أكد(x) ((x) \
    ? (لکھو(" 1 (%s)\n",#x),1) \
    : (لکھو("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#تعریف_کرو O 100
#تعریف_کرو SO 200

/* ------------------------------------------------------ */
#إذا TEST-O == 1
خارجي حرف etext[], _etext[];
خارجي حرف edata[], _edata[];
خارجي حرف سرا[], سرا_3[];
صحيح check_linker_symbols(فراغ)
{
    صحيح errors = 0;
    errors += !أكد(etext == _etext);
    errors += !أكد(edata == _edata);
    errors += !أكد(سرا == سرا_3);
    أرجع errors;
}

#وإلاإذا TEST-MAIN == 1
صحيح check_linker_symbols(فراغ);
صحيح مکھ(فراغ)
{
    لکھو("linker symbols test\n");
    أكد(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 2
خارجي حرف etext[], edata[], سرا[];
فراغ get_dso_سرا(حرف **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = سرا;
}

#وإلاإذا TEST-MAIN == 2
خارجي حرف _etext[], _edata[], سرا_3[];
خارجي فراغ get_dso_سرا(حرف **);
ساكن صحيح fill_انکڑے = 123;
ساكن صحيح fill_bss;

صحيح مکھ(فراغ)
{
    حرف *p[3];
    لکھو("DSO linker symbols test\n");
    get_dso_سرا(p);
    أكد(p[0] == _etext) || لکھو("-- %p %p\n", p[0], _etext);
    أكد(p[1] == _edata) || لکھو("-- %p %p\n", p[1], _edata);
    أكد(p[2] == سرا_3)   || لکھو("-- %p %p\n", p[2], سرا_3);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-MAIN == 3

صحيح etext(فراغ) { أرجع 1; }
صحيح edata(فراغ) { أرجع 2; }
صحيح سرا(فراغ) { أرجع 3; }
صحيح مکھ(فراغ)
{
    لکھو("user definition test\n");
    أكد(etext() + edata() + سرا() == 6);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 4
بنانشانی حرف copy_reloc_انکڑے[257];

#وإلاإذا TEST-MAIN == 4
خارجي بنانشانی حرف copy_reloc_انکڑے[257];
خارجي حرف سرا[], سرا_3[];

صحيح مکھ(فراغ)
{
    بنانشانی لما انکڑے_سرا;
    لکھو("end copy relocation test\n");
    copy_reloc_انکڑے[256] = 42;
    انکڑے_سرا = (بنانشانی لما)(copy_reloc_انکڑے + حجم copy_reloc_انکڑے);
    أكد(سرا == سرا_3);
    أكد((بنانشانی لما)سرا >= انکڑے_سرا);
    أكد(copy_reloc_انکڑے[256] == 42);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-O == 5
فراغ __attribute__((section(".text.linker_test"), noinline, ورتیا))
linker_test_متن(فراغ)
{
}
__attribute__((section(".bss.linker_test"), ورتیا))
بنانشانی حرف linker_test_bss[257];

__attribute__((section(".data.linker_test"), ورتیا))
بنانشانی حرف linker_test_انکڑے[23] = { 1 };

#وإلاإذا TEST-MAIN == 5
خارجي فراغ linker_test_متن(فراغ);
خارجي بنانشانی حرف linker_test_انکڑے[23];
خارجي بنانشانی حرف linker_test_bss[257];
خارجي حرف etext[], _etext[];
خارجي حرف edata[], _edata[];
خارجي حرف سرا[], سرا_3[];

صحيح مکھ(فراغ)
{
    حرف* متن_addr = (فراغ*)linker_test_متن;
    حرف* انکڑے_سرا = linker_test_انکڑے + حجم linker_test_انکڑے;
    حرف* bss_سرا = linker_test_bss + حجم linker_test_bss;

    لکھو("linker boundary test\n");
    linker_test_انکڑے[22] = 42;
    linker_test_bss[256] = 42;
    أكد(linker_test_bss > linker_test_انکڑے);
    أكد(etext == _etext);
    أكد(edata == _edata);
    أكد(سرا == سرا_3);
    أكد(etext >= متن_addr);
    أكد(edata >= انکڑے_سرا);
    أكد(سرا >= bss_سرا);
    أكد(linker_test_انکڑے[22] == 42);
    أكد(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 6
صحيح سرا;
صحيح eight = 8;
صحيح nine;
صحيح dso_جوڑو() { أرجع سرا + eight + nine; }

#وإلاإذا TEST-MAIN == 6
صحيح سرا = 7;
صحيح eight;
صحيح nine = 9;
صحيح dso_جوڑو();
صحيح مکھ()
{
    صحيح جوڑ;
    لکھو("DSO initialized data test\n");
    جوڑ = dso_جوڑو();
    أكد(سرا == 7);
    أكد(eight == 8);
    أكد(nine == 9);
    أكد(جوڑ == 24) || لکھو("-- %d + %d + %d = %d\n", سرا, eight, nine, جوڑ);
}

/* ------------------------------------------------------ */
#جے_انت

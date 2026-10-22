ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ u8;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {} ਖਾਲੀ_ਥਾਵਾਂ_s;
ਬਣਤਰ ਸ਼ਾਮਲ_ਹੈ_ਖਾਲੀ_ਥਾਵਾਂ {
    u8 a;
    ਖਾਲੀ_ਥਾਵਾਂ_s ਖਾਲੀ_ਥਾਵਾਂ;
    u8 b;
};
ਬਣਤਰ ਸ਼ਾਮਲ_ਹੈ_ਖਾਲੀ_ਥਾਵਾਂ ce = { { (1) }, (ਖਾਲੀ_ਥਾਵਾਂ_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
ਬਣਤਰ SS {u8 a[3], b; };
ਬਣਤਰ SS sinit16[] = { { 1 }, 2 };
ਬਣਤਰ S
{
  u8 a,b;
  u8 c[2];
};

ਬਣਤਰ T
{
  u8 s[16];
  u8 a;
};

ਬਣਤਰ U
{
  u8 a;
  ਬਣਤਰ S s;
  u8 b;
  ਬਣਤਰ T t;
};

ਬਣਤਰ V
{
  ਬਣਤਰ S s;
  ਬਣਤਰ T t;
  u8 a;
};

ਬਣਤਰ W
{
  ਬਣਤਰ V t;
  ਬਣਤਰ S s[];
};

ਬਣਤਰ S gs = ((ਬਣਤਰ S){1, 2, 3, 4});
ਬਣਤਰ S gs2 = {1, 2, {3, 4}};
ਬਣਤਰ T gt = {"hello", 42};
ਬਣਤਰ U gu = {3, 5,6,7,8, 4, "huhu", 43};
ਬਣਤਰ U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
ਬਣਤਰ U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
ਬਣਤਰ U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
ਬਣਤਰ S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
ਬਣਤਰ V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
ਬਣਤਰ V gv2 = {(ਬਣਤਰ S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
ਬਣਤਰ V gv3 = {((ਬਣਤਰ S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
ਬਣਤਰ W gw = {{1,2,3,4}, {1,2,3,4,5}};

ਸੰਘ UU {
    u8 a;
    u8 b;
};
ਬਣਤਰ SU {
    ਸੰਘ UU u;
    u8 c;
};
ਬਣਤਰ SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
ਸੰਘ UV {
    ਬਣਤਰ {u8 a,b;};
    ਬਣਤਰ S s;
};
ਸੰਘ UV guv = {{6,5}};
ਸੰਘ UV guv2 = {{.b = 7, .a = 8}};
ਸੰਘ UV guv3 = {.b = 8, .a = 7};

ਬਣਤਰ SSU {
    ਪੂਰਨ y;
    ਬਣਤਰ { ਪੂਰਨ x; };
};
ਬਣਤਰ SSU gssu1 = { .y = 5, .x = 3 };
ਬਣਤਰ SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

ਬਣਤਰ in6_addr {
    ਸੰਘ {
	u8 u6_addr8[16];
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ u6_addr16[8];
    } u;
};
ਬਣਤਰ flowi6 {
    ਬਣਤਰ in6_addr saddr, daddr;
};
ਬਣਤਰ pkthdr {
    ਬਣਤਰ in6_addr daddr, saddr;
};
ਬਣਤਰ pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

ਬਣਤਰ Wrap {
    ਖਾਲੀ *func;
};
ਪੂਰਨ global;
ਖਾਲੀ inc_global (ਖਾਲੀ)
{
  global++;
}

ਬਣਤਰ Wrap global_wrap[] = {
    ((ਬਣਤਰ Wrap) {inc_global}),
    inc_global,
};

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
ਖਾਲੀ print_ (ਅਚਲ ਅੱਖਰ *name, ਅਚਲ u8 *p, ਲੰਮਾ ਮਾਪ)
{
  ਲਿਖੋ ("%s:", name);
  ਜਦੋਂ (ਮਾਪ--) {
      ਲਿਖੋ (" %x", *p++);
  }
  ਲਿਖੋ ("\n");
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ print(x) print_(#x, (u8*)&x, ਆਕਾਰ (x))
#ਜੇ 1
ਖਾਲੀ foo (ਬਣਤਰ W *w, ਬਣਤਰ pkthdr *phdr_)
{
  ਬਣਤਰ S ls = {1, 2, 3, 4};
  ਬਣਤਰ S ls2 = {1, 2, {3, 4}};
  ਬਣਤਰ T lt = {"hello", 42};
  ਬਣਤਰ U lu = {3, 5,6,7,8, 4, "huhu", 43};
  ਬਣਤਰ U lu1 = {3, ls, 4, {"huhu", 43}};
  ਬਣਤਰ U lu2 = {3, (ls), 4, {"huhu", 43}};
  ਅਚਲ ਬਣਤਰ S *pls = &ls;
  ਬਣਤਰ S ls21 = *pls;
  ਬਣਤਰ U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  ਬਣਤਰ U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  ਬਣਤਰ U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  ਬਣਤਰ U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  ਬਣਤਰ S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  ਬਣਤਰ V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  ਬਣਤਰ V lv2 = {(ਬਣਤਰ S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  ਬਣਤਰ V lv3 = {((ਬਣਤਰ S){7,8,{9,10}}), ((ਅਚਲ ਬਣਤਰ W *)w)->t.t, 50};
  ਅਚਲ ਬਣਤਰ pkthdr *phdr = phdr_;
  ਬਣਤਰ flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  ਪੂਰਨ elt = 0x42;
  /* Range init, overlapping */
  ਬਣਤਰ T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  ਬਣਤਰ SSU lssu1 = { 5, 3 };
  ਬਣਤਰ SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ਜੇ defined(__GNUC__) || defined(__TINYC__)
  ਬਣਤਰ S ls4 = {a: 1, b: 2, c: {3, 4}};
#ਨਹੀਂਤਾਂ
  ਬਣਤਰ S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
#ਜੇ_ਅੰਤ
  print(ls);
  print(ls2);
  print(lt);
  print(lu);
  print(lu1);
  print(lu2);
  print(ls21);
  print(lu21);
  print(lu22);
  print(lu3);
  print(lu4);
  print(ls3);
  print(lv);
  print(lv2);
  print(lv3);
  print(lt2);
  print(lssu1);
  print(lssu2);
  print(flow);
  print(ls4);
}
#ਜੇ_ਅੰਤ

ਖਾਲੀ test_compound_with_relocs (ਖਾਲੀ)
{
  ਬਣਤਰ Wrap local_wrap[] = {
      ((ਬਣਤਰ Wrap) {inc_global}),
      inc_global,
  };
  ਖਾਲੀ (*p)(ਖਾਲੀ);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

ਖਾਲੀ sys_ni(ਖਾਲੀ) { ਲਿਖੋ("ni\n"); }
ਖਾਲੀ sys_one(ਖਾਲੀ) { ਲਿਖੋ("one\n"); }
ਖਾਲੀ sys_two(ਖਾਲੀ) { ਲਿਖੋ("two\n"); }
ਖਾਲੀ sys_three(ਖਾਲੀ) { ਲਿਖੋ("three\n"); }
ਖਾਲੀ sys_four(ਖਾਲੀ) { ਲਿਖੋ("four\n"); }
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (*fptr)(ਖਾਲੀ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ array_ਮਾਪ(a) (ਆਕਾਰ a / ਆਕਾਰ a[0])

ਖਾਲੀ test_multi_relocs(ਖਾਲੀ)
{
  ਪੂਰਨ i;

  ਸਥਿਰ ਅਚਲ fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ਲਈ (i = 0; i < array_ਮਾਪ(tabl1); i++)
    ਜੇ (tabl1[i])
      tabl1[i]();
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ("(0)\n");

  ਅਚਲ fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ਲਈ (i = 0; i < array_ਮਾਪ(tabl2); i++)
    ਜੇ (tabl2[i])
      tabl2[i]();
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ("(0)\n");

  ਪੂਰਨ c = 0;
  ਪੂਰਨ dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  ਲਈ (i = 0; i < array_ਮਾਪ(dd); i++)
    ਲਿਖੋ(" %d", dd[i]);
  ਲਿਖੋ("\n");

  /* multi-dimensional flex array with range initializers */
  ਸਥਿਰ ਅੱਖਰ m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ਅੱਖਰ        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ਪੂਰਨ g, j, k;
  ਲਈ (g = 2; g-- > 0;) {
    ਲਿਖੋ("mdfa %s: %d -", "locl\0glob" + g * 5, ਆਕਾਰ m1);
    ਲਈ (i = 0; i < array_ਮਾਪ(m1); i++)
    ਲਈ (j = 0; j < array_ਮਾਪ(m1[0]); j++)
    ਲਈ (k = 0; k < array_ਮਾਪ(m1[0][0]); k++)
      ਲਿਖੋ(" %d", (g ? m1:m2)[i][j][k]);
    ਲਿਖੋ("\n");
  }
}

ਖਾਲੀ test_init_ranges(ਖਾਲੀ) {
    ਪੂਰਨ i,c=0;
    ਸਥਿਰ ਖਾਲੀ *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    ਲਈ (i = 0; i < 256; i++) {
        ਜਾਓ *gostring[i];
        l_bad: c++;
        l_loop: c++;
        l_esc: c++;
        l_qdown: c++;
        l_utf8_2: c++;
        l_utf8_3: c++;
        l_utf8_4: c++;
    }
    ਲਿਖੋ ("%d\n", c);
}


/* Following is from GCC gcc.c-torture/execute/20050613-1.c.  */

ਬਣਤਰ SEA { ਪੂਰਨ i; ਪੂਰਨ j; ਪੂਰਨ k; ਪੂਰਨ l; };
ਬਣਤਰ SEB { ਬਣਤਰ SEA a; ਪੂਰਨ r[1]; };
ਬਣਤਰ SEC { ਬਣਤਰ SEA a; ਪੂਰਨ r[0]; };
ਬਣਤਰ SED { ਬਣਤਰ SEA a; ਪੂਰਨ r[]; };

ਸਥਿਰ ਖਾਲੀ
test_correct_filling (ਬਣਤਰ SEA *x)
{
  ਸਥਿਰ ਪੂਰਨ i;
  ਜੇ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    ਲਿਖੋ("sea_fill%d: wrong\n", i);
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ("sea_fill%d: okay\n", i);
  i++;
}

ਪੂਰਨ
test_zero_init (ਖਾਲੀ)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  ਬਣਤਰ SEB b = { .a.j = 5 };
  ਬਣਤਰ SEC c = { .a.j = 5 };
  ਬਣਤਰ SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  ਵਾਪਸ 0;
}

ਖਾਲੀ test_init_struct_from_struct(ਖਾਲੀ)
{
    ਪੂਰਨ i = 0;
    ਬਣਤਰ S {ਪੂਰਨ x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (ਬਣਤਰ S){5,6}}
        ;

    ਲਿਖੋ("%s: %d %d %d %d - %d %d %d %d - %d %d %d %d\n",
        __FUNCTION__,
        c[0].x,
        c[0].y,
        c[1].x,
        c[1].y,
        d[0].x,
        d[0].y,
        d[1].x,
        d[1].y,
        e[0].x,
        e[0].y,
        e[1].x,
        e[1].y
        );
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ a;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ : 32;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ b;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ : 64;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

ਖਾਲੀ
test_init_bf(ਖਾਲੀ)
{
    ਲਿਖੋ ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


ਪੂਰਨ ਮੁੱਖ()
{
  print(ce);
  print(gs);
  print(gs2);
  print(gt);
  print(gu);
  print(gu2);
  print(gu3);
  print(gu4);
  print(gs3);
  print(gv);
  print(gv2);
  print(gv3);
  print(sinit16);
  print(gw);
  print(gsu);
  print(guv);
  print(guv.b);
  print(guv2);
  print(guv3);
  print(gssu1);
  print(gssu2);
  print(phdr);
  foo(&gw, &phdr);
  //printf("q: %s\n", q);
  test_compound_with_relocs();
  test_multi_relocs();
  test_zero_init();
  test_init_ranges();
  test_init_struct_from_struct();
  test_init_bf();
  ਵਾਪਸ 0;
}

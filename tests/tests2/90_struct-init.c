ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ u8;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {} ಖಾಲಿಗಳು_s;
ರಚನೆ ಒಳಗೊಂಡಿದೆ_ಖಾಲಿಗಳು {
    u8 a;
    ಖಾಲಿಗಳು_s ಖಾಲಿಗಳು;
    u8 b;
};
ರಚನೆ ಒಳಗೊಂಡಿದೆ_ಖಾಲಿಗಳು ce = { { (1) }, (ಖಾಲಿಗಳು_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
ರಚನೆ SS {u8 a[3], b; };
ರಚನೆ SS sinit16[] = { { 1 }, 2 };
ರಚನೆ S
{
  u8 a,b;
  u8 c[2];
};

ರಚನೆ T
{
  u8 s[16];
  u8 a;
};

ರಚನೆ U
{
  u8 a;
  ರಚನೆ S s;
  u8 b;
  ರಚನೆ T t;
};

ರಚನೆ V
{
  ರಚನೆ S s;
  ರಚನೆ T t;
  u8 a;
};

ರಚನೆ W
{
  ರಚನೆ V t;
  ರಚನೆ S s[];
};

ರಚನೆ S gs = ((ರಚನೆ S){1, 2, 3, 4});
ರಚನೆ S gs2 = {1, 2, {3, 4}};
ರಚನೆ T gt = {"hello", 42};
ರಚನೆ U gu = {3, 5,6,7,8, 4, "huhu", 43};
ರಚನೆ U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
ರಚನೆ U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
ರಚನೆ U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
ರಚನೆ S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
ರಚನೆ V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
ರಚನೆ V gv2 = {(ರಚನೆ S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
ರಚನೆ V gv3 = {((ರಚನೆ S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
ರಚನೆ W gw = {{1,2,3,4}, {1,2,3,4,5}};

ಒಕ್ಕೂಟ UU {
    u8 a;
    u8 b;
};
ರಚನೆ SU {
    ಒಕ್ಕೂಟ UU u;
    u8 c;
};
ರಚನೆ SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
ಒಕ್ಕೂಟ UV {
    ರಚನೆ {u8 a,b;};
    ರಚನೆ S s;
};
ಒಕ್ಕೂಟ UV guv = {{6,5}};
ಒಕ್ಕೂಟ UV guv2 = {{.b = 7, .a = 8}};
ಒಕ್ಕೂಟ UV guv3 = {.b = 8, .a = 7};

ರಚನೆ SSU {
    ಪೂರ್ಣಾಂಕ y;
    ರಚನೆ { ಪೂರ್ಣಾಂಕ x; };
};
ರಚನೆ SSU gssu1 = { .y = 5, .x = 3 };
ರಚನೆ SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

ರಚನೆ in6_addr {
    ಒಕ್ಕೂಟ {
	u8 u6_addr8[16];
	ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ u6_addr16[8];
    } u;
};
ರಚನೆ flowi6 {
    ರಚನೆ in6_addr saddr, daddr;
};
ರಚನೆ pkthdr {
    ರಚನೆ in6_addr daddr, saddr;
};
ರಚನೆ pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

ರಚನೆ Wrap {
    ಶೂನ್ಯ *func;
};
ಪೂರ್ಣಾಂಕ global;
ಶೂನ್ಯ inc_global (ಶೂನ್ಯ)
{
  global++;
}

ರಚನೆ Wrap global_wrap[] = {
    ((ರಚನೆ Wrap) {inc_global}),
    inc_global,
};

#ಅನ್ತರ್ಭಾವ <stdio.h>
ಶೂನ್ಯ print_ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ u8 *p, ದೀರ್ಘ ಗಾತ್ರ_2)
{
  ಬರೆ ("%s:", name);
  ಆಗ (ಗಾತ್ರ_2--) {
      ಬರೆ (" %x", *p++);
  }
  ಬರೆ ("\n");
}
#ವ್ಯಾಖ್ಯಾನಿಸು print(x) print_(#x, (u8*)&x, ಗಾತ್ರ (x))
#ಆದರೆ 1
ಶೂನ್ಯ foo (ರಚನೆ W *w, ರಚನೆ pkthdr *phdr_)
{
  ರಚನೆ S ls = {1, 2, 3, 4};
  ರಚನೆ S ls2 = {1, 2, {3, 4}};
  ರಚನೆ T lt = {"hello", 42};
  ರಚನೆ U lu = {3, 5,6,7,8, 4, "huhu", 43};
  ರಚನೆ U lu1 = {3, ls, 4, {"huhu", 43}};
  ರಚನೆ U lu2 = {3, (ls), 4, {"huhu", 43}};
  ಸ್ಥಿರಾಂಕ ರಚನೆ S *pls = &ls;
  ರಚನೆ S ls21 = *pls;
  ರಚನೆ U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  ರಚನೆ U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  ರಚನೆ U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  ರಚನೆ U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  ರಚನೆ S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  ರಚನೆ V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  ರಚನೆ V lv2 = {(ರಚನೆ S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  ರಚನೆ V lv3 = {((ರಚನೆ S){7,8,{9,10}}), ((ಸ್ಥಿರಾಂಕ ರಚನೆ W *)w)->t.t, 50};
  ಸ್ಥಿರಾಂಕ ರಚನೆ pkthdr *phdr = phdr_;
  ರಚನೆ flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  ಪೂರ್ಣಾಂಕ elt = 0x42;
  /* Range init, overlapping */
  ರಚನೆ T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  ರಚನೆ SSU lssu1 = { 5, 3 };
  ರಚನೆ SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ಆದರೆ defined(__GNUC__) || defined(__TINYC__)
  ರಚನೆ S ls4 = {a: 1, b: 2, c: {3, 4}};
#ಇಲ್ಲದಿದ್ದರೆ
  ರಚನೆ S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
#ಆದರೆ_ಅಂತ್ಯ
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
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ test_compound_with_relocs (ಶೂನ್ಯ)
{
  ರಚನೆ Wrap local_wrap[] = {
      ((ರಚನೆ Wrap) {inc_global}),
      inc_global,
  };
  ಶೂನ್ಯ (*p)(ಶೂನ್ಯ);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

ಶೂನ್ಯ sys_ni(ಶೂನ್ಯ) { ಬರೆ("ni\n"); }
ಶೂನ್ಯ sys_one(ಶೂನ್ಯ) { ಬರೆ("one\n"); }
ಶೂನ್ಯ sys_two(ಶೂನ್ಯ) { ಬರೆ("two\n"); }
ಶೂನ್ಯ sys_three(ಶೂನ್ಯ) { ಬರೆ("three\n"); }
ಶೂನ್ಯ sys_four(ಶೂನ್ಯ) { ಬರೆ("four\n"); }
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (*fptr)(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿಸು array_ಗಾತ್ರ(a) (ಗಾತ್ರ a / ಗಾತ್ರ a[0])

ಶೂನ್ಯ test_multi_relocs(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i;

  ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ಗಾಗಿ (i = 0; i < array_ಗಾತ್ರ(tabl1); i++)
    ಆದರೆ (tabl1[i])
      tabl1[i]();
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ("(0)\n");

  ಸ್ಥಿರಾಂಕ fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ಗಾಗಿ (i = 0; i < array_ಗಾತ್ರ(tabl2); i++)
    ಆದರೆ (tabl2[i])
      tabl2[i]();
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ("(0)\n");

  ಪೂರ್ಣಾಂಕ c = 0;
  ಪೂರ್ಣಾಂಕ dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  ಗಾಗಿ (i = 0; i < array_ಗಾತ್ರ(dd); i++)
    ಬರೆ(" %d", dd[i]);
  ಬರೆ("\n");

  /* multi-dimensional flex array with range initializers */
  ಸ್ಥಿರ ಅಕ್ಷರ m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ಅಕ್ಷರ        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ಪೂರ್ಣಾಂಕ g, j, k;
  ಗಾಗಿ (g = 2; g-- > 0;) {
    ಬರೆ("mdfa %s: %d -", "locl\0glob" + g * 5, ಗಾತ್ರ m1);
    ಗಾಗಿ (i = 0; i < array_ಗಾತ್ರ(m1); i++)
    ಗಾಗಿ (j = 0; j < array_ಗಾತ್ರ(m1[0]); j++)
    ಗಾಗಿ (k = 0; k < array_ಗಾತ್ರ(m1[0][0]); k++)
      ಬರೆ(" %d", (g ? m1:m2)[i][j][k]);
    ಬರೆ("\n");
  }
}

ಶೂನ್ಯ test_init_ranges(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಂಕ i,c=0;
    ಸ್ಥಿರ ಶೂನ್ಯ *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    ಗಾಗಿ (i = 0; i < 256; i++) {
        ಹೋಗು *gostring[i];
        l_bad: c++;
        l_loop: c++;
        l_esc: c++;
        l_qdown: c++;
        l_utf8_2: c++;
        l_utf8_3: c++;
        l_utf8_4: c++;
    }
    ಬರೆ ("%d\n", c);
}


/* Following is from GCC gcc.c-torture/execute/20050613-1.c.  */

ರಚನೆ SEA { ಪೂರ್ಣಾಂಕ i; ಪೂರ್ಣಾಂಕ j; ಪೂರ್ಣಾಂಕ k; ಪೂರ್ಣಾಂಕ l; };
ರಚನೆ SEB { ರಚನೆ SEA a; ಪೂರ್ಣಾಂಕ r[1]; };
ರಚನೆ SEC { ರಚನೆ SEA a; ಪೂರ್ಣಾಂಕ r[0]; };
ರಚನೆ SED { ರಚನೆ SEA a; ಪೂರ್ಣಾಂಕ r[]; };

ಸ್ಥಿರ ಶೂನ್ಯ
test_correct_filling (ರಚನೆ SEA *x)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ i;
  ಆದರೆ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    ಬರೆ("sea_fill%d: wrong\n", i);
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("sea_fill%d: okay\n", i);
  i++;
}

ಪೂರ್ಣಾಂಕ
test_zero_init (ಶೂನ್ಯ)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  ರಚನೆ SEB b = { .a.j = 5 };
  ರಚನೆ SEC c = { .a.j = 5 };
  ರಚನೆ SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ test_init_struct_from_struct(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i = 0;
    ರಚನೆ S {ಪೂರ್ಣಾಂಕ x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (ರಚನೆ S){5,6}}
        ;

    ಬರೆ("%s: %d %d %d %d - %d %d %d %d - %d %d %d %d\n",
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

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ a;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ : 32;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ b;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ : 64;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

ಶೂನ್ಯ
test_init_bf(ಶೂನ್ಯ)
{
    ಬರೆ ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
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
  ಹಿಂತಿರುಗಿ 0;
}

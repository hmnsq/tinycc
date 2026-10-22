ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ u8;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {} empty_s;
ಸಂರಚನಾ contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
ಸಂರಚನಾ contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
ಸಂರಚನಾ SS {u8 a[3], b; };
ಸಂರಚನಾ SS sinit16[] = { { 1 }, 2 };
ಸಂರಚನಾ S
{
  u8 a,b;
  u8 c[2];
};

ಸಂರಚನಾ T
{
  u8 s[16];
  u8 a;
};

ಸಂರಚನಾ U
{
  u8 a;
  ಸಂರಚನಾ S s;
  u8 b;
  ಸಂರಚನಾ T t;
};

ಸಂರಚನಾ V
{
  ಸಂರಚನಾ S s;
  ಸಂರಚನಾ T t;
  u8 a;
};

ಸಂರಚನಾ W
{
  ಸಂರಚನಾ V t;
  ಸಂರಚನಾ S s[];
};

ಸಂರಚನಾ S gs = ((ಸಂರಚನಾ S){1, 2, 3, 4});
ಸಂರಚನಾ S gs2 = {1, 2, {3, 4}};
ಸಂರಚನಾ T gt = {"hello", 42};
ಸಂರಚನಾ U gu = {3, 5,6,7,8, 4, "huhu", 43};
ಸಂರಚನಾ U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
ಸಂರಚನಾ U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
ಸಂರಚನಾ U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
ಸಂರಚನಾ S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
ಸಂರಚನಾ V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
ಸಂರಚನಾ V gv2 = {(ಸಂರಚನಾ S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
ಸಂರಚನಾ V gv3 = {((ಸಂರಚನಾ S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
ಸಂರಚನಾ W gw = {{1,2,3,4}, {1,2,3,4,5}};

ಸಙ್ಘ UU {
    u8 a;
    u8 b;
};
ಸಂರಚನಾ SU {
    ಸಙ್ಘ UU u;
    u8 c;
};
ಸಂರಚನಾ SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
ಸಙ್ಘ UV {
    ಸಂರಚನಾ {u8 a,b;};
    ಸಂರಚನಾ S s;
};
ಸಙ್ಘ UV guv = {{6,5}};
ಸಙ್ಘ UV guv2 = {{.b = 7, .a = 8}};
ಸಙ್ಘ UV guv3 = {.b = 8, .a = 7};

ಸಂರಚನಾ SSU {
    ಪೂರ್ಣಾಙ್ಕ y;
    ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x; };
};
ಸಂರಚನಾ SSU gssu1 = { .y = 5, .x = 3 };
ಸಂರಚನಾ SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

ಸಂರಚನಾ in6_addr {
    ಸಙ್ಘ {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
ಸಂರಚನಾ flowi6 {
    ಸಂರಚನಾ in6_addr saddr, daddr;
};
ಸಂರಚನಾ pkthdr {
    ಸಂರಚನಾ in6_addr daddr, saddr;
};
ಸಂರಚನಾ pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

ಸಂರಚನಾ Wrap {
    ಶೂನ್ಯ *func;
};
ಪೂರ್ಣಾಙ್ಕ global;
ಶೂನ್ಯ inc_global (ಶೂನ್ಯ)
{
  global++;
}

ಸಂರಚನಾ Wrap global_wrap[] = {
    ((ಸಂರಚನಾ Wrap) {inc_global}),
    inc_global,
};

#ಅನ್ತರ್ಭಾವ <stdio.h>
ಶೂನ್ಯ print_ (ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ u8 *p, long size)
{
  printf ("%s:", name);
  ಯಾವತ್ (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, ಪರಿಮಾಣ (x))
#ಯದಿ 1
ಶೂನ್ಯ foo (ಸಂರಚನಾ W *w, ಸಂರಚನಾ pkthdr *phdr_)
{
  ಸಂರಚನಾ S ls = {1, 2, 3, 4};
  ಸಂರಚನಾ S ls2 = {1, 2, {3, 4}};
  ಸಂರಚನಾ T lt = {"hello", 42};
  ಸಂರಚನಾ U lu = {3, 5,6,7,8, 4, "huhu", 43};
  ಸಂರಚನಾ U lu1 = {3, ls, 4, {"huhu", 43}};
  ಸಂರಚನಾ U lu2 = {3, (ls), 4, {"huhu", 43}};
  ಧ್ರುವ ಸಂರಚನಾ S *pls = &ls;
  ಸಂರಚನಾ S ls21 = *pls;
  ಸಂರಚನಾ U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  ಸಂರಚನಾ U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  ಸಂರಚನಾ U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  ಸಂರಚನಾ U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  ಸಂರಚನಾ S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  ಸಂರಚನಾ V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  ಸಂರಚನಾ V lv2 = {(ಸಂರಚನಾ S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  ಸಂರಚನಾ V lv3 = {((ಸಂರಚನಾ S){7,8,{9,10}}), ((ಧ್ರುವ ಸಂರಚನಾ W *)w)->t.t, 50};
  ಧ್ರುವ ಸಂರಚನಾ pkthdr *phdr = phdr_;
  ಸಂರಚನಾ flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  ಪೂರ್ಣಾಙ್ಕ elt = 0x42;
  /* Range init, overlapping */
  ಸಂರಚನಾ T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  ಸಂರಚನಾ SSU lssu1 = { 5, 3 };
  ಸಂರಚನಾ SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ಯದಿ defined(__GNUC__) || defined(__TINYC__)
  ಸಂರಚನಾ S ls4 = {a: 1, b: 2, c: {3, 4}};
#ಅನ್ಯಥಾ
  ಸಂರಚನಾ S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
#endif
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
#endif

ಶೂನ್ಯ test_compound_with_relocs (ಶೂನ್ಯ)
{
  ಸಂರಚನಾ Wrap local_wrap[] = {
      ((ಸಂರಚನಾ Wrap) {inc_global}),
      inc_global,
  };
  ಶೂನ್ಯ (*p)(ಶೂನ್ಯ);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

ಶೂನ್ಯ sys_ni(ಶೂನ್ಯ) { printf("ni\n"); }
ಶೂನ್ಯ sys_one(ಶೂನ್ಯ) { printf("one\n"); }
ಶೂನ್ಯ sys_two(ಶೂನ್ಯ) { printf("two\n"); }
ಶೂನ್ಯ sys_three(ಶೂನ್ಯ) { printf("three\n"); }
ಶೂನ್ಯ sys_four(ಶೂನ್ಯ) { printf("four\n"); }
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (*fptr)(ಶೂನ್ಯ);

#define array_size(a) (ಪರಿಮಾಣ a / ಪರಿಮಾಣ a[0])

ಶೂನ್ಯ test_multi_relocs(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i;

  ಸ್ಥಿರ ಧ್ರುವ fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ಪ್ರತಿ (i = 0; i < array_size(tabl1); i++)
    ಯದಿ (tabl1[i])
      tabl1[i]();
    ಅನ್ಯಥಾ
      printf("(0)\n");

  ಧ್ರುವ fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ಪ್ರತಿ (i = 0; i < array_size(tabl2); i++)
    ಯದಿ (tabl2[i])
      tabl2[i]();
    ಅನ್ಯಥಾ
      printf("(0)\n");

  ಪೂರ್ಣಾಙ್ಕ c = 0;
  ಪೂರ್ಣಾಙ್ಕ dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  ಪ್ರತಿ (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  ಸ್ಥಿರ ವರ್ಣ m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ವರ್ಣ        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ಪೂರ್ಣಾಙ್ಕ g, j, k;
  ಪ್ರತಿ (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, ಪರಿಮಾಣ m1);
    ಪ್ರತಿ (i = 0; i < array_size(m1); i++)
    ಪ್ರತಿ (j = 0; j < array_size(m1[0]); j++)
    ಪ್ರತಿ (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

ಶೂನ್ಯ test_init_ranges(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಙ್ಕ i,c=0;
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

    ಪ್ರತಿ (i = 0; i < 256; i++) {
        ಗಚ್ಛ *gostring[i];
        l_bad: c++;
        l_loop: c++;
        l_esc: c++;
        l_qdown: c++;
        l_utf8_2: c++;
        l_utf8_3: c++;
        l_utf8_4: c++;
    }
    printf ("%d\n", c);
}


/* Following is from GCC gcc.c-torture/execute/20050613-1.c.  */

ಸಂರಚನಾ SEA { ಪೂರ್ಣಾಙ್ಕ i; ಪೂರ್ಣಾಙ್ಕ j; ಪೂರ್ಣಾಙ್ಕ k; ಪೂರ್ಣಾಙ್ಕ l; };
ಸಂರಚನಾ SEB { ಸಂರಚನಾ SEA a; ಪೂರ್ಣಾಙ್ಕ r[1]; };
ಸಂರಚನಾ SEC { ಸಂರಚನಾ SEA a; ಪೂರ್ಣಾಙ್ಕ r[0]; };
ಸಂರಚನಾ SED { ಸಂರಚನಾ SEA a; ಪೂರ್ಣಾಙ್ಕ r[]; };

ಸ್ಥಿರ ಶೂನ್ಯ
test_correct_filling (ಸಂರಚನಾ SEA *x)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ i;
  ಯದಿ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  ಅನ್ಯಥಾ
    printf("sea_fill%d: okay\n", i);
  i++;
}

ಪೂರ್ಣಾಙ್ಕ
test_zero_init (ಶೂನ್ಯ)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  ಸಂರಚನಾ SEB b = { .a.j = 5 };
  ಸಂರಚನಾ SEC c = { .a.j = 5 };
  ಸಂರಚನಾ SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ test_init_struct_from_struct(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಸಂರಚನಾ S {ಪೂರ್ಣಾಙ್ಕ x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (ಸಂರಚನಾ S){5,6}}
        ;

    printf("%s: %d %d %d %d - %d %d %d %d - %d %d %d %d\n",
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

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    unsigned ಪೂರ್ಣಾಙ್ಕ a;
    unsigned ಪೂರ್ಣಾಙ್ಕ : 32;
    unsigned ಪೂರ್ಣಾಙ್ಕ b;
    unsigned long long : 64;
    unsigned ಪೂರ್ಣಾಙ್ಕ c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

ಶೂನ್ಯ
test_init_bf(ಶೂನ್ಯ)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


ಪೂರ್ಣಾಙ್ಕ main()
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
  ಪ್ರತ್ಯಾಗಮ 0;
}

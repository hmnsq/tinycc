ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ଅକ୍ଷର u8;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {} empty_s;
ସଂରଚନା contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
ସଂରଚନା contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
ସଂରଚନା SS {u8 a[3], b; };
ସଂରଚନା SS sinit16[] = { { 1 }, 2 };
ସଂରଚନା S
{
  u8 a,b;
  u8 c[2];
};

ସଂରଚନା T
{
  u8 s[16];
  u8 a;
};

ସଂରଚନା U
{
  u8 a;
  ସଂରଚନା S s;
  u8 b;
  ସଂରଚନା T t;
};

ସଂରଚନା V
{
  ସଂରଚନା S s;
  ସଂରଚନା T t;
  u8 a;
};

ସଂରଚନା W
{
  ସଂରଚନା V t;
  ସଂରଚନା S s[];
};

ସଂରଚନା S gs = ((ସଂରଚନା S){1, 2, 3, 4});
ସଂରଚନା S gs2 = {1, 2, {3, 4}};
ସଂରଚନା T gt = {"hello", 42};
ସଂରଚନା U gu = {3, 5,6,7,8, 4, "huhu", 43};
ସଂରଚନା U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
ସଂରଚନା U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
ସଂରଚନା U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
ସଂରଚନା S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
ସଂରଚନା V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
ସଂରଚନା V gv2 = {(ସଂରଚନା S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
ସଂରଚନା V gv3 = {((ସଂରଚନା S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
ସଂରଚନା W gw = {{1,2,3,4}, {1,2,3,4,5}};

ସଂଘ UU {
    u8 a;
    u8 b;
};
ସଂରଚନା SU {
    ସଂଘ UU u;
    u8 c;
};
ସଂରଚନା SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
ସଂଘ UV {
    ସଂରଚନା {u8 a,b;};
    ସଂରଚନା S s;
};
ସଂଘ UV guv = {{6,5}};
ସଂଘ UV guv2 = {{.b = 7, .a = 8}};
ସଂଘ UV guv3 = {.b = 8, .a = 7};

ସଂରଚନା SSU {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା y;
    ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା x; };
};
ସଂରଚନା SSU gssu1 = { .y = 5, .x = 3 };
ସଂରଚନା SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

ସଂରଚନା in6_addr {
    ସଂଘ {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
ସଂରଚନା flowi6 {
    ସଂରଚନା in6_addr saddr, daddr;
};
ସଂରଚନା pkthdr {
    ସଂରଚନା in6_addr daddr, saddr;
};
ସଂରଚନା pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

ସଂରଚନା Wrap {
    ଶୂନ୍ୟ *func;
};
ପୂର୍ଣ୍ଣସଂଖ୍ୟା global;
ଶୂନ୍ୟ inc_global (ଶୂନ୍ୟ)
{
  global++;
}

ସଂରଚନା Wrap global_wrap[] = {
    ((ସଂରଚନା Wrap) {inc_global}),
    inc_global,
};

#ଅନ୍ତର୍ଭାଵ <stdio.h>
ଶୂନ୍ୟ print_ (ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ u8 *p, long size)
{
  printf ("%s:", name);
  ଯେତେବେଳେ (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, ଆକାର (x))
#ଯଦି 1
ଶୂନ୍ୟ foo (ସଂରଚନା W *w, ସଂରଚନା pkthdr *phdr_)
{
  ସଂରଚନା S ls = {1, 2, 3, 4};
  ସଂରଚନା S ls2 = {1, 2, {3, 4}};
  ସଂରଚନା T lt = {"hello", 42};
  ସଂରଚନା U lu = {3, 5,6,7,8, 4, "huhu", 43};
  ସଂରଚନା U lu1 = {3, ls, 4, {"huhu", 43}};
  ସଂରଚନା U lu2 = {3, (ls), 4, {"huhu", 43}};
  ଅଚଳ ସଂରଚନା S *pls = &ls;
  ସଂରଚନା S ls21 = *pls;
  ସଂରଚନା U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  ସଂରଚନା U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  ସଂରଚନା U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  ସଂରଚନା U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  ସଂରଚନା S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  ସଂରଚନା V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  ସଂରଚନା V lv2 = {(ସଂରଚନା S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  ସଂରଚନା V lv3 = {((ସଂରଚନା S){7,8,{9,10}}), ((ଅଚଳ ସଂରଚନା W *)w)->t.t, 50};
  ଅଚଳ ସଂରଚନା pkthdr *phdr = phdr_;
  ସଂରଚନା flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା elt = 0x42;
  /* Range init, overlapping */
  ସଂରଚନା T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  ସଂରଚନା SSU lssu1 = { 5, 3 };
  ସଂରଚନା SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ଯଦି defined(__GNUC__) || defined(__TINYC__)
  ସଂରଚନା S ls4 = {a: 1, b: 2, c: {3, 4}};
#ଅନ୍ୟଥା
  ସଂରଚନା S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

ଶୂନ୍ୟ test_compound_with_relocs (ଶୂନ୍ୟ)
{
  ସଂରଚନା Wrap local_wrap[] = {
      ((ସଂରଚନା Wrap) {inc_global}),
      inc_global,
  };
  ଶୂନ୍ୟ (*p)(ଶୂନ୍ୟ);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

ଶୂନ୍ୟ sys_ni(ଶୂନ୍ୟ) { printf("ni\n"); }
ଶୂନ୍ୟ sys_one(ଶୂନ୍ୟ) { printf("one\n"); }
ଶୂନ୍ୟ sys_two(ଶୂନ୍ୟ) { printf("two\n"); }
ଶୂନ୍ୟ sys_three(ଶୂନ୍ୟ) { printf("three\n"); }
ଶୂନ୍ୟ sys_four(ଶୂନ୍ୟ) { printf("four\n"); }
ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (*fptr)(ଶୂନ୍ୟ);

#define array_size(a) (ଆକାର a / ଆକାର a[0])

ଶୂନ୍ୟ test_multi_relocs(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

  ସ୍ଥିର ଅଚଳ fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ପାଇଁ (i = 0; i < array_size(tabl1); i++)
    ଯଦି (tabl1[i])
      tabl1[i]();
    ଅନ୍ୟଥା
      printf("(0)\n");

  ଅଚଳ fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  ପାଇଁ (i = 0; i < array_size(tabl2); i++)
    ଯଦି (tabl2[i])
      tabl2[i]();
    ଅନ୍ୟଥା
      printf("(0)\n");

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 0;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  ପାଇଁ (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  ସ୍ଥିର ଅକ୍ଷର m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ଅକ୍ଷର        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା g, j, k;
  ପାଇଁ (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, ଆକାର m1);
    ପାଇଁ (i = 0; i < array_size(m1); i++)
    ପାଇଁ (j = 0; j < array_size(m1[0]); j++)
    ପାଇଁ (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

ଶୂନ୍ୟ test_init_ranges(ଶୂନ୍ୟ) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i,c=0;
    ସ୍ଥିର ଶୂନ୍ୟ *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    ପାଇଁ (i = 0; i < 256; i++) {
        ଯାଅ *gostring[i];
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

ସଂରଚନା SEA { ପୂର୍ଣ୍ଣସଂଖ୍ୟା i; ପୂର୍ଣ୍ଣସଂଖ୍ୟା j; ପୂର୍ଣ୍ଣସଂଖ୍ୟା k; ପୂର୍ଣ୍ଣସଂଖ୍ୟା l; };
ସଂରଚନା SEB { ସଂରଚନା SEA a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା r[1]; };
ସଂରଚନା SEC { ସଂରଚନା SEA a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା r[0]; };
ସଂରଚନା SED { ସଂରଚନା SEA a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା r[]; };

ସ୍ଥିର ଶୂନ୍ୟ
test_correct_filling (ସଂରଚନା SEA *x)
{
  ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
  ଯଦି (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  ଅନ୍ୟଥା
    printf("sea_fill%d: okay\n", i);
  i++;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
test_zero_init (ଶୂନ୍ୟ)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  ସଂରଚନା SEB b = { .a.j = 5 };
  ସଂରଚନା SEC c = { .a.j = 5 };
  ସଂରଚନା SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ test_init_struct_from_struct(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ସଂରଚନା S {ପୂର୍ଣ୍ଣସଂଖ୍ୟା x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (ସଂରଚନା S){5,6}}
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା : 32;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
    unsigned long long : 64;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

ଶୂନ୍ୟ
test_init_bf(ଶୂନ୍ୟ)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
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
  ଫେରନ୍ତୁ 0;
}

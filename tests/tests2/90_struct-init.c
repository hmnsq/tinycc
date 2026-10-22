প্রকারনির্দেশ unsigned বর্ণ u8;
প্রকারনির্দেশ সংরচনা {} empty_s;
সংরচনা contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
সংরচনা contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
সংরচনা SS {u8 a[3], b; };
সংরচনা SS sinit16[] = { { 1 }, 2 };
সংরচনা S
{
  u8 a,b;
  u8 c[2];
};

সংরচনা T
{
  u8 s[16];
  u8 a;
};

সংরচনা U
{
  u8 a;
  সংরচনা S s;
  u8 b;
  সংরচনা T t;
};

সংরচনা V
{
  সংরচনা S s;
  সংরচনা T t;
  u8 a;
};

সংরচনা W
{
  সংরচনা V t;
  সংরচনা S s[];
};

সংরচনা S gs = ((সংরচনা S){1, 2, 3, 4});
সংরচনা S gs2 = {1, 2, {3, 4}};
সংরচনা T gt = {"hello", 42};
সংরচনা U gu = {3, 5,6,7,8, 4, "huhu", 43};
সংরচনা U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
সংরচনা U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
সংরচনা U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
সংরচনা S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
সংরচনা V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
সংরচনা V gv2 = {(সংরচনা S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
সংরচনা V gv3 = {((সংরচনা S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
সংরচনা W gw = {{1,2,3,4}, {1,2,3,4,5}};

সঙ্ঘ UU {
    u8 a;
    u8 b;
};
সংরচনা SU {
    সঙ্ঘ UU u;
    u8 c;
};
সংরচনা SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
সঙ্ঘ UV {
    সংরচনা {u8 a,b;};
    সংরচনা S s;
};
সঙ্ঘ UV guv = {{6,5}};
সঙ্ঘ UV guv2 = {{.b = 7, .a = 8}};
সঙ্ঘ UV guv3 = {.b = 8, .a = 7};

সংরচনা SSU {
    পূর্ণাঙ্ক y;
    সংরচনা { পূর্ণাঙ্ক x; };
};
সংরচনা SSU gssu1 = { .y = 5, .x = 3 };
সংরচনা SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

সংরচনা in6_addr {
    সঙ্ঘ {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
সংরচনা flowi6 {
    সংরচনা in6_addr saddr, daddr;
};
সংরচনা pkthdr {
    সংরচনা in6_addr daddr, saddr;
};
সংরচনা pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

সংরচনা Wrap {
    শূন্য *func;
};
পূর্ণাঙ্ক global;
শূন্য inc_global (শূন্য)
{
  global++;
}

সংরচনা Wrap global_wrap[] = {
    ((সংরচনা Wrap) {inc_global}),
    inc_global,
};

#অন্তর্ভাব <stdio.h>
শূন্য print_ (ধ্রুব বর্ণ *name, ধ্রুব u8 *p, long size)
{
  printf ("%s:", name);
  যাবত্ (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, পরিমাণ (x))
#যদি 1
শূন্য foo (সংরচনা W *w, সংরচনা pkthdr *phdr_)
{
  সংরচনা S ls = {1, 2, 3, 4};
  সংরচনা S ls2 = {1, 2, {3, 4}};
  সংরচনা T lt = {"hello", 42};
  সংরচনা U lu = {3, 5,6,7,8, 4, "huhu", 43};
  সংরচনা U lu1 = {3, ls, 4, {"huhu", 43}};
  সংরচনা U lu2 = {3, (ls), 4, {"huhu", 43}};
  ধ্রুব সংরচনা S *pls = &ls;
  সংরচনা S ls21 = *pls;
  সংরচনা U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  সংরচনা U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  সংরচনা U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  সংরচনা U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  সংরচনা S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  সংরচনা V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  সংরচনা V lv2 = {(সংরচনা S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  সংরচনা V lv3 = {((সংরচনা S){7,8,{9,10}}), ((ধ্রুব সংরচনা W *)w)->t.t, 50};
  ধ্রুব সংরচনা pkthdr *phdr = phdr_;
  সংরচনা flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  পূর্ণাঙ্ক elt = 0x42;
  /* Range init, overlapping */
  সংরচনা T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  সংরচনা SSU lssu1 = { 5, 3 };
  সংরচনা SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#যদি defined(__GNUC__) || defined(__TINYC__)
  সংরচনা S ls4 = {a: 1, b: 2, c: {3, 4}};
#অন্যথা
  সংরচনা S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

শূন্য test_compound_with_relocs (শূন্য)
{
  সংরচনা Wrap local_wrap[] = {
      ((সংরচনা Wrap) {inc_global}),
      inc_global,
  };
  শূন্য (*p)(শূন্য);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

শূন্য sys_ni(শূন্য) { printf("ni\n"); }
শূন্য sys_one(শূন্য) { printf("one\n"); }
শূন্য sys_two(শূন্য) { printf("two\n"); }
শূন্য sys_three(শূন্য) { printf("three\n"); }
শূন্য sys_four(শূন্য) { printf("four\n"); }
প্রকারনির্দেশ শূন্য (*fptr)(শূন্য);

#define array_size(a) (পরিমাণ a / পরিমাণ a[0])

শূন্য test_multi_relocs(শূন্য)
{
  পূর্ণাঙ্ক i;

  স্থির ধ্রুব fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  প্রতি (i = 0; i < array_size(tabl1); i++)
    যদি (tabl1[i])
      tabl1[i]();
    অন্যথা
      printf("(0)\n");

  ধ্রুব fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  প্রতি (i = 0; i < array_size(tabl2); i++)
    যদি (tabl2[i])
      tabl2[i]();
    অন্যথা
      printf("(0)\n");

  পূর্ণাঙ্ক c = 0;
  পূর্ণাঙ্ক dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  প্রতি (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  স্থির বর্ণ m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  বর্ণ        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  পূর্ণাঙ্ক g, j, k;
  প্রতি (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, পরিমাণ m1);
    প্রতি (i = 0; i < array_size(m1); i++)
    প্রতি (j = 0; j < array_size(m1[0]); j++)
    প্রতি (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

শূন্য test_init_ranges(শূন্য) {
    পূর্ণাঙ্ক i,c=0;
    স্থির শূন্য *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    প্রতি (i = 0; i < 256; i++) {
        গচ্ছ *gostring[i];
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

সংরচনা SEA { পূর্ণাঙ্ক i; পূর্ণাঙ্ক j; পূর্ণাঙ্ক k; পূর্ণাঙ্ক l; };
সংরচনা SEB { সংরচনা SEA a; পূর্ণাঙ্ক r[1]; };
সংরচনা SEC { সংরচনা SEA a; পূর্ণাঙ্ক r[0]; };
সংরচনা SED { সংরচনা SEA a; পূর্ণাঙ্ক r[]; };

স্থির শূন্য
test_correct_filling (সংরচনা SEA *x)
{
  স্থির পূর্ণাঙ্ক i;
  যদি (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  অন্যথা
    printf("sea_fill%d: okay\n", i);
  i++;
}

পূর্ণাঙ্ক
test_zero_init (শূন্য)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  সংরচনা SEB b = { .a.j = 5 };
  সংরচনা SEC c = { .a.j = 5 };
  সংরচনা SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  প্রত্যাগম 0;
}

শূন্য test_init_struct_from_struct(শূন্য)
{
    পূর্ণাঙ্ক i = 0;
    সংরচনা S {পূর্ণাঙ্ক x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (সংরচনা S){5,6}}
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

প্রকারনির্দেশ সংরচনা {
    unsigned পূর্ণাঙ্ক a;
    unsigned পূর্ণাঙ্ক : 32;
    unsigned পূর্ণাঙ্ক b;
    unsigned long long : 64;
    unsigned পূর্ণাঙ্ক c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

শূন্য
test_init_bf(শূন্য)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


পূর্ণাঙ্ক main()
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
  প্রত্যাগম 0;
}

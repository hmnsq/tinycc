تعريفنوع unsigned حرف u8;
تعريفنوع بنية {} empty_s;
بنية contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
بنية contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
بنية SS {u8 a[3], b; };
بنية SS sinit16[] = { { 1 }, 2 };
بنية S
{
  u8 a,b;
  u8 c[2];
};

بنية T
{
  u8 s[16];
  u8 a;
};

بنية U
{
  u8 a;
  بنية S s;
  u8 b;
  بنية T t;
};

بنية V
{
  بنية S s;
  بنية T t;
  u8 a;
};

بنية W
{
  بنية V t;
  بنية S s[];
};

بنية S gs = ((بنية S){1, 2, 3, 4});
بنية S gs2 = {1, 2, {3, 4}};
بنية T gt = {"hello", 42};
بنية U gu = {3, 5,6,7,8, 4, "huhu", 43};
بنية U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
بنية U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
بنية U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
بنية S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
بنية V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
بنية V gv2 = {(بنية S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
بنية V gv3 = {((بنية S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
بنية W gw = {{1,2,3,4}, {1,2,3,4,5}};

اتحاد UU {
    u8 a;
    u8 b;
};
بنية SU {
    اتحاد UU u;
    u8 c;
};
بنية SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
اتحاد UV {
    بنية {u8 a,b;};
    بنية S s;
};
اتحاد UV guv = {{6,5}};
اتحاد UV guv2 = {{.b = 7, .a = 8}};
اتحاد UV guv3 = {.b = 8, .a = 7};

بنية SSU {
    صحيح y;
    بنية { صحيح x; };
};
بنية SSU gssu1 = { .y = 5, .x = 3 };
بنية SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

بنية in6_addr {
    اتحاد {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
بنية flowi6 {
    بنية in6_addr saddr, daddr;
};
بنية pkthdr {
    بنية in6_addr daddr, saddr;
};
بنية pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

بنية Wrap {
    فراغ *func;
};
صحيح global;
فراغ inc_global (فراغ)
{
  global++;
}

بنية Wrap global_wrap[] = {
    ((بنية Wrap) {inc_global}),
    inc_global,
};

#ضمن <stdio.h>
فراغ print_ (ثابت حرف *name, ثابت u8 *p, long size)
{
  printf ("%s:", name);
  طالما (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, حجم (x))
#𐡄𐡍 1
فراغ foo (بنية W *w, بنية pkthdr *phdr_)
{
  بنية S ls = {1, 2, 3, 4};
  بنية S ls2 = {1, 2, {3, 4}};
  بنية T lt = {"hello", 42};
  بنية U lu = {3, 5,6,7,8, 4, "huhu", 43};
  بنية U lu1 = {3, ls, 4, {"huhu", 43}};
  بنية U lu2 = {3, (ls), 4, {"huhu", 43}};
  ثابت بنية S *pls = &ls;
  بنية S ls21 = *pls;
  بنية U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  بنية U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  بنية U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  بنية U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  بنية S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  بنية V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  بنية V lv2 = {(بنية S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  بنية V lv3 = {((بنية S){7,8,{9,10}}), ((ثابت بنية W *)w)->t.t, 50};
  ثابت بنية pkthdr *phdr = phdr_;
  بنية flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  صحيح elt = 0x42;
  /* Range init, overlapping */
  بنية T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  بنية SSU lssu1 = { 5, 3 };
  بنية SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#𐡄𐡍 defined(__GNUC__) || defined(__TINYC__)
  بنية S ls4 = {a: 1, b: 2, c: {3, 4}};
#وإلا
  بنية S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

فراغ test_compound_with_relocs (فراغ)
{
  بنية Wrap local_wrap[] = {
      ((بنية Wrap) {inc_global}),
      inc_global,
  };
  فراغ (*p)(فراغ);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

فراغ sys_ni(فراغ) { printf("ni\n"); }
فراغ sys_one(فراغ) { printf("one\n"); }
فراغ sys_two(فراغ) { printf("two\n"); }
فراغ sys_three(فراغ) { printf("three\n"); }
فراغ sys_four(فراغ) { printf("four\n"); }
تعريفنوع فراغ (*fptr)(فراغ);

#define array_size(a) (حجم a / حجم a[0])

فراغ test_multi_relocs(فراغ)
{
  صحيح i;

  ساكن ثابت fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  لكل (i = 0; i < array_size(tabl1); i++)
    𐡄𐡍 (tabl1[i])
      tabl1[i]();
    وإلا
      printf("(0)\n");

  ثابت fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  لكل (i = 0; i < array_size(tabl2); i++)
    𐡄𐡍 (tabl2[i])
      tabl2[i]();
    وإلا
      printf("(0)\n");

  صحيح c = 0;
  صحيح dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  لكل (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  ساكن حرف m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  حرف        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  صحيح g, j, k;
  لكل (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, حجم m1);
    لكل (i = 0; i < array_size(m1); i++)
    لكل (j = 0; j < array_size(m1[0]); j++)
    لكل (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

فراغ test_init_ranges(فراغ) {
    صحيح i,c=0;
    ساكن فراغ *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    لكل (i = 0; i < 256; i++) {
        اذهب *gostring[i];
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

بنية SEA { صحيح i; صحيح j; صحيح k; صحيح l; };
بنية SEB { بنية SEA a; صحيح r[1]; };
بنية SEC { بنية SEA a; صحيح r[0]; };
بنية SED { بنية SEA a; صحيح r[]; };

ساكن فراغ
test_correct_filling (بنية SEA *x)
{
  ساكن صحيح i;
  𐡄𐡍 (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  وإلا
    printf("sea_fill%d: okay\n", i);
  i++;
}

صحيح
test_zero_init (فراغ)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  بنية SEB b = { .a.j = 5 };
  بنية SEC c = { .a.j = 5 };
  بنية SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  أرجع 0;
}

فراغ test_init_struct_from_struct(فراغ)
{
    صحيح i = 0;
    بنية S {صحيح x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (بنية S){5,6}}
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

تعريفنوع بنية {
    unsigned صحيح a;
    unsigned صحيح : 32;
    unsigned صحيح b;
    unsigned long long : 64;
    unsigned صحيح c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

فراغ
test_init_bf(فراغ)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


صحيح main()
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
  أرجع 0;
}

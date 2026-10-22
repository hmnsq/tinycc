തരനിർവചനം unsigned അക്ഷരം u8;
തരനിർവചനം ഘടന {} empty_s;
ഘടന contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
ഘടന contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
ഘടന SS {u8 a[3], b; };
ഘടന SS sinit16[] = { { 1 }, 2 };
ഘടന S
{
  u8 a,b;
  u8 c[2];
};

ഘടന T
{
  u8 s[16];
  u8 a;
};

ഘടന U
{
  u8 a;
  ഘടന S s;
  u8 b;
  ഘടന T t;
};

ഘടന V
{
  ഘടന S s;
  ഘടന T t;
  u8 a;
};

ഘടന W
{
  ഘടന V t;
  ഘടന S s[];
};

ഘടന S gs = ((ഘടന S){1, 2, 3, 4});
ഘടന S gs2 = {1, 2, {3, 4}};
ഘടന T gt = {"hello", 42};
ഘടന U gu = {3, 5,6,7,8, 4, "huhu", 43};
ഘടന U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
ഘടന U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
ഘടന U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
ഘടന S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
ഘടന V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
ഘടന V gv2 = {(ഘടന S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
ഘടന V gv3 = {((ഘടന S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
ഘടന W gw = {{1,2,3,4}, {1,2,3,4,5}};

സംഘം UU {
    u8 a;
    u8 b;
};
ഘടന SU {
    സംഘം UU u;
    u8 c;
};
ഘടന SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
സംഘം UV {
    ഘടന {u8 a,b;};
    ഘടന S s;
};
സംഘം UV guv = {{6,5}};
സംഘം UV guv2 = {{.b = 7, .a = 8}};
സംഘം UV guv3 = {.b = 8, .a = 7};

ഘടന SSU {
    പൂർണ്ണസംഖ്യ y;
    ഘടന { പൂർണ്ണസംഖ്യ x; };
};
ഘടന SSU gssu1 = { .y = 5, .x = 3 };
ഘടന SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

ഘടന in6_addr {
    സംഘം {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
ഘടന flowi6 {
    ഘടന in6_addr saddr, daddr;
};
ഘടന pkthdr {
    ഘടന in6_addr daddr, saddr;
};
ഘടന pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

ഘടന Wrap {
    ശൂന്യം *func;
};
പൂർണ്ണസംഖ്യ global;
ശൂന്യം inc_global (ശൂന്യം)
{
  global++;
}

ഘടന Wrap global_wrap[] = {
    ((ഘടന Wrap) {inc_global}),
    inc_global,
};

#അന്തര്ഭാവ <stdio.h>
ശൂന്യം print_ (സ്ഥിരം അക്ഷരം *name, സ്ഥിരം u8 *p, long size)
{
  printf ("%s:", name);
  ആകുമ്പോൾ (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, വലുപ്പം (x))
#എങ്കിൽ 1
ശൂന്യം foo (ഘടന W *w, ഘടന pkthdr *phdr_)
{
  ഘടന S ls = {1, 2, 3, 4};
  ഘടന S ls2 = {1, 2, {3, 4}};
  ഘടന T lt = {"hello", 42};
  ഘടന U lu = {3, 5,6,7,8, 4, "huhu", 43};
  ഘടന U lu1 = {3, ls, 4, {"huhu", 43}};
  ഘടന U lu2 = {3, (ls), 4, {"huhu", 43}};
  സ്ഥിരം ഘടന S *pls = &ls;
  ഘടന S ls21 = *pls;
  ഘടന U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  ഘടന U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  ഘടന U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  ഘടന U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  ഘടന S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  ഘടന V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  ഘടന V lv2 = {(ഘടന S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  ഘടന V lv3 = {((ഘടന S){7,8,{9,10}}), ((സ്ഥിരം ഘടന W *)w)->t.t, 50};
  സ്ഥിരം ഘടന pkthdr *phdr = phdr_;
  ഘടന flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  പൂർണ്ണസംഖ്യ elt = 0x42;
  /* Range init, overlapping */
  ഘടന T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  ഘടന SSU lssu1 = { 5, 3 };
  ഘടന SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#എങ്കിൽ defined(__GNUC__) || defined(__TINYC__)
  ഘടന S ls4 = {a: 1, b: 2, c: {3, 4}};
#അല്ലെങ്കിൽ
  ഘടന S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

ശൂന്യം test_compound_with_relocs (ശൂന്യം)
{
  ഘടന Wrap local_wrap[] = {
      ((ഘടന Wrap) {inc_global}),
      inc_global,
  };
  ശൂന്യം (*p)(ശൂന്യം);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

ശൂന്യം sys_ni(ശൂന്യം) { printf("ni\n"); }
ശൂന്യം sys_one(ശൂന്യം) { printf("one\n"); }
ശൂന്യം sys_two(ശൂന്യം) { printf("two\n"); }
ശൂന്യം sys_three(ശൂന്യം) { printf("three\n"); }
ശൂന്യം sys_four(ശൂന്യം) { printf("four\n"); }
തരനിർവചനം ശൂന്യം (*fptr)(ശൂന്യം);

#define array_size(a) (വലുപ്പം a / വലുപ്പം a[0])

ശൂന്യം test_multi_relocs(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i;

  സ്ഥിതം സ്ഥിരം fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  വേണ്ടി (i = 0; i < array_size(tabl1); i++)
    എങ്കിൽ (tabl1[i])
      tabl1[i]();
    അല്ലെങ്കിൽ
      printf("(0)\n");

  സ്ഥിരം fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  വേണ്ടി (i = 0; i < array_size(tabl2); i++)
    എങ്കിൽ (tabl2[i])
      tabl2[i]();
    അല്ലെങ്കിൽ
      printf("(0)\n");

  പൂർണ്ണസംഖ്യ c = 0;
  പൂർണ്ണസംഖ്യ dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  വേണ്ടി (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  സ്ഥിതം അക്ഷരം m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  അക്ഷരം        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  പൂർണ്ണസംഖ്യ g, j, k;
  വേണ്ടി (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, വലുപ്പം m1);
    വേണ്ടി (i = 0; i < array_size(m1); i++)
    വേണ്ടി (j = 0; j < array_size(m1[0]); j++)
    വേണ്ടി (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

ശൂന്യം test_init_ranges(ശൂന്യം) {
    പൂർണ്ണസംഖ്യ i,c=0;
    സ്ഥിതം ശൂന്യം *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    വേണ്ടി (i = 0; i < 256; i++) {
        പോകുക *gostring[i];
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

ഘടന SEA { പൂർണ്ണസംഖ്യ i; പൂർണ്ണസംഖ്യ j; പൂർണ്ണസംഖ്യ k; പൂർണ്ണസംഖ്യ l; };
ഘടന SEB { ഘടന SEA a; പൂർണ്ണസംഖ്യ r[1]; };
ഘടന SEC { ഘടന SEA a; പൂർണ്ണസംഖ്യ r[0]; };
ഘടന SED { ഘടന SEA a; പൂർണ്ണസംഖ്യ r[]; };

സ്ഥിതം ശൂന്യം
test_correct_filling (ഘടന SEA *x)
{
  സ്ഥിതം പൂർണ്ണസംഖ്യ i;
  എങ്കിൽ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  അല്ലെങ്കിൽ
    printf("sea_fill%d: okay\n", i);
  i++;
}

പൂർണ്ണസംഖ്യ
test_zero_init (ശൂന്യം)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  ഘടന SEB b = { .a.j = 5 };
  ഘടന SEC c = { .a.j = 5 };
  ഘടന SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  തിരികെ 0;
}

ശൂന്യം test_init_struct_from_struct(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i = 0;
    ഘടന S {പൂർണ്ണസംഖ്യ x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (ഘടന S){5,6}}
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

തരനിർവചനം ഘടന {
    unsigned പൂർണ്ണസംഖ്യ a;
    unsigned പൂർണ്ണസംഖ്യ : 32;
    unsigned പൂർണ്ണസംഖ്യ b;
    unsigned long long : 64;
    unsigned പൂർണ്ണസംഖ്യ c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

ശൂന്യം
test_init_bf(ശൂന്യം)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


പൂർണ്ണസംഖ്യ പ്രധാന()
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
  തിരികെ 0;
}

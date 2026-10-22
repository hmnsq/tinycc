typedef unsigned var_na u8;
typedef sa_nracanaa {} empty_s;
sa_nracanaa contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
sa_nracanaa contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
sa_nracanaa SS {u8 a[3], b; };
sa_nracanaa SS sinit16[] = { { 1 }, 2 };
sa_nracanaa S
{
  u8 a,b;
  u8 c[2];
};

sa_nracanaa T
{
  u8 s[16];
  u8 a;
};

sa_nracanaa U
{
  u8 a;
  sa_nracanaa S s;
  u8 b;
  sa_nracanaa T t;
};

sa_nracanaa V
{
  sa_nracanaa S s;
  sa_nracanaa T t;
  u8 a;
};

sa_nracanaa W
{
  sa_nracanaa V t;
  sa_nracanaa S s[];
};

sa_nracanaa S gs = ((sa_nracanaa S){1, 2, 3, 4});
sa_nracanaa S gs2 = {1, 2, {3, 4}};
sa_nracanaa T gt = {"hello", 42};
sa_nracanaa U gu = {3, 5,6,7,8, 4, "huhu", 43};
sa_nracanaa U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
sa_nracanaa U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
sa_nracanaa U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
sa_nracanaa S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
sa_nracanaa V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
sa_nracanaa V gv2 = {(sa_nracanaa S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
sa_nracanaa V gv3 = {((sa_nracanaa S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
sa_nracanaa W gw = {{1,2,3,4}, {1,2,3,4,5}};

sa_ngha UU {
    u8 a;
    u8 b;
};
sa_nracanaa SU {
    sa_ngha UU u;
    u8 c;
};
sa_nracanaa SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
sa_ngha UV {
    sa_nracanaa {u8 a,b;};
    sa_nracanaa S s;
};
sa_ngha UV guv = {{6,5}};
sa_ngha UV guv2 = {{.b = 7, .a = 8}};
sa_ngha UV guv3 = {.b = 8, .a = 7};

sa_nracanaa SSU {
    puur_naa_nka y;
    sa_nracanaa { puur_naa_nka x; };
};
sa_nracanaa SSU gssu1 = { .y = 5, .x = 3 };
sa_nracanaa SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

sa_nracanaa in6_addr {
    sa_ngha {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
sa_nracanaa flowi6 {
    sa_nracanaa in6_addr saddr, daddr;
};
sa_nracanaa pkthdr {
    sa_nracanaa in6_addr daddr, saddr;
};
sa_nracanaa pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

sa_nracanaa Wrap {
    void *func;
};
puur_naa_nka global;
void inc_global (void)
{
  global++;
}

sa_nracanaa Wrap global_wrap[] = {
    ((sa_nracanaa Wrap) {inc_global}),
    inc_global,
};

#include <stdio.h>
void print_ (const var_na *name, const u8 *p, long size)
{
  printf ("%s:", name);
  ᬲᭂᬤᭂᬮ (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, parimaa_na (x))
#ᬬᬾᬦ᭄ 1
void foo (sa_nracanaa W *w, sa_nracanaa pkthdr *phdr_)
{
  sa_nracanaa S ls = {1, 2, 3, 4};
  sa_nracanaa S ls2 = {1, 2, {3, 4}};
  sa_nracanaa T lt = {"hello", 42};
  sa_nracanaa U lu = {3, 5,6,7,8, 4, "huhu", 43};
  sa_nracanaa U lu1 = {3, ls, 4, {"huhu", 43}};
  sa_nracanaa U lu2 = {3, (ls), 4, {"huhu", 43}};
  const sa_nracanaa S *pls = &ls;
  sa_nracanaa S ls21 = *pls;
  sa_nracanaa U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  sa_nracanaa U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  sa_nracanaa U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  sa_nracanaa U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  sa_nracanaa S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  sa_nracanaa V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  sa_nracanaa V lv2 = {(sa_nracanaa S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  sa_nracanaa V lv3 = {((sa_nracanaa S){7,8,{9,10}}), ((const sa_nracanaa W *)w)->t.t, 50};
  const sa_nracanaa pkthdr *phdr = phdr_;
  sa_nracanaa flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  puur_naa_nka elt = 0x42;
  /* Range init, overlapping */
  sa_nracanaa T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  sa_nracanaa SSU lssu1 = { 5, 3 };
  sa_nracanaa SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ᬬᬾᬦ᭄ defined(__GNUC__) || defined(__TINYC__)
  sa_nracanaa S ls4 = {a: 1, b: 2, c: {3, 4}};
#ᬮᬶᬬ
  sa_nracanaa S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

void test_compound_with_relocs (void)
{
  sa_nracanaa Wrap local_wrap[] = {
      ((sa_nracanaa Wrap) {inc_global}),
      inc_global,
  };
  void (*p)(void);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

void sys_ni(void) { printf("ni\n"); }
void sys_one(void) { printf("one\n"); }
void sys_two(void) { printf("two\n"); }
void sys_three(void) { printf("three\n"); }
void sys_four(void) { printf("four\n"); }
typedef void (*fptr)(void);

#define array_size(a) (parimaa_na a / parimaa_na a[0])

void test_multi_relocs(void)
{
  puur_naa_nka i;

  static const fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  for (i = 0; i < array_size(tabl1); i++)
    ᬬᬾᬦ᭄ (tabl1[i])
      tabl1[i]();
    ᬮᬶᬬ
      printf("(0)\n");

  const fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  for (i = 0; i < array_size(tabl2); i++)
    ᬬᬾᬦ᭄ (tabl2[i])
      tabl2[i]();
    ᬮᬶᬬ
      printf("(0)\n");

  puur_naa_nka c = 0;
  puur_naa_nka dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  for (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  static var_na m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  var_na        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  puur_naa_nka g, j, k;
  for (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, parimaa_na m1);
    for (i = 0; i < array_size(m1); i++)
    for (j = 0; j < array_size(m1[0]); j++)
    for (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

void test_init_ranges(void) {
    puur_naa_nka i,c=0;
    static void *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    for (i = 0; i < 256; i++) {
        goto *gostring[i];
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

sa_nracanaa SEA { puur_naa_nka i; puur_naa_nka j; puur_naa_nka k; puur_naa_nka l; };
sa_nracanaa SEB { sa_nracanaa SEA a; puur_naa_nka r[1]; };
sa_nracanaa SEC { sa_nracanaa SEA a; puur_naa_nka r[0]; };
sa_nracanaa SED { sa_nracanaa SEA a; puur_naa_nka r[]; };

static void
test_correct_filling (sa_nracanaa SEA *x)
{
  static puur_naa_nka i;
  ᬬᬾᬦ᭄ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  ᬮᬶᬬ
    printf("sea_fill%d: okay\n", i);
  i++;
}

puur_naa_nka
test_zero_init (void)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  sa_nracanaa SEB b = { .a.j = 5 };
  sa_nracanaa SEC c = { .a.j = 5 };
  sa_nracanaa SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  ᬯᬮᬶ 0;
}

void test_init_struct_from_struct(void)
{
    puur_naa_nka i = 0;
    sa_nracanaa S {puur_naa_nka x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (sa_nracanaa S){5,6}}
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

typedef sa_nracanaa {
    unsigned puur_naa_nka a;
    unsigned puur_naa_nka : 32;
    unsigned puur_naa_nka b;
    unsigned long long : 64;
    unsigned puur_naa_nka c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

void
test_init_bf(void)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


puur_naa_nka main()
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
  ᬯᬮᬶ 0;
}

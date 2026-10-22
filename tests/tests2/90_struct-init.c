પ્રકારવ્યાખ્યા unsigned અક્ષર u8;
પ્રકારવ્યાખ્યા સંરચના {} empty_s;
સંરચના contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
સંરચના contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
સંરચના SS {u8 a[3], b; };
સંરચના SS sinit16[] = { { 1 }, 2 };
સંરચના S
{
  u8 a,b;
  u8 c[2];
};

સંરચના T
{
  u8 s[16];
  u8 a;
};

સંરચના U
{
  u8 a;
  સંરચના S s;
  u8 b;
  સંરચના T t;
};

સંરચના V
{
  સંરચના S s;
  સંરચના T t;
  u8 a;
};

સંરચના W
{
  સંરચના V t;
  સંરચના S s[];
};

સંરચના S gs = ((સંરચના S){1, 2, 3, 4});
સંરચના S gs2 = {1, 2, {3, 4}};
સંરચના T gt = {"hello", 42};
સંરચના U gu = {3, 5,6,7,8, 4, "huhu", 43};
સંરચના U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
સંરચના U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
સંરચના U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
સંરચના S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
સંરચના V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
સંરચના V gv2 = {(સંરચના S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
સંરચના V gv3 = {((સંરચના S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
સંરચના W gw = {{1,2,3,4}, {1,2,3,4,5}};

સંઘ UU {
    u8 a;
    u8 b;
};
સંરચના SU {
    સંઘ UU u;
    u8 c;
};
સંરચના SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
સંઘ UV {
    સંરચના {u8 a,b;};
    સંરચના S s;
};
સંઘ UV guv = {{6,5}};
સંઘ UV guv2 = {{.b = 7, .a = 8}};
સંઘ UV guv3 = {.b = 8, .a = 7};

સંરચના SSU {
    પૂર્ણાંક y;
    સંરચના { પૂર્ણાંક x; };
};
સંરચના SSU gssu1 = { .y = 5, .x = 3 };
સંરચના SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

સંરચના in6_addr {
    સંઘ {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
સંરચના flowi6 {
    સંરચના in6_addr saddr, daddr;
};
સંરચના pkthdr {
    સંરચના in6_addr daddr, saddr;
};
સંરચના pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

સંરચના Wrap {
    શૂન્ય *func;
};
પૂર્ણાંક global;
શૂન્ય inc_global (શૂન્ય)
{
  global++;
}

સંરચના Wrap global_wrap[] = {
    ((સંરચના Wrap) {inc_global}),
    inc_global,
};

#અન્તર્ભાવ <stdio.h>
શૂન્ય print_ (અચલ અક્ષર *name, અચલ u8 *p, long size)
{
  printf ("%s:", name);
  જ્યારે (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, કદ (x))
#જો 1
શૂન્ય foo (સંરચના W *w, સંરચના pkthdr *phdr_)
{
  સંરચના S ls = {1, 2, 3, 4};
  સંરચના S ls2 = {1, 2, {3, 4}};
  સંરચના T lt = {"hello", 42};
  સંરચના U lu = {3, 5,6,7,8, 4, "huhu", 43};
  સંરચના U lu1 = {3, ls, 4, {"huhu", 43}};
  સંરચના U lu2 = {3, (ls), 4, {"huhu", 43}};
  અચલ સંરચના S *pls = &ls;
  સંરચના S ls21 = *pls;
  સંરચના U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  સંરચના U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  સંરચના U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  સંરચના U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  સંરચના S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  સંરચના V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  સંરચના V lv2 = {(સંરચના S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  સંરચના V lv3 = {((સંરચના S){7,8,{9,10}}), ((અચલ સંરચના W *)w)->t.t, 50};
  અચલ સંરચના pkthdr *phdr = phdr_;
  સંરચના flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  પૂર્ણાંક elt = 0x42;
  /* Range init, overlapping */
  સંરચના T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  સંરચના SSU lssu1 = { 5, 3 };
  સંરચના SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#જો defined(__GNUC__) || defined(__TINYC__)
  સંરચના S ls4 = {a: 1, b: 2, c: {3, 4}};
#નહીંતર
  સંરચના S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

શૂન્ય test_compound_with_relocs (શૂન્ય)
{
  સંરચના Wrap local_wrap[] = {
      ((સંરચના Wrap) {inc_global}),
      inc_global,
  };
  શૂન્ય (*p)(શૂન્ય);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

શૂન્ય sys_ni(શૂન્ય) { printf("ni\n"); }
શૂન્ય sys_one(શૂન્ય) { printf("one\n"); }
શૂન્ય sys_two(શૂન્ય) { printf("two\n"); }
શૂન્ય sys_three(શૂન્ય) { printf("three\n"); }
શૂન્ય sys_four(શૂન્ય) { printf("four\n"); }
પ્રકારવ્યાખ્યા શૂન્ય (*fptr)(શૂન્ય);

#define array_size(a) (કદ a / કદ a[0])

શૂન્ય test_multi_relocs(શૂન્ય)
{
  પૂર્ણાંક i;

  સ્થિર અચલ fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  માટે (i = 0; i < array_size(tabl1); i++)
    જો (tabl1[i])
      tabl1[i]();
    નહીંતર
      printf("(0)\n");

  અચલ fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  માટે (i = 0; i < array_size(tabl2); i++)
    જો (tabl2[i])
      tabl2[i]();
    નહીંતર
      printf("(0)\n");

  પૂર્ણાંક c = 0;
  પૂર્ણાંક dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  માટે (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  સ્થિર અક્ષર m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  અક્ષર        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  પૂર્ણાંક g, j, k;
  માટે (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, કદ m1);
    માટે (i = 0; i < array_size(m1); i++)
    માટે (j = 0; j < array_size(m1[0]); j++)
    માટે (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

શૂન્ય test_init_ranges(શૂન્ય) {
    પૂર્ણાંક i,c=0;
    સ્થિર શૂન્ય *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    માટે (i = 0; i < 256; i++) {
        જાઓ *gostring[i];
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

સંરચના SEA { પૂર્ણાંક i; પૂર્ણાંક j; પૂર્ણાંક k; પૂર્ણાંક l; };
સંરચના SEB { સંરચના SEA a; પૂર્ણાંક r[1]; };
સંરચના SEC { સંરચના SEA a; પૂર્ણાંક r[0]; };
સંરચના SED { સંરચના SEA a; પૂર્ણાંક r[]; };

સ્થિર શૂન્ય
test_correct_filling (સંરચના SEA *x)
{
  સ્થિર પૂર્ણાંક i;
  જો (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  નહીંતર
    printf("sea_fill%d: okay\n", i);
  i++;
}

પૂર્ણાંક
test_zero_init (શૂન્ય)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  સંરચના SEB b = { .a.j = 5 };
  સંરચના SEC c = { .a.j = 5 };
  સંરચના SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  પાછા 0;
}

શૂન્ય test_init_struct_from_struct(શૂન્ય)
{
    પૂર્ણાંક i = 0;
    સંરચના S {પૂર્ણાંક x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (સંરચના S){5,6}}
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

પ્રકારવ્યાખ્યા સંરચના {
    unsigned પૂર્ણાંક a;
    unsigned પૂર્ણાંક : 32;
    unsigned પૂર્ણાંક b;
    unsigned long long : 64;
    unsigned પૂર્ણાંક c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

શૂન્ય
test_init_bf(શૂન્ય)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


પૂર્ણાંક મુખ્ય()
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
  પાછા 0;
}

வகைவரை unsigned எழுத்து u8;
வகைவரை கட்டமைப்பு {} empty_s;
கட்டமைப்பு contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
கட்டமைப்பு contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
கட்டமைப்பு SS {u8 a[3], b; };
கட்டமைப்பு SS sinit16[] = { { 1 }, 2 };
கட்டமைப்பு S
{
  u8 a,b;
  u8 c[2];
};

கட்டமைப்பு T
{
  u8 s[16];
  u8 a;
};

கட்டமைப்பு U
{
  u8 a;
  கட்டமைப்பு S s;
  u8 b;
  கட்டமைப்பு T t;
};

கட்டமைப்பு V
{
  கட்டமைப்பு S s;
  கட்டமைப்பு T t;
  u8 a;
};

கட்டமைப்பு W
{
  கட்டமைப்பு V t;
  கட்டமைப்பு S s[];
};

கட்டமைப்பு S gs = ((கட்டமைப்பு S){1, 2, 3, 4});
கட்டமைப்பு S gs2 = {1, 2, {3, 4}};
கட்டமைப்பு T gt = {"hello", 42};
கட்டமைப்பு U gu = {3, 5,6,7,8, 4, "huhu", 43};
கட்டமைப்பு U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
கட்டமைப்பு U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
கட்டமைப்பு U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
கட்டமைப்பு S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
கட்டமைப்பு V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
கட்டமைப்பு V gv2 = {(கட்டமைப்பு S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
கட்டமைப்பு V gv3 = {((கட்டமைப்பு S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
கட்டமைப்பு W gw = {{1,2,3,4}, {1,2,3,4,5}};

ஒன்றிப்பு UU {
    u8 a;
    u8 b;
};
கட்டமைப்பு SU {
    ஒன்றிப்பு UU u;
    u8 c;
};
கட்டமைப்பு SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
ஒன்றிப்பு UV {
    கட்டமைப்பு {u8 a,b;};
    கட்டமைப்பு S s;
};
ஒன்றிப்பு UV guv = {{6,5}};
ஒன்றிப்பு UV guv2 = {{.b = 7, .a = 8}};
ஒன்றிப்பு UV guv3 = {.b = 8, .a = 7};

கட்டமைப்பு SSU {
    முழு y;
    கட்டமைப்பு { முழு x; };
};
கட்டமைப்பு SSU gssu1 = { .y = 5, .x = 3 };
கட்டமைப்பு SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

கட்டமைப்பு in6_addr {
    ஒன்றிப்பு {
	u8 u6_addr8[16];
	unsigned short u6_addr16[8];
    } u;
};
கட்டமைப்பு flowi6 {
    கட்டமைப்பு in6_addr saddr, daddr;
};
கட்டமைப்பு pkthdr {
    கட்டமைப்பு in6_addr daddr, saddr;
};
கட்டமைப்பு pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

கட்டமைப்பு Wrap {
    வெறுமை *func;
};
முழு global;
வெறுமை inc_global (வெறுமை)
{
  global++;
}

கட்டமைப்பு Wrap global_wrap[] = {
    ((கட்டமைப்பு Wrap) {inc_global}),
    inc_global,
};

#அந்தர்பாவ <stdio.h>
வெறுமை print_ (மாறிலி எழுத்து *name, மாறிலி u8 *p, long size)
{
  printf ("%s:", name);
  போது (size--) {
      printf (" %x", *p++);
  }
  printf ("\n");
}
#define print(x) print_(#x, (u8*)&x, அளவு (x))
#எனில் 1
வெறுமை foo (கட்டமைப்பு W *w, கட்டமைப்பு pkthdr *phdr_)
{
  கட்டமைப்பு S ls = {1, 2, 3, 4};
  கட்டமைப்பு S ls2 = {1, 2, {3, 4}};
  கட்டமைப்பு T lt = {"hello", 42};
  கட்டமைப்பு U lu = {3, 5,6,7,8, 4, "huhu", 43};
  கட்டமைப்பு U lu1 = {3, ls, 4, {"huhu", 43}};
  கட்டமைப்பு U lu2 = {3, (ls), 4, {"huhu", 43}};
  மாறிலி கட்டமைப்பு S *pls = &ls;
  கட்டமைப்பு S ls21 = *pls;
  கட்டமைப்பு U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  கட்டமைப்பு U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  கட்டமைப்பு U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  கட்டமைப்பு U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  கட்டமைப்பு S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  கட்டமைப்பு V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  கட்டமைப்பு V lv2 = {(கட்டமைப்பு S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  கட்டமைப்பு V lv3 = {((கட்டமைப்பு S){7,8,{9,10}}), ((மாறிலி கட்டமைப்பு W *)w)->t.t, 50};
  மாறிலி கட்டமைப்பு pkthdr *phdr = phdr_;
  கட்டமைப்பு flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  முழு elt = 0x42;
  /* Range init, overlapping */
  கட்டமைப்பு T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  கட்டமைப்பு SSU lssu1 = { 5, 3 };
  கட்டமைப்பு SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#எனில் defined(__GNUC__) || defined(__TINYC__)
  கட்டமைப்பு S ls4 = {a: 1, b: 2, c: {3, 4}};
#இல்லையெனில்
  கட்டமைப்பு S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

வெறுமை test_compound_with_relocs (வெறுமை)
{
  கட்டமைப்பு Wrap local_wrap[] = {
      ((கட்டமைப்பு Wrap) {inc_global}),
      inc_global,
  };
  வெறுமை (*p)(வெறுமை);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

வெறுமை sys_ni(வெறுமை) { printf("ni\n"); }
வெறுமை sys_one(வெறுமை) { printf("one\n"); }
வெறுமை sys_two(வெறுமை) { printf("two\n"); }
வெறுமை sys_three(வெறுமை) { printf("three\n"); }
வெறுமை sys_four(வெறுமை) { printf("four\n"); }
வகைவரை வெறுமை (*fptr)(வெறுமை);

#define array_size(a) (அளவு a / அளவு a[0])

வெறுமை test_multi_relocs(வெறுமை)
{
  முழு i;

  நிலையான மாறிலி fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  க்கு (i = 0; i < array_size(tabl1); i++)
    எனில் (tabl1[i])
      tabl1[i]();
    இல்லையெனில்
      printf("(0)\n");

  மாறிலி fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  க்கு (i = 0; i < array_size(tabl2); i++)
    எனில் (tabl2[i])
      tabl2[i]();
    இல்லையெனில்
      printf("(0)\n");

  முழு c = 0;
  முழு dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  க்கு (i = 0; i < array_size(dd); i++)
    printf(" %d", dd[i]);
  printf("\n");

  /* multi-dimensional flex array with range initializers */
  நிலையான எழுத்து m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  எழுத்து        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  முழு g, j, k;
  க்கு (g = 2; g-- > 0;) {
    printf("mdfa %s: %d -", "locl\0glob" + g * 5, அளவு m1);
    க்கு (i = 0; i < array_size(m1); i++)
    க்கு (j = 0; j < array_size(m1[0]); j++)
    க்கு (k = 0; k < array_size(m1[0][0]); k++)
      printf(" %d", (g ? m1:m2)[i][j][k]);
    printf("\n");
  }
}

வெறுமை test_init_ranges(வெறுமை) {
    முழு i,c=0;
    நிலையான வெறுமை *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    க்கு (i = 0; i < 256; i++) {
        செல் *gostring[i];
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

கட்டமைப்பு SEA { முழு i; முழு j; முழு k; முழு l; };
கட்டமைப்பு SEB { கட்டமைப்பு SEA a; முழு r[1]; };
கட்டமைப்பு SEC { கட்டமைப்பு SEA a; முழு r[0]; };
கட்டமைப்பு SED { கட்டமைப்பு SEA a; முழு r[]; };

நிலையான வெறுமை
test_correct_filling (கட்டமைப்பு SEA *x)
{
  நிலையான முழு i;
  எனில் (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    printf("sea_fill%d: wrong\n", i);
  இல்லையெனில்
    printf("sea_fill%d: okay\n", i);
  i++;
}

முழு
test_zero_init (வெறுமை)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  கட்டமைப்பு SEB b = { .a.j = 5 };
  கட்டமைப்பு SEC c = { .a.j = 5 };
  கட்டமைப்பு SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  திரும்பு 0;
}

வெறுமை test_init_struct_from_struct(வெறுமை)
{
    முழு i = 0;
    கட்டமைப்பு S {முழு x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (கட்டமைப்பு S){5,6}}
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

வகைவரை கட்டமைப்பு {
    unsigned முழு a;
    unsigned முழு : 32;
    unsigned முழு b;
    unsigned long long : 64;
    unsigned முழு c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

வெறுமை
test_init_bf(வெறுமை)
{
    printf ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


முழு முதன்மை()
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
  திரும்பு 0;
}

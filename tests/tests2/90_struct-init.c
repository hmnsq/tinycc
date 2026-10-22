రకనిర్వచనం గుర్తులేని అక్షరం u8;
రకనిర్వచనం నిర్మాణం {} ఖాళీలు_s;
నిర్మాణం కలిగియుంది_ఖాళీలు {
    u8 a;
    ఖాళీలు_s ఖాళీలు;
    u8 b;
};
నిర్మాణం కలిగియుంది_ఖాళీలు ce = { { (1) }, (ఖాళీలు_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
నిర్మాణం SS {u8 a[3], b; };
నిర్మాణం SS sinit16[] = { { 1 }, 2 };
నిర్మాణం S
{
  u8 a,b;
  u8 c[2];
};

నిర్మాణం T
{
  u8 s[16];
  u8 a;
};

నిర్మాణం U
{
  u8 a;
  నిర్మాణం S s;
  u8 b;
  నిర్మాణం T t;
};

నిర్మాణం V
{
  నిర్మాణం S s;
  నిర్మాణం T t;
  u8 a;
};

నిర్మాణం W
{
  నిర్మాణం V t;
  నిర్మాణం S s[];
};

నిర్మాణం S gs = ((నిర్మాణం S){1, 2, 3, 4});
నిర్మాణం S gs2 = {1, 2, {3, 4}};
నిర్మాణం T gt = {"hello", 42};
నిర్మాణం U gu = {3, 5,6,7,8, 4, "huhu", 43};
నిర్మాణం U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
నిర్మాణం U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
నిర్మాణం U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
నిర్మాణం S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
నిర్మాణం V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
నిర్మాణం V gv2 = {(నిర్మాణం S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
నిర్మాణం V gv3 = {((నిర్మాణం S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
నిర్మాణం W gw = {{1,2,3,4}, {1,2,3,4,5}};

సంఘం UU {
    u8 a;
    u8 b;
};
నిర్మాణం SU {
    సంఘం UU u;
    u8 c;
};
నిర్మాణం SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
సంఘం UV {
    నిర్మాణం {u8 a,b;};
    నిర్మాణం S s;
};
సంఘం UV guv = {{6,5}};
సంఘం UV guv2 = {{.b = 7, .a = 8}};
సంఘం UV guv3 = {.b = 8, .a = 7};

నిర్మాణం SSU {
    పూర్ణాంకం y;
    నిర్మాణం { పూర్ణాంకం x; };
};
నిర్మాణం SSU gssu1 = { .y = 5, .x = 3 };
నిర్మాణం SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

నిర్మాణం in6_addr {
    సంఘం {
	u8 u6_addr8[16];
	గుర్తులేని పొట్టి u6_addr16[8];
    } u;
};
నిర్మాణం flowi6 {
    నిర్మాణం in6_addr saddr, daddr;
};
నిర్మాణం pkthdr {
    నిర్మాణం in6_addr daddr, saddr;
};
నిర్మాణం pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

నిర్మాణం Wrap {
    శూన్య *func;
};
పూర్ణాంకం global;
శూన్య inc_global (శూన్య)
{
  global++;
}

నిర్మాణం Wrap global_wrap[] = {
    ((నిర్మాణం Wrap) {inc_global}),
    inc_global,
};

#అన్తర్భావ <stdio.h>
శూన్య print_ (స్థిరరాశి అక్షరం *name, స్థిరరాశి u8 *p, దీర్ఘ కొలత)
{
  రాయి ("%s:", name);
  అయితే (కొలత--) {
      రాయి (" %x", *p++);
  }
  రాయి ("\n");
}
#నిర్వచించు print(x) print_(#x, (u8*)&x, పరిమాణం (x))
#ఒకవేళ 1
శూన్య foo (నిర్మాణం W *w, నిర్మాణం pkthdr *phdr_)
{
  నిర్మాణం S ls = {1, 2, 3, 4};
  నిర్మాణం S ls2 = {1, 2, {3, 4}};
  నిర్మాణం T lt = {"hello", 42};
  నిర్మాణం U lu = {3, 5,6,7,8, 4, "huhu", 43};
  నిర్మాణం U lu1 = {3, ls, 4, {"huhu", 43}};
  నిర్మాణం U lu2 = {3, (ls), 4, {"huhu", 43}};
  స్థిరరాశి నిర్మాణం S *pls = &ls;
  నిర్మాణం S ls21 = *pls;
  నిర్మాణం U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  నిర్మాణం U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  నిర్మాణం U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  నిర్మాణం U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  నిర్మాణం S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  నిర్మాణం V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  నిర్మాణం V lv2 = {(నిర్మాణం S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  నిర్మాణం V lv3 = {((నిర్మాణం S){7,8,{9,10}}), ((స్థిరరాశి నిర్మాణం W *)w)->t.t, 50};
  స్థిరరాశి నిర్మాణం pkthdr *phdr = phdr_;
  నిర్మాణం flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  పూర్ణాంకం elt = 0x42;
  /* Range init, overlapping */
  నిర్మాణం T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  నిర్మాణం SSU lssu1 = { 5, 3 };
  నిర్మాణం SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#ఒకవేళ defined(__GNUC__) || defined(__TINYC__)
  నిర్మాణం S ls4 = {a: 1, b: 2, c: {3, 4}};
#లేకపోతే
  నిర్మాణం S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
#అయితే_ముగింపు
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
#అయితే_ముగింపు

శూన్య test_compound_with_relocs (శూన్య)
{
  నిర్మాణం Wrap local_wrap[] = {
      ((నిర్మాణం Wrap) {inc_global}),
      inc_global,
  };
  శూన్య (*p)(శూన్య);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

శూన్య sys_ni(శూన్య) { రాయి("ni\n"); }
శూన్య sys_one(శూన్య) { రాయి("one\n"); }
శూన్య sys_two(శూన్య) { రాయి("two\n"); }
శూన్య sys_three(శూన్య) { రాయి("three\n"); }
శూన్య sys_four(శూన్య) { రాయి("four\n"); }
రకనిర్వచనం శూన్య (*fptr)(శూన్య);

#నిర్వచించు array_కొలత(a) (పరిమాణం a / పరిమాణం a[0])

శూన్య test_multi_relocs(శూన్య)
{
  పూర్ణాంకం i;

  స్థిర స్థిరరాశి fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  కొరకు (i = 0; i < array_కొలత(tabl1); i++)
    ఒకవేళ (tabl1[i])
      tabl1[i]();
    లేకపోతే
      రాయి("(0)\n");

  స్థిరరాశి fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  కొరకు (i = 0; i < array_కొలత(tabl2); i++)
    ఒకవేళ (tabl2[i])
      tabl2[i]();
    లేకపోతే
      రాయి("(0)\n");

  పూర్ణాంకం c = 0;
  పూర్ణాంకం dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  కొరకు (i = 0; i < array_కొలత(dd); i++)
    రాయి(" %d", dd[i]);
  రాయి("\n");

  /* multi-dimensional flex array with range initializers */
  స్థిర అక్షరం m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  అక్షరం        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  పూర్ణాంకం g, j, k;
  కొరకు (g = 2; g-- > 0;) {
    రాయి("mdfa %s: %d -", "locl\0glob" + g * 5, పరిమాణం m1);
    కొరకు (i = 0; i < array_కొలత(m1); i++)
    కొరకు (j = 0; j < array_కొలత(m1[0]); j++)
    కొరకు (k = 0; k < array_కొలత(m1[0][0]); k++)
      రాయి(" %d", (g ? m1:m2)[i][j][k]);
    రాయి("\n");
  }
}

శూన్య test_init_ranges(శూన్య) {
    పూర్ణాంకం i,c=0;
    స్థిర శూన్య *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    కొరకు (i = 0; i < 256; i++) {
        వెళ్ళు *gostring[i];
        l_bad: c++;
        l_loop: c++;
        l_esc: c++;
        l_qdown: c++;
        l_utf8_2: c++;
        l_utf8_3: c++;
        l_utf8_4: c++;
    }
    రాయి ("%d\n", c);
}


/* Following is from GCC gcc.c-torture/execute/20050613-1.c.  */

నిర్మాణం SEA { పూర్ణాంకం i; పూర్ణాంకం j; పూర్ణాంకం k; పూర్ణాంకం l; };
నిర్మాణం SEB { నిర్మాణం SEA a; పూర్ణాంకం r[1]; };
నిర్మాణం SEC { నిర్మాణం SEA a; పూర్ణాంకం r[0]; };
నిర్మాణం SED { నిర్మాణం SEA a; పూర్ణాంకం r[]; };

స్థిర శూన్య
test_correct_filling (నిర్మాణం SEA *x)
{
  స్థిర పూర్ణాంకం i;
  ఒకవేళ (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    రాయి("sea_fill%d: wrong\n", i);
  లేకపోతే
    రాయి("sea_fill%d: okay\n", i);
  i++;
}

పూర్ణాంకం
test_zero_init (శూన్య)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  నిర్మాణం SEB b = { .a.j = 5 };
  నిర్మాణం SEC c = { .a.j = 5 };
  నిర్మాణం SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  తిరిగి 0;
}

శూన్య test_init_struct_from_struct(శూన్య)
{
    పూర్ణాంకం i = 0;
    నిర్మాణం S {పూర్ణాంకం x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (నిర్మాణం S){5,6}}
        ;

    రాయి("%s: %d %d %d %d - %d %d %d %d - %d %d %d %d\n",
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

రకనిర్వచనం నిర్మాణం {
    గుర్తులేని పూర్ణాంకం a;
    గుర్తులేని పూర్ణాంకం : 32;
    గుర్తులేని పూర్ణాంకం b;
    గుర్తులేని దీర్ఘ దీర్ఘ : 64;
    గుర్తులేని పూర్ణాంకం c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

శూన్య
test_init_bf(శూన్య)
{
    రాయి ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


పూర్ణాంకం ప్రధాన()
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
  తిరిగి 0;
}

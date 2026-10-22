प्रकारव्याख्या अचिन्हित अक्षर u8;
प्रकारव्याख्या संरचना {} empty_s;
संरचना contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
संरचना contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
संरचना SS {u8 a[3], b; };
संरचना SS sinit16[] = { { 1 }, 2 };
संरचना S
{
  u8 a,b;
  u8 c[2];
};

संरचना T
{
  u8 s[16];
  u8 a;
};

संरचना U
{
  u8 a;
  संरचना S s;
  u8 b;
  संरचना T t;
};

संरचना V
{
  संरचना S s;
  संरचना T t;
  u8 a;
};

संरचना W
{
  संरचना V t;
  संरचना S s[];
};

संरचना S gs = ((संरचना S){1, 2, 3, 4});
संरचना S gs2 = {1, 2, {3, 4}};
संरचना T gt = {"hello", 42};
संरचना U gu = {3, 5,6,7,8, 4, "huhu", 43};
संरचना U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
संरचना U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
संरचना U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
संरचना S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
संरचना V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
संरचना V gv2 = {(संरचना S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
संरचना V gv3 = {((संरचना S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
संरचना W gw = {{1,2,3,4}, {1,2,3,4,5}};

संघ UU {
    u8 a;
    u8 b;
};
संरचना SU {
    संघ UU u;
    u8 c;
};
संरचना SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
संघ UV {
    संरचना {u8 a,b;};
    संरचना S s;
};
संघ UV guv = {{6,5}};
संघ UV guv2 = {{.b = 7, .a = 8}};
संघ UV guv3 = {.b = 8, .a = 7};

संरचना SSU {
    पूर्णांक y;
    संरचना { पूर्णांक x; };
};
संरचना SSU gssu1 = { .y = 5, .x = 3 };
संरचना SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

संरचना in6_addr {
    संघ {
	u8 u6_addr8[16];
	अचिन्हित लघु u6_addr16[8];
    } u;
};
संरचना flowi6 {
    संरचना in6_addr saddr, daddr;
};
संरचना pkthdr {
    संरचना in6_addr daddr, saddr;
};
संरचना pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

संरचना Wrap {
    शून्य *func;
};
पूर्णांक global;
शून्य inc_global (शून्य)
{
  global++;
}

संरचना Wrap global_wrap[] = {
    ((संरचना Wrap) {inc_global}),
    inc_global,
};

#अन्तर्भाव <stdio.h>
शून्य print_ (स्थिरांक अक्षर *name, स्थिरांक u8 *p, दीर्घ size)
{
  म_लिखो ("%s:", name);
  पर्यंत (size--) {
      म_लिखो (" %x", *p++);
  }
  म_लिखो ("\n");
}
#define print(x) print_(#x, (u8*)&x, आकार (x))
#जर 1
शून्य foo (संरचना W *w, संरचना pkthdr *phdr_)
{
  संरचना S ls = {1, 2, 3, 4};
  संरचना S ls2 = {1, 2, {3, 4}};
  संरचना T lt = {"hello", 42};
  संरचना U lu = {3, 5,6,7,8, 4, "huhu", 43};
  संरचना U lu1 = {3, ls, 4, {"huhu", 43}};
  संरचना U lu2 = {3, (ls), 4, {"huhu", 43}};
  स्थिरांक संरचना S *pls = &ls;
  संरचना S ls21 = *pls;
  संरचना U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  संरचना U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  संरचना U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  संरचना U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  संरचना S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  संरचना V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  संरचना V lv2 = {(संरचना S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  संरचना V lv3 = {((संरचना S){7,8,{9,10}}), ((स्थिरांक संरचना W *)w)->t.t, 50};
  स्थिरांक संरचना pkthdr *phdr = phdr_;
  संरचना flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  पूर्णांक elt = 0x42;
  /* Range init, overlapping */
  संरचना T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  संरचना SSU lssu1 = { 5, 3 };
  संरचना SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#जर defined(__GNUC__) || defined(__TINYC__)
  संरचना S ls4 = {a: 1, b: 2, c: {3, 4}};
#अन्यथा
  संरचना S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
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

शून्य test_compound_with_relocs (शून्य)
{
  संरचना Wrap local_wrap[] = {
      ((संरचना Wrap) {inc_global}),
      inc_global,
  };
  शून्य (*p)(शून्य);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

शून्य sys_ni(शून्य) { म_लिखो("ni\n"); }
शून्य sys_one(शून्य) { म_लिखो("one\n"); }
शून्य sys_two(शून्य) { म_लिखो("two\n"); }
शून्य sys_three(शून्य) { म_लिखो("three\n"); }
शून्य sys_four(शून्य) { म_लिखो("four\n"); }
प्रकारव्याख्या शून्य (*fptr)(शून्य);

#define array_size(a) (आकार a / आकार a[0])

शून्य test_multi_relocs(शून्य)
{
  पूर्णांक i;

  स्थिर स्थिरांक fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  साठी (i = 0; i < array_size(tabl1); i++)
    जर (tabl1[i])
      tabl1[i]();
    अन्यथा
      म_लिखो("(0)\n");

  स्थिरांक fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  साठी (i = 0; i < array_size(tabl2); i++)
    जर (tabl2[i])
      tabl2[i]();
    अन्यथा
      म_लिखो("(0)\n");

  पूर्णांक c = 0;
  पूर्णांक dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  साठी (i = 0; i < array_size(dd); i++)
    म_लिखो(" %d", dd[i]);
  म_लिखो("\n");

  /* multi-dimensional flex array with range initializers */
  स्थिर अक्षर m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  अक्षर        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  पूर्णांक g, j, k;
  साठी (g = 2; g-- > 0;) {
    म_लिखो("mdfa %s: %d -", "locl\0glob" + g * 5, आकार m1);
    साठी (i = 0; i < array_size(m1); i++)
    साठी (j = 0; j < array_size(m1[0]); j++)
    साठी (k = 0; k < array_size(m1[0][0]); k++)
      म_लिखो(" %d", (g ? m1:m2)[i][j][k]);
    म_लिखो("\n");
  }
}

शून्य test_init_ranges(शून्य) {
    पूर्णांक i,c=0;
    स्थिर शून्य *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    साठी (i = 0; i < 256; i++) {
        जा *gostring[i];
        l_bad: c++;
        l_loop: c++;
        l_esc: c++;
        l_qdown: c++;
        l_utf8_2: c++;
        l_utf8_3: c++;
        l_utf8_4: c++;
    }
    म_लिखो ("%d\n", c);
}


/* Following is from GCC gcc.c-torture/execute/20050613-1.c.  */

संरचना SEA { पूर्णांक i; पूर्णांक j; पूर्णांक k; पूर्णांक l; };
संरचना SEB { संरचना SEA a; पूर्णांक r[1]; };
संरचना SEC { संरचना SEA a; पूर्णांक r[0]; };
संरचना SED { संरचना SEA a; पूर्णांक r[]; };

स्थिर शून्य
test_correct_filling (संरचना SEA *x)
{
  स्थिर पूर्णांक i;
  जर (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    म_लिखो("sea_fill%d: wrong\n", i);
  अन्यथा
    म_लिखो("sea_fill%d: okay\n", i);
  i++;
}

पूर्णांक
test_zero_init (शून्य)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  संरचना SEB b = { .a.j = 5 };
  संरचना SEC c = { .a.j = 5 };
  संरचना SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  परत 0;
}

शून्य test_init_struct_from_struct(शून्य)
{
    पूर्णांक i = 0;
    संरचना S {पूर्णांक x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (संरचना S){5,6}}
        ;

    म_लिखो("%s: %d %d %d %d - %d %d %d %d - %d %d %d %d\n",
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

प्रकारव्याख्या संरचना {
    अचिन्हित पूर्णांक a;
    अचिन्हित पूर्णांक : 32;
    अचिन्हित पूर्णांक b;
    अचिन्हित दीर्घ दीर्घ : 64;
    अचिन्हित पूर्णांक c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

शून्य
test_init_bf(शून्य)
{
    म_लिखो ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


पूर्णांक main()
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
  परत 0;
}

प्रकार अचिन्हित अक्षर u8;
प्रकार काष्ठा {} empty_s;
काष्ठा contains_empty {
    u8 a;
    empty_s empty;
    u8 b;
};
काष्ठा contains_empty ce = { { (1) }, (empty_s){}, 022, };
/* The following decl of 'q' would demonstrate the TCC bug in init_putv when
   handling copying compound literals.  (Compound literals
   aren't acceptable constant initializers in isoc99, but
   we accept them like gcc, except for this case)
//char *q = (char *){ "trara" }; */
काष्ठा SS {u8 a[3], b; };
काष्ठा SS sinit16[] = { { 1 }, 2 };
काष्ठा S
{
  u8 a,b;
  u8 c[2];
};

काष्ठा T
{
  u8 s[16];
  u8 a;
};

काष्ठा U
{
  u8 a;
  काष्ठा S s;
  u8 b;
  काष्ठा T t;
};

काष्ठा V
{
  काष्ठा S s;
  काष्ठा T t;
  u8 a;
};

काष्ठा W
{
  काष्ठा V t;
  काष्ठा S s[];
};

काष्ठा S gs = ((काष्ठा S){1, 2, 3, 4});
काष्ठा S gs2 = {1, 2, {3, 4}};
काष्ठा T gt = {"hello", 42};
काष्ठा U gu = {3, 5,6,7,8, 4, "huhu", 43};
काष्ठा U gu2 = {3, {5,6,7,8}, 4, {"huhu", 43}};
/* Optional braces around scalar initializers.  Accepted, but with
   a warning.  */
काष्ठा U gu3 = { {3}, {5,6,7,8,}, 4, {"huhu", 43}};
/* Many superfluous braces and leaving out one initializer for U.s.c[1] */
काष्ठा U gu4 = { 3, {5,6,7,},  5, { "bla", {44}} };
/* Superfluous braces and useless parens around values */
काष्ठा S gs3 = { (1), {(2)}, {(((3))), {4}}};
/* Superfluous braces, and leaving out braces for V.t, plus cast */
काष्ठा V gv = {{{3},4,{5,6}}, "haha", (u8)45, 46};
/* Compound literal */
काष्ठा V gv2 = {(काष्ठा S){7,8,{9,10}}, {"hihi", 47}, 48};
/* Parens around compound literal */
काष्ठा V gv3 = {((काष्ठा S){7,8,{9,10}}), {"hoho", 49}, 50};
/* Initialization of a flex array member (warns in GCC) */
काष्ठा W gw = {{1,2,3,4}, {1,2,3,4,5}};

जोड़ UU {
    u8 a;
    u8 b;
};
काष्ठा SU {
    जोड़ UU u;
    u8 c;
};
काष्ठा SU gsu = {5,6};

/* Unnamed struct/union members aren't ISO C, but it's a widely accepted
   extension.  See below for further extensions to that under -fms-extension.*/
जोड़ UV {
    काष्ठा {u8 a,b;};
    काष्ठा S s;
};
जोड़ UV guv = {{6,5}};
जोड़ UV guv2 = {{.b = 7, .a = 8}};
जोड़ UV guv3 = {.b = 8, .a = 7};

काष्ठा SSU {
    पूर्णांक y;
    काष्ठा { पूर्णांक x; };
};
काष्ठा SSU gssu1 = { .y = 5, .x = 3 };
काष्ठा SSU gssu2 = { 5, 3 };

/* Under -fms-extensions also the following is valid:
union UV2 {
    struct Anon {u8 a,b;};    // unnamed member, but tagged struct, ...
    struct S s;
};
struct Anon gan = { 10, 11 }; // ... which makes it available here.
union UV2 guv4 = {{4,3}};     // and the other inits from above as well
*/

काष्ठा in6_addr {
    जोड़ {
	u8 u6_addr8[16];
	अचिन्हित लघु u6_addr16[8];
    } u;
};
काष्ठा flowi6 {
    काष्ठा in6_addr saddr, daddr;
};
काष्ठा pkthdr {
    काष्ठा in6_addr daddr, saddr;
};
काष्ठा pkthdr phdr = { { { 6,5,4,3 } }, { { 9,8,7,6 } } };

काष्ठा Wrap {
    व्योम *func;
};
पूर्णांक global;
व्योम inc_global (व्योम)
{
  global++;
}

काष्ठा Wrap global_wrap[] = {
    ((काष्ठा Wrap) {inc_global}),
    inc_global,
};

#समावेश <stdio.h>
व्योम print_ (स्थिर अक्षर *name, स्थिर u8 *p, दीर्घ आकार)
{
  म_लिखो ("%s:", name);
  जबतक (आकार--) {
      म_लिखो (" %x", *p++);
  }
  म_लिखो ("\n");
}
#घोषणा print(x) print_(#x, (u8*)&x, माप (x))
#अगर 1
व्योम foo (काष्ठा W *w, काष्ठा pkthdr *phdr_)
{
  काष्ठा S ls = {1, 2, 3, 4};
  काष्ठा S ls2 = {1, 2, {3, 4}};
  काष्ठा T lt = {"hello", 42};
  काष्ठा U lu = {3, 5,6,7,8, 4, "huhu", 43};
  काष्ठा U lu1 = {3, ls, 4, {"huhu", 43}};
  काष्ठा U lu2 = {3, (ls), 4, {"huhu", 43}};
  स्थिर काष्ठा S *pls = &ls;
  काष्ठा S ls21 = *pls;
  काष्ठा U lu22 = {3, *pls, 4, {"huhu", 43}};
  /* Incomplete bracing.  */
  काष्ठा U lu21 = {3, ls, 4, "huhu", 43};
  /* Optional braces around scalar initializers.  Accepted, but with
     a warning.  */
  काष्ठा U lu3 = { 3, {5,6,7,8,}, 4, {"huhu", 43}};
  /* Many superfluous braces and leaving out one initializer for U.s.c[1] */
  काष्ठा U lu4 = { 3, {5,6,7,},  5, { "bla", 44} };
  /* Superfluous braces and useless parens around values */
  काष्ठा S ls3 = { (1), (2), {(((3))), 4}};
  /* Superfluous braces, and leaving out braces for V.t, plus cast */
  काष्ठा V lv = {{3,4,{5,6}}, "haha", (u8)45, 46};
  /* Compound literal */
  काष्ठा V lv2 = {(काष्ठा S)w->t.s, {"hihi", 47}, 48};
  /* Parens around compound literal */
  काष्ठा V lv3 = {((काष्ठा S){7,8,{9,10}}), ((स्थिर काष्ठा W *)w)->t.t, 50};
  स्थिर काष्ठा pkthdr *phdr = phdr_;
  काष्ठा flowi6 flow = { .daddr = phdr->daddr, .saddr = phdr->saddr };
  पूर्णांक elt = 0x42;
  /* Range init, overlapping */
  काष्ठा T lt2 = { { [1 ... 5] = 9, [6 ... 10] = elt, [4 ... 7] = elt+1 }, 1 };
  काष्ठा SSU lssu1 = { 5, 3 };
  काष्ठा SSU lssu2 = { .y = 5, .x = 3 };
  /* designated initializers in GNU form */
#अगर defined(__GNUC__) || defined(__TINYC__)
  काष्ठा S ls4 = {a: 1, b: 2, c: {3, 4}};
#अन्यथा
  काष्ठा S ls4 = {.a = 1, .b = 2, .c = {3, 4}};
#पूर्ण_अगर
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
#पूर्ण_अगर

व्योम test_compound_with_relocs (व्योम)
{
  काष्ठा Wrap local_wrap[] = {
      ((काष्ठा Wrap) {inc_global}),
      inc_global,
  };
  व्योम (*p)(व्योम);
  p = global_wrap[0].func; p();
  p = global_wrap[1].func; p();
  p = local_wrap[0].func; p();
  p = local_wrap[1].func; p();
}

व्योम sys_ni(व्योम) { म_लिखो("ni\n"); }
व्योम sys_one(व्योम) { म_लिखो("one\n"); }
व्योम sys_two(व्योम) { म_लिखो("two\n"); }
व्योम sys_three(व्योम) { म_लिखो("three\n"); }
व्योम sys_four(व्योम) { म_लिखो("four\n"); }
प्रकार व्योम (*fptr)(व्योम);

#घोषणा array_आकार(a) (माप a / माप a[0])

व्योम test_multi_relocs(व्योम)
{
  पूर्णांक i;

  अटल स्थिर fptr tabl1[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  क्रम (i = 0; i < array_आकार(tabl1); i++)
    अगर (tabl1[i])
      tabl1[i]();
    अन्यथा
      म_लिखो("(0)\n");

  स्थिर fptr tabl2[4] = {
      [0 ... 3] = &sys_ni,
      [0] = sys_one,
      [1] = sys_two,
      [2] = sys_three,
      sys_four,
      [1 ... 2] = &sys_ni,
      [1] = 0,
  };
  क्रम (i = 0; i < array_आकार(tabl2); i++)
    अगर (tabl2[i])
      tabl2[i]();
    अन्यथा
      म_लिखो("(0)\n");

  पूर्णांक c = 0;
  पूर्णांक dd[] = {
    [0 ... 1] = ++c,
    [2 ... 3] = ++c
  };
  क्रम (i = 0; i < array_आकार(dd); i++)
    म_लिखो(" %d", dd[i]);
  म_लिखो("\n");

  /* multi-dimensional flex array with range initializers */
  अटल अक्षर m1[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  अक्षर        m2[][2][3] = {[0 ... 2]={{3,4,5},{6,7,8}},{{9},10},"abc"};
  पूर्णांक g, j, k;
  क्रम (g = 2; g-- > 0;) {
    म_लिखो("mdfa %s: %d -", "locl\0glob" + g * 5, माप m1);
    क्रम (i = 0; i < array_आकार(m1); i++)
    क्रम (j = 0; j < array_आकार(m1[0]); j++)
    क्रम (k = 0; k < array_आकार(m1[0][0]); k++)
      म_लिखो(" %d", (g ? m1:m2)[i][j][k]);
    म_लिखो("\n");
  }
}

व्योम test_init_ranges(व्योम) {
    पूर्णांक i,c=0;
    अटल व्योम *gostring[] = {
        [0 ... 31] = &&l_bad, [127] = &&l_bad,
        [32 ... 126] = &&l_loop,
        ['\\'] = &&l_esc, ['"'] = &&l_qdown,
        [128 ... 191] = &&l_bad,
        [192 ... 223] = &&l_utf8_2,
        [224 ... 239] = &&l_utf8_3,
        [240 ... 247] = &&l_utf8_4,
        [248 ... 255] = &&l_bad
    };

    क्रम (i = 0; i < 256; i++) {
        जाओ *gostring[i];
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

काष्ठा SEA { पूर्णांक i; पूर्णांक j; पूर्णांक k; पूर्णांक l; };
काष्ठा SEB { काष्ठा SEA a; पूर्णांक r[1]; };
काष्ठा SEC { काष्ठा SEA a; पूर्णांक r[0]; };
काष्ठा SED { काष्ठा SEA a; पूर्णांक r[]; };

अटल व्योम
test_correct_filling (काष्ठा SEA *x)
{
  अटल पूर्णांक i;
  अगर (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    म_लिखो("sea_fill%d: wrong\n", i);
  अन्यथा
    म_लिखो("sea_fill%d: okay\n", i);
  i++;
}

पूर्णांक
test_zero_init (व्योम)
{
  /* The peculiarity here is that only a.j is initialized.  That
     means that all other members must be zero initialized.  TCC
     once didn't do that for sub-level designators.  */
  काष्ठा SEB b = { .a.j = 5 };
  काष्ठा SEC c = { .a.j = 5 };
  काष्ठा SED d = { .a.j = 5 };
  test_correct_filling (&b.a);
  test_correct_filling (&c.a);
  test_correct_filling (&d.a);
  वापस 0;
}

व्योम test_init_struct_from_struct(व्योम)
{
    पूर्णांक i = 0;
    काष्ठा S {पूर्णांक x,y;}
        a = {1,2},
        b = {3,4},
        c[] = {a,b},
        d[] = {++i, ++i, ++i, ++i},
        e[] = {b, (काष्ठा S){5,6}}
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

प्रकार काष्ठा {
    अचिन्हित पूर्णांक a;
    अचिन्हित पूर्णांक : 32;
    अचिन्हित पूर्णांक b;
    अचिन्हित दीर्घ दीर्घ : 64;
    अचिन्हित पूर्णांक c;
} tst_bf;

tst_bf arr[] = { { 1, 2, 3 } };

व्योम
test_init_bf(व्योम)
{
    म_लिखो ("%s: %d %d %d\n", __FUNCTION__, arr[0].a, arr[0].b, arr[0].c);
}


पूर्णांक मुख्य()
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
  वापस 0;
}

పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం*, ...);

#ఒకవేళ defined test_56_btype_excess_1
నిర్మాణం A {} పూర్ణాంకం i;
#లేదావేళ defined test_57_btype_excess_2
అక్షరం పూర్ణాంకం i;
#లేదావేళ defined test_58_function_redefinition
పూర్ణాంకం f(శూన్య) { తిరిగి 0; }
పూర్ణాంకం f(శూన్య) { తిరిగి 1; }

#లేదావేళ defined test_global_redefinition
పూర్ణాంకం xxx = 1;
పూర్ణాంకం xxx;
పూర్ణాంకం xxx = 2;

#లేదావేళ defined test_59_function_array
పూర్ణాంకం (*fct)[42](పూర్ణాంకం x);

#లేదావేళ defined test_60_enum_redefinition
గణన color { RED, GREEN, BLUE };
గణన color { R, G, B };
గణన color c;

#లేదావేళ defined test_62_enumerator_redefinition
గణన color { RED, GREEN, BLUE };
గణన rgb { RED, G, B};
గణన color c = RED;

#లేదావేళ defined test_63_local_enumerator_redefinition
గణన {
    FOO,
    BAR
};

పూర్ణాంకం ప్రధాన(శూన్య)
{
    గణన {
        FOO = 2,
        BAR
    };

    తిరిగి BAR - FOO;
}

#లేదావేళ defined test_61_undefined_enum
గణన rgb3 c = 42;

#లేదావేళ defined test_74_non_const_init
పూర్ణాంకం i = i++;

#లేదావేళ defined test_సూచిక_assignment

శూన్య (*f1)(శూన్య);
శూన్య f2(శూన్య) {}

నిర్మాణం s1 *ps1;
నిర్మాణం s2 *ps2;

శూన్య *v1, **v2, ***v3;

గణన e1 { a = 4 } e10, *e11, *e12;
గణన e2 { b = -4 } e20, *e21;
గణన e3 { c = 5000000000LL } e30;

పూర్ణాంకం *ip;
గుర్తులేని పూర్ణాంకం *పైకి;
దీర్ఘ *lp;
దీర్ఘ దీర్ఘ *llp;

అక్షరం **c1;
అక్షరం స్థిరరాశి **c2;
గుర్తులేని అక్షరం **u1;

పూర్ణాంకం no_main ()
{
    // function
    f1 = f2;
    // struct
    ps1 = ps2;
    // void*
    v1 = v3;
    v2 = v3;

    // enum
    e11 = e12;
    e11 = e21;
    e11 = &e10;
    ip = &e10;
    ip = &e20;
    పైకి = &e10;
    పైకి = &e20;
    పైకి = &e30;

    lp = ip;
    lp = llp;

    // constness
    c1 = c2;
    *c1 = *c2;
    **c1 = **c2;

    // unsigned = signed
    u1 = c2;
    *u1 = *c2;
    **u1 = **c2;

    c2 = c1;
    *c2 = *c1;
    **c2 = **c1;

    తిరిగి 0;
}


#లేదావేళ defined test_enum_compat
గణన e4;
గణన e5;
శూన్య f3(గణన e4 e);
శూన్య f3(గణన e5 e);

#లేదావేళ defined test_enum_compat_2
గణన e6 { E1 = -1, E0 };
శూన్య f3(గణన e6);
శూన్య f3(పూర్ణాంకం);        // should work as int and e6 are compatible
శూన్య f4(గణన e6 e);
శూన్య f4(గుర్తులేని e); // should error as unsigned and e6 are incompatible

#లేదావేళ defined test_ptr_గమ్యం_str
శూన్య f() { _Generic((పూర్ణాంకం స్థిరరాశి *[]){0}, పూర్ణాంకం:0); }
#లేదావేళ defined test_fnptr_గమ్యం_str
శూన్య f() { _Generic((పూర్ణాంకం (*(*)(దశాంశం,అక్షరం))(ద్విగుణ,పూర్ణాంకం)){0}, పూర్ణాంకం:0); }
#లేదావేళ defined test_array_గమ్యం_str
శూన్య f() { _Generic((పూర్ణాంకం(*)[3]){0}, పూర్ణాంకం:0); }
#లేదావేళ defined test_duplicate_def_1
స్థిర గణన myenum { L = -1 } L;                                                
#లేదావేళ defined test_duplicate_def_2
శూన్య foo(శూన్య) {
స్థిర గణన myenum { L = -1 } L;                                                
}
#లేదావేళ defined test_abstract_decls
పూర్ణాంకం bar(స్థిరరాశి అక్షరం *());     // abstract declarator here is okay
పూర్ణాంకం bar (స్థిరరాశి అక్షరం *(*g)()) // should match this 'g' argument
{
  g();
  తిరిగి 42;
}
పూర్ణాంకం foo(పూర్ణాంకం ())              // abstract decl is wrong in definitions
{
  తిరిగి 0;
#లేదావేళ defined test_invalid_1
శూన్య f(అక్షరం*);
శూన్య g(శూన్య) {
  f((అక్షరం[]){1, ,});
}
#లేదావేళ defined test_invalid_2
పూర్ణాంకం ga = 0.42 { 2 };
#లేదావేళ defined test_invalid_3
నిర్మాణం S { పూర్ణాంకం a, b; };
నిర్మాణం T { నిర్మాణం S x; };
నిర్మాణం T gt = { 42 a: 1, 43 };
#లేదావేళ defined test_invalid_4
గణన E {
    x = 1 / 0
};
#లేదావేళ defined test_conflicting_types
పూర్ణాంకం i;
శూన్య foo(శూన్య) {
    పూర్ణాంకం i;
      {
        బాహ్య ద్విగుణ i;
        i = 42.2;
      }
}
#లేదావేళ defined test_nested_types
సంఘం u {
    సంఘం u {
        పూర్ణాంకం i;
    } m;
};
#లేదావేళ defined test_vla_1
పూర్ణాంకం X=1;

పూర్ణాంకం ప్రధాన(శూన్య) {
  పూర్ణాంకం t[][][X];
}
#లేదావేళ defined test_invalid_alignas
/* _Alignas is no type qualifier */
శూన్య * _Alignas(16) p1;

#లేదావేళ defined test_static_assert

#నిర్వచించు ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 నిర్మాణం x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#లేదావేళ defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
నిర్మాణం y {  _Static_assert(0, "0"" is 0"); };

#లేదావేళ defined test_static_assert_c2x
 _Static_assert(1);
నిర్మాణం z {  _Static_assert(0); }

#లేదావేళ defined test_static_assert_ఖాళీలు_string
 _Static_assert(0,"");

#లేదావేళ defined test_void_array
 శూన్య t[3];

#లేదావేళ defined test_incomplete_enum_array
  గణన e t[3];

#లేదావేళ defined test_incomplete_struct_array
  నిర్మాణం s t[3];

#లేదావేళ defined test_const_fun_array
  రకనిర్వచనం శూన్య f(శూన్య);
  స్థిరరాశి f t[3];

#లేదావేళ defined test_incomplete_array_array
  పూర్ణాంకం t[][3]; // gr: not an error, see below

/******************************************************************/
#లేదావేళ defined test_extern_array
పూర్ణాంకం iii[] = { 1,2,3 };
బాహ్య పూర్ణాంకం iii[];
పూర్ణాంకం x[];
పూర్ణాంకం x[2];
పూర్ణాంకం x[];
పూర్ణాంకం x[2];
పూర్ణాంకం x[];
బాహ్య పూర్ణాంకం x[2];
బాహ్య పూర్ణాంకం x[];
పూర్ణాంకం x[3];

/******************************************************************/
#లేదావేళ defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ఒకవేళ defined test_func_1
పూర్ణాంకం hello(పూర్ణాంకం);
#లేదావేళ defined test_func_4
స్థిర పూర్ణాంకం hello(పూర్ణాంకం);
#అయితే_ముగింపు
పూర్ణాంకం ప్రధాన () {
#ఒకవేళ defined test_func_6
    స్థిర
#అయితే_ముగింపు
    పూర్ణాంకం hello(పూర్ణాంకం);
    hello(123);
    తిరిగి 0;
}

#ఒకవేళ defined test_func_3
స్థిర పూర్ణాంకం hello(పూర్ణాంకం a)
#లేదావేళ defined test_func_5
పూర్ణాంకం hello(పూర్ణాంకం a, పూర్ణాంకం b)
#లేకపోతే
పూర్ణాంకం hello(పూర్ణాంకం a)
#అయితే_ముగింపు
{ రాయి("%s: a = %d\n", __FUNCTION__, a); తిరిగి 0; }

/******************************************************************/
#లేదావేళ defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#నిర్వచించు P(n,v) రాయి("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ఒకవేళ defined test_var_1
పూర్ణాంకం xxx[];
#అయితే_ముగింపు
పూర్ణాంకం bar();

పూర్ణాంకం ప్రధాన ()
{
#ఒకవేళ !defined test_var_3
    పూర్ణాంకం xxx = 2;
#అయితే_ముగింపు
    {
        బాహ్య పూర్ణాంకం xxx[
#ఒకవేళ defined test_var_3
        2
#అయితే_ముగింపు
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ఒకవేళ !defined test_var_3
    P(2, xxx);
#అయితే_ముగింపు
    bar(123);
    తిరిగి 0;
}
పూర్ణాంకం xxx[1] = {1};
పూర్ణాంకం bar() { P(3, xxx[0]); తిరిగి 0; }

#లేదావేళ defined test_var_4
నిర్మాణం yyy { పూర్ణాంకం y; };
నిర్మాణం zzz;
శూన్య f1() {
    బాహ్య అక్షరం *x;
    బాహ్య అక్షరం **xx;
    బాహ్య నిర్మాణం yyy y;
    బాహ్య నిర్మాణం yyy *yy;
    బాహ్య నిర్మాణం zzz z;
    బాహ్య నిర్మాణం zzz *zz;
}
శూన్య f2() {
    బాహ్య అక్షరం *x;
    బాహ్య అక్షరం **xx;
    బాహ్య నిర్మాణం yyy y;
    బాహ్య నిర్మాణం yyy *yy;
    బాహ్య నిర్మాణం zzz z;
    బాహ్య నిర్మాణం zzz *zz;
}
నిర్మాణం yyy y, *yy;
నిర్మాణం zzz { పూర్ణాంకం z; } z, *zz;

/******************************************************************/
#లేదావేళ defined test_long_double_type_for_win32

పూర్ణాంకం ప్రధాన()
{
    ద్విగుణ *a = 0;
    దీర్ఘ ద్విగుణ *b = a;
    పూర్ణాంకం n = _Generic(*a, ద్విగుణ:0, దీర్ఘ ద్విగుణ:1);
}

#లేదావేళ defined test_stray_backslash
#నిర్వచించు x \a
x

#లేదావేళ defined test_stray_backslash2

పూర్ణాంకం ప్రధాన()
{
#నిర్వచించు _S(x) #x
#నిర్వచించు S(x) _S(x)
    రాయి("%sn\n", S(\\));
}

/******************************************************************/
#లేదావేళ defined test_var_array

స్థిర నిర్మాణం var_len { పూర్ణాంకం i; స్థిరరాశి అక్షరం str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#లేదావేళ defined test_var_array2

నిర్మాణం c1 { పూర్ణాంకం a; పూర్ణాంకం b[]; };
నిర్మాణం c1 c1 = { 1, { 2, 3, 4 } };

నిర్మాణం c2 { పూర్ణాంకం c; నిర్మాణం c1 c1; };
నిర్మాణం c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#లేదావేళ defined test_var_array3
/* similar to test_var_array2 but with string initializers */
నిర్మాణం A { పూర్ణాంకం a; అక్షరం b[]; };
నిర్మాణం A a = { 1, "1" };
నిర్మాణం B { నిర్మాణం A a; };
నిర్మాణం B b = { { 1, "1" } };
/******************************************************************/
#లేదావేళ defined test_default_int_type
n; // warn
f(); // don't warn

#లేదావేళ defined test_invalid_global_stmtexpr
n[పరిమాణం({3;})]; // crashed in block() due to missing local scope

#లేదావేళ defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#లేదావేళ defined test_duplicate_member
నిర్మాణం S {
  పూర్ణాంకం a, a;
};
#లేదావేళ defined test_duplicate_member_anon
నిర్మాణం S1 {
  పూర్ణాంకం b;
  నిర్మాణం {
    పూర్ణాంకం b;
  } c;
};
నిర్మాణం S2 {
  పూర్ణాంకం d;
  నిర్మాణం {
    పూర్ణాంకం d;
  };
};

/******************************************************************/
#లేదావేళ defined test_conflicting_array_definition
బాహ్య పూర్ణాంకం array[2];
పూర్ణాంకం array[] = { 1, 2, 3 };

#లేదావేళ defined test_incompatible_local_redef
శూన్య foo (శూన్య)
{
  రకనిర్వచనం పూర్ణాంకం localfunctype (పూర్ణాంకం);
  బాహ్య localfunctype func2;
  రకనిర్వచనం శూన్య localfunctype (పూర్ణాంకం, పూర్ణాంకం);
}

#లేదావేళ defined test_cast_from_void
శూన్య v() {}
పూర్ణాంకం f() { తిరిగి v(); }

#లేదావేళ defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ఒకవేళ defined test_switch_W1
#సూచన comment(option, "-Wall")
#లేదావేళ defined test_switch_W2
#సూచన comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#లేదావేళ defined test_switch_W3
#సూచన comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#లేదావేళ defined test_switch_W4
#సూచన comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#అయితే_ముగింపు
శూన్య func(శూన్య)
{
    అక్షరం *ccp = "123";
    fink();
}
__attribute__((stuff)) పూర్ణాంకం fink() {తిరిగి 0;}

#లేదావేళ defined test_invalid_funcparam_1
శూన్య func(పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం a);

#లేదావేళ defined test_invalid_funcparam_2
శూన్య func(పూర్ణాంకం a, పూర్ణాంకం ఒకవేళ);

#లేదావేళ defined test_array_funcparam
పూర్ణాంకం amain(పూర్ణాంకం argc, అక్షరం *argv[స్థిర argc + 1])
{
    పూర్ణాంకం i;

    కొరకు (i = 0; i < argc; ++i)
        రాయి("arg[%d] = \"%s\"\n", i, argv[i]);
    తిరిగి 0;
}
పూర్ణాంకం ప్రధాన()
{
    తిరిగి amain(2, (అక్షరం *[]){ "X", "Y", 0 });
}

#లేదావేళ defined test_return_from_statement_సమాసం
పూర్ణాంకం f() { ({ తిరిగి 78; }); }
పూర్ణాంకం ప్రధాన() { తిరిగి f(); }

/******************************************************************/

#లేదావేళ defined test_illegal_unicode
పూర్ణాంకం ప్రధాన() {
    అక్షరం *str = "\Uffffffff";
}

#లేదావేళ defined test_error_string
#దోషం \123\\
456

#లేదావేళ defined test_error_incomplete_type
నిర్మాణం A;
శూన్య f(నిర్మాణం A *);

పూర్ణాంకం ప్రధాన()
{
    f(&(నిర్మాణం A){});
}

నిర్మాణం A {
    పూర్ణాంకం x;
};

#లేదావేళ defined test_pp_error_1
# ఒకవేళ //no expression
# endif
#లేదావేళ defined test_pp_error_2
# ఒకవేళ X(1,2) //undefined function macro
# endif

#లేదావేళ defined test_సూచిక_plus_double

పూర్ణాంకం *invalid_operation(పూర్ణాంకం *p, ద్విగుణ d)
{
    తిరిగి p + d;
}

#లేదావేళ defined test_duplicate_case

పూర్ణాంకం ప్రధాన()
{
    గుర్తులేని పూర్ణాంకం x;
    ఎంపిక (x) {
        స్థితి -1 ... 0: /* empty case range with unsigned */
        స్థితి 3:
        స్థితి 1:
        స్థితి 2:
        స్థితి 3: /* show this line number in error */
        స్థితి 4:
        స్థితి 5:
    }
}
#లేదావేళ defined test_సాధారణ_funcargs || defined test_తిరగేయి_funcargs

#నిర్వచితమైతే test_తిరగేయి_funcargs
# pragma comment(option, "-freverse-funcargs")
#అయితే_ముగింపు

పూర్ణాంకం ప్రధాన()
{
    రాయి(" %d %d %d\n", రాయి("1"), రాయి("22"), రాయి("333"));
}

#లేదావేళ defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

నిర్మాణం xxx {పూర్ణాంకం x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
పూర్ణాంకం bar(గణన ee { a = 12, b = 34 } i, పూర్ణాంకం(*f)(పూర్ణాంకం i))
{
    రాయి("bar %d %d %d\n", i, a, b);
    తిరిగి 0;
}
/* 'xxx' not defined outside of function */
పూర్ణాంకం foo(నిర్మాణం xxx {పూర్ణాంకం x[3];}*p)
{
    రాయి("foo %d", పరిమాణం *p);
    తిరిగి p->x[3];
}
#నిర్వచితమైతే test_scope_2
/* incompatible redefinition */
పూర్ణాంకం foo(నిర్మాణం xxx {పూర్ణాంకం x[2];}*p);
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే test_scope_3
గణన ee { a = 1, b };
#అయితే_ముగింపు

నిర్మాణం xxx x = { 11,22,33,44 };
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    రాయి(" %d %d\n", foo(&x), పరిమాణం (నిర్మాణం xxx));
    గణన ee e = b;
    bar(13 + e, 0);

}

#లేదావేళ defined test_const_array_member_addr_ok

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

int_array స్థిరరాశి *get_array(స్థిరరాశి my_struct *s)
{
    తిరిగి &(s->arr);
}

#లేదావేళ defined test_const_array_member_decay_ok

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

స్థిరరాశి పూర్ణాంకం *good_decay(స్థిరరాశి my_struct *s)
{
    తిరిగి s->arr;
}

#లేదావేళ defined test_const_array_member_addr_bad

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

int_array *bad_array_addr(స్థిరరాశి my_struct *s)
{
    తిరిగి &(s->arr);
}

#లేదావేళ defined test_const_array_member_decay_bad

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

పూర్ణాంకం *bad_decay(స్థిరరాశి my_struct *s)
{
    తిరిగి s->arr;
}

#లేదావేళ defined test_const_array_member_write_bad

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

శూన్య bad_write(స్థిరరాశి my_struct *s)
{
    s->arr[0] = 1;
}

#లేదావేళ defined test_const_struct_array_member_write_bad

రకనిర్వచనం నిర్మాణం { పూర్ణాంకం x; } inner;
రకనిర్వచనం నిర్మాణం { inner arr[1]; } outer;

శూన్య bad_inner_write(స్థిరరాశి outer *s)
{
    s->arr[0].x = 1;
}

#లేదావేళ defined test_volatile_array_member_addr_ok

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

int_array అస్థిర *get_volatile_array(అస్థిర my_struct *s)
{
    తిరిగి &(s->arr);
}

#లేదావేళ defined test_volatile_array_member_decay_ok

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

అస్థిర పూర్ణాంకం *good_volatile_decay(అస్థిర my_struct *s)
{
    తిరిగి s->arr;
}

#లేదావేళ defined test_volatile_array_member_addr_bad

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(అస్థిర my_struct *s)
{
    తిరిగి &(s->arr);
}

#లేదావేళ defined test_volatile_array_member_decay_bad

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

పూర్ణాంకం *bad_volatile_decay(అస్థిర my_struct *s)
{
    తిరిగి s->arr;
}

#లేదావేళ defined test_volatile_array_member_write_ok

రకనిర్వచనం పూర్ణాంకం int_array[1];
రకనిర్వచనం నిర్మాణం { int_array arr; } my_struct;

శూన్య good_volatile_write(అస్థిర my_struct *s)
{
    s->arr[0] = 1;
}

#లేదావేళ defined test_conditional_array_qualifiers

రకనిర్వచనం పూర్ణాంకం Array2[2];
రకనిర్వచనం పూర్ణాంకం Array2x3[2][3];

Array2 *p;
స్థిరరాశి Array2 *cp;
స్థిరరాశి Array2x3 *cap;
అస్థిర Array2x3 *vap;

శూన్య test(శూన్య)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#లేదావేళ defined test_restrict_scalar

పరిమిత పూర్ణాంకం object;

#లేదావేళ defined test_restrict_function_సూచిక

పూర్ణాంకం (*పరిమిత function_సూచిక)(శూన్య);

#లేదావేళ defined test_discarded_restrict

రకనిర్వచనం పూర్ణాంకం *పరిమిత restricted_సూచిక;

restricted_సూచిక *ఆధారం;
పూర్ణాంకం **destination;

శూన్య test(శూన్య)
{
    destination = ఆధారం;
}

#అయితే_ముగింపు

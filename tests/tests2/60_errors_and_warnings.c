ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*, ...);

#ਜੇ defined test_56_btype_excess_1
ਬਣਤਰ A {} ਪੂਰਨ i;
#ਜਾਂਜੇ defined test_57_btype_excess_2
ਅੱਖਰ ਪੂਰਨ i;
#ਜਾਂਜੇ defined test_58_function_redefinition
ਪੂਰਨ f(ਖਾਲੀ) { ਵਾਪਸ 0; }
ਪੂਰਨ f(ਖਾਲੀ) { ਵਾਪਸ 1; }

#ਜਾਂਜੇ defined test_global_redefinition
ਪੂਰਨ xxx = 1;
ਪੂਰਨ xxx;
ਪੂਰਨ xxx = 2;

#ਜਾਂਜੇ defined test_59_function_array
ਪੂਰਨ (*fct)[42](ਪੂਰਨ x);

#ਜਾਂਜੇ defined test_60_enum_redefinition
ਗਿਣਤੀ color { RED, GREEN, BLUE };
ਗਿਣਤੀ color { R, G, B };
ਗਿਣਤੀ color c;

#ਜਾਂਜੇ defined test_62_enumerator_redefinition
ਗਿਣਤੀ color { RED, GREEN, BLUE };
ਗਿਣਤੀ rgb { RED, G, B};
ਗਿਣਤੀ color c = RED;

#ਜਾਂਜੇ defined test_63_local_enumerator_redefinition
ਗਿਣਤੀ {
    FOO,
    BAR
};

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਗਿਣਤੀ {
        FOO = 2,
        BAR
    };

    ਵਾਪਸ BAR - FOO;
}

#ਜਾਂਜੇ defined test_61_undefined_enum
ਗਿਣਤੀ rgb3 c = 42;

#ਜਾਂਜੇ defined test_74_non_const_init
ਪੂਰਨ i = i++;

#ਜਾਂਜੇ defined test_ਸੂਚਕ_assignment

ਖਾਲੀ (*f1)(ਖਾਲੀ);
ਖਾਲੀ f2(ਖਾਲੀ) {}

ਬਣਤਰ s1 *ps1;
ਬਣਤਰ s2 *ps2;

ਖਾਲੀ *v1, **v2, ***v3;

ਗਿਣਤੀ e1 { a = 4 } e10, *e11, *e12;
ਗਿਣਤੀ e2 { b = -4 } e20, *e21;
ਗਿਣਤੀ e3 { c = 5000000000LL } e30;

ਪੂਰਨ *ip;
ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਉੱਪਰ;
ਲੰਮਾ *lp;
ਲੰਮਾ ਲੰਮਾ *llp;

ਅੱਖਰ **c1;
ਅੱਖਰ ਅਚਲ **c2;
ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ **u1;

ਪੂਰਨ no_main ()
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
    ਉੱਪਰ = &e10;
    ਉੱਪਰ = &e20;
    ਉੱਪਰ = &e30;

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

    ਵਾਪਸ 0;
}


#ਜਾਂਜੇ defined test_enum_compat
ਗਿਣਤੀ e4;
ਗਿਣਤੀ e5;
ਖਾਲੀ f3(ਗਿਣਤੀ e4 e);
ਖਾਲੀ f3(ਗਿਣਤੀ e5 e);

#ਜਾਂਜੇ defined test_enum_compat_2
ਗਿਣਤੀ e6 { E1 = -1, E0 };
ਖਾਲੀ f3(ਗਿਣਤੀ e6);
ਖਾਲੀ f3(ਪੂਰਨ);        // should work as int and e6 are compatible
ਖਾਲੀ f4(ਗਿਣਤੀ e6 e);
ਖਾਲੀ f4(ਬਿਨਾਨਿਸ਼ਾਨੀ e); // should error as unsigned and e6 are incompatible

#ਜਾਂਜੇ defined test_ptr_ਮੰਜ਼ਿਲ_str
ਖਾਲੀ f() { _Generic((ਪੂਰਨ ਅਚਲ *[]){0}, ਪੂਰਨ:0); }
#ਜਾਂਜੇ defined test_fnptr_ਮੰਜ਼ਿਲ_str
ਖਾਲੀ f() { _Generic((ਪੂਰਨ (*(*)(ਦਸ਼ਮਲਵ,ਅੱਖਰ))(ਦੁੱਗਣਾ,ਪੂਰਨ)){0}, ਪੂਰਨ:0); }
#ਜਾਂਜੇ defined test_array_ਮੰਜ਼ਿਲ_str
ਖਾਲੀ f() { _Generic((ਪੂਰਨ(*)[3]){0}, ਪੂਰਨ:0); }
#ਜਾਂਜੇ defined test_duplicate_def_1
ਸਥਿਰ ਗਿਣਤੀ myenum { L = -1 } L;                                                
#ਜਾਂਜੇ defined test_duplicate_def_2
ਖਾਲੀ foo(ਖਾਲੀ) {
ਸਥਿਰ ਗਿਣਤੀ myenum { L = -1 } L;                                                
}
#ਜਾਂਜੇ defined test_abstract_decls
ਪੂਰਨ bar(ਅਚਲ ਅੱਖਰ *());     // abstract declarator here is okay
ਪੂਰਨ bar (ਅਚਲ ਅੱਖਰ *(*g)()) // should match this 'g' argument
{
  g();
  ਵਾਪਸ 42;
}
ਪੂਰਨ foo(ਪੂਰਨ ())              // abstract decl is wrong in definitions
{
  ਵਾਪਸ 0;
#ਜਾਂਜੇ defined test_invalid_1
ਖਾਲੀ f(ਅੱਖਰ*);
ਖਾਲੀ g(ਖਾਲੀ) {
  f((ਅੱਖਰ[]){1, ,});
}
#ਜਾਂਜੇ defined test_invalid_2
ਪੂਰਨ ga = 0.42 { 2 };
#ਜਾਂਜੇ defined test_invalid_3
ਬਣਤਰ S { ਪੂਰਨ a, b; };
ਬਣਤਰ T { ਬਣਤਰ S x; };
ਬਣਤਰ T gt = { 42 a: 1, 43 };
#ਜਾਂਜੇ defined test_invalid_4
ਗਿਣਤੀ E {
    x = 1 / 0
};
#ਜਾਂਜੇ defined test_conflicting_types
ਪੂਰਨ i;
ਖਾਲੀ foo(ਖਾਲੀ) {
    ਪੂਰਨ i;
      {
        ਬਾਹਰੀ ਦੁੱਗਣਾ i;
        i = 42.2;
      }
}
#ਜਾਂਜੇ defined test_nested_types
ਸੰਘ u {
    ਸੰਘ u {
        ਪੂਰਨ i;
    } m;
};
#ਜਾਂਜੇ defined test_vla_1
ਪੂਰਨ X=1;

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ t[][][X];
}
#ਜਾਂਜੇ defined test_invalid_alignas
/* _Alignas is no type qualifier */
ਖਾਲੀ * _Alignas(16) p1;

#ਜਾਂਜੇ defined test_static_assert

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ਬਣਤਰ x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#ਜਾਂਜੇ defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ਬਣਤਰ y {  _Static_assert(0, "0"" is 0"); };

#ਜਾਂਜੇ defined test_static_assert_c2x
 _Static_assert(1);
ਬਣਤਰ z {  _Static_assert(0); }

#ਜਾਂਜੇ defined test_static_assert_ਖਾਲੀ_ਥਾਵਾਂ_string
 _Static_assert(0,"");

#ਜਾਂਜੇ defined test_void_array
 ਖਾਲੀ t[3];

#ਜਾਂਜੇ defined test_incomplete_enum_array
  ਗਿਣਤੀ e t[3];

#ਜਾਂਜੇ defined test_incomplete_struct_array
  ਬਣਤਰ s t[3];

#ਜਾਂਜੇ defined test_const_fun_array
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ f(ਖਾਲੀ);
  ਅਚਲ f t[3];

#ਜਾਂਜੇ defined test_incomplete_array_array
  ਪੂਰਨ t[][3]; // gr: not an error, see below

/******************************************************************/
#ਜਾਂਜੇ defined test_extern_array
ਪੂਰਨ iii[] = { 1,2,3 };
ਬਾਹਰੀ ਪੂਰਨ iii[];
ਪੂਰਨ x[];
ਪੂਰਨ x[2];
ਪੂਰਨ x[];
ਪੂਰਨ x[2];
ਪੂਰਨ x[];
ਬਾਹਰੀ ਪੂਰਨ x[2];
ਬਾਹਰੀ ਪੂਰਨ x[];
ਪੂਰਨ x[3];

/******************************************************************/
#ਜਾਂਜੇ defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ਜੇ defined test_func_1
ਪੂਰਨ hello(ਪੂਰਨ);
#ਜਾਂਜੇ defined test_func_4
ਸਥਿਰ ਪੂਰਨ hello(ਪੂਰਨ);
#ਜੇ_ਅੰਤ
ਪੂਰਨ ਮੁੱਖ () {
#ਜੇ defined test_func_6
    ਸਥਿਰ
#ਜੇ_ਅੰਤ
    ਪੂਰਨ hello(ਪੂਰਨ);
    hello(123);
    ਵਾਪਸ 0;
}

#ਜੇ defined test_func_3
ਸਥਿਰ ਪੂਰਨ hello(ਪੂਰਨ a)
#ਜਾਂਜੇ defined test_func_5
ਪੂਰਨ hello(ਪੂਰਨ a, ਪੂਰਨ b)
#ਨਹੀਂਤਾਂ
ਪੂਰਨ hello(ਪੂਰਨ a)
#ਜੇ_ਅੰਤ
{ ਲਿਖੋ("%s: a = %d\n", __FUNCTION__, a); ਵਾਪਸ 0; }

/******************************************************************/
#ਜਾਂਜੇ defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P(n,v) ਲਿਖੋ("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ਜੇ defined test_var_1
ਪੂਰਨ xxx[];
#ਜੇ_ਅੰਤ
ਪੂਰਨ bar();

ਪੂਰਨ ਮੁੱਖ ()
{
#ਜੇ !defined test_var_3
    ਪੂਰਨ xxx = 2;
#ਜੇ_ਅੰਤ
    {
        ਬਾਹਰੀ ਪੂਰਨ xxx[
#ਜੇ defined test_var_3
        2
#ਜੇ_ਅੰਤ
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ਜੇ !defined test_var_3
    P(2, xxx);
#ਜੇ_ਅੰਤ
    bar(123);
    ਵਾਪਸ 0;
}
ਪੂਰਨ xxx[1] = {1};
ਪੂਰਨ bar() { P(3, xxx[0]); ਵਾਪਸ 0; }

#ਜਾਂਜੇ defined test_var_4
ਬਣਤਰ yyy { ਪੂਰਨ y; };
ਬਣਤਰ zzz;
ਖਾਲੀ f1() {
    ਬਾਹਰੀ ਅੱਖਰ *x;
    ਬਾਹਰੀ ਅੱਖਰ **xx;
    ਬਾਹਰੀ ਬਣਤਰ yyy y;
    ਬਾਹਰੀ ਬਣਤਰ yyy *yy;
    ਬਾਹਰੀ ਬਣਤਰ zzz z;
    ਬਾਹਰੀ ਬਣਤਰ zzz *zz;
}
ਖਾਲੀ f2() {
    ਬਾਹਰੀ ਅੱਖਰ *x;
    ਬਾਹਰੀ ਅੱਖਰ **xx;
    ਬਾਹਰੀ ਬਣਤਰ yyy y;
    ਬਾਹਰੀ ਬਣਤਰ yyy *yy;
    ਬਾਹਰੀ ਬਣਤਰ zzz z;
    ਬਾਹਰੀ ਬਣਤਰ zzz *zz;
}
ਬਣਤਰ yyy y, *yy;
ਬਣਤਰ zzz { ਪੂਰਨ z; } z, *zz;

/******************************************************************/
#ਜਾਂਜੇ defined test_long_double_type_for_win32

ਪੂਰਨ ਮੁੱਖ()
{
    ਦੁੱਗਣਾ *a = 0;
    ਲੰਮਾ ਦੁੱਗਣਾ *b = a;
    ਪੂਰਨ n = _Generic(*a, ਦੁੱਗਣਾ:0, ਲੰਮਾ ਦੁੱਗਣਾ:1);
}

#ਜਾਂਜੇ defined test_stray_backslash
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ x \a
x

#ਜਾਂਜੇ defined test_stray_backslash2

ਪੂਰਨ ਮੁੱਖ()
{
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S(x) #x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S(x) _S(x)
    ਲਿਖੋ("%sn\n", S(\\));
}

/******************************************************************/
#ਜਾਂਜੇ defined test_var_array

ਸਥਿਰ ਬਣਤਰ var_len { ਪੂਰਨ i; ਅਚਲ ਅੱਖਰ str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#ਜਾਂਜੇ defined test_var_array2

ਬਣਤਰ c1 { ਪੂਰਨ a; ਪੂਰਨ b[]; };
ਬਣਤਰ c1 c1 = { 1, { 2, 3, 4 } };

ਬਣਤਰ c2 { ਪੂਰਨ c; ਬਣਤਰ c1 c1; };
ਬਣਤਰ c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#ਜਾਂਜੇ defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ਬਣਤਰ A { ਪੂਰਨ a; ਅੱਖਰ b[]; };
ਬਣਤਰ A a = { 1, "1" };
ਬਣਤਰ B { ਬਣਤਰ A a; };
ਬਣਤਰ B b = { { 1, "1" } };
/******************************************************************/
#ਜਾਂਜੇ defined test_default_int_type
n; // warn
f(); // don't warn

#ਜਾਂਜੇ defined test_invalid_global_stmtexpr
n[ਆਕਾਰ({3;})]; // crashed in block() due to missing local scope

#ਜਾਂਜੇ defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#ਜਾਂਜੇ defined test_duplicate_member
ਬਣਤਰ S {
  ਪੂਰਨ a, a;
};
#ਜਾਂਜੇ defined test_duplicate_member_anon
ਬਣਤਰ S1 {
  ਪੂਰਨ b;
  ਬਣਤਰ {
    ਪੂਰਨ b;
  } c;
};
ਬਣਤਰ S2 {
  ਪੂਰਨ d;
  ਬਣਤਰ {
    ਪੂਰਨ d;
  };
};

/******************************************************************/
#ਜਾਂਜੇ defined test_conflicting_array_definition
ਬਾਹਰੀ ਪੂਰਨ array[2];
ਪੂਰਨ array[] = { 1, 2, 3 };

#ਜਾਂਜੇ defined test_incompatible_local_redef
ਖਾਲੀ foo (ਖਾਲੀ)
{
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ localfunctype (ਪੂਰਨ);
  ਬਾਹਰੀ localfunctype func2;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ localfunctype (ਪੂਰਨ, ਪੂਰਨ);
}

#ਜਾਂਜੇ defined test_cast_from_void
ਖਾਲੀ v() {}
ਪੂਰਨ f() { ਵਾਪਸ v(); }

#ਜਾਂਜੇ defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ਜੇ defined test_switch_W1
#ਹਦਾਇਤ comment(option, "-Wall")
#ਜਾਂਜੇ defined test_switch_W2
#ਹਦਾਇਤ comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#ਜਾਂਜੇ defined test_switch_W3
#ਹਦਾਇਤ comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#ਜਾਂਜੇ defined test_switch_W4
#ਹਦਾਇਤ comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#ਜੇ_ਅੰਤ
ਖਾਲੀ func(ਖਾਲੀ)
{
    ਅੱਖਰ *ccp = "123";
    fink();
}
__attribute__((stuff)) ਪੂਰਨ fink() {ਵਾਪਸ 0;}

#ਜਾਂਜੇ defined test_invalid_funcparam_1
ਖਾਲੀ func(ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ a);

#ਜਾਂਜੇ defined test_invalid_funcparam_2
ਖਾਲੀ func(ਪੂਰਨ a, ਪੂਰਨ ਜੇ);

#ਜਾਂਜੇ defined test_array_funcparam
ਪੂਰਨ amain(ਪੂਰਨ argc, ਅੱਖਰ *argv[ਸਥਿਰ argc + 1])
{
    ਪੂਰਨ i;

    ਲਈ (i = 0; i < argc; ++i)
        ਲਿਖੋ("arg[%d] = \"%s\"\n", i, argv[i]);
    ਵਾਪਸ 0;
}
ਪੂਰਨ ਮੁੱਖ()
{
    ਵਾਪਸ amain(2, (ਅੱਖਰ *[]){ "X", "Y", 0 });
}

#ਜਾਂਜੇ defined test_return_from_statement_ਵਿਅੰਜਕ
ਪੂਰਨ f() { ({ ਵਾਪਸ 78; }); }
ਪੂਰਨ ਮੁੱਖ() { ਵਾਪਸ f(); }

/******************************************************************/

#ਜਾਂਜੇ defined test_illegal_unicode
ਪੂਰਨ ਮੁੱਖ() {
    ਅੱਖਰ *str = "\Uffffffff";
}

#ਜਾਂਜੇ defined test_error_string
#ਗਲਤੀ \123\\
456

#ਜਾਂਜੇ defined test_error_incomplete_type
ਬਣਤਰ A;
ਖਾਲੀ f(ਬਣਤਰ A *);

ਪੂਰਨ ਮੁੱਖ()
{
    f(&(ਬਣਤਰ A){});
}

ਬਣਤਰ A {
    ਪੂਰਨ x;
};

#ਜਾਂਜੇ defined test_pp_error_1
# ਜੇ //no expression
# endif
#ਜਾਂਜੇ defined test_pp_error_2
# ਜੇ X(1,2) //undefined function macro
# endif

#ਜਾਂਜੇ defined test_ਸੂਚਕ_plus_double

ਪੂਰਨ *invalid_operation(ਪੂਰਨ *p, ਦੁੱਗਣਾ d)
{
    ਵਾਪਸ p + d;
}

#ਜਾਂਜੇ defined test_duplicate_case

ਪੂਰਨ ਮੁੱਖ()
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x;
    ਚੋਣ (x) {
        ਹਾਲਤ -1 ... 0: /* empty case range with unsigned */
        ਹਾਲਤ 3:
        ਹਾਲਤ 1:
        ਹਾਲਤ 2:
        ਹਾਲਤ 3: /* show this line number in error */
        ਹਾਲਤ 4:
        ਹਾਲਤ 5:
    }
}
#ਜਾਂਜੇ defined test_ਸਾਧਾਰਨ_funcargs || defined test_ਉਲਟ_funcargs

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ test_ਉਲਟ_funcargs
# pragma comment(option, "-freverse-funcargs")
#ਜੇ_ਅੰਤ

ਪੂਰਨ ਮੁੱਖ()
{
    ਲਿਖੋ(" %d %d %d\n", ਲਿਖੋ("1"), ਲਿਖੋ("22"), ਲਿਖੋ("333"));
}

#ਜਾਂਜੇ defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ਬਣਤਰ xxx {ਪੂਰਨ x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
ਪੂਰਨ bar(ਗਿਣਤੀ ee { a = 12, b = 34 } i, ਪੂਰਨ(*f)(ਪੂਰਨ i))
{
    ਲਿਖੋ("bar %d %d %d\n", i, a, b);
    ਵਾਪਸ 0;
}
/* 'xxx' not defined outside of function */
ਪੂਰਨ foo(ਬਣਤਰ xxx {ਪੂਰਨ x[3];}*p)
{
    ਲਿਖੋ("foo %d", ਆਕਾਰ *p);
    ਵਾਪਸ p->x[3];
}
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ test_scope_2
/* incompatible redefinition */
ਪੂਰਨ foo(ਬਣਤਰ xxx {ਪੂਰਨ x[2];}*p);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ test_scope_3
ਗਿਣਤੀ ee { a = 1, b };
#ਜੇ_ਅੰਤ

ਬਣਤਰ xxx x = { 11,22,33,44 };
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲਿਖੋ(" %d %d\n", foo(&x), ਆਕਾਰ (ਬਣਤਰ xxx));
    ਗਿਣਤੀ ee e = b;
    bar(13 + e, 0);

}

#ਜਾਂਜੇ defined test_const_array_member_addr_ok

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

int_array ਅਚਲ *get_array(ਅਚਲ my_struct *s)
{
    ਵਾਪਸ &(s->arr);
}

#ਜਾਂਜੇ defined test_const_array_member_decay_ok

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਅਚਲ ਪੂਰਨ *good_decay(ਅਚਲ my_struct *s)
{
    ਵਾਪਸ s->arr;
}

#ਜਾਂਜੇ defined test_const_array_member_addr_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

int_array *bad_array_addr(ਅਚਲ my_struct *s)
{
    ਵਾਪਸ &(s->arr);
}

#ਜਾਂਜੇ defined test_const_array_member_decay_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਪੂਰਨ *bad_decay(ਅਚਲ my_struct *s)
{
    ਵਾਪਸ s->arr;
}

#ਜਾਂਜੇ defined test_const_array_member_write_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਖਾਲੀ bad_write(ਅਚਲ my_struct *s)
{
    s->arr[0] = 1;
}

#ਜਾਂਜੇ defined test_const_struct_array_member_write_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ x; } inner;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { inner arr[1]; } outer;

ਖਾਲੀ bad_inner_write(ਅਚਲ outer *s)
{
    s->arr[0].x = 1;
}

#ਜਾਂਜੇ defined test_volatile_array_member_addr_ok

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

int_array ਅਸਥਿਰ *get_volatile_array(ਅਸਥਿਰ my_struct *s)
{
    ਵਾਪਸ &(s->arr);
}

#ਜਾਂਜੇ defined test_volatile_array_member_decay_ok

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਅਸਥਿਰ ਪੂਰਨ *good_volatile_decay(ਅਸਥਿਰ my_struct *s)
{
    ਵਾਪਸ s->arr;
}

#ਜਾਂਜੇ defined test_volatile_array_member_addr_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(ਅਸਥਿਰ my_struct *s)
{
    ਵਾਪਸ &(s->arr);
}

#ਜਾਂਜੇ defined test_volatile_array_member_decay_bad

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਪੂਰਨ *bad_volatile_decay(ਅਸਥਿਰ my_struct *s)
{
    ਵਾਪਸ s->arr;
}

#ਜਾਂਜੇ defined test_volatile_array_member_write_ok

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_array[1];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { int_array arr; } my_struct;

ਖਾਲੀ good_volatile_write(ਅਸਥਿਰ my_struct *s)
{
    s->arr[0] = 1;
}

#ਜਾਂਜੇ defined test_conditional_array_qualifiers

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ Array2[2];
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ Array2x3[2][3];

Array2 *p;
ਅਚਲ Array2 *cp;
ਅਚਲ Array2x3 *cap;
ਅਸਥਿਰ Array2x3 *vap;

ਖਾਲੀ test(ਖਾਲੀ)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#ਜਾਂਜੇ defined test_restrict_scalar

ਸੀਮਿਤ ਪੂਰਨ object;

#ਜਾਂਜੇ defined test_restrict_function_ਸੂਚਕ

ਪੂਰਨ (*ਸੀਮਿਤ function_ਸੂਚਕ)(ਖਾਲੀ);

#ਜਾਂਜੇ defined test_discarded_restrict

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ *ਸੀਮਿਤ restricted_ਸੂਚਕ;

restricted_ਸੂਚਕ *ਸਰੋਤ;
ਪੂਰਨ **destination;

ਖਾਲੀ test(ਖਾਲੀ)
{
    destination = ਸਰੋਤ;
}

#ਜੇ_ਅੰਤ

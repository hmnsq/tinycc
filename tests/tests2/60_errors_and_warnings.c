ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);

#ಆದರೆ defined test_56_btype_excess_1
ರಚನೆ A {} ಪೂರ್ಣಾಂಕ i;
#ಅಥವಾಆದರೆ defined test_57_btype_excess_2
ಅಕ್ಷರ ಪೂರ್ಣಾಂಕ i;
#ಅಥವಾಆದರೆ defined test_58_function_redefinition
ಪೂರ್ಣಾಂಕ f(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 0; }
ಪೂರ್ಣಾಂಕ f(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 1; }

#ಅಥವಾಆದರೆ defined test_global_redefinition
ಪೂರ್ಣಾಂಕ xxx = 1;
ಪೂರ್ಣಾಂಕ xxx;
ಪೂರ್ಣಾಂಕ xxx = 2;

#ಅಥವಾಆದರೆ defined test_59_function_array
ಪೂರ್ಣಾಂಕ (*fct)[42](ಪೂರ್ಣಾಂಕ x);

#ಅಥವಾಆದರೆ defined test_60_enum_redefinition
ಎಣಿಕೆ color { RED, GREEN, BLUE };
ಎಣಿಕೆ color { R, G, B };
ಎಣಿಕೆ color c;

#ಅಥವಾಆದರೆ defined test_62_enumerator_redefinition
ಎಣಿಕೆ color { RED, GREEN, BLUE };
ಎಣಿಕೆ rgb { RED, G, B};
ಎಣಿಕೆ color c = RED;

#ಅಥವಾಆದರೆ defined test_63_local_enumerator_redefinition
ಎಣಿಕೆ {
    FOO,
    BAR
};

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಎಣಿಕೆ {
        FOO = 2,
        BAR
    };

    ಹಿಂತಿರುಗಿ BAR - FOO;
}

#ಅಥವಾಆದರೆ defined test_61_undefined_enum
ಎಣಿಕೆ rgb3 c = 42;

#ಅಥವಾಆದರೆ defined test_74_non_const_init
ಪೂರ್ಣಾಂಕ i = i++;

#ಅಥವಾಆದರೆ defined test_ಸೂಚಕ_assignment

ಶೂನ್ಯ (*f1)(ಶೂನ್ಯ);
ಶೂನ್ಯ f2(ಶೂನ್ಯ) {}

ರಚನೆ s1 *ps1;
ರಚನೆ s2 *ps2;

ಶೂನ್ಯ *v1, **v2, ***v3;

ಎಣಿಕೆ e1 { a = 4 } e10, *e11, *e12;
ಎಣಿಕೆ e2 { b = -4 } e20, *e21;
ಎಣಿಕೆ e3 { c = 5000000000LL } e30;

ಪೂರ್ಣಾಂಕ *ip;
ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಮೇಲೆ;
ದೀರ್ಘ *lp;
ದೀರ್ಘ ದೀರ್ಘ *llp;

ಅಕ್ಷರ **c1;
ಅಕ್ಷರ ಸ್ಥಿರಾಂಕ **c2;
ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ **u1;

ಪೂರ್ಣಾಂಕ no_main ()
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
    ಮೇಲೆ = &e10;
    ಮೇಲೆ = &e20;
    ಮೇಲೆ = &e30;

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

    ಹಿಂತಿರುಗಿ 0;
}


#ಅಥವಾಆದರೆ defined test_enum_compat
ಎಣಿಕೆ e4;
ಎಣಿಕೆ e5;
ಶೂನ್ಯ f3(ಎಣಿಕೆ e4 e);
ಶೂನ್ಯ f3(ಎಣಿಕೆ e5 e);

#ಅಥವಾಆದರೆ defined test_enum_compat_2
ಎಣಿಕೆ e6 { E1 = -1, E0 };
ಶೂನ್ಯ f3(ಎಣಿಕೆ e6);
ಶೂನ್ಯ f3(ಪೂರ್ಣಾಂಕ);        // should work as int and e6 are compatible
ಶೂನ್ಯ f4(ಎಣಿಕೆ e6 e);
ಶೂನ್ಯ f4(ಚಿಹ್ನೆರಹಿತ e); // should error as unsigned and e6 are incompatible

#ಅಥವಾಆದರೆ defined test_ptr_ಗಮ್ಯ_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಂಕ ಸ್ಥಿರಾಂಕ *[]){0}, ಪೂರ್ಣಾಂಕ:0); }
#ಅಥವಾಆದರೆ defined test_fnptr_ಗಮ್ಯ_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಂಕ (*(*)(ದಶಮಾಂಶ,ಅಕ್ಷರ))(ದ್ವಿಗುಣ,ಪೂರ್ಣಾಂಕ)){0}, ಪೂರ್ಣಾಂಕ:0); }
#ಅಥವಾಆದರೆ defined test_array_ಗಮ್ಯ_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಂಕ(*)[3]){0}, ಪೂರ್ಣಾಂಕ:0); }
#ಅಥವಾಆದರೆ defined test_duplicate_def_1
ಸ್ಥಿರ ಎಣಿಕೆ myenum { L = -1 } L;                                                
#ಅಥವಾಆದರೆ defined test_duplicate_def_2
ಶೂನ್ಯ foo(ಶೂನ್ಯ) {
ಸ್ಥಿರ ಎಣಿಕೆ myenum { L = -1 } L;                                                
}
#ಅಥವಾಆದರೆ defined test_abstract_decls
ಪೂರ್ಣಾಂಕ bar(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *());     // abstract declarator here is okay
ಪೂರ್ಣಾಂಕ bar (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *(*g)()) // should match this 'g' argument
{
  g();
  ಹಿಂತಿರುಗಿ 42;
}
ಪೂರ್ಣಾಂಕ foo(ಪೂರ್ಣಾಂಕ ())              // abstract decl is wrong in definitions
{
  ಹಿಂತಿರುಗಿ 0;
#ಅಥವಾಆದರೆ defined test_invalid_1
ಶೂನ್ಯ f(ಅಕ್ಷರ*);
ಶೂನ್ಯ g(ಶೂನ್ಯ) {
  f((ಅಕ್ಷರ[]){1, ,});
}
#ಅಥವಾಆದರೆ defined test_invalid_2
ಪೂರ್ಣಾಂಕ ga = 0.42 { 2 };
#ಅಥವಾಆದರೆ defined test_invalid_3
ರಚನೆ S { ಪೂರ್ಣಾಂಕ a, b; };
ರಚನೆ T { ರಚನೆ S x; };
ರಚನೆ T gt = { 42 a: 1, 43 };
#ಅಥವಾಆದರೆ defined test_invalid_4
ಎಣಿಕೆ E {
    x = 1 / 0
};
#ಅಥವಾಆದರೆ defined test_conflicting_types
ಪೂರ್ಣಾಂಕ i;
ಶೂನ್ಯ foo(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಂಕ i;
      {
        ಬಾಹ್ಯ ದ್ವಿಗುಣ i;
        i = 42.2;
      }
}
#ಅಥವಾಆದರೆ defined test_nested_types
ಒಕ್ಕೂಟ u {
    ಒಕ್ಕೂಟ u {
        ಪೂರ್ಣಾಂಕ i;
    } m;
};
#ಅಥವಾಆದರೆ defined test_vla_1
ಪೂರ್ಣಾಂಕ X=1;

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ t[][][X];
}
#ಅಥವಾಆದರೆ defined test_invalid_alignas
/* _Alignas is no type qualifier */
ಶೂನ್ಯ * _Alignas(16) p1;

#ಅಥವಾಆದರೆ defined test_static_assert

#ವ್ಯಾಖ್ಯಾನಿಸು ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ರಚನೆ x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#ಅಥವಾಆದರೆ defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ರಚನೆ y {  _Static_assert(0, "0"" is 0"); };

#ಅಥವಾಆದರೆ defined test_static_assert_c2x
 _Static_assert(1);
ರಚನೆ z {  _Static_assert(0); }

#ಅಥವಾಆದರೆ defined test_static_assert_ಖಾಲಿಗಳು_string
 _Static_assert(0,"");

#ಅಥವಾಆದರೆ defined test_void_array
 ಶೂನ್ಯ t[3];

#ಅಥವಾಆದರೆ defined test_incomplete_enum_array
  ಎಣಿಕೆ e t[3];

#ಅಥವಾಆದರೆ defined test_incomplete_struct_array
  ರಚನೆ s t[3];

#ಅಥವಾಆದರೆ defined test_const_fun_array
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ f(ಶೂನ್ಯ);
  ಸ್ಥಿರಾಂಕ f t[3];

#ಅಥವಾಆದರೆ defined test_incomplete_array_array
  ಪೂರ್ಣಾಂಕ t[][3]; // gr: not an error, see below

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_extern_array
ಪೂರ್ಣಾಂಕ iii[] = { 1,2,3 };
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ iii[];
ಪೂರ್ಣಾಂಕ x[];
ಪೂರ್ಣಾಂಕ x[2];
ಪೂರ್ಣಾಂಕ x[];
ಪೂರ್ಣಾಂಕ x[2];
ಪೂರ್ಣಾಂಕ x[];
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ x[2];
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ x[];
ಪೂರ್ಣಾಂಕ x[3];

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ಆದರೆ defined test_func_1
ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ);
#ಅಥವಾಆದರೆ defined test_func_4
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ);
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ () {
#ಆದರೆ defined test_func_6
    ಸ್ಥಿರ
#ಆದರೆ_ಅಂತ್ಯ
    ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ);
    hello(123);
    ಹಿಂತಿರುಗಿ 0;
}

#ಆದರೆ defined test_func_3
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ a)
#ಅಥವಾಆದರೆ defined test_func_5
ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ hello(ಪೂರ್ಣಾಂಕ a)
#ಆದರೆ_ಅಂತ್ಯ
{ ಬರೆ("%s: a = %d\n", __FUNCTION__, a); ಹಿಂತಿರುಗಿ 0; }

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#ವ್ಯಾಖ್ಯಾನಿಸು P(n,v) ಬರೆ("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ಆದರೆ defined test_var_1
ಪೂರ್ಣಾಂಕ xxx[];
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ bar();

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ ()
{
#ಆದರೆ !defined test_var_3
    ಪೂರ್ಣಾಂಕ xxx = 2;
#ಆದರೆ_ಅಂತ್ಯ
    {
        ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ xxx[
#ಆದರೆ defined test_var_3
        2
#ಆದರೆ_ಅಂತ್ಯ
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ಆದರೆ !defined test_var_3
    P(2, xxx);
#ಆದರೆ_ಅಂತ್ಯ
    bar(123);
    ಹಿಂತಿರುಗಿ 0;
}
ಪೂರ್ಣಾಂಕ xxx[1] = {1};
ಪೂರ್ಣಾಂಕ bar() { P(3, xxx[0]); ಹಿಂತಿರುಗಿ 0; }

#ಅಥವಾಆದರೆ defined test_var_4
ರಚನೆ yyy { ಪೂರ್ಣಾಂಕ y; };
ರಚನೆ zzz;
ಶೂನ್ಯ f1() {
    ಬಾಹ್ಯ ಅಕ್ಷರ *x;
    ಬಾಹ್ಯ ಅಕ್ಷರ **xx;
    ಬಾಹ್ಯ ರಚನೆ yyy y;
    ಬಾಹ್ಯ ರಚನೆ yyy *yy;
    ಬಾಹ್ಯ ರಚನೆ zzz z;
    ಬಾಹ್ಯ ರಚನೆ zzz *zz;
}
ಶೂನ್ಯ f2() {
    ಬಾಹ್ಯ ಅಕ್ಷರ *x;
    ಬಾಹ್ಯ ಅಕ್ಷರ **xx;
    ಬಾಹ್ಯ ರಚನೆ yyy y;
    ಬಾಹ್ಯ ರಚನೆ yyy *yy;
    ಬಾಹ್ಯ ರಚನೆ zzz z;
    ಬಾಹ್ಯ ರಚನೆ zzz *zz;
}
ರಚನೆ yyy y, *yy;
ರಚನೆ zzz { ಪೂರ್ಣಾಂಕ z; } z, *zz;

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_long_double_type_for_win32

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ದ್ವಿಗುಣ *a = 0;
    ದೀರ್ಘ ದ್ವಿಗುಣ *b = a;
    ಪೂರ್ಣಾಂಕ n = _Generic(*a, ದ್ವಿಗುಣ:0, ದೀರ್ಘ ದ್ವಿಗುಣ:1);
}

#ಅಥವಾಆದರೆ defined test_stray_backslash
#ವ್ಯಾಖ್ಯಾನಿಸು x \a
x

#ಅಥವಾಆದರೆ defined test_stray_backslash2

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
#ವ್ಯಾಖ್ಯಾನಿಸು _S(x) #x
#ವ್ಯಾಖ್ಯಾನಿಸು S(x) _S(x)
    ಬರೆ("%sn\n", S(\\));
}

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_var_array

ಸ್ಥಿರ ರಚನೆ var_len { ಪೂರ್ಣಾಂಕ i; ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#ಅಥವಾಆದರೆ defined test_var_array2

ರಚನೆ c1 { ಪೂರ್ಣಾಂಕ a; ಪೂರ್ಣಾಂಕ b[]; };
ರಚನೆ c1 c1 = { 1, { 2, 3, 4 } };

ರಚನೆ c2 { ಪೂರ್ಣಾಂಕ c; ರಚನೆ c1 c1; };
ರಚನೆ c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#ಅಥವಾಆದರೆ defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ರಚನೆ A { ಪೂರ್ಣಾಂಕ a; ಅಕ್ಷರ b[]; };
ರಚನೆ A a = { 1, "1" };
ರಚನೆ B { ರಚನೆ A a; };
ರಚನೆ B b = { { 1, "1" } };
/******************************************************************/
#ಅಥವಾಆದರೆ defined test_default_int_type
n; // warn
f(); // don't warn

#ಅಥವಾಆದರೆ defined test_invalid_global_stmtexpr
n[ಗಾತ್ರ({3;})]; // crashed in block() due to missing local scope

#ಅಥವಾಆದರೆ defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_duplicate_member
ರಚನೆ S {
  ಪೂರ್ಣಾಂಕ a, a;
};
#ಅಥವಾಆದರೆ defined test_duplicate_member_anon
ರಚನೆ S1 {
  ಪೂರ್ಣಾಂಕ b;
  ರಚನೆ {
    ಪೂರ್ಣಾಂಕ b;
  } c;
};
ರಚನೆ S2 {
  ಪೂರ್ಣಾಂಕ d;
  ರಚನೆ {
    ಪೂರ್ಣಾಂಕ d;
  };
};

/******************************************************************/
#ಅಥವಾಆದರೆ defined test_conflicting_array_definition
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ array[2];
ಪೂರ್ಣಾಂಕ array[] = { 1, 2, 3 };

#ಅಥವಾಆದರೆ defined test_incompatible_local_redef
ಶೂನ್ಯ foo (ಶೂನ್ಯ)
{
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ localfunctype (ಪೂರ್ಣಾಂಕ);
  ಬಾಹ್ಯ localfunctype func2;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ localfunctype (ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ);
}

#ಅಥವಾಆದರೆ defined test_cast_from_void
ಶೂನ್ಯ v() {}
ಪೂರ್ಣಾಂಕ f() { ಹಿಂತಿರುಗಿ v(); }

#ಅಥವಾಆದರೆ defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ಆದರೆ defined test_switch_W1
#ಸೂಚನೆ comment(option, "-Wall")
#ಅಥವಾಆದರೆ defined test_switch_W2
#ಸೂಚನೆ comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#ಅಥವಾಆದರೆ defined test_switch_W3
#ಸೂಚನೆ comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#ಅಥವಾಆದರೆ defined test_switch_W4
#ಸೂಚನೆ comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#ಆದರೆ_ಅಂತ್ಯ
ಶೂನ್ಯ func(ಶೂನ್ಯ)
{
    ಅಕ್ಷರ *ccp = "123";
    fink();
}
__attribute__((stuff)) ಪೂರ್ಣಾಂಕ fink() {ಹಿಂತಿರುಗಿ 0;}

#ಅಥವಾಆದರೆ defined test_invalid_funcparam_1
ಶೂನ್ಯ func(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ a);

#ಅಥವಾಆದರೆ defined test_invalid_funcparam_2
ಶೂನ್ಯ func(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ ಆದರೆ);

#ಅಥವಾಆದರೆ defined test_array_funcparam
ಪೂರ್ಣಾಂಕ amain(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ *argv[ಸ್ಥಿರ argc + 1])
{
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 0; i < argc; ++i)
        ಬರೆ("arg[%d] = \"%s\"\n", i, argv[i]);
    ಹಿಂತಿರುಗಿ 0;
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಹಿಂತಿರುಗಿ amain(2, (ಅಕ್ಷರ *[]){ "X", "Y", 0 });
}

#ಅಥವಾಆದರೆ defined test_return_from_statement_ಅಭಿವ್ಯಕ್ತಿ
ಪೂರ್ಣಾಂಕ f() { ({ ಹಿಂತಿರುಗಿ 78; }); }
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ() { ಹಿಂತಿರುಗಿ f(); }

/******************************************************************/

#ಅಥವಾಆದರೆ defined test_illegal_unicode
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ() {
    ಅಕ್ಷರ *str = "\Uffffffff";
}

#ಅಥವಾಆದರೆ defined test_error_string
#ದೋಷ \123\\
456

#ಅಥವಾಆದರೆ defined test_error_incomplete_type
ರಚನೆ A;
ಶೂನ್ಯ f(ರಚನೆ A *);

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    f(&(ರಚನೆ A){});
}

ರಚನೆ A {
    ಪೂರ್ಣಾಂಕ x;
};

#ಅಥವಾಆದರೆ defined test_pp_error_1
# ಆದರೆ //no expression
# endif
#ಅಥವಾಆದರೆ defined test_pp_error_2
# ಆದರೆ X(1,2) //undefined function macro
# endif

#ಅಥವಾಆದರೆ defined test_ಸೂಚಕ_plus_double

ಪೂರ್ಣಾಂಕ *invalid_operation(ಪೂರ್ಣಾಂಕ *p, ದ್ವಿಗುಣ d)
{
    ಹಿಂತಿರುಗಿ p + d;
}

#ಅಥವಾಆದರೆ defined test_duplicate_case

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x;
    ಆಯ್ಕೆ (x) {
        ಸ್ಥಿತಿ -1 ... 0: /* empty case range with unsigned */
        ಸ್ಥಿತಿ 3:
        ಸ್ಥಿತಿ 1:
        ಸ್ಥಿತಿ 2:
        ಸ್ಥಿತಿ 3: /* show this line number in error */
        ಸ್ಥಿತಿ 4:
        ಸ್ಥಿತಿ 5:
    }
}
#ಅಥವಾಆದರೆ defined test_ಸಾಮಾನ್ಯ_funcargs || defined test_ಹಿಮ್ಮುಖ_funcargs

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ test_ಹಿಮ್ಮುಖ_funcargs
# pragma comment(option, "-freverse-funcargs")
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಬರೆ(" %d %d %d\n", ಬರೆ("1"), ಬರೆ("22"), ಬರೆ("333"));
}

#ಅಥವಾಆದರೆ defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ರಚನೆ xxx {ಪೂರ್ಣಾಂಕ x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
ಪೂರ್ಣಾಂಕ bar(ಎಣಿಕೆ ee { a = 12, b = 34 } i, ಪೂರ್ಣಾಂಕ(*f)(ಪೂರ್ಣಾಂಕ i))
{
    ಬರೆ("bar %d %d %d\n", i, a, b);
    ಹಿಂತಿರುಗಿ 0;
}
/* 'xxx' not defined outside of function */
ಪೂರ್ಣಾಂಕ foo(ರಚನೆ xxx {ಪೂರ್ಣಾಂಕ x[3];}*p)
{
    ಬರೆ("foo %d", ಗಾತ್ರ *p);
    ಹಿಂತಿರುಗಿ p->x[3];
}
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ test_scope_2
/* incompatible redefinition */
ಪೂರ್ಣಾಂಕ foo(ರಚನೆ xxx {ಪೂರ್ಣಾಂಕ x[2];}*p);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ test_scope_3
ಎಣಿಕೆ ee { a = 1, b };
#ಆದರೆ_ಅಂತ್ಯ

ರಚನೆ xxx x = { 11,22,33,44 };
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಬರೆ(" %d %d\n", foo(&x), ಗಾತ್ರ (ರಚನೆ xxx));
    ಎಣಿಕೆ ee e = b;
    bar(13 + e, 0);

}

#ಅಥವಾಆದರೆ defined test_const_array_member_addr_ok

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

int_array ಸ್ಥಿರಾಂಕ *get_array(ಸ್ಥಿರಾಂಕ my_struct *s)
{
    ಹಿಂತಿರುಗಿ &(s->arr);
}

#ಅಥವಾಆದರೆ defined test_const_array_member_decay_ok

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *good_decay(ಸ್ಥಿರಾಂಕ my_struct *s)
{
    ಹಿಂತಿರುಗಿ s->arr;
}

#ಅಥವಾಆದರೆ defined test_const_array_member_addr_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

int_array *bad_array_addr(ಸ್ಥಿರಾಂಕ my_struct *s)
{
    ಹಿಂತಿರುಗಿ &(s->arr);
}

#ಅಥವಾಆದರೆ defined test_const_array_member_decay_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಪೂರ್ಣಾಂಕ *bad_decay(ಸ್ಥಿರಾಂಕ my_struct *s)
{
    ಹಿಂತಿರುಗಿ s->arr;
}

#ಅಥವಾಆದರೆ defined test_const_array_member_write_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಶೂನ್ಯ bad_write(ಸ್ಥಿರಾಂಕ my_struct *s)
{
    s->arr[0] = 1;
}

#ಅಥವಾಆದರೆ defined test_const_struct_array_member_write_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ x; } inner;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { inner arr[1]; } outer;

ಶೂನ್ಯ bad_inner_write(ಸ್ಥಿರಾಂಕ outer *s)
{
    s->arr[0].x = 1;
}

#ಅಥವಾಆದರೆ defined test_volatile_array_member_addr_ok

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

int_array ಅಸ್ಥಿರ *get_volatile_array(ಅಸ್ಥಿರ my_struct *s)
{
    ಹಿಂತಿರುಗಿ &(s->arr);
}

#ಅಥವಾಆದರೆ defined test_volatile_array_member_decay_ok

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ *good_volatile_decay(ಅಸ್ಥಿರ my_struct *s)
{
    ಹಿಂತಿರುಗಿ s->arr;
}

#ಅಥವಾಆದರೆ defined test_volatile_array_member_addr_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(ಅಸ್ಥಿರ my_struct *s)
{
    ಹಿಂತಿರುಗಿ &(s->arr);
}

#ಅಥವಾಆದರೆ defined test_volatile_array_member_decay_bad

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಪೂರ್ಣಾಂಕ *bad_volatile_decay(ಅಸ್ಥಿರ my_struct *s)
{
    ಹಿಂತಿರುಗಿ s->arr;
}

#ಅಥವಾಆದರೆ defined test_volatile_array_member_write_ok

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ int_array[1];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { int_array arr; } my_struct;

ಶೂನ್ಯ good_volatile_write(ಅಸ್ಥಿರ my_struct *s)
{
    s->arr[0] = 1;
}

#ಅಥವಾಆದರೆ defined test_conditional_array_qualifiers

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ Array2[2];
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ Array2x3[2][3];

Array2 *p;
ಸ್ಥಿರಾಂಕ Array2 *cp;
ಸ್ಥಿರಾಂಕ Array2x3 *cap;
ಅಸ್ಥಿರ Array2x3 *vap;

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#ಅಥವಾಆದರೆ defined test_restrict_scalar

ಸೀಮಿತ ಪೂರ್ಣಾಂಕ object;

#ಅಥವಾಆದರೆ defined test_restrict_function_ಸೂಚಕ

ಪೂರ್ಣಾಂಕ (*ಸೀಮಿತ function_ಸೂಚಕ)(ಶೂನ್ಯ);

#ಅಥವಾಆದರೆ defined test_discarded_restrict

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ *ಸೀಮಿತ restricted_ಸೂಚಕ;

restricted_ಸೂಚಕ *ಮೂಲ;
ಪೂರ್ಣಾಂಕ **destination;

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    destination = ಮೂಲ;
}

#ಆದರೆ_ಅಂತ್ಯ

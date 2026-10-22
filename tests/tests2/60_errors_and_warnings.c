ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);

#ಯದಿ defined test_56_btype_excess_1
ಸಂರಚನಾ A {} ಪೂರ್ಣಾಙ್ಕ i;
#ನೋಚೇದ್ಯದಿ defined test_57_btype_excess_2
ವರ್ಣ ಪೂರ್ಣಾಙ್ಕ i;
#ನೋಚೇದ್ಯದಿ defined test_58_function_redefinition
ಪೂರ್ಣಾಙ್ಕ f(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 0; }
ಪೂರ್ಣಾಙ್ಕ f(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 1; }

#ನೋಚೇದ್ಯದಿ defined test_global_redefinition
ಪೂರ್ಣಾಙ್ಕ xxx = 1;
ಪೂರ್ಣಾಙ್ಕ xxx;
ಪೂರ್ಣಾಙ್ಕ xxx = 2;

#ನೋಚೇದ್ಯದಿ defined test_59_function_array
ಪೂರ್ಣಾಙ್ಕ (*fct)[42](ಪೂರ್ಣಾಙ್ಕ x);

#ನೋಚೇದ್ಯದಿ defined test_60_enum_redefinition
ಗಣನಾ color { RED, GREEN, BLUE };
ಗಣನಾ color { R, G, B };
ಗಣನಾ color c;

#ನೋಚೇದ್ಯದಿ defined test_62_enumerator_redefinition
ಗಣನಾ color { RED, GREEN, BLUE };
ಗಣನಾ rgb { RED, G, B};
ಗಣನಾ color c = RED;

#ನೋಚೇದ್ಯದಿ defined test_63_local_enumerator_redefinition
ಗಣನಾ {
    FOO,
    BAR
};

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ಗಣನಾ {
        FOO = 2,
        BAR
    };

    ಪ್ರತ್ಯಾಗಮ BAR - FOO;
}

#ನೋಚೇದ್ಯದಿ defined test_61_undefined_enum
ಗಣನಾ rgb3 c = 42;

#ನೋಚೇದ್ಯದಿ defined test_74_non_const_init
ಪೂರ್ಣಾಙ್ಕ i = i++;

#ನೋಚೇದ್ಯದಿ defined test_pointer_assignment

ಶೂನ್ಯ (*f1)(ಶೂನ್ಯ);
ಶೂನ್ಯ f2(ಶೂನ್ಯ) {}

ಸಂರಚನಾ s1 *ps1;
ಸಂರಚನಾ s2 *ps2;

ಶೂನ್ಯ *v1, **v2, ***v3;

ಗಣನಾ e1 { a = 4 } e10, *e11, *e12;
ಗಣನಾ e2 { b = -4 } e20, *e21;
ಗಣನಾ e3 { c = 5000000000LL } e30;

ಪೂರ್ಣಾಙ್ಕ *ip;
unsigned ಪೂರ್ಣಾಙ್ಕ *up;
long *lp;
long long *llp;

ವರ್ಣ **c1;
ವರ್ಣ ಧ್ರುವ **c2;
unsigned ವರ್ಣ **u1;

ಪೂರ್ಣಾಙ್ಕ no_main ()
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
    up = &e10;
    up = &e20;
    up = &e30;

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

    ಪ್ರತ್ಯಾಗಮ 0;
}


#ನೋಚೇದ್ಯದಿ defined test_enum_compat
ಗಣನಾ e4;
ಗಣನಾ e5;
ಶೂನ್ಯ f3(ಗಣನಾ e4 e);
ಶೂನ್ಯ f3(ಗಣನಾ e5 e);

#ನೋಚೇದ್ಯದಿ defined test_enum_compat_2
ಗಣನಾ e6 { E1 = -1, E0 };
ಶೂನ್ಯ f3(ಗಣನಾ e6);
ಶೂನ್ಯ f3(ಪೂರ್ಣಾಙ್ಕ);        // should work as int and e6 are compatible
ಶೂನ್ಯ f4(ಗಣನಾ e6 e);
ಶೂನ್ಯ f4(unsigned e); // should error as unsigned and e6 are incompatible

#ನೋಚೇದ್ಯದಿ defined test_ptr_to_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಙ್ಕ ಧ್ರುವ *[]){0}, ಪೂರ್ಣಾಙ್ಕ:0); }
#ನೋಚೇದ್ಯದಿ defined test_fnptr_to_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಙ್ಕ (*(*)(ಭಿನ್ನ,ವರ್ಣ))(ದ್ವಿಗುಣ,ಪೂರ್ಣಾಙ್ಕ)){0}, ಪೂರ್ಣಾಙ್ಕ:0); }
#ನೋಚೇದ್ಯದಿ defined test_array_to_str
ಶೂನ್ಯ f() { _Generic((ಪೂರ್ಣಾಙ್ಕ(*)[3]){0}, ಪೂರ್ಣಾಙ್ಕ:0); }
#ನೋಚೇದ್ಯದಿ defined test_duplicate_def_1
ಸ್ಥಿರ ಗಣನಾ myenum { L = -1 } L;                                                
#ನೋಚೇದ್ಯದಿ defined test_duplicate_def_2
ಶೂನ್ಯ foo(ಶೂನ್ಯ) {
ಸ್ಥಿರ ಗಣನಾ myenum { L = -1 } L;                                                
}
#ನೋಚೇದ್ಯದಿ defined test_abstract_decls
ಪೂರ್ಣಾಙ್ಕ bar(ಧ್ರುವ ವರ್ಣ *());     // abstract declarator here is okay
ಪೂರ್ಣಾಙ್ಕ bar (ಧ್ರುವ ವರ್ಣ *(*g)()) // should match this 'g' argument
{
  g();
  ಪ್ರತ್ಯಾಗಮ 42;
}
ಪೂರ್ಣಾಙ್ಕ foo(ಪೂರ್ಣಾಙ್ಕ ())              // abstract decl is wrong in definitions
{
  ಪ್ರತ್ಯಾಗಮ 0;
#ನೋಚೇದ್ಯದಿ defined test_invalid_1
ಶೂನ್ಯ f(ವರ್ಣ*);
ಶೂನ್ಯ g(ಶೂನ್ಯ) {
  f((ವರ್ಣ[]){1, ,});
}
#ನೋಚೇದ್ಯದಿ defined test_invalid_2
ಪೂರ್ಣಾಙ್ಕ ga = 0.42 { 2 };
#ನೋಚೇದ್ಯದಿ defined test_invalid_3
ಸಂರಚನಾ S { ಪೂರ್ಣಾಙ್ಕ a, b; };
ಸಂರಚನಾ T { ಸಂರಚನಾ S x; };
ಸಂರಚನಾ T gt = { 42 a: 1, 43 };
#ನೋಚೇದ್ಯದಿ defined test_invalid_4
ಗಣನಾ E {
    x = 1 / 0
};
#ನೋಚೇದ್ಯದಿ defined test_conflicting_types
ಪೂರ್ಣಾಙ್ಕ i;
ಶೂನ್ಯ foo(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಙ್ಕ i;
      {
        ಬಾಹ್ಯ ದ್ವಿಗುಣ i;
        i = 42.2;
      }
}
#ನೋಚೇದ್ಯದಿ defined test_nested_types
ಸಙ್ಘ u {
    ಸಙ್ಘ u {
        ಪೂರ್ಣಾಙ್ಕ i;
    } m;
};
#ನೋಚೇದ್ಯದಿ defined test_vla_1
ಪೂರ್ಣಾಙ್ಕ X=1;

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಙ್ಕ t[][][X];
}
#ನೋಚೇದ್ಯದಿ defined test_invalid_alignas
/* _Alignas is no type qualifier */
ಶೂನ್ಯ * _Alignas(16) p1;

#ನೋಚೇದ್ಯದಿ defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ಸಂರಚನಾ x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#ನೋಚೇದ್ಯದಿ defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ಸಂರಚನಾ y {  _Static_assert(0, "0"" is 0"); };

#ನೋಚೇದ್ಯದಿ defined test_static_assert_c2x
 _Static_assert(1);
ಸಂರಚನಾ z {  _Static_assert(0); }

#ನೋಚೇದ್ಯದಿ defined test_static_assert_empty_string
 _Static_assert(0,"");

#ನೋಚೇದ್ಯದಿ defined test_void_array
 ಶೂನ್ಯ t[3];

#ನೋಚೇದ್ಯದಿ defined test_incomplete_enum_array
  ಗಣನಾ e t[3];

#ನೋಚೇದ್ಯದಿ defined test_incomplete_struct_array
  ಸಂರಚನಾ s t[3];

#ನೋಚೇದ್ಯದಿ defined test_const_fun_array
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ f(ಶೂನ್ಯ);
  ಧ್ರುವ f t[3];

#ನೋಚೇದ್ಯದಿ defined test_incomplete_array_array
  ಪೂರ್ಣಾಙ್ಕ t[][3]; // gr: not an error, see below

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_extern_array
ಪೂರ್ಣಾಙ್ಕ iii[] = { 1,2,3 };
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ iii[];
ಪೂರ್ಣಾಙ್ಕ x[];
ಪೂರ್ಣಾಙ್ಕ x[2];
ಪೂರ್ಣಾಙ್ಕ x[];
ಪೂರ್ಣಾಙ್ಕ x[2];
ಪೂರ್ಣಾಙ್ಕ x[];
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ x[2];
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ x[];
ಪೂರ್ಣಾಙ್ಕ x[3];

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ಯದಿ defined test_func_1
ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ);
#ನೋಚೇದ್ಯದಿ defined test_func_4
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ);
#endif
ಪೂರ್ಣಾಙ್ಕ main () {
#ಯದಿ defined test_func_6
    ಸ್ಥಿರ
#endif
    ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ);
    hello(123);
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ಯದಿ defined test_func_3
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ a)
#ನೋಚೇದ್ಯದಿ defined test_func_5
ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
#ಅನ್ಯಥಾ
ಪೂರ್ಣಾಙ್ಕ hello(ಪೂರ್ಣಾಙ್ಕ a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); ಪ್ರತ್ಯಾಗಮ 0; }

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ಯದಿ defined test_var_1
ಪೂರ್ಣಾಙ್ಕ xxx[];
#endif
ಪೂರ್ಣಾಙ್ಕ bar();

ಪೂರ್ಣಾಙ್ಕ main ()
{
#ಯದಿ !defined test_var_3
    ಪೂರ್ಣಾಙ್ಕ xxx = 2;
#endif
    {
        ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ xxx[
#ಯದಿ defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ಯದಿ !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    ಪ್ರತ್ಯಾಗಮ 0;
}
ಪೂರ್ಣಾಙ್ಕ xxx[1] = {1};
ಪೂರ್ಣಾಙ್ಕ bar() { P(3, xxx[0]); ಪ್ರತ್ಯಾಗಮ 0; }

#ನೋಚೇದ್ಯದಿ defined test_var_4
ಸಂರಚನಾ yyy { ಪೂರ್ಣಾಙ್ಕ y; };
ಸಂರಚನಾ zzz;
ಶೂನ್ಯ f1() {
    ಬಾಹ್ಯ ವರ್ಣ *x;
    ಬಾಹ್ಯ ವರ್ಣ **xx;
    ಬಾಹ್ಯ ಸಂರಚನಾ yyy y;
    ಬಾಹ್ಯ ಸಂರಚನಾ yyy *yy;
    ಬಾಹ್ಯ ಸಂರಚನಾ zzz z;
    ಬಾಹ್ಯ ಸಂರಚನಾ zzz *zz;
}
ಶೂನ್ಯ f2() {
    ಬಾಹ್ಯ ವರ್ಣ *x;
    ಬಾಹ್ಯ ವರ್ಣ **xx;
    ಬಾಹ್ಯ ಸಂರಚನಾ yyy y;
    ಬಾಹ್ಯ ಸಂರಚನಾ yyy *yy;
    ಬಾಹ್ಯ ಸಂರಚನಾ zzz z;
    ಬಾಹ್ಯ ಸಂರಚನಾ zzz *zz;
}
ಸಂರಚನಾ yyy y, *yy;
ಸಂರಚನಾ zzz { ಪೂರ್ಣಾಙ್ಕ z; } z, *zz;

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_long_double_type_for_win32

ಪೂರ್ಣಾಙ್ಕ main()
{
    ದ್ವಿಗುಣ *a = 0;
    long ದ್ವಿಗುಣ *b = a;
    ಪೂರ್ಣಾಙ್ಕ n = _Generic(*a, ದ್ವಿಗುಣ:0, long ದ್ವಿಗುಣ:1);
}

#ನೋಚೇದ್ಯದಿ defined test_stray_backslash
#define x \a
x

#ನೋಚೇದ್ಯದಿ defined test_stray_backslash2

ಪೂರ್ಣಾಙ್ಕ main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_var_array

ಸ್ಥಿರ ಸಂರಚನಾ var_len { ಪೂರ್ಣಾಙ್ಕ i; ಧ್ರುವ ವರ್ಣ str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#ನೋಚೇದ್ಯದಿ defined test_var_array2

ಸಂರಚನಾ c1 { ಪೂರ್ಣಾಙ್ಕ a; ಪೂರ್ಣಾಙ್ಕ b[]; };
ಸಂರಚನಾ c1 c1 = { 1, { 2, 3, 4 } };

ಸಂರಚನಾ c2 { ಪೂರ್ಣಾಙ್ಕ c; ಸಂರಚನಾ c1 c1; };
ಸಂರಚನಾ c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#ನೋಚೇದ್ಯದಿ defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ಸಂರಚನಾ A { ಪೂರ್ಣಾಙ್ಕ a; ವರ್ಣ b[]; };
ಸಂರಚನಾ A a = { 1, "1" };
ಸಂರಚನಾ B { ಸಂರಚನಾ A a; };
ಸಂರಚನಾ B b = { { 1, "1" } };
/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_default_int_type
n; // warn
f(); // don't warn

#ನೋಚೇದ್ಯದಿ defined test_invalid_global_stmtexpr
n[ಪರಿಮಾಣ({3;})]; // crashed in block() due to missing local scope

#ನೋಚೇದ್ಯದಿ defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_duplicate_member
ಸಂರಚನಾ S {
  ಪೂರ್ಣಾಙ್ಕ a, a;
};
#ನೋಚೇದ್ಯದಿ defined test_duplicate_member_anon
ಸಂರಚನಾ S1 {
  ಪೂರ್ಣಾಙ್ಕ b;
  ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ b;
  } c;
};
ಸಂರಚನಾ S2 {
  ಪೂರ್ಣಾಙ್ಕ d;
  ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ d;
  };
};

/******************************************************************/
#ನೋಚೇದ್ಯದಿ defined test_conflicting_array_definition
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ array[2];
ಪೂರ್ಣಾಙ್ಕ array[] = { 1, 2, 3 };

#ನೋಚೇದ್ಯದಿ defined test_incompatible_local_redef
ಶೂನ್ಯ foo (ಶೂನ್ಯ)
{
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ localfunctype (ಪೂರ್ಣಾಙ್ಕ);
  ಬಾಹ್ಯ localfunctype func2;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ localfunctype (ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ);
}

#ನೋಚೇದ್ಯದಿ defined test_cast_from_void
ಶೂನ್ಯ v() {}
ಪೂರ್ಣಾಙ್ಕ f() { ಪ್ರತ್ಯಾಗಮ v(); }

#ನೋಚೇದ್ಯದಿ defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ಯದಿ defined test_switch_W1
#pragma comment(option, "-Wall")
#ನೋಚೇದ್ಯದಿ defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#ನೋಚೇದ್ಯದಿ defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#ನೋಚೇದ್ಯದಿ defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
ಶೂನ್ಯ func(ಶೂನ್ಯ)
{
    ವರ್ಣ *ccp = "123";
    fink();
}
__attribute__((stuff)) ಪೂರ್ಣಾಙ್ಕ fink() {ಪ್ರತ್ಯಾಗಮ 0;}

#ನೋಚೇದ್ಯದಿ defined test_invalid_funcparam_1
ಶೂನ್ಯ func(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ a);

#ನೋಚೇದ್ಯದಿ defined test_invalid_funcparam_2
ಶೂನ್ಯ func(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ ಯದಿ);

#ನೋಚೇದ್ಯದಿ defined test_array_funcparam
ಪೂರ್ಣಾಙ್ಕ amain(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ *argv[ಸ್ಥಿರ argc + 1])
{
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    ಪ್ರತ್ಯಾಗಮ 0;
}
ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪ್ರತ್ಯಾಗಮ amain(2, (ವರ್ಣ *[]){ "X", "Y", 0 });
}

#ನೋಚೇದ್ಯದಿ defined test_return_from_statement_ಅಭಿವ್ಯಕ್ತಿ
ಪೂರ್ಣಾಙ್ಕ f() { ({ ಪ್ರತ್ಯಾಗಮ 78; }); }
ಪೂರ್ಣಾಙ್ಕ main() { ಪ್ರತ್ಯಾಗಮ f(); }

/******************************************************************/

#ನೋಚೇದ್ಯದಿ defined test_illegal_unicode
ಪೂರ್ಣಾಙ್ಕ main() {
    ವರ್ಣ *str = "\Uffffffff";
}

#ನೋಚೇದ್ಯದಿ defined test_error_string
#error \123\\
456

#ನೋಚೇದ್ಯದಿ defined test_error_incomplete_type
ಸಂರಚನಾ A;
ಶೂನ್ಯ f(ಸಂರಚನಾ A *);

ಪೂರ್ಣಾಙ್ಕ main()
{
    f(&(ಸಂರಚನಾ A){});
}

ಸಂರಚನಾ A {
    ಪೂರ್ಣಾಙ್ಕ x;
};

#ನೋಚೇದ್ಯದಿ defined test_pp_error_1
# ಯದಿ //no expression
# endif
#ನೋಚೇದ್ಯದಿ defined test_pp_error_2
# ಯದಿ X(1,2) //undefined function macro
# endif

#ನೋಚೇದ್ಯದಿ defined test_pointer_plus_double

ಪೂರ್ಣಾಙ್ಕ *invalid_operation(ಪೂರ್ಣಾಙ್ಕ *p, ದ್ವಿಗುಣ d)
{
    ಪ್ರತ್ಯಾಗಮ p + d;
}

#ನೋಚೇದ್ಯದಿ defined test_duplicate_case

ಪೂರ್ಣಾಙ್ಕ main()
{
    unsigned ಪೂರ್ಣಾಙ್ಕ x;
    ವಿಕಲ್ಪ (x) {
        ಪಕ್ಷ -1 ... 0: /* empty case range with unsigned */
        ಪಕ್ಷ 3:
        ಪಕ್ಷ 1:
        ಪಕ್ಷ 2:
        ಪಕ್ಷ 3: /* show this line number in error */
        ಪಕ್ಷ 4:
        ಪಕ್ಷ 5:
    }
}
#ನೋಚೇದ್ಯದಿ defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

ಪೂರ್ಣಾಙ್ಕ main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#ನೋಚೇದ್ಯದಿ defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ಸಂರಚನಾ xxx {ಪೂರ್ಣಾಙ್ಕ x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
ಪೂರ್ಣಾಙ್ಕ bar(ಗಣನಾ ee { a = 12, b = 34 } i, ಪೂರ್ಣಾಙ್ಕ(*f)(ಪೂರ್ಣಾಙ್ಕ i))
{
    printf("bar %d %d %d\n", i, a, b);
    ಪ್ರತ್ಯಾಗಮ 0;
}
/* 'xxx' not defined outside of function */
ಪೂರ್ಣಾಙ್ಕ foo(ಸಂರಚನಾ xxx {ಪೂರ್ಣಾಙ್ಕ x[3];}*p)
{
    printf("foo %d", ಪರಿಮಾಣ *p);
    ಪ್ರತ್ಯಾಗಮ p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
ಪೂರ್ಣಾಙ್ಕ foo(ಸಂರಚನಾ xxx {ಪೂರ್ಣಾಙ್ಕ x[2];}*p);
#endif
#ifndef test_scope_3
ಗಣನಾ ee { a = 1, b };
#endif

ಸಂರಚನಾ xxx x = { 11,22,33,44 };
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    printf(" %d %d\n", foo(&x), ಪರಿಮಾಣ (ಸಂರಚನಾ xxx));
    ಗಣನಾ ee e = b;
    bar(13 + e, 0);

}

#ನೋಚೇದ್ಯದಿ defined test_const_array_member_addr_ok

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

int_array ಧ್ರುವ *get_array(ಧ್ರುವ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ &(s->arr);
}

#ನೋಚೇದ್ಯದಿ defined test_const_array_member_decay_ok

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *good_decay(ಧ್ರುವ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ s->arr;
}

#ನೋಚೇದ್ಯದಿ defined test_const_array_member_addr_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

int_array *bad_array_addr(ಧ್ರುವ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ &(s->arr);
}

#ನೋಚೇದ್ಯದಿ defined test_const_array_member_decay_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಪೂರ್ಣಾಙ್ಕ *bad_decay(ಧ್ರುವ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ s->arr;
}

#ನೋಚೇದ್ಯದಿ defined test_const_array_member_write_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಶೂನ್ಯ bad_write(ಧ್ರುವ my_struct *s)
{
    s->arr[0] = 1;
}

#ನೋಚೇದ್ಯದಿ defined test_const_struct_array_member_write_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x; } inner;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { inner arr[1]; } outer;

ಶೂನ್ಯ bad_inner_write(ಧ್ರುವ outer *s)
{
    s->arr[0].x = 1;
}

#ನೋಚೇದ್ಯದಿ defined test_volatile_array_member_addr_ok

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

int_array ಚಞ್ಚಲ *get_volatile_array(ಚಞ್ಚಲ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ &(s->arr);
}

#ನೋಚೇದ್ಯದಿ defined test_volatile_array_member_decay_ok

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ *good_volatile_decay(ಚಞ್ಚಲ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ s->arr;
}

#ನೋಚೇದ್ಯದಿ defined test_volatile_array_member_addr_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(ಚಞ್ಚಲ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ &(s->arr);
}

#ನೋಚೇದ್ಯದಿ defined test_volatile_array_member_decay_bad

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಪೂರ್ಣಾಙ್ಕ *bad_volatile_decay(ಚಞ್ಚಲ my_struct *s)
{
    ಪ್ರತ್ಯಾಗಮ s->arr;
}

#ನೋಚೇದ್ಯದಿ defined test_volatile_array_member_write_ok

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_array[1];
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { int_array arr; } my_struct;

ಶೂನ್ಯ good_volatile_write(ಚಞ್ಚಲ my_struct *s)
{
    s->arr[0] = 1;
}

#ನೋಚೇದ್ಯದಿ defined test_conditional_array_qualifiers

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ Array2[2];
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ Array2x3[2][3];

Array2 *p;
ಧ್ರುವ Array2 *cp;
ಧ್ರುವ Array2x3 *cap;
ಚಞ್ಚಲ Array2x3 *vap;

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#ನೋಚೇದ್ಯದಿ defined test_restrict_scalar

restrict ಪೂರ್ಣಾಙ್ಕ object;

#ನೋಚೇದ್ಯದಿ defined test_restrict_function_pointer

ಪೂರ್ಣಾಙ್ಕ (*restrict function_pointer)(ಶೂನ್ಯ);

#ನೋಚೇದ್ಯದಿ defined test_discarded_restrict

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *restrict restricted_pointer;

restricted_pointer *source;
ಪೂರ್ಣಾಙ್ಕ **destination;

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    destination = source;
}

#endif

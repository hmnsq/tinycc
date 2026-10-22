ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);

#ଯଦି defined test_56_btype_excess_1
ସଂରଚନା A {} ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
#ନଚେତଯଦି defined test_57_btype_excess_2
ଅକ୍ଷର ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
#ନଚେତଯଦି defined test_58_function_redefinition
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 0; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 1; }

#ନଚେତଯଦି defined test_global_redefinition
ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx = 1;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx = 2;

#ନଚେତଯଦି defined test_59_function_array
ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*fct)[42](ପୂର୍ଣ୍ଣସଂଖ୍ୟା x);

#ନଚେତଯଦି defined test_60_enum_redefinition
ଗଣନା color { RED, GREEN, BLUE };
ଗଣନା color { R, G, B };
ଗଣନା color c;

#ନଚେତଯଦି defined test_62_enumerator_redefinition
ଗଣନା color { RED, GREEN, BLUE };
ଗଣନା rgb { RED, G, B};
ଗଣନା color c = RED;

#ନଚେତଯଦି defined test_63_local_enumerator_redefinition
ଗଣନା {
    FOO,
    BAR
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ଗଣନା {
        FOO = 2,
        BAR
    };

    ଫେରନ୍ତୁ BAR - FOO;
}

#ନଚେତଯଦି defined test_61_undefined_enum
ଗଣନା rgb3 c = 42;

#ନଚେତଯଦି defined test_74_non_const_init
ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = i++;

#ନଚେତଯଦି defined test_pointer_assignment

ଶୂନ୍ୟ (*f1)(ଶୂନ୍ୟ);
ଶୂନ୍ୟ f2(ଶୂନ୍ୟ) {}

ସଂରଚନା s1 *ps1;
ସଂରଚନା s2 *ps2;

ଶୂନ୍ୟ *v1, **v2, ***v3;

ଗଣନା e1 { a = 4 } e10, *e11, *e12;
ଗଣନା e2 { b = -4 } e20, *e21;
ଗଣନା e3 { c = 5000000000LL } e30;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ip;
unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *up;
long *lp;
long long *llp;

ଅକ୍ଷର **c1;
ଅକ୍ଷର ଅଚଳ **c2;
unsigned ଅକ୍ଷର **u1;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା no_main ()
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

    ଫେରନ୍ତୁ 0;
}


#ନଚେତଯଦି defined test_enum_compat
ଗଣନା e4;
ଗଣନା e5;
ଶୂନ୍ୟ f3(ଗଣନା e4 e);
ଶୂନ୍ୟ f3(ଗଣନା e5 e);

#ନଚେତଯଦି defined test_enum_compat_2
ଗଣନା e6 { E1 = -1, E0 };
ଶୂନ୍ୟ f3(ଗଣନା e6);
ଶୂନ୍ୟ f3(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);        // should work as int and e6 are compatible
ଶୂନ୍ୟ f4(ଗଣନା e6 e);
ଶୂନ୍ୟ f4(unsigned e); // should error as unsigned and e6 are incompatible

#ନଚେତଯଦି defined test_ptr_to_str
ଶୂନ୍ୟ f() { _Generic((ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଚଳ *[]){0}, ପୂର୍ଣ୍ଣସଂଖ୍ୟା:0); }
#ନଚେତଯଦି defined test_fnptr_to_str
ଶୂନ୍ୟ f() { _Generic((ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*(*)(ଦଶମିକ,ଅକ୍ଷର))(ଦ୍ୱିଗୁଣ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା)){0}, ପୂର୍ଣ୍ଣସଂଖ୍ୟା:0); }
#ନଚେତଯଦି defined test_array_to_str
ଶୂନ୍ୟ f() { _Generic((ପୂର୍ଣ୍ଣସଂଖ୍ୟା(*)[3]){0}, ପୂର୍ଣ୍ଣସଂଖ୍ୟା:0); }
#ନଚେତଯଦି defined test_duplicate_def_1
ସ୍ଥିର ଗଣନା myenum { L = -1 } L;                                                
#ନଚେତଯଦି defined test_duplicate_def_2
ଶୂନ୍ୟ foo(ଶୂନ୍ୟ) {
ସ୍ଥିର ଗଣନା myenum { L = -1 } L;                                                
}
#ନଚେତଯଦି defined test_abstract_decls
ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar(ଅଚଳ ଅକ୍ଷର *());     // abstract declarator here is okay
ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar (ଅଚଳ ଅକ୍ଷର *(*g)()) // should match this 'g' argument
{
  g();
  ଫେରନ୍ତୁ 42;
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା foo(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ())              // abstract decl is wrong in definitions
{
  ଫେରନ୍ତୁ 0;
#ନଚେତଯଦି defined test_invalid_1
ଶୂନ୍ୟ f(ଅକ୍ଷର*);
ଶୂନ୍ୟ g(ଶୂନ୍ୟ) {
  f((ଅକ୍ଷର[]){1, ,});
}
#ନଚେତଯଦି defined test_invalid_2
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ga = 0.42 { 2 };
#ନଚେତଯଦି defined test_invalid_3
ସଂରଚନା S { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b; };
ସଂରଚନା T { ସଂରଚନା S x; };
ସଂରଚନା T gt = { 42 a: 1, 43 };
#ନଚେତଯଦି defined test_invalid_4
ଗଣନା E {
    x = 1 / 0
};
#ନଚେତଯଦି defined test_conflicting_types
ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
ଶୂନ୍ୟ foo(ଶୂନ୍ୟ) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
      {
        ବାହ୍ୟ ଦ୍ୱିଗୁଣ i;
        i = 42.2;
      }
}
#ନଚେତଯଦି defined test_nested_types
ସଂଘ u {
    ସଂଘ u {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    } m;
};
#ନଚେତଯଦି defined test_vla_1
ପୂର୍ଣ୍ଣସଂଖ୍ୟା X=1;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ) {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା t[][][X];
}
#ନଚେତଯଦି defined test_invalid_alignas
/* _Alignas is no type qualifier */
ଶୂନ୍ୟ * _Alignas(16) p1;

#ନଚେତଯଦି defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ସଂରଚନା x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#ନଚେତଯଦି defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ସଂରଚନା y {  _Static_assert(0, "0"" is 0"); };

#ନଚେତଯଦି defined test_static_assert_c2x
 _Static_assert(1);
ସଂରଚନା z {  _Static_assert(0); }

#ନଚେତଯଦି defined test_static_assert_empty_string
 _Static_assert(0,"");

#ନଚେତଯଦି defined test_void_array
 ଶୂନ୍ୟ t[3];

#ନଚେତଯଦି defined test_incomplete_enum_array
  ଗଣନା e t[3];

#ନଚେତଯଦି defined test_incomplete_struct_array
  ସଂରଚନା s t[3];

#ନଚେତଯଦି defined test_const_fun_array
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ f(ଶୂନ୍ୟ);
  ଅଚଳ f t[3];

#ନଚେତଯଦି defined test_incomplete_array_array
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା t[][3]; // gr: not an error, see below

/******************************************************************/
#ନଚେତଯଦି defined test_extern_array
ପୂର୍ଣ୍ଣସଂଖ୍ୟା iii[] = { 1,2,3 };
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା iii[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[2];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[2];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[];
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[2];
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[3];

/******************************************************************/
#ନଚେତଯଦି defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ଯଦି defined test_func_1
ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
#ନଚେତଯଦି defined test_func_4
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
#endif
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ () {
#ଯଦି defined test_func_6
    ସ୍ଥିର
#endif
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    hello(123);
    ଫେରନ୍ତୁ 0;
}

#ଯଦି defined test_func_3
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
#ନଚେତଯଦି defined test_func_5
ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
#ଅନ୍ୟଥା
ପୂର୍ଣ୍ଣସଂଖ୍ୟା hello(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); ଫେରନ୍ତୁ 0; }

/******************************************************************/
#ନଚେତଯଦି defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ଯଦି defined test_var_1
ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx[];
#endif
ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar();

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ ()
{
#ଯଦି !defined test_var_3
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx = 2;
#endif
    {
        ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx[
#ଯଦି defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ଯଦି !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    ଫେରନ୍ତୁ 0;
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx[1] = {1};
ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar() { P(3, xxx[0]); ଫେରନ୍ତୁ 0; }

#ନଚେତଯଦି defined test_var_4
ସଂରଚନା yyy { ପୂର୍ଣ୍ଣସଂଖ୍ୟା y; };
ସଂରଚନା zzz;
ଶୂନ୍ୟ f1() {
    ବାହ୍ୟ ଅକ୍ଷର *x;
    ବାହ୍ୟ ଅକ୍ଷର **xx;
    ବାହ୍ୟ ସଂରଚନା yyy y;
    ବାହ୍ୟ ସଂରଚନା yyy *yy;
    ବାହ୍ୟ ସଂରଚନା zzz z;
    ବାହ୍ୟ ସଂରଚନା zzz *zz;
}
ଶୂନ୍ୟ f2() {
    ବାହ୍ୟ ଅକ୍ଷର *x;
    ବାହ୍ୟ ଅକ୍ଷର **xx;
    ବାହ୍ୟ ସଂରଚନା yyy y;
    ବାହ୍ୟ ସଂରଚନା yyy *yy;
    ବାହ୍ୟ ସଂରଚନା zzz z;
    ବାହ୍ୟ ସଂରଚନା zzz *zz;
}
ସଂରଚନା yyy y, *yy;
ସଂରଚନା zzz { ପୂର୍ଣ୍ଣସଂଖ୍ୟା z; } z, *zz;

/******************************************************************/
#ନଚେତଯଦି defined test_long_double_type_for_win32

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଦ୍ୱିଗୁଣ *a = 0;
    long ଦ୍ୱିଗୁଣ *b = a;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = _Generic(*a, ଦ୍ୱିଗୁଣ:0, long ଦ୍ୱିଗୁଣ:1);
}

#ନଚେତଯଦି defined test_stray_backslash
#define x \a
x

#ନଚେତଯଦି defined test_stray_backslash2

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#ନଚେତଯଦି defined test_var_array

ସ୍ଥିର ସଂରଚନା var_len { ପୂର୍ଣ୍ଣସଂଖ୍ୟା i; ଅଚଳ ଅକ୍ଷର str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#ନଚେତଯଦି defined test_var_array2

ସଂରଚନା c1 { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା b[]; };
ସଂରଚନା c1 c1 = { 1, { 2, 3, 4 } };

ସଂରଚନା c2 { ପୂର୍ଣ୍ଣସଂଖ୍ୟା c; ସଂରଚନା c1 c1; };
ସଂରଚନା c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#ନଚେତଯଦି defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ସଂରଚନା A { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a; ଅକ୍ଷର b[]; };
ସଂରଚନା A a = { 1, "1" };
ସଂରଚନା B { ସଂରଚନା A a; };
ସଂରଚନା B b = { { 1, "1" } };
/******************************************************************/
#ନଚେତଯଦି defined test_default_int_type
n; // warn
f(); // don't warn

#ନଚେତଯଦି defined test_invalid_global_stmtexpr
n[ଆକାର({3;})]; // crashed in block() due to missing local scope

#ନଚେତଯଦି defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#ନଚେତଯଦି defined test_duplicate_member
ସଂରଚନା S {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, a;
};
#ନଚେତଯଦି defined test_duplicate_member_anon
ସଂରଚନା S1 {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
  ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
  } c;
};
ସଂରଚନା S2 {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା d;
  ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା d;
  };
};

/******************************************************************/
#ନଚେତଯଦି defined test_conflicting_array_definition
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା array[2];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା array[] = { 1, 2, 3 };

#ନଚେତଯଦି defined test_incompatible_local_redef
ଶୂନ୍ୟ foo (ଶୂନ୍ୟ)
{
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା localfunctype (ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  ବାହ୍ୟ localfunctype func2;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ localfunctype (ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
}

#ନଚେତଯଦି defined test_cast_from_void
ଶୂନ୍ୟ v() {}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f() { ଫେରନ୍ତୁ v(); }

#ନଚେତଯଦି defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ଯଦି defined test_switch_W1
#pragma comment(option, "-Wall")
#ନଚେତଯଦି defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#ନଚେତଯଦି defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#ନଚେତଯଦି defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
ଶୂନ୍ୟ func(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର *ccp = "123";
    fink();
}
__attribute__((stuff)) ପୂର୍ଣ୍ଣସଂଖ୍ୟା fink() {ଫେରନ୍ତୁ 0;}

#ନଚେତଯଦି defined test_invalid_funcparam_1
ଶୂନ୍ୟ func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a);

#ନଚେତଯଦି defined test_invalid_funcparam_2
ଶୂନ୍ୟ func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଯଦି);

#ନଚେତଯଦି defined test_array_funcparam
ପୂର୍ଣ୍ଣସଂଖ୍ୟା amain(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର *argv[ସ୍ଥିର argc + 1])
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    ଫେରନ୍ତୁ 0;
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଫେରନ୍ତୁ amain(2, (ଅକ୍ଷର *[]){ "X", "Y", 0 });
}

#ନଚେତଯଦି defined test_return_from_statement_ପଦସମଷ୍ଟି
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f() { ({ ଫେରନ୍ତୁ 78; }); }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() { ଫେରନ୍ତୁ f(); }

/******************************************************************/

#ନଚେତଯଦି defined test_illegal_unicode
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() {
    ଅକ୍ଷର *str = "\Uffffffff";
}

#ନଚେତଯଦି defined test_error_string
#error \123\\
456

#ନଚେତଯଦି defined test_error_incomplete_type
ସଂରଚନା A;
ଶୂନ୍ୟ f(ସଂରଚନା A *);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    f(&(ସଂରଚନା A){});
}

ସଂରଚନା A {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
};

#ନଚେତଯଦି defined test_pp_error_1
# ଯଦି //no expression
# endif
#ନଚେତଯଦି defined test_pp_error_2
# ଯଦି X(1,2) //undefined function macro
# endif

#ନଚେତଯଦି defined test_pointer_plus_double

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *invalid_operation(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p, ଦ୍ୱିଗୁଣ d)
{
    ଫେରନ୍ତୁ p + d;
}

#ନଚେତଯଦି defined test_duplicate_case

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
    ବାଛ (x) {
        ସ୍ଥିତି -1 ... 0: /* empty case range with unsigned */
        ସ୍ଥିତି 3:
        ସ୍ଥିତି 1:
        ସ୍ଥିତି 2:
        ସ୍ଥିତି 3: /* show this line number in error */
        ସ୍ଥିତି 4:
        ସ୍ଥିତି 5:
    }
}
#ନଚେତଯଦି defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#ନଚେତଯଦି defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ସଂରଚନା xxx {ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar(ଗଣନା ee { a = 12, b = 34 } i, ପୂର୍ଣ୍ଣସଂଖ୍ୟା(*f)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i))
{
    printf("bar %d %d %d\n", i, a, b);
    ଫେରନ୍ତୁ 0;
}
/* 'xxx' not defined outside of function */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା foo(ସଂରଚନା xxx {ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[3];}*p)
{
    printf("foo %d", ଆକାର *p);
    ଫେରନ୍ତୁ p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା foo(ସଂରଚନା xxx {ପୂର୍ଣ୍ଣସଂଖ୍ୟା x[2];}*p);
#endif
#ifndef test_scope_3
ଗଣନା ee { a = 1, b };
#endif

ସଂରଚନା xxx x = { 11,22,33,44 };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    printf(" %d %d\n", foo(&x), ଆକାର (ସଂରଚନା xxx));
    ଗଣନା ee e = b;
    bar(13 + e, 0);

}

#ନଚେତଯଦି defined test_const_array_member_addr_ok

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

int_array ଅଚଳ *get_array(ଅଚଳ my_struct *s)
{
    ଫେରନ୍ତୁ &(s->arr);
}

#ନଚେତଯଦି defined test_const_array_member_decay_ok

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *good_decay(ଅଚଳ my_struct *s)
{
    ଫେରନ୍ତୁ s->arr;
}

#ନଚେତଯଦି defined test_const_array_member_addr_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

int_array *bad_array_addr(ଅଚଳ my_struct *s)
{
    ଫେରନ୍ତୁ &(s->arr);
}

#ନଚେତଯଦି defined test_const_array_member_decay_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bad_decay(ଅଚଳ my_struct *s)
{
    ଫେରନ୍ତୁ s->arr;
}

#ନଚେତଯଦି defined test_const_array_member_write_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ଶୂନ୍ୟ bad_write(ଅଚଳ my_struct *s)
{
    s->arr[0] = 1;
}

#ନଚେତଯଦି defined test_const_struct_array_member_write_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା x; } inner;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { inner arr[1]; } outer;

ଶୂନ୍ୟ bad_inner_write(ଅଚଳ outer *s)
{
    s->arr[0].x = 1;
}

#ନଚେତଯଦି defined test_volatile_array_member_addr_ok

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

int_array ଅସ୍ଥିର *get_volatile_array(ଅସ୍ଥିର my_struct *s)
{
    ଫେରନ୍ତୁ &(s->arr);
}

#ନଚେତଯଦି defined test_volatile_array_member_decay_ok

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା *good_volatile_decay(ଅସ୍ଥିର my_struct *s)
{
    ଫେରନ୍ତୁ s->arr;
}

#ନଚେତଯଦି defined test_volatile_array_member_addr_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(ଅସ୍ଥିର my_struct *s)
{
    ଫେରନ୍ତୁ &(s->arr);
}

#ନଚେତଯଦି defined test_volatile_array_member_decay_bad

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bad_volatile_decay(ଅସ୍ଥିର my_struct *s)
{
    ଫେରନ୍ତୁ s->arr;
}

#ନଚେତଯଦି defined test_volatile_array_member_write_ok

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା int_array[1];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { int_array arr; } my_struct;

ଶୂନ୍ୟ good_volatile_write(ଅସ୍ଥିର my_struct *s)
{
    s->arr[0] = 1;
}

#ନଚେତଯଦି defined test_conditional_array_qualifiers

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା Array2[2];
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା Array2x3[2][3];

Array2 *p;
ଅଚଳ Array2 *cp;
ଅଚଳ Array2x3 *cap;
ଅସ୍ଥିର Array2x3 *vap;

ଶୂନ୍ୟ test(ଶୂନ୍ୟ)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#ନଚେତଯଦି defined test_restrict_scalar

restrict ପୂର୍ଣ୍ଣସଂଖ୍ୟା object;

#ନଚେତଯଦି defined test_restrict_function_pointer

ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*restrict function_pointer)(ଶୂନ୍ୟ);

#ନଚେତଯଦି defined test_discarded_restrict

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict restricted_pointer;

restricted_pointer *source;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା **destination;

ଶୂନ୍ୟ test(ଶୂନ୍ୟ)
{
    destination = source;
}

#endif

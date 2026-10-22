പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);

#എങ്കിൽ defined test_56_btype_excess_1
ഘടന A {} പൂർണ്ണസംഖ്യ i;
#അല്ലെങ്കിലെങ്കിൽ defined test_57_btype_excess_2
അക്ഷരം പൂർണ്ണസംഖ്യ i;
#അല്ലെങ്കിലെങ്കിൽ defined test_58_function_redefinition
പൂർണ്ണസംഖ്യ f(ശൂന്യം) { തിരികെ 0; }
പൂർണ്ണസംഖ്യ f(ശൂന്യം) { തിരികെ 1; }

#അല്ലെങ്കിലെങ്കിൽ defined test_global_redefinition
പൂർണ്ണസംഖ്യ xxx = 1;
പൂർണ്ണസംഖ്യ xxx;
പൂർണ്ണസംഖ്യ xxx = 2;

#അല്ലെങ്കിലെങ്കിൽ defined test_59_function_array
പൂർണ്ണസംഖ്യ (*fct)[42](പൂർണ്ണസംഖ്യ x);

#അല്ലെങ്കിലെങ്കിൽ defined test_60_enum_redefinition
എണ്ണൽ color { RED, GREEN, BLUE };
എണ്ണൽ color { R, G, B };
എണ്ണൽ color c;

#അല്ലെങ്കിലെങ്കിൽ defined test_62_enumerator_redefinition
എണ്ണൽ color { RED, GREEN, BLUE };
എണ്ണൽ rgb { RED, G, B};
എണ്ണൽ color c = RED;

#അല്ലെങ്കിലെങ്കിൽ defined test_63_local_enumerator_redefinition
എണ്ണൽ {
    FOO,
    BAR
};

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    എണ്ണൽ {
        FOO = 2,
        BAR
    };

    തിരികെ BAR - FOO;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_61_undefined_enum
എണ്ണൽ rgb3 c = 42;

#അല്ലെങ്കിലെങ്കിൽ defined test_74_non_const_init
പൂർണ്ണസംഖ്യ i = i++;

#അല്ലെങ്കിലെങ്കിൽ defined test_pointer_assignment

ശൂന്യം (*f1)(ശൂന്യം);
ശൂന്യം f2(ശൂന്യം) {}

ഘടന s1 *ps1;
ഘടന s2 *ps2;

ശൂന്യം *v1, **v2, ***v3;

എണ്ണൽ e1 { a = 4 } e10, *e11, *e12;
എണ്ണൽ e2 { b = -4 } e20, *e21;
എണ്ണൽ e3 { c = 5000000000LL } e30;

പൂർണ്ണസംഖ്യ *ip;
unsigned പൂർണ്ണസംഖ്യ *up;
long *lp;
long long *llp;

അക്ഷരം **c1;
അക്ഷരം സ്ഥിരം **c2;
unsigned അക്ഷരം **u1;

പൂർണ്ണസംഖ്യ no_main ()
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

    തിരികെ 0;
}


#അല്ലെങ്കിലെങ്കിൽ defined test_enum_compat
എണ്ണൽ e4;
എണ്ണൽ e5;
ശൂന്യം f3(എണ്ണൽ e4 e);
ശൂന്യം f3(എണ്ണൽ e5 e);

#അല്ലെങ്കിലെങ്കിൽ defined test_enum_compat_2
എണ്ണൽ e6 { E1 = -1, E0 };
ശൂന്യം f3(എണ്ണൽ e6);
ശൂന്യം f3(പൂർണ്ണസംഖ്യ);        // should work as int and e6 are compatible
ശൂന്യം f4(എണ്ണൽ e6 e);
ശൂന്യം f4(unsigned e); // should error as unsigned and e6 are incompatible

#അല്ലെങ്കിലെങ്കിൽ defined test_ptr_to_str
ശൂന്യം f() { _Generic((പൂർണ്ണസംഖ്യ സ്ഥിരം *[]){0}, പൂർണ്ണസംഖ്യ:0); }
#അല്ലെങ്കിലെങ്കിൽ defined test_fnptr_to_str
ശൂന്യം f() { _Generic((പൂർണ്ണസംഖ്യ (*(*)(ദശാംശം,അക്ഷരം))(ഇരട്ട,പൂർണ്ണസംഖ്യ)){0}, പൂർണ്ണസംഖ്യ:0); }
#അല്ലെങ്കിലെങ്കിൽ defined test_array_to_str
ശൂന്യം f() { _Generic((പൂർണ്ണസംഖ്യ(*)[3]){0}, പൂർണ്ണസംഖ്യ:0); }
#അല്ലെങ്കിലെങ്കിൽ defined test_duplicate_def_1
സ്ഥിതം എണ്ണൽ myenum { L = -1 } L;                                                
#അല്ലെങ്കിലെങ്കിൽ defined test_duplicate_def_2
ശൂന്യം foo(ശൂന്യം) {
സ്ഥിതം എണ്ണൽ myenum { L = -1 } L;                                                
}
#അല്ലെങ്കിലെങ്കിൽ defined test_abstract_decls
പൂർണ്ണസംഖ്യ bar(സ്ഥിരം അക്ഷരം *());     // abstract declarator here is okay
പൂർണ്ണസംഖ്യ bar (സ്ഥിരം അക്ഷരം *(*g)()) // should match this 'g' argument
{
  g();
  തിരികെ 42;
}
പൂർണ്ണസംഖ്യ foo(പൂർണ്ണസംഖ്യ ())              // abstract decl is wrong in definitions
{
  തിരികെ 0;
#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_1
ശൂന്യം f(അക്ഷരം*);
ശൂന്യം g(ശൂന്യം) {
  f((അക്ഷരം[]){1, ,});
}
#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_2
പൂർണ്ണസംഖ്യ ga = 0.42 { 2 };
#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_3
ഘടന S { പൂർണ്ണസംഖ്യ a, b; };
ഘടന T { ഘടന S x; };
ഘടന T gt = { 42 a: 1, 43 };
#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_4
എണ്ണൽ E {
    x = 1 / 0
};
#അല്ലെങ്കിലെങ്കിൽ defined test_conflicting_types
പൂർണ്ണസംഖ്യ i;
ശൂന്യം foo(ശൂന്യം) {
    പൂർണ്ണസംഖ്യ i;
      {
        ബാഹ്യ ഇരട്ട i;
        i = 42.2;
      }
}
#അല്ലെങ്കിലെങ്കിൽ defined test_nested_types
സംഘം u {
    സംഘം u {
        പൂർണ്ണസംഖ്യ i;
    } m;
};
#അല്ലെങ്കിലെങ്കിൽ defined test_vla_1
പൂർണ്ണസംഖ്യ X=1;

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം) {
  പൂർണ്ണസംഖ്യ t[][][X];
}
#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_alignas
/* _Alignas is no type qualifier */
ശൂന്യം * _Alignas(16) p1;

#അല്ലെങ്കിലെങ്കിൽ defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ഘടന x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#അല്ലെങ്കിലെങ്കിൽ defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ഘടന y {  _Static_assert(0, "0"" is 0"); };

#അല്ലെങ്കിലെങ്കിൽ defined test_static_assert_c2x
 _Static_assert(1);
ഘടന z {  _Static_assert(0); }

#അല്ലെങ്കിലെങ്കിൽ defined test_static_assert_empty_string
 _Static_assert(0,"");

#അല്ലെങ്കിലെങ്കിൽ defined test_void_array
 ശൂന്യം t[3];

#അല്ലെങ്കിലെങ്കിൽ defined test_incomplete_enum_array
  എണ്ണൽ e t[3];

#അല്ലെങ്കിലെങ്കിൽ defined test_incomplete_struct_array
  ഘടന s t[3];

#അല്ലെങ്കിലെങ്കിൽ defined test_const_fun_array
  തരനിർവചനം ശൂന്യം f(ശൂന്യം);
  സ്ഥിരം f t[3];

#അല്ലെങ്കിലെങ്കിൽ defined test_incomplete_array_array
  പൂർണ്ണസംഖ്യ t[][3]; // gr: not an error, see below

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_extern_array
പൂർണ്ണസംഖ്യ iii[] = { 1,2,3 };
ബാഹ്യ പൂർണ്ണസംഖ്യ iii[];
പൂർണ്ണസംഖ്യ x[];
പൂർണ്ണസംഖ്യ x[2];
പൂർണ്ണസംഖ്യ x[];
പൂർണ്ണസംഖ്യ x[2];
പൂർണ്ണസംഖ്യ x[];
ബാഹ്യ പൂർണ്ണസംഖ്യ x[2];
ബാഹ്യ പൂർണ്ണസംഖ്യ x[];
പൂർണ്ണസംഖ്യ x[3];

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#എങ്കിൽ defined test_func_1
പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ);
#അല്ലെങ്കിലെങ്കിൽ defined test_func_4
സ്ഥിതം പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ);
#endif
പൂർണ്ണസംഖ്യ പ്രധാന () {
#എങ്കിൽ defined test_func_6
    സ്ഥിതം
#endif
    പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ);
    hello(123);
    തിരികെ 0;
}

#എങ്കിൽ defined test_func_3
സ്ഥിതം പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ a)
#അല്ലെങ്കിലെങ്കിൽ defined test_func_5
പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
#അല്ലെങ്കിൽ
പൂർണ്ണസംഖ്യ hello(പൂർണ്ണസംഖ്യ a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); തിരികെ 0; }

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#എങ്കിൽ defined test_var_1
പൂർണ്ണസംഖ്യ xxx[];
#endif
പൂർണ്ണസംഖ്യ bar();

പൂർണ്ണസംഖ്യ പ്രധാന ()
{
#എങ്കിൽ !defined test_var_3
    പൂർണ്ണസംഖ്യ xxx = 2;
#endif
    {
        ബാഹ്യ പൂർണ്ണസംഖ്യ xxx[
#എങ്കിൽ defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#എങ്കിൽ !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    തിരികെ 0;
}
പൂർണ്ണസംഖ്യ xxx[1] = {1};
പൂർണ്ണസംഖ്യ bar() { P(3, xxx[0]); തിരികെ 0; }

#അല്ലെങ്കിലെങ്കിൽ defined test_var_4
ഘടന yyy { പൂർണ്ണസംഖ്യ y; };
ഘടന zzz;
ശൂന്യം f1() {
    ബാഹ്യ അക്ഷരം *x;
    ബാഹ്യ അക്ഷരം **xx;
    ബാഹ്യ ഘടന yyy y;
    ബാഹ്യ ഘടന yyy *yy;
    ബാഹ്യ ഘടന zzz z;
    ബാഹ്യ ഘടന zzz *zz;
}
ശൂന്യം f2() {
    ബാഹ്യ അക്ഷരം *x;
    ബാഹ്യ അക്ഷരം **xx;
    ബാഹ്യ ഘടന yyy y;
    ബാഹ്യ ഘടന yyy *yy;
    ബാഹ്യ ഘടന zzz z;
    ബാഹ്യ ഘടന zzz *zz;
}
ഘടന yyy y, *yy;
ഘടന zzz { പൂർണ്ണസംഖ്യ z; } z, *zz;

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_long_double_type_for_win32

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    ഇരട്ട *a = 0;
    long ഇരട്ട *b = a;
    പൂർണ്ണസംഖ്യ n = _Generic(*a, ഇരട്ട:0, long ഇരട്ട:1);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_stray_backslash
#define x \a
x

#അല്ലെങ്കിലെങ്കിൽ defined test_stray_backslash2

പൂർണ്ണസംഖ്യ പ്രധാന()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_var_array

സ്ഥിതം ഘടന var_len { പൂർണ്ണസംഖ്യ i; സ്ഥിരം അക്ഷരം str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#അല്ലെങ്കിലെങ്കിൽ defined test_var_array2

ഘടന c1 { പൂർണ്ണസംഖ്യ a; പൂർണ്ണസംഖ്യ b[]; };
ഘടന c1 c1 = { 1, { 2, 3, 4 } };

ഘടന c2 { പൂർണ്ണസംഖ്യ c; ഘടന c1 c1; };
ഘടന c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#അല്ലെങ്കിലെങ്കിൽ defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ഘടന A { പൂർണ്ണസംഖ്യ a; അക്ഷരം b[]; };
ഘടന A a = { 1, "1" };
ഘടന B { ഘടന A a; };
ഘടന B b = { { 1, "1" } };
/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_default_int_type
n; // warn
f(); // don't warn

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_global_stmtexpr
n[വലുപ്പം({3;})]; // crashed in block() due to missing local scope

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_duplicate_member
ഘടന S {
  പൂർണ്ണസംഖ്യ a, a;
};
#അല്ലെങ്കിലെങ്കിൽ defined test_duplicate_member_anon
ഘടന S1 {
  പൂർണ്ണസംഖ്യ b;
  ഘടന {
    പൂർണ്ണസംഖ്യ b;
  } c;
};
ഘടന S2 {
  പൂർണ്ണസംഖ്യ d;
  ഘടന {
    പൂർണ്ണസംഖ്യ d;
  };
};

/******************************************************************/
#അല്ലെങ്കിലെങ്കിൽ defined test_conflicting_array_definition
ബാഹ്യ പൂർണ്ണസംഖ്യ array[2];
പൂർണ്ണസംഖ്യ array[] = { 1, 2, 3 };

#അല്ലെങ്കിലെങ്കിൽ defined test_incompatible_local_redef
ശൂന്യം foo (ശൂന്യം)
{
  തരനിർവചനം പൂർണ്ണസംഖ്യ localfunctype (പൂർണ്ണസംഖ്യ);
  ബാഹ്യ localfunctype func2;
  തരനിർവചനം ശൂന്യം localfunctype (പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_cast_from_void
ശൂന്യം v() {}
പൂർണ്ണസംഖ്യ f() { തിരികെ v(); }

#അല്ലെങ്കിലെങ്കിൽ defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#എങ്കിൽ defined test_switch_W1
#pragma comment(option, "-Wall")
#അല്ലെങ്കിലെങ്കിൽ defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#അല്ലെങ്കിലെങ്കിൽ defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#അല്ലെങ്കിലെങ്കിൽ defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
ശൂന്യം func(ശൂന്യം)
{
    അക്ഷരം *ccp = "123";
    fink();
}
__attribute__((stuff)) പൂർണ്ണസംഖ്യ fink() {തിരികെ 0;}

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_funcparam_1
ശൂന്യം func(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ a);

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_funcparam_2
ശൂന്യം func(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ എങ്കിൽ);

#അല്ലെങ്കിലെങ്കിൽ defined test_array_funcparam
പൂർണ്ണസംഖ്യ amain(പൂർണ്ണസംഖ്യ argc, അക്ഷരം *argv[സ്ഥിതം argc + 1])
{
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    തിരികെ 0;
}
പൂർണ്ണസംഖ്യ പ്രധാന()
{
    തിരികെ amain(2, (അക്ഷരം *[]){ "X", "Y", 0 });
}

#അല്ലെങ്കിലെങ്കിൽ defined test_return_from_statement_വ്യഞ്ജകം
പൂർണ്ണസംഖ്യ f() { ({ തിരികെ 78; }); }
പൂർണ്ണസംഖ്യ പ്രധാന() { തിരികെ f(); }

/******************************************************************/

#അല്ലെങ്കിലെങ്കിൽ defined test_illegal_unicode
പൂർണ്ണസംഖ്യ പ്രധാന() {
    അക്ഷരം *str = "\Uffffffff";
}

#അല്ലെങ്കിലെങ്കിൽ defined test_error_string
#error \123\\
456

#അല്ലെങ്കിലെങ്കിൽ defined test_error_incomplete_type
ഘടന A;
ശൂന്യം f(ഘടന A *);

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    f(&(ഘടന A){});
}

ഘടന A {
    പൂർണ്ണസംഖ്യ x;
};

#അല്ലെങ്കിലെങ്കിൽ defined test_pp_error_1
# എങ്കിൽ //no expression
# endif
#അല്ലെങ്കിലെങ്കിൽ defined test_pp_error_2
# എങ്കിൽ X(1,2) //undefined function macro
# endif

#അല്ലെങ്കിലെങ്കിൽ defined test_pointer_plus_double

പൂർണ്ണസംഖ്യ *invalid_operation(പൂർണ്ണസംഖ്യ *p, ഇരട്ട d)
{
    തിരികെ p + d;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_duplicate_case

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    unsigned പൂർണ്ണസംഖ്യ x;
    തിരഞ്ഞെടുപ്പ് (x) {
        അവസ്ഥ -1 ... 0: /* empty case range with unsigned */
        അവസ്ഥ 3:
        അവസ്ഥ 1:
        അവസ്ഥ 2:
        അവസ്ഥ 3: /* show this line number in error */
        അവസ്ഥ 4:
        അവസ്ഥ 5:
    }
}
#അല്ലെങ്കിലെങ്കിൽ defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#അല്ലെങ്കിലെങ്കിൽ defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ഘടന xxx {പൂർണ്ണസംഖ്യ x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
പൂർണ്ണസംഖ്യ bar(എണ്ണൽ ee { a = 12, b = 34 } i, പൂർണ്ണസംഖ്യ(*f)(പൂർണ്ണസംഖ്യ i))
{
    printf("bar %d %d %d\n", i, a, b);
    തിരികെ 0;
}
/* 'xxx' not defined outside of function */
പൂർണ്ണസംഖ്യ foo(ഘടന xxx {പൂർണ്ണസംഖ്യ x[3];}*p)
{
    printf("foo %d", വലുപ്പം *p);
    തിരികെ p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
പൂർണ്ണസംഖ്യ foo(ഘടന xxx {പൂർണ്ണസംഖ്യ x[2];}*p);
#endif
#ifndef test_scope_3
എണ്ണൽ ee { a = 1, b };
#endif

ഘടന xxx x = { 11,22,33,44 };
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    printf(" %d %d\n", foo(&x), വലുപ്പം (ഘടന xxx));
    എണ്ണൽ ee e = b;
    bar(13 + e, 0);

}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_array_member_addr_ok

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

int_array സ്ഥിരം *get_array(സ്ഥിരം my_struct *s)
{
    തിരികെ &(s->arr);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_array_member_decay_ok

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

സ്ഥിരം പൂർണ്ണസംഖ്യ *good_decay(സ്ഥിരം my_struct *s)
{
    തിരികെ s->arr;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_array_member_addr_bad

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

int_array *bad_array_addr(സ്ഥിരം my_struct *s)
{
    തിരികെ &(s->arr);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_array_member_decay_bad

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

പൂർണ്ണസംഖ്യ *bad_decay(സ്ഥിരം my_struct *s)
{
    തിരികെ s->arr;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_array_member_write_bad

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

ശൂന്യം bad_write(സ്ഥിരം my_struct *s)
{
    s->arr[0] = 1;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_const_struct_array_member_write_bad

തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ x; } inner;
തരനിർവചനം ഘടന { inner arr[1]; } outer;

ശൂന്യം bad_inner_write(സ്ഥിരം outer *s)
{
    s->arr[0].x = 1;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_volatile_array_member_addr_ok

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

int_array അസ്ഥിര *get_volatile_array(അസ്ഥിര my_struct *s)
{
    തിരികെ &(s->arr);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_volatile_array_member_decay_ok

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

അസ്ഥിര പൂർണ്ണസംഖ്യ *good_volatile_decay(അസ്ഥിര my_struct *s)
{
    തിരികെ s->arr;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_volatile_array_member_addr_bad

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(അസ്ഥിര my_struct *s)
{
    തിരികെ &(s->arr);
}

#അല്ലെങ്കിലെങ്കിൽ defined test_volatile_array_member_decay_bad

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

പൂർണ്ണസംഖ്യ *bad_volatile_decay(അസ്ഥിര my_struct *s)
{
    തിരികെ s->arr;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_volatile_array_member_write_ok

തരനിർവചനം പൂർണ്ണസംഖ്യ int_array[1];
തരനിർവചനം ഘടന { int_array arr; } my_struct;

ശൂന്യം good_volatile_write(അസ്ഥിര my_struct *s)
{
    s->arr[0] = 1;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_conditional_array_qualifiers

തരനിർവചനം പൂർണ്ണസംഖ്യ Array2[2];
തരനിർവചനം പൂർണ്ണസംഖ്യ Array2x3[2][3];

Array2 *p;
സ്ഥിരം Array2 *cp;
സ്ഥിരം Array2x3 *cap;
അസ്ഥിര Array2x3 *vap;

ശൂന്യം test(ശൂന്യം)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_restrict_scalar

restrict പൂർണ്ണസംഖ്യ object;

#അല്ലെങ്കിലെങ്കിൽ defined test_restrict_function_pointer

പൂർണ്ണസംഖ്യ (*restrict function_pointer)(ശൂന്യം);

#അല്ലെങ്കിലെങ്കിൽ defined test_discarded_restrict

തരനിർവചനം പൂർണ്ണസംഖ്യ *restrict restricted_pointer;

restricted_pointer *source;
പൂർണ്ണസംഖ്യ **destination;

ശൂന്യം test(ശൂന്യം)
{
    destination = source;
}

#endif

পূর্ণাঙ্ক printf(ধ্রুব বর্ণ*, ...);

#যদি defined test_56_btype_excess_1
সংরচনা A {} পূর্ণাঙ্ক i;
#নোচেদ্যদি defined test_57_btype_excess_2
বর্ণ পূর্ণাঙ্ক i;
#নোচেদ্যদি defined test_58_function_redefinition
পূর্ণাঙ্ক f(শূন্য) { প্রত্যাগম 0; }
পূর্ণাঙ্ক f(শূন্য) { প্রত্যাগম 1; }

#নোচেদ্যদি defined test_global_redefinition
পূর্ণাঙ্ক xxx = 1;
পূর্ণাঙ্ক xxx;
পূর্ণাঙ্ক xxx = 2;

#নোচেদ্যদি defined test_59_function_array
পূর্ণাঙ্ক (*fct)[42](পূর্ণাঙ্ক x);

#নোচেদ্যদি defined test_60_enum_redefinition
গণনা color { RED, GREEN, BLUE };
গণনা color { R, G, B };
গণনা color c;

#নোচেদ্যদি defined test_62_enumerator_redefinition
গণনা color { RED, GREEN, BLUE };
গণনা rgb { RED, G, B};
গণনা color c = RED;

#নোচেদ্যদি defined test_63_local_enumerator_redefinition
গণনা {
    FOO,
    BAR
};

পূর্ণাঙ্ক main(শূন্য)
{
    গণনা {
        FOO = 2,
        BAR
    };

    প্রত্যাগম BAR - FOO;
}

#নোচেদ্যদি defined test_61_undefined_enum
গণনা rgb3 c = 42;

#নোচেদ্যদি defined test_74_non_const_init
পূর্ণাঙ্ক i = i++;

#নোচেদ্যদি defined test_pointer_assignment

শূন্য (*f1)(শূন্য);
শূন্য f2(শূন্য) {}

সংরচনা s1 *ps1;
সংরচনা s2 *ps2;

শূন্য *v1, **v2, ***v3;

গণনা e1 { a = 4 } e10, *e11, *e12;
গণনা e2 { b = -4 } e20, *e21;
গণনা e3 { c = 5000000000LL } e30;

পূর্ণাঙ্ক *ip;
unsigned পূর্ণাঙ্ক *up;
long *lp;
long long *llp;

বর্ণ **c1;
বর্ণ ধ্রুব **c2;
unsigned বর্ণ **u1;

পূর্ণাঙ্ক no_main ()
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

    প্রত্যাগম 0;
}


#নোচেদ্যদি defined test_enum_compat
গণনা e4;
গণনা e5;
শূন্য f3(গণনা e4 e);
শূন্য f3(গণনা e5 e);

#নোচেদ্যদি defined test_enum_compat_2
গণনা e6 { E1 = -1, E0 };
শূন্য f3(গণনা e6);
শূন্য f3(পূর্ণাঙ্ক);        // should work as int and e6 are compatible
শূন্য f4(গণনা e6 e);
শূন্য f4(unsigned e); // should error as unsigned and e6 are incompatible

#নোচেদ্যদি defined test_ptr_to_str
শূন্য f() { _Generic((পূর্ণাঙ্ক ধ্রুব *[]){0}, পূর্ণাঙ্ক:0); }
#নোচেদ্যদি defined test_fnptr_to_str
শূন্য f() { _Generic((পূর্ণাঙ্ক (*(*)(ভিন্ন,বর্ণ))(দ্বিগুণ,পূর্ণাঙ্ক)){0}, পূর্ণাঙ্ক:0); }
#নোচেদ্যদি defined test_array_to_str
শূন্য f() { _Generic((পূর্ণাঙ্ক(*)[3]){0}, পূর্ণাঙ্ক:0); }
#নোচেদ্যদি defined test_duplicate_def_1
স্থির গণনা myenum { L = -1 } L;                                                
#নোচেদ্যদি defined test_duplicate_def_2
শূন্য foo(শূন্য) {
স্থির গণনা myenum { L = -1 } L;                                                
}
#নোচেদ্যদি defined test_abstract_decls
পূর্ণাঙ্ক bar(ধ্রুব বর্ণ *());     // abstract declarator here is okay
পূর্ণাঙ্ক bar (ধ্রুব বর্ণ *(*g)()) // should match this 'g' argument
{
  g();
  প্রত্যাগম 42;
}
পূর্ণাঙ্ক foo(পূর্ণাঙ্ক ())              // abstract decl is wrong in definitions
{
  প্রত্যাগম 0;
#নোচেদ্যদি defined test_invalid_1
শূন্য f(বর্ণ*);
শূন্য g(শূন্য) {
  f((বর্ণ[]){1, ,});
}
#নোচেদ্যদি defined test_invalid_2
পূর্ণাঙ্ক ga = 0.42 { 2 };
#নোচেদ্যদি defined test_invalid_3
সংরচনা S { পূর্ণাঙ্ক a, b; };
সংরচনা T { সংরচনা S x; };
সংরচনা T gt = { 42 a: 1, 43 };
#নোচেদ্যদি defined test_invalid_4
গণনা E {
    x = 1 / 0
};
#নোচেদ্যদি defined test_conflicting_types
পূর্ণাঙ্ক i;
শূন্য foo(শূন্য) {
    পূর্ণাঙ্ক i;
      {
        বাহ্য দ্বিগুণ i;
        i = 42.2;
      }
}
#নোচেদ্যদি defined test_nested_types
সঙ্ঘ u {
    সঙ্ঘ u {
        পূর্ণাঙ্ক i;
    } m;
};
#নোচেদ্যদি defined test_vla_1
পূর্ণাঙ্ক X=1;

পূর্ণাঙ্ক main(শূন্য) {
  পূর্ণাঙ্ক t[][][X];
}
#নোচেদ্যদি defined test_invalid_alignas
/* _Alignas is no type qualifier */
শূন্য * _Alignas(16) p1;

#নোচেদ্যদি defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 সংরচনা x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#নোচেদ্যদি defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
সংরচনা y {  _Static_assert(0, "0"" is 0"); };

#নোচেদ্যদি defined test_static_assert_c2x
 _Static_assert(1);
সংরচনা z {  _Static_assert(0); }

#নোচেদ্যদি defined test_static_assert_empty_string
 _Static_assert(0,"");

#নোচেদ্যদি defined test_void_array
 শূন্য t[3];

#নোচেদ্যদি defined test_incomplete_enum_array
  গণনা e t[3];

#নোচেদ্যদি defined test_incomplete_struct_array
  সংরচনা s t[3];

#নোচেদ্যদি defined test_const_fun_array
  প্রকারনির্দেশ শূন্য f(শূন্য);
  ধ্রুব f t[3];

#নোচেদ্যদি defined test_incomplete_array_array
  পূর্ণাঙ্ক t[][3]; // gr: not an error, see below

/******************************************************************/
#নোচেদ্যদি defined test_extern_array
পূর্ণাঙ্ক iii[] = { 1,2,3 };
বাহ্য পূর্ণাঙ্ক iii[];
পূর্ণাঙ্ক x[];
পূর্ণাঙ্ক x[2];
পূর্ণাঙ্ক x[];
পূর্ণাঙ্ক x[2];
পূর্ণাঙ্ক x[];
বাহ্য পূর্ণাঙ্ক x[2];
বাহ্য পূর্ণাঙ্ক x[];
পূর্ণাঙ্ক x[3];

/******************************************************************/
#নোচেদ্যদি defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#যদি defined test_func_1
পূর্ণাঙ্ক hello(পূর্ণাঙ্ক);
#নোচেদ্যদি defined test_func_4
স্থির পূর্ণাঙ্ক hello(পূর্ণাঙ্ক);
#endif
পূর্ণাঙ্ক main () {
#যদি defined test_func_6
    স্থির
#endif
    পূর্ণাঙ্ক hello(পূর্ণাঙ্ক);
    hello(123);
    প্রত্যাগম 0;
}

#যদি defined test_func_3
স্থির পূর্ণাঙ্ক hello(পূর্ণাঙ্ক a)
#নোচেদ্যদি defined test_func_5
পূর্ণাঙ্ক hello(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
#অন্যথা
পূর্ণাঙ্ক hello(পূর্ণাঙ্ক a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); প্রত্যাগম 0; }

/******************************************************************/
#নোচেদ্যদি defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#যদি defined test_var_1
পূর্ণাঙ্ক xxx[];
#endif
পূর্ণাঙ্ক bar();

পূর্ণাঙ্ক main ()
{
#যদি !defined test_var_3
    পূর্ণাঙ্ক xxx = 2;
#endif
    {
        বাহ্য পূর্ণাঙ্ক xxx[
#যদি defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#যদি !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    প্রত্যাগম 0;
}
পূর্ণাঙ্ক xxx[1] = {1};
পূর্ণাঙ্ক bar() { P(3, xxx[0]); প্রত্যাগম 0; }

#নোচেদ্যদি defined test_var_4
সংরচনা yyy { পূর্ণাঙ্ক y; };
সংরচনা zzz;
শূন্য f1() {
    বাহ্য বর্ণ *x;
    বাহ্য বর্ণ **xx;
    বাহ্য সংরচনা yyy y;
    বাহ্য সংরচনা yyy *yy;
    বাহ্য সংরচনা zzz z;
    বাহ্য সংরচনা zzz *zz;
}
শূন্য f2() {
    বাহ্য বর্ণ *x;
    বাহ্য বর্ণ **xx;
    বাহ্য সংরচনা yyy y;
    বাহ্য সংরচনা yyy *yy;
    বাহ্য সংরচনা zzz z;
    বাহ্য সংরচনা zzz *zz;
}
সংরচনা yyy y, *yy;
সংরচনা zzz { পূর্ণাঙ্ক z; } z, *zz;

/******************************************************************/
#নোচেদ্যদি defined test_long_double_type_for_win32

পূর্ণাঙ্ক main()
{
    দ্বিগুণ *a = 0;
    long দ্বিগুণ *b = a;
    পূর্ণাঙ্ক n = _Generic(*a, দ্বিগুণ:0, long দ্বিগুণ:1);
}

#নোচেদ্যদি defined test_stray_backslash
#define x \a
x

#নোচেদ্যদি defined test_stray_backslash2

পূর্ণাঙ্ক main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#নোচেদ্যদি defined test_var_array

স্থির সংরচনা var_len { পূর্ণাঙ্ক i; ধ্রুব বর্ণ str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#নোচেদ্যদি defined test_var_array2

সংরচনা c1 { পূর্ণাঙ্ক a; পূর্ণাঙ্ক b[]; };
সংরচনা c1 c1 = { 1, { 2, 3, 4 } };

সংরচনা c2 { পূর্ণাঙ্ক c; সংরচনা c1 c1; };
সংরচনা c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#নোচেদ্যদি defined test_var_array3
/* similar to test_var_array2 but with string initializers */
সংরচনা A { পূর্ণাঙ্ক a; বর্ণ b[]; };
সংরচনা A a = { 1, "1" };
সংরচনা B { সংরচনা A a; };
সংরচনা B b = { { 1, "1" } };
/******************************************************************/
#নোচেদ্যদি defined test_default_int_type
n; // warn
f(); // don't warn

#নোচেদ্যদি defined test_invalid_global_stmtexpr
n[পরিমাণ({3;})]; // crashed in block() due to missing local scope

#নোচেদ্যদি defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#নোচেদ্যদি defined test_duplicate_member
সংরচনা S {
  পূর্ণাঙ্ক a, a;
};
#নোচেদ্যদি defined test_duplicate_member_anon
সংরচনা S1 {
  পূর্ণাঙ্ক b;
  সংরচনা {
    পূর্ণাঙ্ক b;
  } c;
};
সংরচনা S2 {
  পূর্ণাঙ্ক d;
  সংরচনা {
    পূর্ণাঙ্ক d;
  };
};

/******************************************************************/
#নোচেদ্যদি defined test_conflicting_array_definition
বাহ্য পূর্ণাঙ্ক array[2];
পূর্ণাঙ্ক array[] = { 1, 2, 3 };

#নোচেদ্যদি defined test_incompatible_local_redef
শূন্য foo (শূন্য)
{
  প্রকারনির্দেশ পূর্ণাঙ্ক localfunctype (পূর্ণাঙ্ক);
  বাহ্য localfunctype func2;
  প্রকারনির্দেশ শূন্য localfunctype (পূর্ণাঙ্ক, পূর্ণাঙ্ক);
}

#নোচেদ্যদি defined test_cast_from_void
শূন্য v() {}
পূর্ণাঙ্ক f() { প্রত্যাগম v(); }

#নোচেদ্যদি defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#যদি defined test_switch_W1
#pragma comment(option, "-Wall")
#নোচেদ্যদি defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#নোচেদ্যদি defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#নোচেদ্যদি defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
শূন্য func(শূন্য)
{
    বর্ণ *ccp = "123";
    fink();
}
__attribute__((stuff)) পূর্ণাঙ্ক fink() {প্রত্যাগম 0;}

#নোচেদ্যদি defined test_invalid_funcparam_1
শূন্য func(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b, পূর্ণাঙ্ক a);

#নোচেদ্যদি defined test_invalid_funcparam_2
শূন্য func(পূর্ণাঙ্ক a, পূর্ণাঙ্ক যদি);

#নোচেদ্যদি defined test_array_funcparam
পূর্ণাঙ্ক amain(পূর্ণাঙ্ক argc, বর্ণ *argv[স্থির argc + 1])
{
    পূর্ণাঙ্ক i;

    প্রতি (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    প্রত্যাগম 0;
}
পূর্ণাঙ্ক main()
{
    প্রত্যাগম amain(2, (বর্ণ *[]){ "X", "Y", 0 });
}

#নোচেদ্যদি defined test_return_from_statement_রাশিমালা
পূর্ণাঙ্ক f() { ({ প্রত্যাগম 78; }); }
পূর্ণাঙ্ক main() { প্রত্যাগম f(); }

/******************************************************************/

#নোচেদ্যদি defined test_illegal_unicode
পূর্ণাঙ্ক main() {
    বর্ণ *str = "\Uffffffff";
}

#নোচেদ্যদি defined test_error_string
#error \123\\
456

#নোচেদ্যদি defined test_error_incomplete_type
সংরচনা A;
শূন্য f(সংরচনা A *);

পূর্ণাঙ্ক main()
{
    f(&(সংরচনা A){});
}

সংরচনা A {
    পূর্ণাঙ্ক x;
};

#নোচেদ্যদি defined test_pp_error_1
# যদি //no expression
# endif
#নোচেদ্যদি defined test_pp_error_2
# যদি X(1,2) //undefined function macro
# endif

#নোচেদ্যদি defined test_pointer_plus_double

পূর্ণাঙ্ক *invalid_operation(পূর্ণাঙ্ক *p, দ্বিগুণ d)
{
    প্রত্যাগম p + d;
}

#নোচেদ্যদি defined test_duplicate_case

পূর্ণাঙ্ক main()
{
    unsigned পূর্ণাঙ্ক x;
    বিকল্প (x) {
        পক্ষ -1 ... 0: /* empty case range with unsigned */
        পক্ষ 3:
        পক্ষ 1:
        পক্ষ 2:
        পক্ষ 3: /* show this line number in error */
        পক্ষ 4:
        পক্ষ 5:
    }
}
#নোচেদ্যদি defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

পূর্ণাঙ্ক main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#নোচেদ্যদি defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

সংরচনা xxx {পূর্ণাঙ্ক x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
পূর্ণাঙ্ক bar(গণনা ee { a = 12, b = 34 } i, পূর্ণাঙ্ক(*f)(পূর্ণাঙ্ক i))
{
    printf("bar %d %d %d\n", i, a, b);
    প্রত্যাগম 0;
}
/* 'xxx' not defined outside of function */
পূর্ণাঙ্ক foo(সংরচনা xxx {পূর্ণাঙ্ক x[3];}*p)
{
    printf("foo %d", পরিমাণ *p);
    প্রত্যাগম p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
পূর্ণাঙ্ক foo(সংরচনা xxx {পূর্ণাঙ্ক x[2];}*p);
#endif
#ifndef test_scope_3
গণনা ee { a = 1, b };
#endif

সংরচনা xxx x = { 11,22,33,44 };
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{
    printf(" %d %d\n", foo(&x), পরিমাণ (সংরচনা xxx));
    গণনা ee e = b;
    bar(13 + e, 0);

}

#নোচেদ্যদি defined test_const_array_member_addr_ok

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

int_array ধ্রুব *get_array(ধ্রুব my_struct *s)
{
    প্রত্যাগম &(s->arr);
}

#নোচেদ্যদি defined test_const_array_member_decay_ok

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

ধ্রুব পূর্ণাঙ্ক *good_decay(ধ্রুব my_struct *s)
{
    প্রত্যাগম s->arr;
}

#নোচেদ্যদি defined test_const_array_member_addr_bad

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

int_array *bad_array_addr(ধ্রুব my_struct *s)
{
    প্রত্যাগম &(s->arr);
}

#নোচেদ্যদি defined test_const_array_member_decay_bad

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

পূর্ণাঙ্ক *bad_decay(ধ্রুব my_struct *s)
{
    প্রত্যাগম s->arr;
}

#নোচেদ্যদি defined test_const_array_member_write_bad

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

শূন্য bad_write(ধ্রুব my_struct *s)
{
    s->arr[0] = 1;
}

#নোচেদ্যদি defined test_const_struct_array_member_write_bad

প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক x; } inner;
প্রকারনির্দেশ সংরচনা { inner arr[1]; } outer;

শূন্য bad_inner_write(ধ্রুব outer *s)
{
    s->arr[0].x = 1;
}

#নোচেদ্যদি defined test_volatile_array_member_addr_ok

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

int_array চঞ্চল *get_volatile_array(চঞ্চল my_struct *s)
{
    প্রত্যাগম &(s->arr);
}

#নোচেদ্যদি defined test_volatile_array_member_decay_ok

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

চঞ্চল পূর্ণাঙ্ক *good_volatile_decay(চঞ্চল my_struct *s)
{
    প্রত্যাগম s->arr;
}

#নোচেদ্যদি defined test_volatile_array_member_addr_bad

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(চঞ্চল my_struct *s)
{
    প্রত্যাগম &(s->arr);
}

#নোচেদ্যদি defined test_volatile_array_member_decay_bad

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

পূর্ণাঙ্ক *bad_volatile_decay(চঞ্চল my_struct *s)
{
    প্রত্যাগম s->arr;
}

#নোচেদ্যদি defined test_volatile_array_member_write_ok

প্রকারনির্দেশ পূর্ণাঙ্ক int_array[1];
প্রকারনির্দেশ সংরচনা { int_array arr; } my_struct;

শূন্য good_volatile_write(চঞ্চল my_struct *s)
{
    s->arr[0] = 1;
}

#নোচেদ্যদি defined test_conditional_array_qualifiers

প্রকারনির্দেশ পূর্ণাঙ্ক Array2[2];
প্রকারনির্দেশ পূর্ণাঙ্ক Array2x3[2][3];

Array2 *p;
ধ্রুব Array2 *cp;
ধ্রুব Array2x3 *cap;
চঞ্চল Array2x3 *vap;

শূন্য test(শূন্য)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#নোচেদ্যদি defined test_restrict_scalar

restrict পূর্ণাঙ্ক object;

#নোচেদ্যদি defined test_restrict_function_pointer

পূর্ণাঙ্ক (*restrict function_pointer)(শূন্য);

#নোচেদ্যদি defined test_discarded_restrict

প্রকারনির্দেশ পূর্ণাঙ্ক *restrict restricted_pointer;

restricted_pointer *source;
পূর্ণাঙ্ক **destination;

শূন্য test(শূন্য)
{
    destination = source;
}

#endif

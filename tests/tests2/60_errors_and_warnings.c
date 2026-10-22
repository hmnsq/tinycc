পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);

#যদি defined test_56_btype_excess_1
কাঠামো A {} পূর্ণসংখ্যা i;
#নতুবা_যদি defined test_57_btype_excess_2
অক্ষর পূর্ণসংখ্যা i;
#নতুবা_যদি defined test_58_function_redefinition
পূর্ণসংখ্যা f(শূন্য) { ফেরত 0; }
পূর্ণসংখ্যা f(শূন্য) { ফেরত 1; }

#নতুবা_যদি defined test_global_redefinition
পূর্ণসংখ্যা xxx = 1;
পূর্ণসংখ্যা xxx;
পূর্ণসংখ্যা xxx = 2;

#নতুবা_যদি defined test_59_function_array
পূর্ণসংখ্যা (*fct)[42](পূর্ণসংখ্যা x);

#নতুবা_যদি defined test_60_enum_redefinition
গণনা color { RED, GREEN, BLUE };
গণনা color { R, G, B };
গণনা color c;

#নতুবা_যদি defined test_62_enumerator_redefinition
গণনা color { RED, GREEN, BLUE };
গণনা rgb { RED, G, B};
গণনা color c = RED;

#নতুবা_যদি defined test_63_local_enumerator_redefinition
গণনা {
    FOO,
    BAR
};

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    গণনা {
        FOO = 2,
        BAR
    };

    ফেরত BAR - FOO;
}

#নতুবা_যদি defined test_61_undefined_enum
গণনা rgb3 c = 42;

#নতুবা_যদি defined test_74_non_const_init
পূর্ণসংখ্যা i = i++;

#নতুবা_যদি defined test_pointer_assignment

শূন্য (*f1)(শূন্য);
শূন্য f2(শূন্য) {}

কাঠামো s1 *ps1;
কাঠামো s2 *ps2;

শূন্য *v1, **v2, ***v3;

গণনা e1 { a = 4 } e10, *e11, *e12;
গণনা e2 { b = -4 } e20, *e21;
গণনা e3 { c = 5000000000LL } e30;

পূর্ণসংখ্যা *ip;
unsigned পূর্ণসংখ্যা *up;
long *lp;
long long *llp;

অক্ষর **c1;
অক্ষর ধ্রুবক **c2;
unsigned অক্ষর **u1;

পূর্ণসংখ্যা no_main ()
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

    ফেরত 0;
}


#নতুবা_যদি defined test_enum_compat
গণনা e4;
গণনা e5;
শূন্য f3(গণনা e4 e);
শূন্য f3(গণনা e5 e);

#নতুবা_যদি defined test_enum_compat_2
গণনা e6 { E1 = -1, E0 };
শূন্য f3(গণনা e6);
শূন্য f3(পূর্ণসংখ্যা);        // should work as int and e6 are compatible
শূন্য f4(গণনা e6 e);
শূন্য f4(unsigned e); // should error as unsigned and e6 are incompatible

#নতুবা_যদি defined test_ptr_to_str
শূন্য f() { _Generic((পূর্ণসংখ্যা ধ্রুবক *[]){0}, পূর্ণসংখ্যা:0); }
#নতুবা_যদি defined test_fnptr_to_str
শূন্য f() { _Generic((পূর্ণসংখ্যা (*(*)(দশমিক,অক্ষর))(দ্বিগুণ,পূর্ণসংখ্যা)){0}, পূর্ণসংখ্যা:0); }
#নতুবা_যদি defined test_array_to_str
শূন্য f() { _Generic((পূর্ণসংখ্যা(*)[3]){0}, পূর্ণসংখ্যা:0); }
#নতুবা_যদি defined test_duplicate_def_1
স্থির গণনা myenum { L = -1 } L;                                                
#নতুবা_যদি defined test_duplicate_def_2
শূন্য foo(শূন্য) {
স্থির গণনা myenum { L = -1 } L;                                                
}
#নতুবা_যদি defined test_abstract_decls
পূর্ণসংখ্যা bar(ধ্রুবক অক্ষর *());     // abstract declarator here is okay
পূর্ণসংখ্যা bar (ধ্রুবক অক্ষর *(*g)()) // should match this 'g' argument
{
  g();
  ফেরত 42;
}
পূর্ণসংখ্যা foo(পূর্ণসংখ্যা ())              // abstract decl is wrong in definitions
{
  ফেরত 0;
#নতুবা_যদি defined test_invalid_1
শূন্য f(অক্ষর*);
শূন্য g(শূন্য) {
  f((অক্ষর[]){1, ,});
}
#নতুবা_যদি defined test_invalid_2
পূর্ণসংখ্যা ga = 0.42 { 2 };
#নতুবা_যদি defined test_invalid_3
কাঠামো S { পূর্ণসংখ্যা a, b; };
কাঠামো T { কাঠামো S x; };
কাঠামো T gt = { 42 a: 1, 43 };
#নতুবা_যদি defined test_invalid_4
গণনা E {
    x = 1 / 0
};
#নতুবা_যদি defined test_conflicting_types
পূর্ণসংখ্যা i;
শূন্য foo(শূন্য) {
    পূর্ণসংখ্যা i;
      {
        বাহ্যিক দ্বিগুণ i;
        i = 42.2;
      }
}
#নতুবা_যদি defined test_nested_types
সংঘ u {
    সংঘ u {
        পূর্ণসংখ্যা i;
    } m;
};
#নতুবা_যদি defined test_vla_1
পূর্ণসংখ্যা X=1;

পূর্ণসংখ্যা প্রধান(শূন্য) {
  পূর্ণসংখ্যা t[][][X];
}
#নতুবা_যদি defined test_invalid_alignas
/* _Alignas is no type qualifier */
শূন্য * _Alignas(16) p1;

#নতুবা_যদি defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 কাঠামো x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#নতুবা_যদি defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
কাঠামো y {  _Static_assert(0, "0"" is 0"); };

#নতুবা_যদি defined test_static_assert_c2x
 _Static_assert(1);
কাঠামো z {  _Static_assert(0); }

#নতুবা_যদি defined test_static_assert_empty_string
 _Static_assert(0,"");

#নতুবা_যদি defined test_void_array
 শূন্য t[3];

#নতুবা_যদি defined test_incomplete_enum_array
  গণনা e t[3];

#নতুবা_যদি defined test_incomplete_struct_array
  কাঠামো s t[3];

#নতুবা_যদি defined test_const_fun_array
  প্রকারলেখ শূন্য f(শূন্য);
  ধ্রুবক f t[3];

#নতুবা_যদি defined test_incomplete_array_array
  পূর্ণসংখ্যা t[][3]; // gr: not an error, see below

/******************************************************************/
#নতুবা_যদি defined test_extern_array
পূর্ণসংখ্যা iii[] = { 1,2,3 };
বাহ্যিক পূর্ণসংখ্যা iii[];
পূর্ণসংখ্যা x[];
পূর্ণসংখ্যা x[2];
পূর্ণসংখ্যা x[];
পূর্ণসংখ্যা x[2];
পূর্ণসংখ্যা x[];
বাহ্যিক পূর্ণসংখ্যা x[2];
বাহ্যিক পূর্ণসংখ্যা x[];
পূর্ণসংখ্যা x[3];

/******************************************************************/
#নতুবা_যদি defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#যদি defined test_func_1
পূর্ণসংখ্যা hello(পূর্ণসংখ্যা);
#নতুবা_যদি defined test_func_4
স্থির পূর্ণসংখ্যা hello(পূর্ণসংখ্যা);
#endif
পূর্ণসংখ্যা প্রধান () {
#যদি defined test_func_6
    স্থির
#endif
    পূর্ণসংখ্যা hello(পূর্ণসংখ্যা);
    hello(123);
    ফেরত 0;
}

#যদি defined test_func_3
স্থির পূর্ণসংখ্যা hello(পূর্ণসংখ্যা a)
#নতুবা_যদি defined test_func_5
পূর্ণসংখ্যা hello(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
#অন্যথা
পূর্ণসংখ্যা hello(পূর্ণসংখ্যা a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); ফেরত 0; }

/******************************************************************/
#নতুবা_যদি defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#যদি defined test_var_1
পূর্ণসংখ্যা xxx[];
#endif
পূর্ণসংখ্যা bar();

পূর্ণসংখ্যা প্রধান ()
{
#যদি !defined test_var_3
    পূর্ণসংখ্যা xxx = 2;
#endif
    {
        বাহ্যিক পূর্ণসংখ্যা xxx[
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
    ফেরত 0;
}
পূর্ণসংখ্যা xxx[1] = {1};
পূর্ণসংখ্যা bar() { P(3, xxx[0]); ফেরত 0; }

#নতুবা_যদি defined test_var_4
কাঠামো yyy { পূর্ণসংখ্যা y; };
কাঠামো zzz;
শূন্য f1() {
    বাহ্যিক অক্ষর *x;
    বাহ্যিক অক্ষর **xx;
    বাহ্যিক কাঠামো yyy y;
    বাহ্যিক কাঠামো yyy *yy;
    বাহ্যিক কাঠামো zzz z;
    বাহ্যিক কাঠামো zzz *zz;
}
শূন্য f2() {
    বাহ্যিক অক্ষর *x;
    বাহ্যিক অক্ষর **xx;
    বাহ্যিক কাঠামো yyy y;
    বাহ্যিক কাঠামো yyy *yy;
    বাহ্যিক কাঠামো zzz z;
    বাহ্যিক কাঠামো zzz *zz;
}
কাঠামো yyy y, *yy;
কাঠামো zzz { পূর্ণসংখ্যা z; } z, *zz;

/******************************************************************/
#নতুবা_যদি defined test_long_double_type_for_win32

পূর্ণসংখ্যা প্রধান()
{
    দ্বিগুণ *a = 0;
    long দ্বিগুণ *b = a;
    পূর্ণসংখ্যা n = _Generic(*a, দ্বিগুণ:0, long দ্বিগুণ:1);
}

#নতুবা_যদি defined test_stray_backslash
#define x \a
x

#নতুবা_যদি defined test_stray_backslash2

পূর্ণসংখ্যা প্রধান()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#নতুবা_যদি defined test_var_array

স্থির কাঠামো var_len { পূর্ণসংখ্যা i; ধ্রুবক অক্ষর str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#নতুবা_যদি defined test_var_array2

কাঠামো c1 { পূর্ণসংখ্যা a; পূর্ণসংখ্যা b[]; };
কাঠামো c1 c1 = { 1, { 2, 3, 4 } };

কাঠামো c2 { পূর্ণসংখ্যা c; কাঠামো c1 c1; };
কাঠামো c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#নতুবা_যদি defined test_var_array3
/* similar to test_var_array2 but with string initializers */
কাঠামো A { পূর্ণসংখ্যা a; অক্ষর b[]; };
কাঠামো A a = { 1, "1" };
কাঠামো B { কাঠামো A a; };
কাঠামো B b = { { 1, "1" } };
/******************************************************************/
#নতুবা_যদি defined test_default_int_type
n; // warn
f(); // don't warn

#নতুবা_যদি defined test_invalid_global_stmtexpr
n[আকার({3;})]; // crashed in block() due to missing local scope

#নতুবা_যদি defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#নতুবা_যদি defined test_duplicate_member
কাঠামো S {
  পূর্ণসংখ্যা a, a;
};
#নতুবা_যদি defined test_duplicate_member_anon
কাঠামো S1 {
  পূর্ণসংখ্যা b;
  কাঠামো {
    পূর্ণসংখ্যা b;
  } c;
};
কাঠামো S2 {
  পূর্ণসংখ্যা d;
  কাঠামো {
    পূর্ণসংখ্যা d;
  };
};

/******************************************************************/
#নতুবা_যদি defined test_conflicting_array_definition
বাহ্যিক পূর্ণসংখ্যা array[2];
পূর্ণসংখ্যা array[] = { 1, 2, 3 };

#নতুবা_যদি defined test_incompatible_local_redef
শূন্য foo (শূন্য)
{
  প্রকারলেখ পূর্ণসংখ্যা localfunctype (পূর্ণসংখ্যা);
  বাহ্যিক localfunctype func2;
  প্রকারলেখ শূন্য localfunctype (পূর্ণসংখ্যা, পূর্ণসংখ্যা);
}

#নতুবা_যদি defined test_cast_from_void
শূন্য v() {}
পূর্ণসংখ্যা f() { ফেরত v(); }

#নতুবা_যদি defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#যদি defined test_switch_W1
#pragma comment(option, "-Wall")
#নতুবা_যদি defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#নতুবা_যদি defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#নতুবা_যদি defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
শূন্য func(শূন্য)
{
    অক্ষর *ccp = "123";
    fink();
}
__attribute__((stuff)) পূর্ণসংখ্যা fink() {ফেরত 0;}

#নতুবা_যদি defined test_invalid_funcparam_1
শূন্য func(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b, পূর্ণসংখ্যা a);

#নতুবা_যদি defined test_invalid_funcparam_2
শূন্য func(পূর্ণসংখ্যা a, পূর্ণসংখ্যা যদি);

#নতুবা_যদি defined test_array_funcparam
পূর্ণসংখ্যা amain(পূর্ণসংখ্যা argc, অক্ষর *argv[স্থির argc + 1])
{
    পূর্ণসংখ্যা i;

    জন্য (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    ফেরত 0;
}
পূর্ণসংখ্যা প্রধান()
{
    ফেরত amain(2, (অক্ষর *[]){ "X", "Y", 0 });
}

#নতুবা_যদি defined test_return_from_statement_রাশিমালা
পূর্ণসংখ্যা f() { ({ ফেরত 78; }); }
পূর্ণসংখ্যা প্রধান() { ফেরত f(); }

/******************************************************************/

#নতুবা_যদি defined test_illegal_unicode
পূর্ণসংখ্যা প্রধান() {
    অক্ষর *str = "\Uffffffff";
}

#নতুবা_যদি defined test_error_string
#error \123\\
456

#নতুবা_যদি defined test_error_incomplete_type
কাঠামো A;
শূন্য f(কাঠামো A *);

পূর্ণসংখ্যা প্রধান()
{
    f(&(কাঠামো A){});
}

কাঠামো A {
    পূর্ণসংখ্যা x;
};

#নতুবা_যদি defined test_pp_error_1
# যদি //no expression
# endif
#নতুবা_যদি defined test_pp_error_2
# যদি X(1,2) //undefined function macro
# endif

#নতুবা_যদি defined test_pointer_plus_double

পূর্ণসংখ্যা *invalid_operation(পূর্ণসংখ্যা *p, দ্বিগুণ d)
{
    ফেরত p + d;
}

#নতুবা_যদি defined test_duplicate_case

পূর্ণসংখ্যা প্রধান()
{
    unsigned পূর্ণসংখ্যা x;
    নির্বাচন (x) {
        ক্ষেত্র -1 ... 0: /* empty case range with unsigned */
        ক্ষেত্র 3:
        ক্ষেত্র 1:
        ক্ষেত্র 2:
        ক্ষেত্র 3: /* show this line number in error */
        ক্ষেত্র 4:
        ক্ষেত্র 5:
    }
}
#নতুবা_যদি defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

পূর্ণসংখ্যা প্রধান()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#নতুবা_যদি defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

কাঠামো xxx {পূর্ণসংখ্যা x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
পূর্ণসংখ্যা bar(গণনা ee { a = 12, b = 34 } i, পূর্ণসংখ্যা(*f)(পূর্ণসংখ্যা i))
{
    printf("bar %d %d %d\n", i, a, b);
    ফেরত 0;
}
/* 'xxx' not defined outside of function */
পূর্ণসংখ্যা foo(কাঠামো xxx {পূর্ণসংখ্যা x[3];}*p)
{
    printf("foo %d", আকার *p);
    ফেরত p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
পূর্ণসংখ্যা foo(কাঠামো xxx {পূর্ণসংখ্যা x[2];}*p);
#endif
#ifndef test_scope_3
গণনা ee { a = 1, b };
#endif

কাঠামো xxx x = { 11,22,33,44 };
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    printf(" %d %d\n", foo(&x), আকার (কাঠামো xxx));
    গণনা ee e = b;
    bar(13 + e, 0);

}

#নতুবা_যদি defined test_const_array_member_addr_ok

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

int_array ধ্রুবক *get_array(ধ্রুবক my_struct *s)
{
    ফেরত &(s->arr);
}

#নতুবা_যদি defined test_const_array_member_decay_ok

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

ধ্রুবক পূর্ণসংখ্যা *good_decay(ধ্রুবক my_struct *s)
{
    ফেরত s->arr;
}

#নতুবা_যদি defined test_const_array_member_addr_bad

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

int_array *bad_array_addr(ধ্রুবক my_struct *s)
{
    ফেরত &(s->arr);
}

#নতুবা_যদি defined test_const_array_member_decay_bad

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

পূর্ণসংখ্যা *bad_decay(ধ্রুবক my_struct *s)
{
    ফেরত s->arr;
}

#নতুবা_যদি defined test_const_array_member_write_bad

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

শূন্য bad_write(ধ্রুবক my_struct *s)
{
    s->arr[0] = 1;
}

#নতুবা_যদি defined test_const_struct_array_member_write_bad

প্রকারলেখ কাঠামো { পূর্ণসংখ্যা x; } inner;
প্রকারলেখ কাঠামো { inner arr[1]; } outer;

শূন্য bad_inner_write(ধ্রুবক outer *s)
{
    s->arr[0].x = 1;
}

#নতুবা_যদি defined test_volatile_array_member_addr_ok

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

int_array অস্থির *get_volatile_array(অস্থির my_struct *s)
{
    ফেরত &(s->arr);
}

#নতুবা_যদি defined test_volatile_array_member_decay_ok

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

অস্থির পূর্ণসংখ্যা *good_volatile_decay(অস্থির my_struct *s)
{
    ফেরত s->arr;
}

#নতুবা_যদি defined test_volatile_array_member_addr_bad

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(অস্থির my_struct *s)
{
    ফেরত &(s->arr);
}

#নতুবা_যদি defined test_volatile_array_member_decay_bad

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

পূর্ণসংখ্যা *bad_volatile_decay(অস্থির my_struct *s)
{
    ফেরত s->arr;
}

#নতুবা_যদি defined test_volatile_array_member_write_ok

প্রকারলেখ পূর্ণসংখ্যা int_array[1];
প্রকারলেখ কাঠামো { int_array arr; } my_struct;

শূন্য good_volatile_write(অস্থির my_struct *s)
{
    s->arr[0] = 1;
}

#নতুবা_যদি defined test_conditional_array_qualifiers

প্রকারলেখ পূর্ণসংখ্যা Array2[2];
প্রকারলেখ পূর্ণসংখ্যা Array2x3[2][3];

Array2 *p;
ধ্রুবক Array2 *cp;
ধ্রুবক Array2x3 *cap;
অস্থির Array2x3 *vap;

শূন্য test(শূন্য)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#নতুবা_যদি defined test_restrict_scalar

restrict পূর্ণসংখ্যা object;

#নতুবা_যদি defined test_restrict_function_pointer

পূর্ণসংখ্যা (*restrict function_pointer)(শূন্য);

#নতুবা_যদি defined test_discarded_restrict

প্রকারলেখ পূর্ণসংখ্যা *restrict restricted_pointer;

restricted_pointer *source;
পূর্ণসংখ্যা **destination;

শূন্য test(শূন্য)
{
    destination = source;
}

#endif

صحيح printf(ثابت حرف*, ...);

#إذا defined test_56_btype_excess_1
بنية A {} صحيح i;
#وإلاإذا defined test_57_btype_excess_2
حرف صحيح i;
#وإلاإذا defined test_58_function_redefinition
صحيح f(فراغ) { أرجع 0; }
صحيح f(فراغ) { أرجع 1; }

#وإلاإذا defined test_global_redefinition
صحيح xxx = 1;
صحيح xxx;
صحيح xxx = 2;

#وإلاإذا defined test_59_function_array
صحيح (*fct)[42](صحيح x);

#وإلاإذا defined test_60_enum_redefinition
تعداد color { RED, GREEN, BLUE };
تعداد color { R, G, B };
تعداد color c;

#وإلاإذا defined test_62_enumerator_redefinition
تعداد color { RED, GREEN, BLUE };
تعداد rgb { RED, G, B};
تعداد color c = RED;

#وإلاإذا defined test_63_local_enumerator_redefinition
تعداد {
    FOO,
    BAR
};

صحيح main(فراغ)
{
    تعداد {
        FOO = 2,
        BAR
    };

    أرجع BAR - FOO;
}

#وإلاإذا defined test_61_undefined_enum
تعداد rgb3 c = 42;

#وإلاإذا defined test_74_non_const_init
صحيح i = i++;

#وإلاإذا defined test_pointer_assignment

فراغ (*f1)(فراغ);
فراغ f2(فراغ) {}

بنية s1 *ps1;
بنية s2 *ps2;

فراغ *v1, **v2, ***v3;

تعداد e1 { a = 4 } e10, *e11, *e12;
تعداد e2 { b = -4 } e20, *e21;
تعداد e3 { c = 5000000000LL } e30;

صحيح *ip;
unsigned صحيح *up;
long *lp;
long long *llp;

حرف **c1;
حرف ثابت **c2;
unsigned حرف **u1;

صحيح no_main ()
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

    أرجع 0;
}


#وإلاإذا defined test_enum_compat
تعداد e4;
تعداد e5;
فراغ f3(تعداد e4 e);
فراغ f3(تعداد e5 e);

#وإلاإذا defined test_enum_compat_2
تعداد e6 { E1 = -1, E0 };
فراغ f3(تعداد e6);
فراغ f3(صحيح);        // should work as int and e6 are compatible
فراغ f4(تعداد e6 e);
فراغ f4(unsigned e); // should error as unsigned and e6 are incompatible

#وإلاإذا defined test_ptr_to_str
فراغ f() { _Generic((صحيح ثابت *[]){0}, صحيح:0); }
#وإلاإذا defined test_fnptr_to_str
فراغ f() { _Generic((صحيح (*(*)(عائم,حرف))(مزدوج,صحيح)){0}, صحيح:0); }
#وإلاإذا defined test_array_to_str
فراغ f() { _Generic((صحيح(*)[3]){0}, صحيح:0); }
#وإلاإذا defined test_duplicate_def_1
ساكن تعداد myenum { L = -1 } L;                                                
#وإلاإذا defined test_duplicate_def_2
فراغ foo(فراغ) {
ساكن تعداد myenum { L = -1 } L;                                                
}
#وإلاإذا defined test_abstract_decls
صحيح bar(ثابت حرف *());     // abstract declarator here is okay
صحيح bar (ثابت حرف *(*g)()) // should match this 'g' argument
{
  g();
  أرجع 42;
}
صحيح foo(صحيح ())              // abstract decl is wrong in definitions
{
  أرجع 0;
#وإلاإذا defined test_invalid_1
فراغ f(حرف*);
فراغ g(فراغ) {
  f((حرف[]){1, ,});
}
#وإلاإذا defined test_invalid_2
صحيح ga = 0.42 { 2 };
#وإلاإذا defined test_invalid_3
بنية S { صحيح a, b; };
بنية T { بنية S x; };
بنية T gt = { 42 a: 1, 43 };
#وإلاإذا defined test_invalid_4
تعداد E {
    x = 1 / 0
};
#وإلاإذا defined test_conflicting_types
صحيح i;
فراغ foo(فراغ) {
    صحيح i;
      {
        خارجي مزدوج i;
        i = 42.2;
      }
}
#وإلاإذا defined test_nested_types
اتحاد u {
    اتحاد u {
        صحيح i;
    } m;
};
#وإلاإذا defined test_vla_1
صحيح X=1;

صحيح main(فراغ) {
  صحيح t[][][X];
}
#وإلاإذا defined test_invalid_alignas
/* _Alignas is no type qualifier */
فراغ * _Alignas(16) p1;

#وإلاإذا defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 بنية x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#وإلاإذا defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
بنية y {  _Static_assert(0, "0"" is 0"); };

#وإلاإذا defined test_static_assert_c2x
 _Static_assert(1);
بنية z {  _Static_assert(0); }

#وإلاإذا defined test_static_assert_empty_string
 _Static_assert(0,"");

#وإلاإذا defined test_void_array
 فراغ t[3];

#وإلاإذا defined test_incomplete_enum_array
  تعداد e t[3];

#وإلاإذا defined test_incomplete_struct_array
  بنية s t[3];

#وإلاإذا defined test_const_fun_array
  تعريفنوع فراغ f(فراغ);
  ثابت f t[3];

#وإلاإذا defined test_incomplete_array_array
  صحيح t[][3]; // gr: not an error, see below

/******************************************************************/
#وإلاإذا defined test_extern_array
صحيح iii[] = { 1,2,3 };
خارجي صحيح iii[];
صحيح x[];
صحيح x[2];
صحيح x[];
صحيح x[2];
صحيح x[];
خارجي صحيح x[2];
خارجي صحيح x[];
صحيح x[3];

/******************************************************************/
#وإلاإذا defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#إذا defined test_func_1
صحيح hello(صحيح);
#وإلاإذا defined test_func_4
ساكن صحيح hello(صحيح);
#endif
صحيح main () {
#إذا defined test_func_6
    ساكن
#endif
    صحيح hello(صحيح);
    hello(123);
    أرجع 0;
}

#إذا defined test_func_3
ساكن صحيح hello(صحيح a)
#وإلاإذا defined test_func_5
صحيح hello(صحيح a, صحيح b)
#وإلا
صحيح hello(صحيح a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); أرجع 0; }

/******************************************************************/
#وإلاإذا defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#إذا defined test_var_1
صحيح xxx[];
#endif
صحيح bar();

صحيح main ()
{
#إذا !defined test_var_3
    صحيح xxx = 2;
#endif
    {
        خارجي صحيح xxx[
#إذا defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#إذا !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    أرجع 0;
}
صحيح xxx[1] = {1};
صحيح bar() { P(3, xxx[0]); أرجع 0; }

#وإلاإذا defined test_var_4
بنية yyy { صحيح y; };
بنية zzz;
فراغ f1() {
    خارجي حرف *x;
    خارجي حرف **xx;
    خارجي بنية yyy y;
    خارجي بنية yyy *yy;
    خارجي بنية zzz z;
    خارجي بنية zzz *zz;
}
فراغ f2() {
    خارجي حرف *x;
    خارجي حرف **xx;
    خارجي بنية yyy y;
    خارجي بنية yyy *yy;
    خارجي بنية zzz z;
    خارجي بنية zzz *zz;
}
بنية yyy y, *yy;
بنية zzz { صحيح z; } z, *zz;

/******************************************************************/
#وإلاإذا defined test_long_double_type_for_win32

صحيح main()
{
    مزدوج *a = 0;
    long مزدوج *b = a;
    صحيح n = _Generic(*a, مزدوج:0, long مزدوج:1);
}

#وإلاإذا defined test_stray_backslash
#define x \a
x

#وإلاإذا defined test_stray_backslash2

صحيح main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#وإلاإذا defined test_var_array

ساكن بنية var_len { صحيح i; ثابت حرف str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#وإلاإذا defined test_var_array2

بنية c1 { صحيح a; صحيح b[]; };
بنية c1 c1 = { 1, { 2, 3, 4 } };

بنية c2 { صحيح c; بنية c1 c1; };
بنية c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#وإلاإذا defined test_var_array3
/* similar to test_var_array2 but with string initializers */
بنية A { صحيح a; حرف b[]; };
بنية A a = { 1, "1" };
بنية B { بنية A a; };
بنية B b = { { 1, "1" } };
/******************************************************************/
#وإلاإذا defined test_default_int_type
n; // warn
f(); // don't warn

#وإلاإذا defined test_invalid_global_stmtexpr
n[حجم({3;})]; // crashed in block() due to missing local scope

#وإلاإذا defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#وإلاإذا defined test_duplicate_member
بنية S {
  صحيح a, a;
};
#وإلاإذا defined test_duplicate_member_anon
بنية S1 {
  صحيح b;
  بنية {
    صحيح b;
  } c;
};
بنية S2 {
  صحيح d;
  بنية {
    صحيح d;
  };
};

/******************************************************************/
#وإلاإذا defined test_conflicting_array_definition
خارجي صحيح array[2];
صحيح array[] = { 1, 2, 3 };

#وإلاإذا defined test_incompatible_local_redef
فراغ foo (فراغ)
{
  تعريفنوع صحيح localfunctype (صحيح);
  خارجي localfunctype func2;
  تعريفنوع فراغ localfunctype (صحيح, صحيح);
}

#وإلاإذا defined test_cast_from_void
فراغ v() {}
صحيح f() { أرجع v(); }

#وإلاإذا defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#إذا defined test_switch_W1
#pragma comment(option, "-Wall")
#وإلاإذا defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#وإلاإذا defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#وإلاإذا defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
فراغ func(فراغ)
{
    حرف *ccp = "123";
    fink();
}
__attribute__((stuff)) صحيح fink() {أرجع 0;}

#وإلاإذا defined test_invalid_funcparam_1
فراغ func(صحيح a, صحيح b, صحيح a);

#وإلاإذا defined test_invalid_funcparam_2
فراغ func(صحيح a, صحيح إذا);

#وإلاإذا defined test_array_funcparam
صحيح amain(صحيح argc, حرف *argv[ساكن argc + 1])
{
    صحيح i;

    لكل (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    أرجع 0;
}
صحيح main()
{
    أرجع amain(2, (حرف *[]){ "X", "Y", 0 });
}

#وإلاإذا defined test_return_from_statement_فرچ
صحيح f() { ({ أرجع 78; }); }
صحيح main() { أرجع f(); }

/******************************************************************/

#وإلاإذا defined test_illegal_unicode
صحيح main() {
    حرف *str = "\Uffffffff";
}

#وإلاإذا defined test_error_string
#error \123\\
456

#وإلاإذا defined test_error_incomplete_type
بنية A;
فراغ f(بنية A *);

صحيح main()
{
    f(&(بنية A){});
}

بنية A {
    صحيح x;
};

#وإلاإذا defined test_pp_error_1
# إذا //no expression
# endif
#وإلاإذا defined test_pp_error_2
# إذا X(1,2) //undefined function macro
# endif

#وإلاإذا defined test_pointer_plus_double

صحيح *invalid_operation(صحيح *p, مزدوج d)
{
    أرجع p + d;
}

#وإلاإذا defined test_duplicate_case

صحيح main()
{
    unsigned صحيح x;
    بدل (x) {
        حالة -1 ... 0: /* empty case range with unsigned */
        حالة 3:
        حالة 1:
        حالة 2:
        حالة 3: /* show this line number in error */
        حالة 4:
        حالة 5:
    }
}
#وإلاإذا defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

صحيح main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#وإلاإذا defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

بنية xxx {صحيح x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
صحيح bar(تعداد ee { a = 12, b = 34 } i, صحيح(*f)(صحيح i))
{
    printf("bar %d %d %d\n", i, a, b);
    أرجع 0;
}
/* 'xxx' not defined outside of function */
صحيح foo(بنية xxx {صحيح x[3];}*p)
{
    printf("foo %d", حجم *p);
    أرجع p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
صحيح foo(بنية xxx {صحيح x[2];}*p);
#endif
#ifndef test_scope_3
تعداد ee { a = 1, b };
#endif

بنية xxx x = { 11,22,33,44 };
صحيح main(صحيح argc, حرف **argv)
{
    printf(" %d %d\n", foo(&x), حجم (بنية xxx));
    تعداد ee e = b;
    bar(13 + e, 0);

}

#وإلاإذا defined test_const_array_member_addr_ok

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

int_array ثابت *get_array(ثابت my_struct *s)
{
    أرجع &(s->arr);
}

#وإلاإذا defined test_const_array_member_decay_ok

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

ثابت صحيح *good_decay(ثابت my_struct *s)
{
    أرجع s->arr;
}

#وإلاإذا defined test_const_array_member_addr_bad

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

int_array *bad_array_addr(ثابت my_struct *s)
{
    أرجع &(s->arr);
}

#وإلاإذا defined test_const_array_member_decay_bad

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

صحيح *bad_decay(ثابت my_struct *s)
{
    أرجع s->arr;
}

#وإلاإذا defined test_const_array_member_write_bad

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

فراغ bad_write(ثابت my_struct *s)
{
    s->arr[0] = 1;
}

#وإلاإذا defined test_const_struct_array_member_write_bad

تعريفنوع بنية { صحيح x; } inner;
تعريفنوع بنية { inner arr[1]; } outer;

فراغ bad_inner_write(ثابت outer *s)
{
    s->arr[0].x = 1;
}

#وإلاإذا defined test_volatile_array_member_addr_ok

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

int_array متطاير *get_volatile_array(متطاير my_struct *s)
{
    أرجع &(s->arr);
}

#وإلاإذا defined test_volatile_array_member_decay_ok

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

متطاير صحيح *good_volatile_decay(متطاير my_struct *s)
{
    أرجع s->arr;
}

#وإلاإذا defined test_volatile_array_member_addr_bad

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(متطاير my_struct *s)
{
    أرجع &(s->arr);
}

#وإلاإذا defined test_volatile_array_member_decay_bad

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

صحيح *bad_volatile_decay(متطاير my_struct *s)
{
    أرجع s->arr;
}

#وإلاإذا defined test_volatile_array_member_write_ok

تعريفنوع صحيح int_array[1];
تعريفنوع بنية { int_array arr; } my_struct;

فراغ good_volatile_write(متطاير my_struct *s)
{
    s->arr[0] = 1;
}

#وإلاإذا defined test_conditional_array_qualifiers

تعريفنوع صحيح Array2[2];
تعريفنوع صحيح Array2x3[2][3];

Array2 *p;
ثابت Array2 *cp;
ثابت Array2x3 *cap;
متطاير Array2x3 *vap;

فراغ test(فراغ)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#وإلاإذا defined test_restrict_scalar

restrict صحيح object;

#وإلاإذا defined test_restrict_function_pointer

صحيح (*restrict function_pointer)(فراغ);

#وإلاإذا defined test_discarded_restrict

تعريفنوع صحيح *restrict restricted_pointer;

restricted_pointer *source;
صحيح **destination;

فراغ test(فراغ)
{
    destination = source;
}

#endif

صحیح printf(ثابت نویسه*, ...);

#اگر defined test_56_btype_excess_1
ساختار A {} صحیح i;
#وگرنهاگر defined test_57_btype_excess_2
نویسه صحیح i;
#وگرنهاگر defined test_58_function_redefinition
صحیح f(تهی) { بازگشت 0; }
صحیح f(تهی) { بازگشت 1; }

#وگرنهاگر defined test_global_redefinition
صحیح xxx = 1;
صحیح xxx;
صحیح xxx = 2;

#وگرنهاگر defined test_59_function_array
صحیح (*fct)[42](صحیح x);

#وگرنهاگر defined test_60_enum_redefinition
شمارش color { RED, GREEN, BLUE };
شمارش color { R, G, B };
شمارش color c;

#وگرنهاگر defined test_62_enumerator_redefinition
شمارش color { RED, GREEN, BLUE };
شمارش rgb { RED, G, B};
شمارش color c = RED;

#وگرنهاگر defined test_63_local_enumerator_redefinition
شمارش {
    FOO,
    BAR
};

صحیح اصلی(تهی)
{
    شمارش {
        FOO = 2,
        BAR
    };

    بازگشت BAR - FOO;
}

#وگرنهاگر defined test_61_undefined_enum
شمارش rgb3 c = 42;

#وگرنهاگر defined test_74_non_const_init
صحیح i = i++;

#وگرنهاگر defined test_pointer_assignment

تهی (*f1)(تهی);
تهی f2(تهی) {}

ساختار s1 *ps1;
ساختار s2 *ps2;

تهی *v1, **v2, ***v3;

شمارش e1 { a = 4 } e10, *e11, *e12;
شمارش e2 { b = -4 } e20, *e21;
شمارش e3 { c = 5000000000LL } e30;

صحیح *ip;
unsigned صحیح *up;
long *lp;
long long *llp;

نویسه **c1;
نویسه ثابت **c2;
unsigned نویسه **u1;

صحیح no_main ()
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

    بازگشت 0;
}


#وگرنهاگر defined test_enum_compat
شمارش e4;
شمارش e5;
تهی f3(شمارش e4 e);
تهی f3(شمارش e5 e);

#وگرنهاگر defined test_enum_compat_2
شمارش e6 { E1 = -1, E0 };
تهی f3(شمارش e6);
تهی f3(صحیح);        // should work as int and e6 are compatible
تهی f4(شمارش e6 e);
تهی f4(unsigned e); // should error as unsigned and e6 are incompatible

#وگرنهاگر defined test_ptr_to_str
تهی f() { _Generic((صحیح ثابت *[]){0}, صحیح:0); }
#وگرنهاگر defined test_fnptr_to_str
تهی f() { _Generic((صحیح (*(*)(اعشاری,نویسه))(دوگانه,صحیح)){0}, صحیح:0); }
#وگرنهاگر defined test_array_to_str
تهی f() { _Generic((صحیح(*)[3]){0}, صحیح:0); }
#وگرنهاگر defined test_duplicate_def_1
ایستا شمارش myenum { L = -1 } L;                                                
#وگرنهاگر defined test_duplicate_def_2
تهی foo(تهی) {
ایستا شمارش myenum { L = -1 } L;                                                
}
#وگرنهاگر defined test_abstract_decls
صحیح bar(ثابت نویسه *());     // abstract declarator here is okay
صحیح bar (ثابت نویسه *(*g)()) // should match this 'g' argument
{
  g();
  بازگشت 42;
}
صحیح foo(صحیح ())              // abstract decl is wrong in definitions
{
  بازگشت 0;
#وگرنهاگر defined test_invalid_1
تهی f(نویسه*);
تهی g(تهی) {
  f((نویسه[]){1, ,});
}
#وگرنهاگر defined test_invalid_2
صحیح ga = 0.42 { 2 };
#وگرنهاگر defined test_invalid_3
ساختار S { صحیح a, b; };
ساختار T { ساختار S x; };
ساختار T gt = { 42 a: 1, 43 };
#وگرنهاگر defined test_invalid_4
شمارش E {
    x = 1 / 0
};
#وگرنهاگر defined test_conflicting_types
صحیح i;
تهی foo(تهی) {
    صحیح i;
      {
        بیرونی دوگانه i;
        i = 42.2;
      }
}
#وگرنهاگر defined test_nested_types
اجتماع u {
    اجتماع u {
        صحیح i;
    } m;
};
#وگرنهاگر defined test_vla_1
صحیح X=1;

صحیح اصلی(تهی) {
  صحیح t[][][X];
}
#وگرنهاگر defined test_invalid_alignas
/* _Alignas is no type qualifier */
تهی * _Alignas(16) p1;

#وگرنهاگر defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ساختار x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#وگرنهاگر defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ساختار y {  _Static_assert(0, "0"" is 0"); };

#وگرنهاگر defined test_static_assert_c2x
 _Static_assert(1);
ساختار z {  _Static_assert(0); }

#وگرنهاگر defined test_static_assert_empty_string
 _Static_assert(0,"");

#وگرنهاگر defined test_void_array
 تهی t[3];

#وگرنهاگر defined test_incomplete_enum_array
  شمارش e t[3];

#وگرنهاگر defined test_incomplete_struct_array
  ساختار s t[3];

#وگرنهاگر defined test_const_fun_array
  تعریفنوع تهی f(تهی);
  ثابت f t[3];

#وگرنهاگر defined test_incomplete_array_array
  صحیح t[][3]; // gr: not an error, see below

/******************************************************************/
#وگرنهاگر defined test_extern_array
صحیح iii[] = { 1,2,3 };
بیرونی صحیح iii[];
صحیح x[];
صحیح x[2];
صحیح x[];
صحیح x[2];
صحیح x[];
بیرونی صحیح x[2];
بیرونی صحیح x[];
صحیح x[3];

/******************************************************************/
#وگرنهاگر defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#اگر defined test_func_1
صحیح hello(صحیح);
#وگرنهاگر defined test_func_4
ایستا صحیح hello(صحیح);
#endif
صحیح اصلی () {
#اگر defined test_func_6
    ایستا
#endif
    صحیح hello(صحیح);
    hello(123);
    بازگشت 0;
}

#اگر defined test_func_3
ایستا صحیح hello(صحیح a)
#وگرنهاگر defined test_func_5
صحیح hello(صحیح a, صحیح b)
#وگرنه
صحیح hello(صحیح a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); بازگشت 0; }

/******************************************************************/
#وگرنهاگر defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#اگر defined test_var_1
صحیح xxx[];
#endif
صحیح bar();

صحیح اصلی ()
{
#اگر !defined test_var_3
    صحیح xxx = 2;
#endif
    {
        بیرونی صحیح xxx[
#اگر defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#اگر !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    بازگشت 0;
}
صحیح xxx[1] = {1};
صحیح bar() { P(3, xxx[0]); بازگشت 0; }

#وگرنهاگر defined test_var_4
ساختار yyy { صحیح y; };
ساختار zzz;
تهی f1() {
    بیرونی نویسه *x;
    بیرونی نویسه **xx;
    بیرونی ساختار yyy y;
    بیرونی ساختار yyy *yy;
    بیرونی ساختار zzz z;
    بیرونی ساختار zzz *zz;
}
تهی f2() {
    بیرونی نویسه *x;
    بیرونی نویسه **xx;
    بیرونی ساختار yyy y;
    بیرونی ساختار yyy *yy;
    بیرونی ساختار zzz z;
    بیرونی ساختار zzz *zz;
}
ساختار yyy y, *yy;
ساختار zzz { صحیح z; } z, *zz;

/******************************************************************/
#وگرنهاگر defined test_long_double_type_for_win32

صحیح اصلی()
{
    دوگانه *a = 0;
    long دوگانه *b = a;
    صحیح n = _Generic(*a, دوگانه:0, long دوگانه:1);
}

#وگرنهاگر defined test_stray_backslash
#define x \a
x

#وگرنهاگر defined test_stray_backslash2

صحیح اصلی()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#وگرنهاگر defined test_var_array

ایستا ساختار var_len { صحیح i; ثابت نویسه str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#وگرنهاگر defined test_var_array2

ساختار c1 { صحیح a; صحیح b[]; };
ساختار c1 c1 = { 1, { 2, 3, 4 } };

ساختار c2 { صحیح c; ساختار c1 c1; };
ساختار c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#وگرنهاگر defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ساختار A { صحیح a; نویسه b[]; };
ساختار A a = { 1, "1" };
ساختار B { ساختار A a; };
ساختار B b = { { 1, "1" } };
/******************************************************************/
#وگرنهاگر defined test_default_int_type
n; // warn
f(); // don't warn

#وگرنهاگر defined test_invalid_global_stmtexpr
n[اندازه({3;})]; // crashed in block() due to missing local scope

#وگرنهاگر defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#وگرنهاگر defined test_duplicate_member
ساختار S {
  صحیح a, a;
};
#وگرنهاگر defined test_duplicate_member_anon
ساختار S1 {
  صحیح b;
  ساختار {
    صحیح b;
  } c;
};
ساختار S2 {
  صحیح d;
  ساختار {
    صحیح d;
  };
};

/******************************************************************/
#وگرنهاگر defined test_conflicting_array_definition
بیرونی صحیح array[2];
صحیح array[] = { 1, 2, 3 };

#وگرنهاگر defined test_incompatible_local_redef
تهی foo (تهی)
{
  تعریفنوع صحیح localfunctype (صحیح);
  بیرونی localfunctype func2;
  تعریفنوع تهی localfunctype (صحیح, صحیح);
}

#وگرنهاگر defined test_cast_from_void
تهی v() {}
صحیح f() { بازگشت v(); }

#وگرنهاگر defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#اگر defined test_switch_W1
#pragma comment(option, "-Wall")
#وگرنهاگر defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#وگرنهاگر defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#وگرنهاگر defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
تهی func(تهی)
{
    نویسه *ccp = "123";
    fink();
}
__attribute__((stuff)) صحیح fink() {بازگشت 0;}

#وگرنهاگر defined test_invalid_funcparam_1
تهی func(صحیح a, صحیح b, صحیح a);

#وگرنهاگر defined test_invalid_funcparam_2
تهی func(صحیح a, صحیح اگر);

#وگرنهاگر defined test_array_funcparam
صحیح amain(صحیح argc, نویسه *argv[ایستا argc + 1])
{
    صحیح i;

    برای (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    بازگشت 0;
}
صحیح اصلی()
{
    بازگشت amain(2, (نویسه *[]){ "X", "Y", 0 });
}

#وگرنهاگر defined test_return_from_statement_عبارت
صحیح f() { ({ بازگشت 78; }); }
صحیح اصلی() { بازگشت f(); }

/******************************************************************/

#وگرنهاگر defined test_illegal_unicode
صحیح اصلی() {
    نویسه *str = "\Uffffffff";
}

#وگرنهاگر defined test_error_string
#error \123\\
456

#وگرنهاگر defined test_error_incomplete_type
ساختار A;
تهی f(ساختار A *);

صحیح اصلی()
{
    f(&(ساختار A){});
}

ساختار A {
    صحیح x;
};

#وگرنهاگر defined test_pp_error_1
# اگر //no expression
# endif
#وگرنهاگر defined test_pp_error_2
# اگر X(1,2) //undefined function macro
# endif

#وگرنهاگر defined test_pointer_plus_double

صحیح *invalid_operation(صحیح *p, دوگانه d)
{
    بازگشت p + d;
}

#وگرنهاگر defined test_duplicate_case

صحیح اصلی()
{
    unsigned صحیح x;
    انتخاب (x) {
        حالت -1 ... 0: /* empty case range with unsigned */
        حالت 3:
        حالت 1:
        حالت 2:
        حالت 3: /* show this line number in error */
        حالت 4:
        حالت 5:
    }
}
#وگرنهاگر defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

صحیح اصلی()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#وگرنهاگر defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ساختار xxx {صحیح x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
صحیح bar(شمارش ee { a = 12, b = 34 } i, صحیح(*f)(صحیح i))
{
    printf("bar %d %d %d\n", i, a, b);
    بازگشت 0;
}
/* 'xxx' not defined outside of function */
صحیح foo(ساختار xxx {صحیح x[3];}*p)
{
    printf("foo %d", اندازه *p);
    بازگشت p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
صحیح foo(ساختار xxx {صحیح x[2];}*p);
#endif
#ifndef test_scope_3
شمارش ee { a = 1, b };
#endif

ساختار xxx x = { 11,22,33,44 };
صحیح اصلی(صحیح argc, نویسه **argv)
{
    printf(" %d %d\n", foo(&x), اندازه (ساختار xxx));
    شمارش ee e = b;
    bar(13 + e, 0);

}

#وگرنهاگر defined test_const_array_member_addr_ok

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

int_array ثابت *get_array(ثابت my_struct *s)
{
    بازگشت &(s->arr);
}

#وگرنهاگر defined test_const_array_member_decay_ok

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

ثابت صحیح *good_decay(ثابت my_struct *s)
{
    بازگشت s->arr;
}

#وگرنهاگر defined test_const_array_member_addr_bad

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

int_array *bad_array_addr(ثابت my_struct *s)
{
    بازگشت &(s->arr);
}

#وگرنهاگر defined test_const_array_member_decay_bad

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

صحیح *bad_decay(ثابت my_struct *s)
{
    بازگشت s->arr;
}

#وگرنهاگر defined test_const_array_member_write_bad

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

تهی bad_write(ثابت my_struct *s)
{
    s->arr[0] = 1;
}

#وگرنهاگر defined test_const_struct_array_member_write_bad

تعریفنوع ساختار { صحیح x; } inner;
تعریفنوع ساختار { inner arr[1]; } outer;

تهی bad_inner_write(ثابت outer *s)
{
    s->arr[0].x = 1;
}

#وگرنهاگر defined test_volatile_array_member_addr_ok

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

int_array فرار *get_volatile_array(فرار my_struct *s)
{
    بازگشت &(s->arr);
}

#وگرنهاگر defined test_volatile_array_member_decay_ok

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

فرار صحیح *good_volatile_decay(فرار my_struct *s)
{
    بازگشت s->arr;
}

#وگرنهاگر defined test_volatile_array_member_addr_bad

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(فرار my_struct *s)
{
    بازگشت &(s->arr);
}

#وگرنهاگر defined test_volatile_array_member_decay_bad

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

صحیح *bad_volatile_decay(فرار my_struct *s)
{
    بازگشت s->arr;
}

#وگرنهاگر defined test_volatile_array_member_write_ok

تعریفنوع صحیح int_array[1];
تعریفنوع ساختار { int_array arr; } my_struct;

تهی good_volatile_write(فرار my_struct *s)
{
    s->arr[0] = 1;
}

#وگرنهاگر defined test_conditional_array_qualifiers

تعریفنوع صحیح Array2[2];
تعریفنوع صحیح Array2x3[2][3];

Array2 *p;
ثابت Array2 *cp;
ثابت Array2x3 *cap;
فرار Array2x3 *vap;

تهی test(تهی)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#وگرنهاگر defined test_restrict_scalar

restrict صحیح object;

#وگرنهاگر defined test_restrict_function_pointer

صحیح (*restrict function_pointer)(تهی);

#وگرنهاگر defined test_discarded_restrict

تعریفنوع صحیح *restrict restricted_pointer;

restricted_pointer *source;
صحیح **destination;

تهی test(تهی)
{
    destination = source;
}

#endif

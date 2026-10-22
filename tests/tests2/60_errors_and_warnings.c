صحیح لکھو(ثابت حرف*, ...);

#اگر defined test_56_btype_excess_1
ساخت A {} صحیح i;
#وگرنہ_اگر defined test_57_btype_excess_2
حرف صحیح i;
#وگرنہ_اگر defined test_58_function_redefinition
صحیح f(خالی) { واپس 0; }
صحیح f(خالی) { واپس 1; }

#وگرنہ_اگر defined test_global_redefinition
صحیح xxx = 1;
صحیح xxx;
صحیح xxx = 2;

#وگرنہ_اگر defined test_59_function_array
صحیح (*fct)[42](صحیح x);

#وگرنہ_اگر defined test_60_enum_redefinition
شمار color { RED, GREEN, BLUE };
شمار color { R, G, B };
شمار color c;

#وگرنہ_اگر defined test_62_enumerator_redefinition
شمار color { RED, GREEN, BLUE };
شمار rgb { RED, G, B};
شمار color c = RED;

#وگرنہ_اگر defined test_63_local_enumerator_redefinition
شمار {
    FOO,
    BAR
};

صحیح مین(خالی)
{
    شمار {
        FOO = 2,
        BAR
    };

    واپس BAR - FOO;
}

#وگرنہ_اگر defined test_61_undefined_enum
شمار rgb3 c = 42;

#وگرنہ_اگر defined test_74_non_const_init
صحیح i = i++;

#وگرنہ_اگر defined test_اشارہ_گر_assignment

خالی (*f1)(خالی);
خالی f2(خالی) {}

ساخت s1 *ps1;
ساخت s2 *ps2;

خالی *v1, **v2, ***v3;

شمار e1 { a = 4 } e10, *e11, *e12;
شمار e2 { b = -4 } e20, *e21;
شمار e3 { c = 5000000000LL } e30;

صحیح *ip;
غیرعلامتی صحیح *اوپر;
طویل *lp;
طویل طویل *llp;

حرف **c1;
حرف ثابت **c2;
غیرعلامتی حرف **u1;

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
    اوپر = &e10;
    اوپر = &e20;
    اوپر = &e30;

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

    واپس 0;
}


#وگرنہ_اگر defined test_enum_compat
شمار e4;
شمار e5;
خالی f3(شمار e4 e);
خالی f3(شمار e5 e);

#وگرنہ_اگر defined test_enum_compat_2
شمار e6 { E1 = -1, E0 };
خالی f3(شمار e6);
خالی f3(صحیح);        // should work as int and e6 are compatible
خالی f4(شمار e6 e);
خالی f4(غیرعلامتی e); // should error as unsigned and e6 are incompatible

#وگرنہ_اگر defined test_ptr_مقصد_str
خالی f() { _Generic((صحیح ثابت *[]){0}, صحیح:0); }
#وگرنہ_اگر defined test_fnptr_مقصد_str
خالی f() { _Generic((صحیح (*(*)(اعشاری,حرف))(دوہرا,صحیح)){0}, صحیح:0); }
#وگرنہ_اگر defined test_array_مقصد_str
خالی f() { _Generic((صحیح(*)[3]){0}, صحیح:0); }
#وگرنہ_اگر defined test_duplicate_def_1
ساکن شمار myenum { L = -1 } L;                                                
#وگرنہ_اگر defined test_duplicate_def_2
خالی foo(خالی) {
ساکن شمار myenum { L = -1 } L;                                                
}
#وگرنہ_اگر defined test_abstract_decls
صحیح bar(ثابت حرف *());     // abstract declarator here is okay
صحیح bar (ثابت حرف *(*g)()) // should match this 'g' argument
{
  g();
  واپس 42;
}
صحیح foo(صحیح ())              // abstract decl is wrong in definitions
{
  واپس 0;
#وگرنہ_اگر defined test_invalid_1
خالی f(حرف*);
خالی g(خالی) {
  f((حرف[]){1, ,});
}
#وگرنہ_اگر defined test_invalid_2
صحیح ga = 0.42 { 2 };
#وگرنہ_اگر defined test_invalid_3
ساخت S { صحیح a, b; };
ساخت T { ساخت S x; };
ساخت T gt = { 42 a: 1, 43 };
#وگرنہ_اگر defined test_invalid_4
شمار E {
    x = 1 / 0
};
#وگرنہ_اگر defined test_conflicting_types
صحیح i;
خالی foo(خالی) {
    صحیح i;
      {
        خارجی دوہرا i;
        i = 42.2;
      }
}
#وگرنہ_اگر defined test_nested_types
اتحاد u {
    اتحاد u {
        صحیح i;
    } m;
};
#وگرنہ_اگر defined test_vla_1
صحیح X=1;

صحیح مین(خالی) {
  صحیح t[][][X];
}
#وگرنہ_اگر defined test_invalid_alignas
/* _Alignas is no type qualifier */
خالی * _Alignas(16) p1;

#وگرنہ_اگر defined test_static_assert

#تعریف_کرو ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 ساخت x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#وگرنہ_اگر defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
ساخت y {  _Static_assert(0, "0"" is 0"); };

#وگرنہ_اگر defined test_static_assert_c2x
 _Static_assert(1);
ساخت z {  _Static_assert(0); }

#وگرنہ_اگر defined test_static_assert_خالی_خانے_string
 _Static_assert(0,"");

#وگرنہ_اگر defined test_void_array
 خالی t[3];

#وگرنہ_اگر defined test_incomplete_enum_array
  شمار e t[3];

#وگرنہ_اگر defined test_incomplete_struct_array
  ساخت s t[3];

#وگرنہ_اگر defined test_const_fun_array
  قسمتعریف خالی f(خالی);
  ثابت f t[3];

#وگرنہ_اگر defined test_incomplete_array_array
  صحیح t[][3]; // gr: not an error, see below

/******************************************************************/
#وگرنہ_اگر defined test_extern_array
صحیح iii[] = { 1,2,3 };
خارجی صحیح iii[];
صحیح x[];
صحیح x[2];
صحیح x[];
صحیح x[2];
صحیح x[];
خارجی صحیح x[2];
خارجی صحیح x[];
صحیح x[3];

/******************************************************************/
#وگرنہ_اگر defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#اگر defined test_func_1
صحیح hello(صحیح);
#وگرنہ_اگر defined test_func_4
ساکن صحیح hello(صحیح);
#اگر_ختم
صحیح مین () {
#اگر defined test_func_6
    ساکن
#اگر_ختم
    صحیح hello(صحیح);
    hello(123);
    واپس 0;
}

#اگر defined test_func_3
ساکن صحیح hello(صحیح a)
#وگرنہ_اگر defined test_func_5
صحیح hello(صحیح a, صحیح b)
#ورنہ
صحیح hello(صحیح a)
#اگر_ختم
{ لکھو("%s: a = %d\n", __FUNCTION__, a); واپس 0; }

/******************************************************************/
#وگرنہ_اگر defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#تعریف_کرو P(n,v) لکھو("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#اگر defined test_var_1
صحیح xxx[];
#اگر_ختم
صحیح bar();

صحیح مین ()
{
#اگر !defined test_var_3
    صحیح xxx = 2;
#اگر_ختم
    {
        خارجی صحیح xxx[
#اگر defined test_var_3
        2
#اگر_ختم
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#اگر !defined test_var_3
    P(2, xxx);
#اگر_ختم
    bar(123);
    واپس 0;
}
صحیح xxx[1] = {1};
صحیح bar() { P(3, xxx[0]); واپس 0; }

#وگرنہ_اگر defined test_var_4
ساخت yyy { صحیح y; };
ساخت zzz;
خالی f1() {
    خارجی حرف *x;
    خارجی حرف **xx;
    خارجی ساخت yyy y;
    خارجی ساخت yyy *yy;
    خارجی ساخت zzz z;
    خارجی ساخت zzz *zz;
}
خالی f2() {
    خارجی حرف *x;
    خارجی حرف **xx;
    خارجی ساخت yyy y;
    خارجی ساخت yyy *yy;
    خارجی ساخت zzz z;
    خارجی ساخت zzz *zz;
}
ساخت yyy y, *yy;
ساخت zzz { صحیح z; } z, *zz;

/******************************************************************/
#وگرنہ_اگر defined test_long_double_type_for_win32

صحیح مین()
{
    دوہرا *a = 0;
    طویل دوہرا *b = a;
    صحیح n = _Generic(*a, دوہرا:0, طویل دوہرا:1);
}

#وگرنہ_اگر defined test_stray_backslash
#تعریف_کرو x \a
x

#وگرنہ_اگر defined test_stray_backslash2

صحیح مین()
{
#تعریف_کرو _S(x) #x
#تعریف_کرو S(x) _S(x)
    لکھو("%sn\n", S(\\));
}

/******************************************************************/
#وگرنہ_اگر defined test_var_array

ساکن ساخت var_len { صحیح i; ثابت حرف str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#وگرنہ_اگر defined test_var_array2

ساخت c1 { صحیح a; صحیح b[]; };
ساخت c1 c1 = { 1, { 2, 3, 4 } };

ساخت c2 { صحیح c; ساخت c1 c1; };
ساخت c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#وگرنہ_اگر defined test_var_array3
/* similar to test_var_array2 but with string initializers */
ساخت A { صحیح a; حرف b[]; };
ساخت A a = { 1, "1" };
ساخت B { ساخت A a; };
ساخت B b = { { 1, "1" } };
/******************************************************************/
#وگرنہ_اگر defined test_default_int_type
n; // warn
f(); // don't warn

#وگرنہ_اگر defined test_invalid_global_stmtexpr
n[حجم({3;})]; // crashed in block() due to missing local scope

#وگرنہ_اگر defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#وگرنہ_اگر defined test_duplicate_member
ساخت S {
  صحیح a, a;
};
#وگرنہ_اگر defined test_duplicate_member_anon
ساخت S1 {
  صحیح b;
  ساخت {
    صحیح b;
  } c;
};
ساخت S2 {
  صحیح d;
  ساخت {
    صحیح d;
  };
};

/******************************************************************/
#وگرنہ_اگر defined test_conflicting_array_definition
خارجی صحیح array[2];
صحیح array[] = { 1, 2, 3 };

#وگرنہ_اگر defined test_incompatible_local_redef
خالی foo (خالی)
{
  قسمتعریف صحیح localfunctype (صحیح);
  خارجی localfunctype func2;
  قسمتعریف خالی localfunctype (صحیح, صحیح);
}

#وگرنہ_اگر defined test_cast_from_void
خالی v() {}
صحیح f() { واپس v(); }

#وگرنہ_اگر defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#اگر defined test_switch_W1
#ہدایت comment(option, "-Wall")
#وگرنہ_اگر defined test_switch_W2
#ہدایت comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#وگرنہ_اگر defined test_switch_W3
#ہدایت comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#وگرنہ_اگر defined test_switch_W4
#ہدایت comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#اگر_ختم
خالی func(خالی)
{
    حرف *ccp = "123";
    fink();
}
__attribute__((stuff)) صحیح fink() {واپس 0;}

#وگرنہ_اگر defined test_invalid_funcparam_1
خالی func(صحیح a, صحیح b, صحیح a);

#وگرنہ_اگر defined test_invalid_funcparam_2
خالی func(صحیح a, صحیح اگر);

#وگرنہ_اگر defined test_array_funcparam
صحیح amain(صحیح argc, حرف *argv[ساکن argc + 1])
{
    صحیح i;

    برائے (i = 0; i < argc; ++i)
        لکھو("arg[%d] = \"%s\"\n", i, argv[i]);
    واپس 0;
}
صحیح مین()
{
    واپس amain(2, (حرف *[]){ "X", "Y", 0 });
}

#وگرنہ_اگر defined test_return_from_statement_اظہاریہ
صحیح f() { ({ واپس 78; }); }
صحیح مین() { واپس f(); }

/******************************************************************/

#وگرنہ_اگر defined test_illegal_unicode
صحیح مین() {
    حرف *str = "\Uffffffff";
}

#وگرنہ_اگر defined test_error_string
#غلطی \123\\
456

#وگرنہ_اگر defined test_error_incomplete_type
ساخت A;
خالی f(ساخت A *);

صحیح مین()
{
    f(&(ساخت A){});
}

ساخت A {
    صحیح x;
};

#وگرنہ_اگر defined test_pp_error_1
# اگر //no expression
# endif
#وگرنہ_اگر defined test_pp_error_2
# اگر X(1,2) //undefined function macro
# endif

#وگرنہ_اگر defined test_اشارہ_گر_plus_double

صحیح *invalid_operation(صحیح *p, دوہرا d)
{
    واپس p + d;
}

#وگرنہ_اگر defined test_duplicate_case

صحیح مین()
{
    غیرعلامتی صحیح x;
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
#وگرنہ_اگر defined test_معمول_funcargs || defined test_الٹ_funcargs

#اگر_تعریف_شدہ test_الٹ_funcargs
# pragma comment(option, "-freverse-funcargs")
#اگر_ختم

صحیح مین()
{
    لکھو(" %d %d %d\n", لکھو("1"), لکھو("22"), لکھو("333"));
}

#وگرنہ_اگر defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

ساخت xxx {صحیح x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
صحیح bar(شمار ee { a = 12, b = 34 } i, صحیح(*f)(صحیح i))
{
    لکھو("bar %d %d %d\n", i, a, b);
    واپس 0;
}
/* 'xxx' not defined outside of function */
صحیح foo(ساخت xxx {صحیح x[3];}*p)
{
    لکھو("foo %d", حجم *p);
    واپس p->x[3];
}
#اگر_تعریف_شدہ test_scope_2
/* incompatible redefinition */
صحیح foo(ساخت xxx {صحیح x[2];}*p);
#اگر_ختم
#اگر_غیر_تعریف_شدہ test_scope_3
شمار ee { a = 1, b };
#اگر_ختم

ساخت xxx x = { 11,22,33,44 };
صحیح مین(صحیح argc, حرف **argv)
{
    لکھو(" %d %d\n", foo(&x), حجم (ساخت xxx));
    شمار ee e = b;
    bar(13 + e, 0);

}

#وگرنہ_اگر defined test_const_array_member_addr_ok

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

int_array ثابت *get_array(ثابت my_struct *s)
{
    واپس &(s->arr);
}

#وگرنہ_اگر defined test_const_array_member_decay_ok

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

ثابت صحیح *good_decay(ثابت my_struct *s)
{
    واپس s->arr;
}

#وگرنہ_اگر defined test_const_array_member_addr_bad

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

int_array *bad_array_addr(ثابت my_struct *s)
{
    واپس &(s->arr);
}

#وگرنہ_اگر defined test_const_array_member_decay_bad

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

صحیح *bad_decay(ثابت my_struct *s)
{
    واپس s->arr;
}

#وگرنہ_اگر defined test_const_array_member_write_bad

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

خالی bad_write(ثابت my_struct *s)
{
    s->arr[0] = 1;
}

#وگرنہ_اگر defined test_const_struct_array_member_write_bad

قسمتعریف ساخت { صحیح x; } inner;
قسمتعریف ساخت { inner arr[1]; } outer;

خالی bad_inner_write(ثابت outer *s)
{
    s->arr[0].x = 1;
}

#وگرنہ_اگر defined test_volatile_array_member_addr_ok

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

int_array متلون *get_volatile_array(متلون my_struct *s)
{
    واپس &(s->arr);
}

#وگرنہ_اگر defined test_volatile_array_member_decay_ok

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

متلون صحیح *good_volatile_decay(متلون my_struct *s)
{
    واپس s->arr;
}

#وگرنہ_اگر defined test_volatile_array_member_addr_bad

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(متلون my_struct *s)
{
    واپس &(s->arr);
}

#وگرنہ_اگر defined test_volatile_array_member_decay_bad

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

صحیح *bad_volatile_decay(متلون my_struct *s)
{
    واپس s->arr;
}

#وگرنہ_اگر defined test_volatile_array_member_write_ok

قسمتعریف صحیح int_array[1];
قسمتعریف ساخت { int_array arr; } my_struct;

خالی good_volatile_write(متلون my_struct *s)
{
    s->arr[0] = 1;
}

#وگرنہ_اگر defined test_conditional_array_qualifiers

قسمتعریف صحیح Array2[2];
قسمتعریف صحیح Array2x3[2][3];

Array2 *p;
ثابت Array2 *cp;
ثابت Array2x3 *cap;
متلون Array2x3 *vap;

خالی test(خالی)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#وگرنہ_اگر defined test_restrict_scalar

محدود صحیح object;

#وگرنہ_اگر defined test_restrict_function_اشارہ_گر

صحیح (*محدود function_اشارہ_گر)(خالی);

#وگرنہ_اگر defined test_discarded_restrict

قسمتعریف صحیح *محدود restricted_اشارہ_گر;

restricted_اشارہ_گر *ماخذ;
صحیح **destination;

خالی test(خالی)
{
    destination = ماخذ;
}

#اگر_ختم

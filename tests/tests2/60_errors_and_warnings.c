முழு printf(மாறிலி எழுத்து*, ...);

#எனில் defined test_56_btype_excess_1
கட்டமைப்பு A {} முழு i;
#அல்லதெனில் defined test_57_btype_excess_2
எழுத்து முழு i;
#அல்லதெனில் defined test_58_function_redefinition
முழு f(வெறுமை) { திரும்பு 0; }
முழு f(வெறுமை) { திரும்பு 1; }

#அல்லதெனில் defined test_global_redefinition
முழு xxx = 1;
முழு xxx;
முழு xxx = 2;

#அல்லதெனில் defined test_59_function_array
முழு (*fct)[42](முழு x);

#அல்லதெனில் defined test_60_enum_redefinition
எண்ணிக்கை color { RED, GREEN, BLUE };
எண்ணிக்கை color { R, G, B };
எண்ணிக்கை color c;

#அல்லதெனில் defined test_62_enumerator_redefinition
எண்ணிக்கை color { RED, GREEN, BLUE };
எண்ணிக்கை rgb { RED, G, B};
எண்ணிக்கை color c = RED;

#அல்லதெனில் defined test_63_local_enumerator_redefinition
எண்ணிக்கை {
    FOO,
    BAR
};

முழு முதன்மை(வெறுமை)
{
    எண்ணிக்கை {
        FOO = 2,
        BAR
    };

    திரும்பு BAR - FOO;
}

#அல்லதெனில் defined test_61_undefined_enum
எண்ணிக்கை rgb3 c = 42;

#அல்லதெனில் defined test_74_non_const_init
முழு i = i++;

#அல்லதெனில் defined test_pointer_assignment

வெறுமை (*f1)(வெறுமை);
வெறுமை f2(வெறுமை) {}

கட்டமைப்பு s1 *ps1;
கட்டமைப்பு s2 *ps2;

வெறுமை *v1, **v2, ***v3;

எண்ணிக்கை e1 { a = 4 } e10, *e11, *e12;
எண்ணிக்கை e2 { b = -4 } e20, *e21;
எண்ணிக்கை e3 { c = 5000000000LL } e30;

முழு *ip;
unsigned முழு *up;
long *lp;
long long *llp;

எழுத்து **c1;
எழுத்து மாறிலி **c2;
unsigned எழுத்து **u1;

முழு no_main ()
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

    திரும்பு 0;
}


#அல்லதெனில் defined test_enum_compat
எண்ணிக்கை e4;
எண்ணிக்கை e5;
வெறுமை f3(எண்ணிக்கை e4 e);
வெறுமை f3(எண்ணிக்கை e5 e);

#அல்லதெனில் defined test_enum_compat_2
எண்ணிக்கை e6 { E1 = -1, E0 };
வெறுமை f3(எண்ணிக்கை e6);
வெறுமை f3(முழு);        // should work as int and e6 are compatible
வெறுமை f4(எண்ணிக்கை e6 e);
வெறுமை f4(unsigned e); // should error as unsigned and e6 are incompatible

#அல்லதெனில் defined test_ptr_to_str
வெறுமை f() { _Generic((முழு மாறிலி *[]){0}, முழு:0); }
#அல்லதெனில் defined test_fnptr_to_str
வெறுமை f() { _Generic((முழு (*(*)(தசம,எழுத்து))(இரட்டை,முழு)){0}, முழு:0); }
#அல்லதெனில் defined test_array_to_str
வெறுமை f() { _Generic((முழு(*)[3]){0}, முழு:0); }
#அல்லதெனில் defined test_duplicate_def_1
நிலையான எண்ணிக்கை myenum { L = -1 } L;                                                
#அல்லதெனில் defined test_duplicate_def_2
வெறுமை foo(வெறுமை) {
நிலையான எண்ணிக்கை myenum { L = -1 } L;                                                
}
#அல்லதெனில் defined test_abstract_decls
முழு bar(மாறிலி எழுத்து *());     // abstract declarator here is okay
முழு bar (மாறிலி எழுத்து *(*g)()) // should match this 'g' argument
{
  g();
  திரும்பு 42;
}
முழு foo(முழு ())              // abstract decl is wrong in definitions
{
  திரும்பு 0;
#அல்லதெனில் defined test_invalid_1
வெறுமை f(எழுத்து*);
வெறுமை g(வெறுமை) {
  f((எழுத்து[]){1, ,});
}
#அல்லதெனில் defined test_invalid_2
முழு ga = 0.42 { 2 };
#அல்லதெனில் defined test_invalid_3
கட்டமைப்பு S { முழு a, b; };
கட்டமைப்பு T { கட்டமைப்பு S x; };
கட்டமைப்பு T gt = { 42 a: 1, 43 };
#அல்லதெனில் defined test_invalid_4
எண்ணிக்கை E {
    x = 1 / 0
};
#அல்லதெனில் defined test_conflicting_types
முழு i;
வெறுமை foo(வெறுமை) {
    முழு i;
      {
        வெளி இரட்டை i;
        i = 42.2;
      }
}
#அல்லதெனில் defined test_nested_types
ஒன்றிப்பு u {
    ஒன்றிப்பு u {
        முழு i;
    } m;
};
#அல்லதெனில் defined test_vla_1
முழு X=1;

முழு முதன்மை(வெறுமை) {
  முழு t[][][X];
}
#அல்லதெனில் defined test_invalid_alignas
/* _Alignas is no type qualifier */
வெறுமை * _Alignas(16) p1;

#அல்லதெனில் defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 கட்டமைப்பு x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#அல்லதெனில் defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
கட்டமைப்பு y {  _Static_assert(0, "0"" is 0"); };

#அல்லதெனில் defined test_static_assert_c2x
 _Static_assert(1);
கட்டமைப்பு z {  _Static_assert(0); }

#அல்லதெனில் defined test_static_assert_empty_string
 _Static_assert(0,"");

#அல்லதெனில் defined test_void_array
 வெறுமை t[3];

#அல்லதெனில் defined test_incomplete_enum_array
  எண்ணிக்கை e t[3];

#அல்லதெனில் defined test_incomplete_struct_array
  கட்டமைப்பு s t[3];

#அல்லதெனில் defined test_const_fun_array
  வகைவரை வெறுமை f(வெறுமை);
  மாறிலி f t[3];

#அல்லதெனில் defined test_incomplete_array_array
  முழு t[][3]; // gr: not an error, see below

/******************************************************************/
#அல்லதெனில் defined test_extern_array
முழு iii[] = { 1,2,3 };
வெளி முழு iii[];
முழு x[];
முழு x[2];
முழு x[];
முழு x[2];
முழு x[];
வெளி முழு x[2];
வெளி முழு x[];
முழு x[3];

/******************************************************************/
#அல்லதெனில் defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#எனில் defined test_func_1
முழு hello(முழு);
#அல்லதெனில் defined test_func_4
நிலையான முழு hello(முழு);
#endif
முழு முதன்மை () {
#எனில் defined test_func_6
    நிலையான
#endif
    முழு hello(முழு);
    hello(123);
    திரும்பு 0;
}

#எனில் defined test_func_3
நிலையான முழு hello(முழு a)
#அல்லதெனில் defined test_func_5
முழு hello(முழு a, முழு b)
#இல்லையெனில்
முழு hello(முழு a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); திரும்பு 0; }

/******************************************************************/
#அல்லதெனில் defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#எனில் defined test_var_1
முழு xxx[];
#endif
முழு bar();

முழு முதன்மை ()
{
#எனில் !defined test_var_3
    முழு xxx = 2;
#endif
    {
        வெளி முழு xxx[
#எனில் defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#எனில் !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    திரும்பு 0;
}
முழு xxx[1] = {1};
முழு bar() { P(3, xxx[0]); திரும்பு 0; }

#அல்லதெனில் defined test_var_4
கட்டமைப்பு yyy { முழு y; };
கட்டமைப்பு zzz;
வெறுமை f1() {
    வெளி எழுத்து *x;
    வெளி எழுத்து **xx;
    வெளி கட்டமைப்பு yyy y;
    வெளி கட்டமைப்பு yyy *yy;
    வெளி கட்டமைப்பு zzz z;
    வெளி கட்டமைப்பு zzz *zz;
}
வெறுமை f2() {
    வெளி எழுத்து *x;
    வெளி எழுத்து **xx;
    வெளி கட்டமைப்பு yyy y;
    வெளி கட்டமைப்பு yyy *yy;
    வெளி கட்டமைப்பு zzz z;
    வெளி கட்டமைப்பு zzz *zz;
}
கட்டமைப்பு yyy y, *yy;
கட்டமைப்பு zzz { முழு z; } z, *zz;

/******************************************************************/
#அல்லதெனில் defined test_long_double_type_for_win32

முழு முதன்மை()
{
    இரட்டை *a = 0;
    long இரட்டை *b = a;
    முழு n = _Generic(*a, இரட்டை:0, long இரட்டை:1);
}

#அல்லதெனில் defined test_stray_backslash
#define x \a
x

#அல்லதெனில் defined test_stray_backslash2

முழு முதன்மை()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#அல்லதெனில் defined test_var_array

நிலையான கட்டமைப்பு var_len { முழு i; மாறிலி எழுத்து str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#அல்லதெனில் defined test_var_array2

கட்டமைப்பு c1 { முழு a; முழு b[]; };
கட்டமைப்பு c1 c1 = { 1, { 2, 3, 4 } };

கட்டமைப்பு c2 { முழு c; கட்டமைப்பு c1 c1; };
கட்டமைப்பு c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#அல்லதெனில் defined test_var_array3
/* similar to test_var_array2 but with string initializers */
கட்டமைப்பு A { முழு a; எழுத்து b[]; };
கட்டமைப்பு A a = { 1, "1" };
கட்டமைப்பு B { கட்டமைப்பு A a; };
கட்டமைப்பு B b = { { 1, "1" } };
/******************************************************************/
#அல்லதெனில் defined test_default_int_type
n; // warn
f(); // don't warn

#அல்லதெனில் defined test_invalid_global_stmtexpr
n[அளவு({3;})]; // crashed in block() due to missing local scope

#அல்லதெனில் defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#அல்லதெனில் defined test_duplicate_member
கட்டமைப்பு S {
  முழு a, a;
};
#அல்லதெனில் defined test_duplicate_member_anon
கட்டமைப்பு S1 {
  முழு b;
  கட்டமைப்பு {
    முழு b;
  } c;
};
கட்டமைப்பு S2 {
  முழு d;
  கட்டமைப்பு {
    முழு d;
  };
};

/******************************************************************/
#அல்லதெனில் defined test_conflicting_array_definition
வெளி முழு array[2];
முழு array[] = { 1, 2, 3 };

#அல்லதெனில் defined test_incompatible_local_redef
வெறுமை foo (வெறுமை)
{
  வகைவரை முழு localfunctype (முழு);
  வெளி localfunctype func2;
  வகைவரை வெறுமை localfunctype (முழு, முழு);
}

#அல்லதெனில் defined test_cast_from_void
வெறுமை v() {}
முழு f() { திரும்பு v(); }

#அல்லதெனில் defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#எனில் defined test_switch_W1
#pragma comment(option, "-Wall")
#அல்லதெனில் defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#அல்லதெனில் defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#அல்லதெனில் defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
வெறுமை func(வெறுமை)
{
    எழுத்து *ccp = "123";
    fink();
}
__attribute__((stuff)) முழு fink() {திரும்பு 0;}

#அல்லதெனில் defined test_invalid_funcparam_1
வெறுமை func(முழு a, முழு b, முழு a);

#அல்லதெனில் defined test_invalid_funcparam_2
வெறுமை func(முழு a, முழு எனில்);

#அல்லதெனில் defined test_array_funcparam
முழு amain(முழு argc, எழுத்து *argv[நிலையான argc + 1])
{
    முழு i;

    க்கு (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    திரும்பு 0;
}
முழு முதன்மை()
{
    திரும்பு amain(2, (எழுத்து *[]){ "X", "Y", 0 });
}

#அல்லதெனில் defined test_return_from_statement_கோவை
முழு f() { ({ திரும்பு 78; }); }
முழு முதன்மை() { திரும்பு f(); }

/******************************************************************/

#அல்லதெனில் defined test_illegal_unicode
முழு முதன்மை() {
    எழுத்து *str = "\Uffffffff";
}

#அல்லதெனில் defined test_error_string
#error \123\\
456

#அல்லதெனில் defined test_error_incomplete_type
கட்டமைப்பு A;
வெறுமை f(கட்டமைப்பு A *);

முழு முதன்மை()
{
    f(&(கட்டமைப்பு A){});
}

கட்டமைப்பு A {
    முழு x;
};

#அல்லதெனில் defined test_pp_error_1
# எனில் //no expression
# endif
#அல்லதெனில் defined test_pp_error_2
# எனில் X(1,2) //undefined function macro
# endif

#அல்லதெனில் defined test_pointer_plus_double

முழு *invalid_operation(முழு *p, இரட்டை d)
{
    திரும்பு p + d;
}

#அல்லதெனில் defined test_duplicate_case

முழு முதன்மை()
{
    unsigned முழு x;
    தேர்வு (x) {
        நிலை -1 ... 0: /* empty case range with unsigned */
        நிலை 3:
        நிலை 1:
        நிலை 2:
        நிலை 3: /* show this line number in error */
        நிலை 4:
        நிலை 5:
    }
}
#அல்லதெனில் defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

முழு முதன்மை()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#அல்லதெனில் defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

கட்டமைப்பு xxx {முழு x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
முழு bar(எண்ணிக்கை ee { a = 12, b = 34 } i, முழு(*f)(முழு i))
{
    printf("bar %d %d %d\n", i, a, b);
    திரும்பு 0;
}
/* 'xxx' not defined outside of function */
முழு foo(கட்டமைப்பு xxx {முழு x[3];}*p)
{
    printf("foo %d", அளவு *p);
    திரும்பு p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
முழு foo(கட்டமைப்பு xxx {முழு x[2];}*p);
#endif
#ifndef test_scope_3
எண்ணிக்கை ee { a = 1, b };
#endif

கட்டமைப்பு xxx x = { 11,22,33,44 };
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    printf(" %d %d\n", foo(&x), அளவு (கட்டமைப்பு xxx));
    எண்ணிக்கை ee e = b;
    bar(13 + e, 0);

}

#அல்லதெனில் defined test_const_array_member_addr_ok

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

int_array மாறிலி *get_array(மாறிலி my_struct *s)
{
    திரும்பு &(s->arr);
}

#அல்லதெனில் defined test_const_array_member_decay_ok

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

மாறிலி முழு *good_decay(மாறிலி my_struct *s)
{
    திரும்பு s->arr;
}

#அல்லதெனில் defined test_const_array_member_addr_bad

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

int_array *bad_array_addr(மாறிலி my_struct *s)
{
    திரும்பு &(s->arr);
}

#அல்லதெனில் defined test_const_array_member_decay_bad

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

முழு *bad_decay(மாறிலி my_struct *s)
{
    திரும்பு s->arr;
}

#அல்லதெனில் defined test_const_array_member_write_bad

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

வெறுமை bad_write(மாறிலி my_struct *s)
{
    s->arr[0] = 1;
}

#அல்லதெனில் defined test_const_struct_array_member_write_bad

வகைவரை கட்டமைப்பு { முழு x; } inner;
வகைவரை கட்டமைப்பு { inner arr[1]; } outer;

வெறுமை bad_inner_write(மாறிலி outer *s)
{
    s->arr[0].x = 1;
}

#அல்லதெனில் defined test_volatile_array_member_addr_ok

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

int_array நிலையற்ற *get_volatile_array(நிலையற்ற my_struct *s)
{
    திரும்பு &(s->arr);
}

#அல்லதெனில் defined test_volatile_array_member_decay_ok

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

நிலையற்ற முழு *good_volatile_decay(நிலையற்ற my_struct *s)
{
    திரும்பு s->arr;
}

#அல்லதெனில் defined test_volatile_array_member_addr_bad

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(நிலையற்ற my_struct *s)
{
    திரும்பு &(s->arr);
}

#அல்லதெனில் defined test_volatile_array_member_decay_bad

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

முழு *bad_volatile_decay(நிலையற்ற my_struct *s)
{
    திரும்பு s->arr;
}

#அல்லதெனில் defined test_volatile_array_member_write_ok

வகைவரை முழு int_array[1];
வகைவரை கட்டமைப்பு { int_array arr; } my_struct;

வெறுமை good_volatile_write(நிலையற்ற my_struct *s)
{
    s->arr[0] = 1;
}

#அல்லதெனில் defined test_conditional_array_qualifiers

வகைவரை முழு Array2[2];
வகைவரை முழு Array2x3[2][3];

Array2 *p;
மாறிலி Array2 *cp;
மாறிலி Array2x3 *cap;
நிலையற்ற Array2x3 *vap;

வெறுமை test(வெறுமை)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#அல்லதெனில் defined test_restrict_scalar

restrict முழு object;

#அல்லதெனில் defined test_restrict_function_pointer

முழு (*restrict function_pointer)(வெறுமை);

#அல்லதெனில் defined test_discarded_restrict

வகைவரை முழு *restrict restricted_pointer;

restricted_pointer *source;
முழு **destination;

வெறுமை test(வெறுமை)
{
    destination = source;
}

#endif

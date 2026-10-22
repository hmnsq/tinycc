पूर्णाङ्क printf(ध्रुव वर्ण*, ...);

#यदि defined test_56_btype_excess_1
संरचना A {} पूर्णाङ्क i;
#नोचेद्यदि defined test_57_btype_excess_2
वर्ण पूर्णाङ्क i;
#नोचेद्यदि defined test_58_function_redefinition
पूर्णाङ्क f(शून्य) { प्रत्यागम 0; }
पूर्णाङ्क f(शून्य) { प्रत्यागम 1; }

#नोचेद्यदि defined test_global_redefinition
पूर्णाङ्क xxx = 1;
पूर्णाङ्क xxx;
पूर्णाङ्क xxx = 2;

#नोचेद्यदि defined test_59_function_array
पूर्णाङ्क (*fct)[42](पूर्णाङ्क x);

#नोचेद्यदि defined test_60_enum_redefinition
गणना color { RED, GREEN, BLUE };
गणना color { R, G, B };
गणना color c;

#नोचेद्यदि defined test_62_enumerator_redefinition
गणना color { RED, GREEN, BLUE };
गणना rgb { RED, G, B};
गणना color c = RED;

#नोचेद्यदि defined test_63_local_enumerator_redefinition
गणना {
    FOO,
    BAR
};

पूर्णाङ्क main(शून्य)
{
    गणना {
        FOO = 2,
        BAR
    };

    प्रत्यागम BAR - FOO;
}

#नोचेद्यदि defined test_61_undefined_enum
गणना rgb3 c = 42;

#नोचेद्यदि defined test_74_non_const_init
पूर्णाङ्क i = i++;

#नोचेद्यदि defined test_pointer_assignment

शून्य (*f1)(शून्य);
शून्य f2(शून्य) {}

संरचना s1 *ps1;
संरचना s2 *ps2;

शून्य *v1, **v2, ***v3;

गणना e1 { a = 4 } e10, *e11, *e12;
गणना e2 { b = -4 } e20, *e21;
गणना e3 { c = 5000000000LL } e30;

पूर्णाङ्क *ip;
unsigned पूर्णाङ्क *up;
long *lp;
long long *llp;

वर्ण **c1;
वर्ण ध्रुव **c2;
unsigned वर्ण **u1;

पूर्णाङ्क no_main ()
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

    प्रत्यागम 0;
}


#नोचेद्यदि defined test_enum_compat
गणना e4;
गणना e5;
शून्य f3(गणना e4 e);
शून्य f3(गणना e5 e);

#नोचेद्यदि defined test_enum_compat_2
गणना e6 { E1 = -1, E0 };
शून्य f3(गणना e6);
शून्य f3(पूर्णाङ्क);        // should work as int and e6 are compatible
शून्य f4(गणना e6 e);
शून्य f4(unsigned e); // should error as unsigned and e6 are incompatible

#नोचेद्यदि defined test_ptr_to_str
शून्य f() { _Generic((पूर्णाङ्क ध्रुव *[]){0}, पूर्णाङ्क:0); }
#नोचेद्यदि defined test_fnptr_to_str
शून्य f() { _Generic((पूर्णाङ्क (*(*)(भिन्न,वर्ण))(द्विगुण,पूर्णाङ्क)){0}, पूर्णाङ्क:0); }
#नोचेद्यदि defined test_array_to_str
शून्य f() { _Generic((पूर्णाङ्क(*)[3]){0}, पूर्णाङ्क:0); }
#नोचेद्यदि defined test_duplicate_def_1
स्थिर गणना myenum { L = -1 } L;                                                
#नोचेद्यदि defined test_duplicate_def_2
शून्य foo(शून्य) {
स्थिर गणना myenum { L = -1 } L;                                                
}
#नोचेद्यदि defined test_abstract_decls
पूर्णाङ्क bar(ध्रुव वर्ण *());     // abstract declarator here is okay
पूर्णाङ्क bar (ध्रुव वर्ण *(*g)()) // should match this 'g' argument
{
  g();
  प्रत्यागम 42;
}
पूर्णाङ्क foo(पूर्णाङ्क ())              // abstract decl is wrong in definitions
{
  प्रत्यागम 0;
#नोचेद्यदि defined test_invalid_1
शून्य f(वर्ण*);
शून्य g(शून्य) {
  f((वर्ण[]){1, ,});
}
#नोचेद्यदि defined test_invalid_2
पूर्णाङ्क ga = 0.42 { 2 };
#नोचेद्यदि defined test_invalid_3
संरचना S { पूर्णाङ्क a, b; };
संरचना T { संरचना S x; };
संरचना T gt = { 42 a: 1, 43 };
#नोचेद्यदि defined test_invalid_4
गणना E {
    x = 1 / 0
};
#नोचेद्यदि defined test_conflicting_types
पूर्णाङ्क i;
शून्य foo(शून्य) {
    पूर्णाङ्क i;
      {
        बाह्य द्विगुण i;
        i = 42.2;
      }
}
#नोचेद्यदि defined test_nested_types
सङ्घ u {
    सङ्घ u {
        पूर्णाङ्क i;
    } m;
};
#नोचेद्यदि defined test_vla_1
पूर्णाङ्क X=1;

पूर्णाङ्क main(शून्य) {
  पूर्णाङ्क t[][][X];
}
#नोचेद्यदि defined test_invalid_alignas
/* _Alignas is no type qualifier */
शून्य * _Alignas(16) p1;

#नोचेद्यदि defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 संरचना x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#नोचेद्यदि defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
संरचना y {  _Static_assert(0, "0"" is 0"); };

#नोचेद्यदि defined test_static_assert_c2x
 _Static_assert(1);
संरचना z {  _Static_assert(0); }

#नोचेद्यदि defined test_static_assert_empty_string
 _Static_assert(0,"");

#नोचेद्यदि defined test_void_array
 शून्य t[3];

#नोचेद्यदि defined test_incomplete_enum_array
  गणना e t[3];

#नोचेद्यदि defined test_incomplete_struct_array
  संरचना s t[3];

#नोचेद्यदि defined test_const_fun_array
  प्रकारनिर्देश शून्य f(शून्य);
  ध्रुव f t[3];

#नोचेद्यदि defined test_incomplete_array_array
  पूर्णाङ्क t[][3]; // gr: not an error, see below

/******************************************************************/
#नोचेद्यदि defined test_extern_array
पूर्णाङ्क iii[] = { 1,2,3 };
बाह्य पूर्णाङ्क iii[];
पूर्णाङ्क x[];
पूर्णाङ्क x[2];
पूर्णाङ्क x[];
पूर्णाङ्क x[2];
पूर्णाङ्क x[];
बाह्य पूर्णाङ्क x[2];
बाह्य पूर्णाङ्क x[];
पूर्णाङ्क x[3];

/******************************************************************/
#नोचेद्यदि defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#यदि defined test_func_1
पूर्णाङ्क hello(पूर्णाङ्क);
#नोचेद्यदि defined test_func_4
स्थिर पूर्णाङ्क hello(पूर्णाङ्क);
#endif
पूर्णाङ्क main () {
#यदि defined test_func_6
    स्थिर
#endif
    पूर्णाङ्क hello(पूर्णाङ्क);
    hello(123);
    प्रत्यागम 0;
}

#यदि defined test_func_3
स्थिर पूर्णाङ्क hello(पूर्णाङ्क a)
#नोचेद्यदि defined test_func_5
पूर्णाङ्क hello(पूर्णाङ्क a, पूर्णाङ्क b)
#अन्यथा
पूर्णाङ्क hello(पूर्णाङ्क a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); प्रत्यागम 0; }

/******************************************************************/
#नोचेद्यदि defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#यदि defined test_var_1
पूर्णाङ्क xxx[];
#endif
पूर्णाङ्क bar();

पूर्णाङ्क main ()
{
#यदि !defined test_var_3
    पूर्णाङ्क xxx = 2;
#endif
    {
        बाह्य पूर्णाङ्क xxx[
#यदि defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#यदि !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    प्रत्यागम 0;
}
पूर्णाङ्क xxx[1] = {1};
पूर्णाङ्क bar() { P(3, xxx[0]); प्रत्यागम 0; }

#नोचेद्यदि defined test_var_4
संरचना yyy { पूर्णाङ्क y; };
संरचना zzz;
शून्य f1() {
    बाह्य वर्ण *x;
    बाह्य वर्ण **xx;
    बाह्य संरचना yyy y;
    बाह्य संरचना yyy *yy;
    बाह्य संरचना zzz z;
    बाह्य संरचना zzz *zz;
}
शून्य f2() {
    बाह्य वर्ण *x;
    बाह्य वर्ण **xx;
    बाह्य संरचना yyy y;
    बाह्य संरचना yyy *yy;
    बाह्य संरचना zzz z;
    बाह्य संरचना zzz *zz;
}
संरचना yyy y, *yy;
संरचना zzz { पूर्णाङ्क z; } z, *zz;

/******************************************************************/
#नोचेद्यदि defined test_long_double_type_for_win32

पूर्णाङ्क main()
{
    द्विगुण *a = 0;
    long द्विगुण *b = a;
    पूर्णाङ्क n = _Generic(*a, द्विगुण:0, long द्विगुण:1);
}

#नोचेद्यदि defined test_stray_backslash
#define x \a
x

#नोचेद्यदि defined test_stray_backslash2

पूर्णाङ्क main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#नोचेद्यदि defined test_var_array

स्थिर संरचना var_len { पूर्णाङ्क i; ध्रुव वर्ण str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#नोचेद्यदि defined test_var_array2

संरचना c1 { पूर्णाङ्क a; पूर्णाङ्क b[]; };
संरचना c1 c1 = { 1, { 2, 3, 4 } };

संरचना c2 { पूर्णाङ्क c; संरचना c1 c1; };
संरचना c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#नोचेद्यदि defined test_var_array3
/* similar to test_var_array2 but with string initializers */
संरचना A { पूर्णाङ्क a; वर्ण b[]; };
संरचना A a = { 1, "1" };
संरचना B { संरचना A a; };
संरचना B b = { { 1, "1" } };
/******************************************************************/
#नोचेद्यदि defined test_default_int_type
n; // warn
f(); // don't warn

#नोचेद्यदि defined test_invalid_global_stmtexpr
n[परिमाण({3;})]; // crashed in block() due to missing local scope

#नोचेद्यदि defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#नोचेद्यदि defined test_duplicate_member
संरचना S {
  पूर्णाङ्क a, a;
};
#नोचेद्यदि defined test_duplicate_member_anon
संरचना S1 {
  पूर्णाङ्क b;
  संरचना {
    पूर्णाङ्क b;
  } c;
};
संरचना S2 {
  पूर्णाङ्क d;
  संरचना {
    पूर्णाङ्क d;
  };
};

/******************************************************************/
#नोचेद्यदि defined test_conflicting_array_definition
बाह्य पूर्णाङ्क array[2];
पूर्णाङ्क array[] = { 1, 2, 3 };

#नोचेद्यदि defined test_incompatible_local_redef
शून्य foo (शून्य)
{
  प्रकारनिर्देश पूर्णाङ्क localfunctype (पूर्णाङ्क);
  बाह्य localfunctype func2;
  प्रकारनिर्देश शून्य localfunctype (पूर्णाङ्क, पूर्णाङ्क);
}

#नोचेद्यदि defined test_cast_from_void
शून्य v() {}
पूर्णाङ्क f() { प्रत्यागम v(); }

#नोचेद्यदि defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#यदि defined test_switch_W1
#pragma comment(option, "-Wall")
#नोचेद्यदि defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#नोचेद्यदि defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#नोचेद्यदि defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
शून्य func(शून्य)
{
    वर्ण *ccp = "123";
    fink();
}
__attribute__((stuff)) पूर्णाङ्क fink() {प्रत्यागम 0;}

#नोचेद्यदि defined test_invalid_funcparam_1
शून्य func(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क a);

#नोचेद्यदि defined test_invalid_funcparam_2
शून्य func(पूर्णाङ्क a, पूर्णाङ्क यदि);

#नोचेद्यदि defined test_array_funcparam
पूर्णाङ्क amain(पूर्णाङ्क argc, वर्ण *argv[स्थिर argc + 1])
{
    पूर्णाङ्क i;

    प्रति (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    प्रत्यागम 0;
}
पूर्णाङ्क main()
{
    प्रत्यागम amain(2, (वर्ण *[]){ "X", "Y", 0 });
}

#नोचेद्यदि defined test_return_from_statement_अभिव्यक्ती
पूर्णाङ्क f() { ({ प्रत्यागम 78; }); }
पूर्णाङ्क main() { प्रत्यागम f(); }

/******************************************************************/

#नोचेद्यदि defined test_illegal_unicode
पूर्णाङ्क main() {
    वर्ण *str = "\Uffffffff";
}

#नोचेद्यदि defined test_error_string
#error \123\\
456

#नोचेद्यदि defined test_error_incomplete_type
संरचना A;
शून्य f(संरचना A *);

पूर्णाङ्क main()
{
    f(&(संरचना A){});
}

संरचना A {
    पूर्णाङ्क x;
};

#नोचेद्यदि defined test_pp_error_1
# यदि //no expression
# endif
#नोचेद्यदि defined test_pp_error_2
# यदि X(1,2) //undefined function macro
# endif

#नोचेद्यदि defined test_pointer_plus_double

पूर्णाङ्क *invalid_operation(पूर्णाङ्क *p, द्विगुण d)
{
    प्रत्यागम p + d;
}

#नोचेद्यदि defined test_duplicate_case

पूर्णाङ्क main()
{
    unsigned पूर्णाङ्क x;
    विकल्प (x) {
        पक्ष -1 ... 0: /* empty case range with unsigned */
        पक्ष 3:
        पक्ष 1:
        पक्ष 2:
        पक्ष 3: /* show this line number in error */
        पक्ष 4:
        पक्ष 5:
    }
}
#नोचेद्यदि defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

पूर्णाङ्क main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#नोचेद्यदि defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

संरचना xxx {पूर्णाङ्क x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
पूर्णाङ्क bar(गणना ee { a = 12, b = 34 } i, पूर्णाङ्क(*f)(पूर्णाङ्क i))
{
    printf("bar %d %d %d\n", i, a, b);
    प्रत्यागम 0;
}
/* 'xxx' not defined outside of function */
पूर्णाङ्क foo(संरचना xxx {पूर्णाङ्क x[3];}*p)
{
    printf("foo %d", परिमाण *p);
    प्रत्यागम p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
पूर्णाङ्क foo(संरचना xxx {पूर्णाङ्क x[2];}*p);
#endif
#ifndef test_scope_3
गणना ee { a = 1, b };
#endif

संरचना xxx x = { 11,22,33,44 };
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    printf(" %d %d\n", foo(&x), परिमाण (संरचना xxx));
    गणना ee e = b;
    bar(13 + e, 0);

}

#नोचेद्यदि defined test_const_array_member_addr_ok

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

int_array ध्रुव *get_array(ध्रुव my_struct *s)
{
    प्रत्यागम &(s->arr);
}

#नोचेद्यदि defined test_const_array_member_decay_ok

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

ध्रुव पूर्णाङ्क *good_decay(ध्रुव my_struct *s)
{
    प्रत्यागम s->arr;
}

#नोचेद्यदि defined test_const_array_member_addr_bad

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

int_array *bad_array_addr(ध्रुव my_struct *s)
{
    प्रत्यागम &(s->arr);
}

#नोचेद्यदि defined test_const_array_member_decay_bad

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

पूर्णाङ्क *bad_decay(ध्रुव my_struct *s)
{
    प्रत्यागम s->arr;
}

#नोचेद्यदि defined test_const_array_member_write_bad

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

शून्य bad_write(ध्रुव my_struct *s)
{
    s->arr[0] = 1;
}

#नोचेद्यदि defined test_const_struct_array_member_write_bad

प्रकारनिर्देश संरचना { पूर्णाङ्क x; } inner;
प्रकारनिर्देश संरचना { inner arr[1]; } outer;

शून्य bad_inner_write(ध्रुव outer *s)
{
    s->arr[0].x = 1;
}

#नोचेद्यदि defined test_volatile_array_member_addr_ok

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

int_array चञ्चल *get_volatile_array(चञ्चल my_struct *s)
{
    प्रत्यागम &(s->arr);
}

#नोचेद्यदि defined test_volatile_array_member_decay_ok

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

चञ्चल पूर्णाङ्क *good_volatile_decay(चञ्चल my_struct *s)
{
    प्रत्यागम s->arr;
}

#नोचेद्यदि defined test_volatile_array_member_addr_bad

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(चञ्चल my_struct *s)
{
    प्रत्यागम &(s->arr);
}

#नोचेद्यदि defined test_volatile_array_member_decay_bad

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

पूर्णाङ्क *bad_volatile_decay(चञ्चल my_struct *s)
{
    प्रत्यागम s->arr;
}

#नोचेद्यदि defined test_volatile_array_member_write_ok

प्रकारनिर्देश पूर्णाङ्क int_array[1];
प्रकारनिर्देश संरचना { int_array arr; } my_struct;

शून्य good_volatile_write(चञ्चल my_struct *s)
{
    s->arr[0] = 1;
}

#नोचेद्यदि defined test_conditional_array_qualifiers

प्रकारनिर्देश पूर्णाङ्क Array2[2];
प्रकारनिर्देश पूर्णाङ्क Array2x3[2][3];

Array2 *p;
ध्रुव Array2 *cp;
ध्रुव Array2x3 *cap;
चञ्चल Array2x3 *vap;

शून्य test(शून्य)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#नोचेद्यदि defined test_restrict_scalar

restrict पूर्णाङ्क object;

#नोचेद्यदि defined test_restrict_function_pointer

पूर्णाङ्क (*restrict function_pointer)(शून्य);

#नोचेद्यदि defined test_discarded_restrict

प्रकारनिर्देश पूर्णाङ्क *restrict restricted_pointer;

restricted_pointer *source;
पूर्णाङ्क **destination;

शून्य test(शून्य)
{
    destination = source;
}

#endif

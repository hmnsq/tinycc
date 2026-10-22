पूर्णांक म_लिखो(स्थिरांक अक्षर*, ...);

#जर defined test_56_btype_excess_1
संरचना A {} पूर्णांक i;
#किंवाजर defined test_57_btype_excess_2
अक्षर पूर्णांक i;
#किंवाजर defined test_58_function_redefinition
पूर्णांक f(शून्य) { परत 0; }
पूर्णांक f(शून्य) { परत 1; }

#किंवाजर defined test_global_redefinition
पूर्णांक xxx = 1;
पूर्णांक xxx;
पूर्णांक xxx = 2;

#किंवाजर defined test_59_function_array
पूर्णांक (*fct)[42](पूर्णांक x);

#किंवाजर defined test_60_enum_redefinition
गणना color { RED, GREEN, BLUE };
गणना color { R, G, B };
गणना color c;

#किंवाजर defined test_62_enumerator_redefinition
गणना color { RED, GREEN, BLUE };
गणना rgb { RED, G, B};
गणना color c = RED;

#किंवाजर defined test_63_local_enumerator_redefinition
गणना {
    FOO,
    BAR
};

पूर्णांक main(शून्य)
{
    गणना {
        FOO = 2,
        BAR
    };

    परत BAR - FOO;
}

#किंवाजर defined test_61_undefined_enum
गणना rgb3 c = 42;

#किंवाजर defined test_74_non_const_init
पूर्णांक i = i++;

#किंवाजर defined test_pointer_assignment

शून्य (*f1)(शून्य);
शून्य f2(शून्य) {}

संरचना s1 *ps1;
संरचना s2 *ps2;

शून्य *v1, **v2, ***v3;

गणना e1 { a = 4 } e10, *e11, *e12;
गणना e2 { b = -4 } e20, *e21;
गणना e3 { c = 5000000000LL } e30;

पूर्णांक *ip;
अचिन्हित पूर्णांक *up;
दीर्घ *lp;
दीर्घ दीर्घ *llp;

अक्षर **c1;
अक्षर स्थिरांक **c2;
अचिन्हित अक्षर **u1;

पूर्णांक no_main ()
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

    परत 0;
}


#किंवाजर defined test_enum_compat
गणना e4;
गणना e5;
शून्य f3(गणना e4 e);
शून्य f3(गणना e5 e);

#किंवाजर defined test_enum_compat_2
गणना e6 { E1 = -1, E0 };
शून्य f3(गणना e6);
शून्य f3(पूर्णांक);        // should work as int and e6 are compatible
शून्य f4(गणना e6 e);
शून्य f4(अचिन्हित e); // should error as unsigned and e6 are incompatible

#किंवाजर defined test_ptr_to_str
शून्य f() { _Generic((पूर्णांक स्थिरांक *[]){0}, पूर्णांक:0); }
#किंवाजर defined test_fnptr_to_str
शून्य f() { _Generic((पूर्णांक (*(*)(दशांश,अक्षर))(द्विगुण,पूर्णांक)){0}, पूर्णांक:0); }
#किंवाजर defined test_array_to_str
शून्य f() { _Generic((पूर्णांक(*)[3]){0}, पूर्णांक:0); }
#किंवाजर defined test_duplicate_def_1
स्थिर गणना myenum { L = -1 } L;                                                
#किंवाजर defined test_duplicate_def_2
शून्य foo(शून्य) {
स्थिर गणना myenum { L = -1 } L;                                                
}
#किंवाजर defined test_abstract_decls
पूर्णांक bar(स्थिरांक अक्षर *());     // abstract declarator here is okay
पूर्णांक bar (स्थिरांक अक्षर *(*g)()) // should match this 'g' argument
{
  g();
  परत 42;
}
पूर्णांक foo(पूर्णांक ())              // abstract decl is wrong in definitions
{
  परत 0;
#किंवाजर defined test_invalid_1
शून्य f(अक्षर*);
शून्य g(शून्य) {
  f((अक्षर[]){1, ,});
}
#किंवाजर defined test_invalid_2
पूर्णांक ga = 0.42 { 2 };
#किंवाजर defined test_invalid_3
संरचना S { पूर्णांक a, b; };
संरचना T { संरचना S x; };
संरचना T gt = { 42 a: 1, 43 };
#किंवाजर defined test_invalid_4
गणना E {
    x = 1 / 0
};
#किंवाजर defined test_conflicting_types
पूर्णांक i;
शून्य foo(शून्य) {
    पूर्णांक i;
      {
        बाह्य द्विगुण i;
        i = 42.2;
      }
}
#किंवाजर defined test_nested_types
संघ u {
    संघ u {
        पूर्णांक i;
    } m;
};
#किंवाजर defined test_vla_1
पूर्णांक X=1;

पूर्णांक main(शून्य) {
  पूर्णांक t[][][X];
}
#किंवाजर defined test_invalid_alignas
/* _Alignas is no type qualifier */
शून्य * _Alignas(16) p1;

#किंवाजर defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 संरचना x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#किंवाजर defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
संरचना y {  _Static_assert(0, "0"" is 0"); };

#किंवाजर defined test_static_assert_c2x
 _Static_assert(1);
संरचना z {  _Static_assert(0); }

#किंवाजर defined test_static_assert_empty_string
 _Static_assert(0,"");

#किंवाजर defined test_void_array
 शून्य t[3];

#किंवाजर defined test_incomplete_enum_array
  गणना e t[3];

#किंवाजर defined test_incomplete_struct_array
  संरचना s t[3];

#किंवाजर defined test_const_fun_array
  प्रकारव्याख्या शून्य f(शून्य);
  स्थिरांक f t[3];

#किंवाजर defined test_incomplete_array_array
  पूर्णांक t[][3]; // gr: not an error, see below

/******************************************************************/
#किंवाजर defined test_extern_array
पूर्णांक iii[] = { 1,2,3 };
बाह्य पूर्णांक iii[];
पूर्णांक x[];
पूर्णांक x[2];
पूर्णांक x[];
पूर्णांक x[2];
पूर्णांक x[];
बाह्य पूर्णांक x[2];
बाह्य पूर्णांक x[];
पूर्णांक x[3];

/******************************************************************/
#किंवाजर defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#जर defined test_func_1
पूर्णांक hello(पूर्णांक);
#किंवाजर defined test_func_4
स्थिर पूर्णांक hello(पूर्णांक);
#endif
पूर्णांक main () {
#जर defined test_func_6
    स्थिर
#endif
    पूर्णांक hello(पूर्णांक);
    hello(123);
    परत 0;
}

#जर defined test_func_3
स्थिर पूर्णांक hello(पूर्णांक a)
#किंवाजर defined test_func_5
पूर्णांक hello(पूर्णांक a, पूर्णांक b)
#अन्यथा
पूर्णांक hello(पूर्णांक a)
#endif
{ म_लिखो("%s: a = %d\n", __FUNCTION__, a); परत 0; }

/******************************************************************/
#किंवाजर defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) म_लिखो("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#जर defined test_var_1
पूर्णांक xxx[];
#endif
पूर्णांक bar();

पूर्णांक main ()
{
#जर !defined test_var_3
    पूर्णांक xxx = 2;
#endif
    {
        बाह्य पूर्णांक xxx[
#जर defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#जर !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    परत 0;
}
पूर्णांक xxx[1] = {1};
पूर्णांक bar() { P(3, xxx[0]); परत 0; }

#किंवाजर defined test_var_4
संरचना yyy { पूर्णांक y; };
संरचना zzz;
शून्य f1() {
    बाह्य अक्षर *x;
    बाह्य अक्षर **xx;
    बाह्य संरचना yyy y;
    बाह्य संरचना yyy *yy;
    बाह्य संरचना zzz z;
    बाह्य संरचना zzz *zz;
}
शून्य f2() {
    बाह्य अक्षर *x;
    बाह्य अक्षर **xx;
    बाह्य संरचना yyy y;
    बाह्य संरचना yyy *yy;
    बाह्य संरचना zzz z;
    बाह्य संरचना zzz *zz;
}
संरचना yyy y, *yy;
संरचना zzz { पूर्णांक z; } z, *zz;

/******************************************************************/
#किंवाजर defined test_long_double_type_for_win32

पूर्णांक main()
{
    द्विगुण *a = 0;
    दीर्घ द्विगुण *b = a;
    पूर्णांक n = _Generic(*a, द्विगुण:0, दीर्घ द्विगुण:1);
}

#किंवाजर defined test_stray_backslash
#define x \a
x

#किंवाजर defined test_stray_backslash2

पूर्णांक main()
{
#define _S(x) #x
#define S(x) _S(x)
    म_लिखो("%sn\n", S(\\));
}

/******************************************************************/
#किंवाजर defined test_var_array

स्थिर संरचना var_len { पूर्णांक i; स्थिरांक अक्षर str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#किंवाजर defined test_var_array2

संरचना c1 { पूर्णांक a; पूर्णांक b[]; };
संरचना c1 c1 = { 1, { 2, 3, 4 } };

संरचना c2 { पूर्णांक c; संरचना c1 c1; };
संरचना c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#किंवाजर defined test_var_array3
/* similar to test_var_array2 but with string initializers */
संरचना A { पूर्णांक a; अक्षर b[]; };
संरचना A a = { 1, "1" };
संरचना B { संरचना A a; };
संरचना B b = { { 1, "1" } };
/******************************************************************/
#किंवाजर defined test_default_int_type
n; // warn
f(); // don't warn

#किंवाजर defined test_invalid_global_stmtexpr
n[आकार({3;})]; // crashed in block() due to missing local scope

#किंवाजर defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#किंवाजर defined test_duplicate_member
संरचना S {
  पूर्णांक a, a;
};
#किंवाजर defined test_duplicate_member_anon
संरचना S1 {
  पूर्णांक b;
  संरचना {
    पूर्णांक b;
  } c;
};
संरचना S2 {
  पूर्णांक d;
  संरचना {
    पूर्णांक d;
  };
};

/******************************************************************/
#किंवाजर defined test_conflicting_array_definition
बाह्य पूर्णांक array[2];
पूर्णांक array[] = { 1, 2, 3 };

#किंवाजर defined test_incompatible_local_redef
शून्य foo (शून्य)
{
  प्रकारव्याख्या पूर्णांक localfunctype (पूर्णांक);
  बाह्य localfunctype func2;
  प्रकारव्याख्या शून्य localfunctype (पूर्णांक, पूर्णांक);
}

#किंवाजर defined test_cast_from_void
शून्य v() {}
पूर्णांक f() { परत v(); }

#किंवाजर defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#जर defined test_switch_W1
#pragma comment(option, "-Wall")
#किंवाजर defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#किंवाजर defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#किंवाजर defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
शून्य func(शून्य)
{
    अक्षर *ccp = "123";
    fink();
}
__attribute__((stuff)) पूर्णांक fink() {परत 0;}

#किंवाजर defined test_invalid_funcparam_1
शून्य func(पूर्णांक a, पूर्णांक b, पूर्णांक a);

#किंवाजर defined test_invalid_funcparam_2
शून्य func(पूर्णांक a, पूर्णांक जर);

#किंवाजर defined test_array_funcparam
पूर्णांक amain(पूर्णांक argc, अक्षर *argv[स्थिर argc + 1])
{
    पूर्णांक i;

    साठी (i = 0; i < argc; ++i)
        म_लिखो("arg[%d] = \"%s\"\n", i, argv[i]);
    परत 0;
}
पूर्णांक main()
{
    परत amain(2, (अक्षर *[]){ "X", "Y", 0 });
}

#किंवाजर defined test_return_from_statement_अभिव्यक्ती
पूर्णांक f() { ({ परत 78; }); }
पूर्णांक main() { परत f(); }

/******************************************************************/

#किंवाजर defined test_illegal_unicode
पूर्णांक main() {
    अक्षर *str = "\Uffffffff";
}

#किंवाजर defined test_error_string
#error \123\\
456

#किंवाजर defined test_error_incomplete_type
संरचना A;
शून्य f(संरचना A *);

पूर्णांक main()
{
    f(&(संरचना A){});
}

संरचना A {
    पूर्णांक x;
};

#किंवाजर defined test_pp_error_1
# जर //no expression
# endif
#किंवाजर defined test_pp_error_2
# जर X(1,2) //undefined function macro
# endif

#किंवाजर defined test_pointer_plus_double

पूर्णांक *invalid_operation(पूर्णांक *p, द्विगुण d)
{
    परत p + d;
}

#किंवाजर defined test_duplicate_case

पूर्णांक main()
{
    अचिन्हित पूर्णांक x;
    निवड (x) {
        स्थिती -1 ... 0: /* empty case range with unsigned */
        स्थिती 3:
        स्थिती 1:
        स्थिती 2:
        स्थिती 3: /* show this line number in error */
        स्थिती 4:
        स्थिती 5:
    }
}
#किंवाजर defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

पूर्णांक main()
{
    म_लिखो(" %d %d %d\n", म_लिखो("1"), म_लिखो("22"), म_लिखो("333"));
}

#किंवाजर defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

संरचना xxx {पूर्णांक x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
पूर्णांक bar(गणना ee { a = 12, b = 34 } i, पूर्णांक(*f)(पूर्णांक i))
{
    म_लिखो("bar %d %d %d\n", i, a, b);
    परत 0;
}
/* 'xxx' not defined outside of function */
पूर्णांक foo(संरचना xxx {पूर्णांक x[3];}*p)
{
    म_लिखो("foo %d", आकार *p);
    परत p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
पूर्णांक foo(संरचना xxx {पूर्णांक x[2];}*p);
#endif
#ifndef test_scope_3
गणना ee { a = 1, b };
#endif

संरचना xxx x = { 11,22,33,44 };
पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    म_लिखो(" %d %d\n", foo(&x), आकार (संरचना xxx));
    गणना ee e = b;
    bar(13 + e, 0);

}

#किंवाजर defined test_const_array_member_addr_ok

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

int_array स्थिरांक *get_array(स्थिरांक my_struct *s)
{
    परत &(s->arr);
}

#किंवाजर defined test_const_array_member_decay_ok

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

स्थिरांक पूर्णांक *good_decay(स्थिरांक my_struct *s)
{
    परत s->arr;
}

#किंवाजर defined test_const_array_member_addr_bad

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

int_array *bad_array_addr(स्थिरांक my_struct *s)
{
    परत &(s->arr);
}

#किंवाजर defined test_const_array_member_decay_bad

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

पूर्णांक *bad_decay(स्थिरांक my_struct *s)
{
    परत s->arr;
}

#किंवाजर defined test_const_array_member_write_bad

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

शून्य bad_write(स्थिरांक my_struct *s)
{
    s->arr[0] = 1;
}

#किंवाजर defined test_const_struct_array_member_write_bad

प्रकारव्याख्या संरचना { पूर्णांक x; } inner;
प्रकारव्याख्या संरचना { inner arr[1]; } outer;

शून्य bad_inner_write(स्थिरांक outer *s)
{
    s->arr[0].x = 1;
}

#किंवाजर defined test_volatile_array_member_addr_ok

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

int_array अस्थिर *get_volatile_array(अस्थिर my_struct *s)
{
    परत &(s->arr);
}

#किंवाजर defined test_volatile_array_member_decay_ok

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

अस्थिर पूर्णांक *good_volatile_decay(अस्थिर my_struct *s)
{
    परत s->arr;
}

#किंवाजर defined test_volatile_array_member_addr_bad

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(अस्थिर my_struct *s)
{
    परत &(s->arr);
}

#किंवाजर defined test_volatile_array_member_decay_bad

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

पूर्णांक *bad_volatile_decay(अस्थिर my_struct *s)
{
    परत s->arr;
}

#किंवाजर defined test_volatile_array_member_write_ok

प्रकारव्याख्या पूर्णांक int_array[1];
प्रकारव्याख्या संरचना { int_array arr; } my_struct;

शून्य good_volatile_write(अस्थिर my_struct *s)
{
    s->arr[0] = 1;
}

#किंवाजर defined test_conditional_array_qualifiers

प्रकारव्याख्या पूर्णांक Array2[2];
प्रकारव्याख्या पूर्णांक Array2x3[2][3];

Array2 *p;
स्थिरांक Array2 *cp;
स्थिरांक Array2x3 *cap;
अस्थिर Array2x3 *vap;

शून्य test(शून्य)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#किंवाजर defined test_restrict_scalar

restrict पूर्णांक object;

#किंवाजर defined test_restrict_function_pointer

पूर्णांक (*restrict function_pointer)(शून्य);

#किंवाजर defined test_discarded_restrict

प्रकारव्याख्या पूर्णांक *restrict restricted_pointer;

restricted_pointer *source;
पूर्णांक **destination;

शून्य test(शून्य)
{
    destination = source;
}

#endif

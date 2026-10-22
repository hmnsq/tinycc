पूर्णांक म_लिखो(स्थिर अक्षर*, ...);

#अगर defined test_56_btype_excess_1
काष्ठा A {} पूर्णांक i;
#या_अगर defined test_57_btype_excess_2
अक्षर पूर्णांक i;
#या_अगर defined test_58_function_redefinition
पूर्णांक f(व्योम) { वापस 0; }
पूर्णांक f(व्योम) { वापस 1; }

#या_अगर defined test_global_redefinition
पूर्णांक xxx = 1;
पूर्णांक xxx;
पूर्णांक xxx = 2;

#या_अगर defined test_59_function_array
पूर्णांक (*fct)[42](पूर्णांक x);

#या_अगर defined test_60_enum_redefinition
क्रमागत color { RED, GREEN, BLUE };
क्रमागत color { R, G, B };
क्रमागत color c;

#या_अगर defined test_62_enumerator_redefinition
क्रमागत color { RED, GREEN, BLUE };
क्रमागत rgb { RED, G, B};
क्रमागत color c = RED;

#या_अगर defined test_63_local_enumerator_redefinition
क्रमागत {
    FOO,
    BAR
};

पूर्णांक मुख्य(व्योम)
{
    क्रमागत {
        FOO = 2,
        BAR
    };

    वापस BAR - FOO;
}

#या_अगर defined test_61_undefined_enum
क्रमागत rgb3 c = 42;

#या_अगर defined test_74_non_const_init
पूर्णांक i = i++;

#या_अगर defined test_pointer_assignment

व्योम (*f1)(व्योम);
व्योम f2(व्योम) {}

काष्ठा s1 *ps1;
काष्ठा s2 *ps2;

व्योम *v1, **v2, ***v3;

क्रमागत e1 { a = 4 } e10, *e11, *e12;
क्रमागत e2 { b = -4 } e20, *e21;
क्रमागत e3 { c = 5000000000LL } e30;

पूर्णांक *ip;
अचिन्हित पूर्णांक *up;
दीर्घ *lp;
दीर्घ दीर्घ *llp;

अक्षर **c1;
अक्षर स्थिर **c2;
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

    वापस 0;
}


#या_अगर defined test_enum_compat
क्रमागत e4;
क्रमागत e5;
व्योम f3(क्रमागत e4 e);
व्योम f3(क्रमागत e5 e);

#या_अगर defined test_enum_compat_2
क्रमागत e6 { E1 = -1, E0 };
व्योम f3(क्रमागत e6);
व्योम f3(पूर्णांक);        // should work as int and e6 are compatible
व्योम f4(क्रमागत e6 e);
व्योम f4(अचिन्हित e); // should error as unsigned and e6 are incompatible

#या_अगर defined test_ptr_to_str
व्योम f() { _Generic((पूर्णांक स्थिर *[]){0}, पूर्णांक:0); }
#या_अगर defined test_fnptr_to_str
व्योम f() { _Generic((पूर्णांक (*(*)(भग्न,अक्षर))(द्विगुन,पूर्णांक)){0}, पूर्णांक:0); }
#या_अगर defined test_array_to_str
व्योम f() { _Generic((पूर्णांक(*)[3]){0}, पूर्णांक:0); }
#या_अगर defined test_duplicate_def_1
अटल क्रमागत myenum { L = -1 } L;                                                
#या_अगर defined test_duplicate_def_2
व्योम foo(व्योम) {
अटल क्रमागत myenum { L = -1 } L;                                                
}
#या_अगर defined test_abstract_decls
पूर्णांक bar(स्थिर अक्षर *());     // abstract declarator here is okay
पूर्णांक bar (स्थिर अक्षर *(*g)()) // should match this 'g' argument
{
  g();
  वापस 42;
}
पूर्णांक foo(पूर्णांक ())              // abstract decl is wrong in definitions
{
  वापस 0;
#या_अगर defined test_invalid_1
व्योम f(अक्षर*);
व्योम g(व्योम) {
  f((अक्षर[]){1, ,});
}
#या_अगर defined test_invalid_2
पूर्णांक ga = 0.42 { 2 };
#या_अगर defined test_invalid_3
काष्ठा S { पूर्णांक a, b; };
काष्ठा T { काष्ठा S x; };
काष्ठा T gt = { 42 a: 1, 43 };
#या_अगर defined test_invalid_4
क्रमागत E {
    x = 1 / 0
};
#या_अगर defined test_conflicting_types
पूर्णांक i;
व्योम foo(व्योम) {
    पूर्णांक i;
      {
        बाह्य द्विगुन i;
        i = 42.2;
      }
}
#या_अगर defined test_nested_types
जोड़ u {
    जोड़ u {
        पूर्णांक i;
    } m;
};
#या_अगर defined test_vla_1
पूर्णांक X=1;

पूर्णांक मुख्य(व्योम) {
  पूर्णांक t[][][X];
}
#या_अगर defined test_invalid_alignas
/* _Alignas is no type qualifier */
व्योम * _Alignas(16) p1;

#या_अगर defined test_static_assert

#घोषणा ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 काष्ठा x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#या_अगर defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
काष्ठा y {  _Static_assert(0, "0"" is 0"); };

#या_अगर defined test_static_assert_c2x
 _Static_assert(1);
काष्ठा z {  _Static_assert(0); }

#या_अगर defined test_static_assert_empty_string
 _Static_assert(0,"");

#या_अगर defined test_void_array
 व्योम t[3];

#या_अगर defined test_incomplete_enum_array
  क्रमागत e t[3];

#या_अगर defined test_incomplete_struct_array
  काष्ठा s t[3];

#या_अगर defined test_const_fun_array
  प्रकार व्योम f(व्योम);
  स्थिर f t[3];

#या_अगर defined test_incomplete_array_array
  पूर्णांक t[][3]; // gr: not an error, see below

/******************************************************************/
#या_अगर defined test_extern_array
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
#या_अगर defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#अगर defined test_func_1
पूर्णांक hello(पूर्णांक);
#या_अगर defined test_func_4
अटल पूर्णांक hello(पूर्णांक);
#पूर्ण_अगर
पूर्णांक मुख्य () {
#अगर defined test_func_6
    अटल
#पूर्ण_अगर
    पूर्णांक hello(पूर्णांक);
    hello(123);
    वापस 0;
}

#अगर defined test_func_3
अटल पूर्णांक hello(पूर्णांक a)
#या_अगर defined test_func_5
पूर्णांक hello(पूर्णांक a, पूर्णांक b)
#अन्यथा
पूर्णांक hello(पूर्णांक a)
#पूर्ण_अगर
{ म_लिखो("%s: a = %d\n", __FUNCTION__, a); वापस 0; }

/******************************************************************/
#या_अगर defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#घोषणा P(n,v) म_लिखो("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#अगर defined test_var_1
पूर्णांक xxx[];
#पूर्ण_अगर
पूर्णांक bar();

पूर्णांक मुख्य ()
{
#अगर !defined test_var_3
    पूर्णांक xxx = 2;
#पूर्ण_अगर
    {
        बाह्य पूर्णांक xxx[
#अगर defined test_var_3
        2
#पूर्ण_अगर
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#अगर !defined test_var_3
    P(2, xxx);
#पूर्ण_अगर
    bar(123);
    वापस 0;
}
पूर्णांक xxx[1] = {1};
पूर्णांक bar() { P(3, xxx[0]); वापस 0; }

#या_अगर defined test_var_4
काष्ठा yyy { पूर्णांक y; };
काष्ठा zzz;
व्योम f1() {
    बाह्य अक्षर *x;
    बाह्य अक्षर **xx;
    बाह्य काष्ठा yyy y;
    बाह्य काष्ठा yyy *yy;
    बाह्य काष्ठा zzz z;
    बाह्य काष्ठा zzz *zz;
}
व्योम f2() {
    बाह्य अक्षर *x;
    बाह्य अक्षर **xx;
    बाह्य काष्ठा yyy y;
    बाह्य काष्ठा yyy *yy;
    बाह्य काष्ठा zzz z;
    बाह्य काष्ठा zzz *zz;
}
काष्ठा yyy y, *yy;
काष्ठा zzz { पूर्णांक z; } z, *zz;

/******************************************************************/
#या_अगर defined test_long_double_type_for_win32

पूर्णांक मुख्य()
{
    द्विगुन *a = 0;
    दीर्घ द्विगुन *b = a;
    पूर्णांक n = _Generic(*a, द्विगुन:0, दीर्घ द्विगुन:1);
}

#या_अगर defined test_stray_backslash
#घोषणा x \a
x

#या_अगर defined test_stray_backslash2

पूर्णांक मुख्य()
{
#घोषणा _S(x) #x
#घोषणा S(x) _S(x)
    म_लिखो("%sn\n", S(\\));
}

/******************************************************************/
#या_अगर defined test_var_array

अटल काष्ठा var_len { पूर्णांक i; स्थिर अक्षर str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#या_अगर defined test_var_array2

काष्ठा c1 { पूर्णांक a; पूर्णांक b[]; };
काष्ठा c1 c1 = { 1, { 2, 3, 4 } };

काष्ठा c2 { पूर्णांक c; काष्ठा c1 c1; };
काष्ठा c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#या_अगर defined test_var_array3
/* similar to test_var_array2 but with string initializers */
काष्ठा A { पूर्णांक a; अक्षर b[]; };
काष्ठा A a = { 1, "1" };
काष्ठा B { काष्ठा A a; };
काष्ठा B b = { { 1, "1" } };
/******************************************************************/
#या_अगर defined test_default_int_type
n; // warn
f(); // don't warn

#या_अगर defined test_invalid_global_stmtexpr
n[माप({3;})]; // crashed in block() due to missing local scope

#या_अगर defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#या_अगर defined test_duplicate_member
काष्ठा S {
  पूर्णांक a, a;
};
#या_अगर defined test_duplicate_member_anon
काष्ठा S1 {
  पूर्णांक b;
  काष्ठा {
    पूर्णांक b;
  } c;
};
काष्ठा S2 {
  पूर्णांक d;
  काष्ठा {
    पूर्णांक d;
  };
};

/******************************************************************/
#या_अगर defined test_conflicting_array_definition
बाह्य पूर्णांक array[2];
पूर्णांक array[] = { 1, 2, 3 };

#या_अगर defined test_incompatible_local_redef
व्योम foo (व्योम)
{
  प्रकार पूर्णांक localfunctype (पूर्णांक);
  बाह्य localfunctype func2;
  प्रकार व्योम localfunctype (पूर्णांक, पूर्णांक);
}

#या_अगर defined test_cast_from_void
व्योम v() {}
पूर्णांक f() { वापस v(); }

#या_अगर defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#अगर defined test_switch_W1
#आशय comment(option, "-Wall")
#या_अगर defined test_switch_W2
#आशय comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#या_अगर defined test_switch_W3
#आशय comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#या_अगर defined test_switch_W4
#आशय comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#पूर्ण_अगर
व्योम func(व्योम)
{
    अक्षर *ccp = "123";
    fink();
}
__attribute__((stuff)) पूर्णांक fink() {वापस 0;}

#या_अगर defined test_invalid_funcparam_1
व्योम func(पूर्णांक a, पूर्णांक b, पूर्णांक a);

#या_अगर defined test_invalid_funcparam_2
व्योम func(पूर्णांक a, पूर्णांक अगर);

#या_अगर defined test_array_funcparam
पूर्णांक amain(पूर्णांक argc, अक्षर *argv[अटल argc + 1])
{
    पूर्णांक i;

    क्रम (i = 0; i < argc; ++i)
        म_लिखो("arg[%d] = \"%s\"\n", i, argv[i]);
    वापस 0;
}
पूर्णांक मुख्य()
{
    वापस amain(2, (अक्षर *[]){ "X", "Y", 0 });
}

#या_अगर defined test_return_from_statement_व्यंजक
पूर्णांक f() { ({ वापस 78; }); }
पूर्णांक मुख्य() { वापस f(); }

/******************************************************************/

#या_अगर defined test_illegal_unicode
पूर्णांक मुख्य() {
    अक्षर *str = "\Uffffffff";
}

#या_अगर defined test_error_string
#त्रुटि \123\\
456

#या_अगर defined test_error_incomplete_type
काष्ठा A;
व्योम f(काष्ठा A *);

पूर्णांक मुख्य()
{
    f(&(काष्ठा A){});
}

काष्ठा A {
    पूर्णांक x;
};

#या_अगर defined test_pp_error_1
# अगर //no expression
# endif
#या_अगर defined test_pp_error_2
# अगर X(1,2) //undefined function macro
# endif

#या_अगर defined test_pointer_plus_double

पूर्णांक *invalid_operation(पूर्णांक *p, द्विगुन d)
{
    वापस p + d;
}

#या_अगर defined test_duplicate_case

पूर्णांक मुख्य()
{
    अचिन्हित पूर्णांक x;
    चयन (x) {
        हाल -1 ... 0: /* empty case range with unsigned */
        हाल 3:
        हाल 1:
        हाल 2:
        हाल 3: /* show this line number in error */
        हाल 4:
        हाल 5:
    }
}
#या_अगर defined test_normal_funcargs || defined test_reverse_funcargs

#अगर_घोषित test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#पूर्ण_अगर

पूर्णांक मुख्य()
{
    म_लिखो(" %d %d %d\n", म_लिखो("1"), म_लिखो("22"), म_लिखो("333"));
}

#या_अगर defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

काष्ठा xxx {पूर्णांक x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
पूर्णांक bar(क्रमागत ee { a = 12, b = 34 } i, पूर्णांक(*f)(पूर्णांक i))
{
    म_लिखो("bar %d %d %d\n", i, a, b);
    वापस 0;
}
/* 'xxx' not defined outside of function */
पूर्णांक foo(काष्ठा xxx {पूर्णांक x[3];}*p)
{
    म_लिखो("foo %d", माप *p);
    वापस p->x[3];
}
#अगर_घोषित test_scope_2
/* incompatible redefinition */
पूर्णांक foo(काष्ठा xxx {पूर्णांक x[2];}*p);
#पूर्ण_अगर
#अगर_अघोषित test_scope_3
क्रमागत ee { a = 1, b };
#पूर्ण_अगर

काष्ठा xxx x = { 11,22,33,44 };
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    म_लिखो(" %d %d\n", foo(&x), माप (काष्ठा xxx));
    क्रमागत ee e = b;
    bar(13 + e, 0);

}

#या_अगर defined test_const_array_member_addr_ok

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

int_array स्थिर *get_array(स्थिर my_struct *s)
{
    वापस &(s->arr);
}

#या_अगर defined test_const_array_member_decay_ok

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

स्थिर पूर्णांक *good_decay(स्थिर my_struct *s)
{
    वापस s->arr;
}

#या_अगर defined test_const_array_member_addr_bad

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

int_array *bad_array_addr(स्थिर my_struct *s)
{
    वापस &(s->arr);
}

#या_अगर defined test_const_array_member_decay_bad

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

पूर्णांक *bad_decay(स्थिर my_struct *s)
{
    वापस s->arr;
}

#या_अगर defined test_const_array_member_write_bad

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

व्योम bad_write(स्थिर my_struct *s)
{
    s->arr[0] = 1;
}

#या_अगर defined test_const_struct_array_member_write_bad

प्रकार काष्ठा { पूर्णांक x; } inner;
प्रकार काष्ठा { inner arr[1]; } outer;

व्योम bad_inner_write(स्थिर outer *s)
{
    s->arr[0].x = 1;
}

#या_अगर defined test_volatile_array_member_addr_ok

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

int_array अस्थिर *get_volatile_array(अस्थिर my_struct *s)
{
    वापस &(s->arr);
}

#या_अगर defined test_volatile_array_member_decay_ok

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

अस्थिर पूर्णांक *good_volatile_decay(अस्थिर my_struct *s)
{
    वापस s->arr;
}

#या_अगर defined test_volatile_array_member_addr_bad

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(अस्थिर my_struct *s)
{
    वापस &(s->arr);
}

#या_अगर defined test_volatile_array_member_decay_bad

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

पूर्णांक *bad_volatile_decay(अस्थिर my_struct *s)
{
    वापस s->arr;
}

#या_अगर defined test_volatile_array_member_write_ok

प्रकार पूर्णांक int_array[1];
प्रकार काष्ठा { int_array arr; } my_struct;

व्योम good_volatile_write(अस्थिर my_struct *s)
{
    s->arr[0] = 1;
}

#या_अगर defined test_conditional_array_qualifiers

प्रकार पूर्णांक Array2[2];
प्रकार पूर्णांक Array2x3[2][3];

Array2 *p;
स्थिर Array2 *cp;
स्थिर Array2x3 *cap;
अस्थिर Array2x3 *vap;

व्योम test(व्योम)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#या_अगर defined test_restrict_scalar

restrict पूर्णांक object;

#या_अगर defined test_restrict_function_pointer

पूर्णांक (*restrict function_pointer)(व्योम);

#या_अगर defined test_discarded_restrict

प्रकार पूर्णांक *restrict restricted_pointer;

restricted_pointer *source;
पूर्णांक **destination;

व्योम test(व्योम)
{
    destination = source;
}

#पूर्ण_अगर

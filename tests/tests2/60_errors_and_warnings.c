પૂર્ણાંક printf(અચલ અક્ષર*, ...);

#જો defined test_56_btype_excess_1
સંરચના A {} પૂર્ણાંક i;
#અથવાજો defined test_57_btype_excess_2
અક્ષર પૂર્ણાંક i;
#અથવાજો defined test_58_function_redefinition
પૂર્ણાંક f(શૂન્ય) { પાછા 0; }
પૂર્ણાંક f(શૂન્ય) { પાછા 1; }

#અથવાજો defined test_global_redefinition
પૂર્ણાંક xxx = 1;
પૂર્ણાંક xxx;
પૂર્ણાંક xxx = 2;

#અથવાજો defined test_59_function_array
પૂર્ણાંક (*fct)[42](પૂર્ણાંક x);

#અથવાજો defined test_60_enum_redefinition
ગણના color { RED, GREEN, BLUE };
ગણના color { R, G, B };
ગણના color c;

#અથવાજો defined test_62_enumerator_redefinition
ગણના color { RED, GREEN, BLUE };
ગણના rgb { RED, G, B};
ગણના color c = RED;

#અથવાજો defined test_63_local_enumerator_redefinition
ગણના {
    FOO,
    BAR
};

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    ગણના {
        FOO = 2,
        BAR
    };

    પાછા BAR - FOO;
}

#અથવાજો defined test_61_undefined_enum
ગણના rgb3 c = 42;

#અથવાજો defined test_74_non_const_init
પૂર્ણાંક i = i++;

#અથવાજો defined test_pointer_assignment

શૂન્ય (*f1)(શૂન્ય);
શૂન્ય f2(શૂન્ય) {}

સંરચના s1 *ps1;
સંરચના s2 *ps2;

શૂન્ય *v1, **v2, ***v3;

ગણના e1 { a = 4 } e10, *e11, *e12;
ગણના e2 { b = -4 } e20, *e21;
ગણના e3 { c = 5000000000LL } e30;

પૂર્ણાંક *ip;
unsigned પૂર્ણાંક *up;
long *lp;
long long *llp;

અક્ષર **c1;
અક્ષર અચલ **c2;
unsigned અક્ષર **u1;

પૂર્ણાંક no_main ()
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

    પાછા 0;
}


#અથવાજો defined test_enum_compat
ગણના e4;
ગણના e5;
શૂન્ય f3(ગણના e4 e);
શૂન્ય f3(ગણના e5 e);

#અથવાજો defined test_enum_compat_2
ગણના e6 { E1 = -1, E0 };
શૂન્ય f3(ગણના e6);
શૂન્ય f3(પૂર્ણાંક);        // should work as int and e6 are compatible
શૂન્ય f4(ગણના e6 e);
શૂન્ય f4(unsigned e); // should error as unsigned and e6 are incompatible

#અથવાજો defined test_ptr_to_str
શૂન્ય f() { _Generic((પૂર્ણાંક અચલ *[]){0}, પૂર્ણાંક:0); }
#અથવાજો defined test_fnptr_to_str
શૂન્ય f() { _Generic((પૂર્ણાંક (*(*)(દશાંશ,અક્ષર))(દ્વિગુણ,પૂર્ણાંક)){0}, પૂર્ણાંક:0); }
#અથવાજો defined test_array_to_str
શૂન્ય f() { _Generic((પૂર્ણાંક(*)[3]){0}, પૂર્ણાંક:0); }
#અથવાજો defined test_duplicate_def_1
સ્થિર ગણના myenum { L = -1 } L;                                                
#અથવાજો defined test_duplicate_def_2
શૂન્ય foo(શૂન્ય) {
સ્થિર ગણના myenum { L = -1 } L;                                                
}
#અથવાજો defined test_abstract_decls
પૂર્ણાંક bar(અચલ અક્ષર *());     // abstract declarator here is okay
પૂર્ણાંક bar (અચલ અક્ષર *(*g)()) // should match this 'g' argument
{
  g();
  પાછા 42;
}
પૂર્ણાંક foo(પૂર્ણાંક ())              // abstract decl is wrong in definitions
{
  પાછા 0;
#અથવાજો defined test_invalid_1
શૂન્ય f(અક્ષર*);
શૂન્ય g(શૂન્ય) {
  f((અક્ષર[]){1, ,});
}
#અથવાજો defined test_invalid_2
પૂર્ણાંક ga = 0.42 { 2 };
#અથવાજો defined test_invalid_3
સંરચના S { પૂર્ણાંક a, b; };
સંરચના T { સંરચના S x; };
સંરચના T gt = { 42 a: 1, 43 };
#અથવાજો defined test_invalid_4
ગણના E {
    x = 1 / 0
};
#અથવાજો defined test_conflicting_types
પૂર્ણાંક i;
શૂન્ય foo(શૂન્ય) {
    પૂર્ણાંક i;
      {
        બાહ્ય દ્વિગુણ i;
        i = 42.2;
      }
}
#અથવાજો defined test_nested_types
સંઘ u {
    સંઘ u {
        પૂર્ણાંક i;
    } m;
};
#અથવાજો defined test_vla_1
પૂર્ણાંક X=1;

પૂર્ણાંક મુખ્ય(શૂન્ય) {
  પૂર્ણાંક t[][][X];
}
#અથવાજો defined test_invalid_alignas
/* _Alignas is no type qualifier */
શૂન્ય * _Alignas(16) p1;

#અથવાજો defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 સંરચના x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#અથવાજો defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
સંરચના y {  _Static_assert(0, "0"" is 0"); };

#અથવાજો defined test_static_assert_c2x
 _Static_assert(1);
સંરચના z {  _Static_assert(0); }

#અથવાજો defined test_static_assert_empty_string
 _Static_assert(0,"");

#અથવાજો defined test_void_array
 શૂન્ય t[3];

#અથવાજો defined test_incomplete_enum_array
  ગણના e t[3];

#અથવાજો defined test_incomplete_struct_array
  સંરચના s t[3];

#અથવાજો defined test_const_fun_array
  પ્રકારવ્યાખ્યા શૂન્ય f(શૂન્ય);
  અચલ f t[3];

#અથવાજો defined test_incomplete_array_array
  પૂર્ણાંક t[][3]; // gr: not an error, see below

/******************************************************************/
#અથવાજો defined test_extern_array
પૂર્ણાંક iii[] = { 1,2,3 };
બાહ્ય પૂર્ણાંક iii[];
પૂર્ણાંક x[];
પૂર્ણાંક x[2];
પૂર્ણાંક x[];
પૂર્ણાંક x[2];
પૂર્ણાંક x[];
બાહ્ય પૂર્ણાંક x[2];
બાહ્ય પૂર્ણાંક x[];
પૂર્ણાંક x[3];

/******************************************************************/
#અથવાજો defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#જો defined test_func_1
પૂર્ણાંક hello(પૂર્ણાંક);
#અથવાજો defined test_func_4
સ્થિર પૂર્ણાંક hello(પૂર્ણાંક);
#endif
પૂર્ણાંક મુખ્ય () {
#જો defined test_func_6
    સ્થિર
#endif
    પૂર્ણાંક hello(પૂર્ણાંક);
    hello(123);
    પાછા 0;
}

#જો defined test_func_3
સ્થિર પૂર્ણાંક hello(પૂર્ણાંક a)
#અથવાજો defined test_func_5
પૂર્ણાંક hello(પૂર્ણાંક a, પૂર્ણાંક b)
#નહીંતર
પૂર્ણાંક hello(પૂર્ણાંક a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); પાછા 0; }

/******************************************************************/
#અથવાજો defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#જો defined test_var_1
પૂર્ણાંક xxx[];
#endif
પૂર્ણાંક bar();

પૂર્ણાંક મુખ્ય ()
{
#જો !defined test_var_3
    પૂર્ણાંક xxx = 2;
#endif
    {
        બાહ્ય પૂર્ણાંક xxx[
#જો defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#જો !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    પાછા 0;
}
પૂર્ણાંક xxx[1] = {1};
પૂર્ણાંક bar() { P(3, xxx[0]); પાછા 0; }

#અથવાજો defined test_var_4
સંરચના yyy { પૂર્ણાંક y; };
સંરચના zzz;
શૂન્ય f1() {
    બાહ્ય અક્ષર *x;
    બાહ્ય અક્ષર **xx;
    બાહ્ય સંરચના yyy y;
    બાહ્ય સંરચના yyy *yy;
    બાહ્ય સંરચના zzz z;
    બાહ્ય સંરચના zzz *zz;
}
શૂન્ય f2() {
    બાહ્ય અક્ષર *x;
    બાહ્ય અક્ષર **xx;
    બાહ્ય સંરચના yyy y;
    બાહ્ય સંરચના yyy *yy;
    બાહ્ય સંરચના zzz z;
    બાહ્ય સંરચના zzz *zz;
}
સંરચના yyy y, *yy;
સંરચના zzz { પૂર્ણાંક z; } z, *zz;

/******************************************************************/
#અથવાજો defined test_long_double_type_for_win32

પૂર્ણાંક મુખ્ય()
{
    દ્વિગુણ *a = 0;
    long દ્વિગુણ *b = a;
    પૂર્ણાંક n = _Generic(*a, દ્વિગુણ:0, long દ્વિગુણ:1);
}

#અથવાજો defined test_stray_backslash
#define x \a
x

#અથવાજો defined test_stray_backslash2

પૂર્ણાંક મુખ્ય()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#અથવાજો defined test_var_array

સ્થિર સંરચના var_len { પૂર્ણાંક i; અચલ અક્ષર str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#અથવાજો defined test_var_array2

સંરચના c1 { પૂર્ણાંક a; પૂર્ણાંક b[]; };
સંરચના c1 c1 = { 1, { 2, 3, 4 } };

સંરચના c2 { પૂર્ણાંક c; સંરચના c1 c1; };
સંરચના c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#અથવાજો defined test_var_array3
/* similar to test_var_array2 but with string initializers */
સંરચના A { પૂર્ણાંક a; અક્ષર b[]; };
સંરચના A a = { 1, "1" };
સંરચના B { સંરચના A a; };
સંરચના B b = { { 1, "1" } };
/******************************************************************/
#અથવાજો defined test_default_int_type
n; // warn
f(); // don't warn

#અથવાજો defined test_invalid_global_stmtexpr
n[કદ({3;})]; // crashed in block() due to missing local scope

#અથવાજો defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#અથવાજો defined test_duplicate_member
સંરચના S {
  પૂર્ણાંક a, a;
};
#અથવાજો defined test_duplicate_member_anon
સંરચના S1 {
  પૂર્ણાંક b;
  સંરચના {
    પૂર્ણાંક b;
  } c;
};
સંરચના S2 {
  પૂર્ણાંક d;
  સંરચના {
    પૂર્ણાંક d;
  };
};

/******************************************************************/
#અથવાજો defined test_conflicting_array_definition
બાહ્ય પૂર્ણાંક array[2];
પૂર્ણાંક array[] = { 1, 2, 3 };

#અથવાજો defined test_incompatible_local_redef
શૂન્ય foo (શૂન્ય)
{
  પ્રકારવ્યાખ્યા પૂર્ણાંક localfunctype (પૂર્ણાંક);
  બાહ્ય localfunctype func2;
  પ્રકારવ્યાખ્યા શૂન્ય localfunctype (પૂર્ણાંક, પૂર્ણાંક);
}

#અથવાજો defined test_cast_from_void
શૂન્ય v() {}
પૂર્ણાંક f() { પાછા v(); }

#અથવાજો defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#જો defined test_switch_W1
#pragma comment(option, "-Wall")
#અથવાજો defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#અથવાજો defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#અથવાજો defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
શૂન્ય func(શૂન્ય)
{
    અક્ષર *ccp = "123";
    fink();
}
__attribute__((stuff)) પૂર્ણાંક fink() {પાછા 0;}

#અથવાજો defined test_invalid_funcparam_1
શૂન્ય func(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક a);

#અથવાજો defined test_invalid_funcparam_2
શૂન્ય func(પૂર્ણાંક a, પૂર્ણાંક જો);

#અથવાજો defined test_array_funcparam
પૂર્ણાંક amain(પૂર્ણાંક argc, અક્ષર *argv[સ્થિર argc + 1])
{
    પૂર્ણાંક i;

    માટે (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    પાછા 0;
}
પૂર્ણાંક મુખ્ય()
{
    પાછા amain(2, (અક્ષર *[]){ "X", "Y", 0 });
}

#અથવાજો defined test_return_from_statement_પદાવલિ
પૂર્ણાંક f() { ({ પાછા 78; }); }
પૂર્ણાંક મુખ્ય() { પાછા f(); }

/******************************************************************/

#અથવાજો defined test_illegal_unicode
પૂર્ણાંક મુખ્ય() {
    અક્ષર *str = "\Uffffffff";
}

#અથવાજો defined test_error_string
#error \123\\
456

#અથવાજો defined test_error_incomplete_type
સંરચના A;
શૂન્ય f(સંરચના A *);

પૂર્ણાંક મુખ્ય()
{
    f(&(સંરચના A){});
}

સંરચના A {
    પૂર્ણાંક x;
};

#અથવાજો defined test_pp_error_1
# જો //no expression
# endif
#અથવાજો defined test_pp_error_2
# જો X(1,2) //undefined function macro
# endif

#અથવાજો defined test_pointer_plus_double

પૂર્ણાંક *invalid_operation(પૂર્ણાંક *p, દ્વિગુણ d)
{
    પાછા p + d;
}

#અથવાજો defined test_duplicate_case

પૂર્ણાંક મુખ્ય()
{
    unsigned પૂર્ણાંક x;
    પસંદગી (x) {
        સ્થિતિ -1 ... 0: /* empty case range with unsigned */
        સ્થિતિ 3:
        સ્થિતિ 1:
        સ્થિતિ 2:
        સ્થિતિ 3: /* show this line number in error */
        સ્થિતિ 4:
        સ્થિતિ 5:
    }
}
#અથવાજો defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

પૂર્ણાંક મુખ્ય()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#અથવાજો defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

સંરચના xxx {પૂર્ણાંક x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
પૂર્ણાંક bar(ગણના ee { a = 12, b = 34 } i, પૂર્ણાંક(*f)(પૂર્ણાંક i))
{
    printf("bar %d %d %d\n", i, a, b);
    પાછા 0;
}
/* 'xxx' not defined outside of function */
પૂર્ણાંક foo(સંરચના xxx {પૂર્ણાંક x[3];}*p)
{
    printf("foo %d", કદ *p);
    પાછા p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
પૂર્ણાંક foo(સંરચના xxx {પૂર્ણાંક x[2];}*p);
#endif
#ifndef test_scope_3
ગણના ee { a = 1, b };
#endif

સંરચના xxx x = { 11,22,33,44 };
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    printf(" %d %d\n", foo(&x), કદ (સંરચના xxx));
    ગણના ee e = b;
    bar(13 + e, 0);

}

#અથવાજો defined test_const_array_member_addr_ok

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

int_array અચલ *get_array(અચલ my_struct *s)
{
    પાછા &(s->arr);
}

#અથવાજો defined test_const_array_member_decay_ok

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

અચલ પૂર્ણાંક *good_decay(અચલ my_struct *s)
{
    પાછા s->arr;
}

#અથવાજો defined test_const_array_member_addr_bad

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

int_array *bad_array_addr(અચલ my_struct *s)
{
    પાછા &(s->arr);
}

#અથવાજો defined test_const_array_member_decay_bad

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

પૂર્ણાંક *bad_decay(અચલ my_struct *s)
{
    પાછા s->arr;
}

#અથવાજો defined test_const_array_member_write_bad

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

શૂન્ય bad_write(અચલ my_struct *s)
{
    s->arr[0] = 1;
}

#અથવાજો defined test_const_struct_array_member_write_bad

પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક x; } inner;
પ્રકારવ્યાખ્યા સંરચના { inner arr[1]; } outer;

શૂન્ય bad_inner_write(અચલ outer *s)
{
    s->arr[0].x = 1;
}

#અથવાજો defined test_volatile_array_member_addr_ok

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

int_array અસ્થિર *get_volatile_array(અસ્થિર my_struct *s)
{
    પાછા &(s->arr);
}

#અથવાજો defined test_volatile_array_member_decay_ok

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

અસ્થિર પૂર્ણાંક *good_volatile_decay(અસ્થિર my_struct *s)
{
    પાછા s->arr;
}

#અથવાજો defined test_volatile_array_member_addr_bad

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(અસ્થિર my_struct *s)
{
    પાછા &(s->arr);
}

#અથવાજો defined test_volatile_array_member_decay_bad

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

પૂર્ણાંક *bad_volatile_decay(અસ્થિર my_struct *s)
{
    પાછા s->arr;
}

#અથવાજો defined test_volatile_array_member_write_ok

પ્રકારવ્યાખ્યા પૂર્ણાંક int_array[1];
પ્રકારવ્યાખ્યા સંરચના { int_array arr; } my_struct;

શૂન્ય good_volatile_write(અસ્થિર my_struct *s)
{
    s->arr[0] = 1;
}

#અથવાજો defined test_conditional_array_qualifiers

પ્રકારવ્યાખ્યા પૂર્ણાંક Array2[2];
પ્રકારવ્યાખ્યા પૂર્ણાંક Array2x3[2][3];

Array2 *p;
અચલ Array2 *cp;
અચલ Array2x3 *cap;
અસ્થિર Array2x3 *vap;

શૂન્ય test(શૂન્ય)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#અથવાજો defined test_restrict_scalar

restrict પૂર્ણાંક object;

#અથવાજો defined test_restrict_function_pointer

પૂર્ણાંક (*restrict function_pointer)(શૂન્ય);

#અથવાજો defined test_discarded_restrict

પ્રકારવ્યાખ્યા પૂર્ણાંક *restrict restricted_pointer;

restricted_pointer *source;
પૂર્ણાંક **destination;

શૂન્ય test(શૂન્ય)
{
    destination = source;
}

#endif

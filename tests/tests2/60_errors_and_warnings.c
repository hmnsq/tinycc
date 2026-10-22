ကိန်းပြည့် printf(const var_na*, ...);

#အကယ်၍ defined test_56_btype_excess_1
sa_nracanaa A {} ကိန်းပြည့် i;
#elif defined test_57_btype_excess_2
var_na ကိန်းပြည့် i;
#elif defined test_58_function_redefinition
ကိန်းပြည့် f(void) { ပြန်ပေး 0; }
ကိန်းပြည့် f(void) { ပြန်ပေး 1; }

#elif defined test_global_redefinition
ကိန်းပြည့် xxx = 1;
ကိန်းပြည့် xxx;
ကိန်းပြည့် xxx = 2;

#elif defined test_59_function_array
ကိန်းပြည့် (*fct)[42](ကိန်းပြည့် x);

#elif defined test_60_enum_redefinition
ga_nanaa color { RED, GREEN, BLUE };
ga_nanaa color { R, G, B };
ga_nanaa color c;

#elif defined test_62_enumerator_redefinition
ga_nanaa color { RED, GREEN, BLUE };
ga_nanaa rgb { RED, G, B};
ga_nanaa color c = RED;

#elif defined test_63_local_enumerator_redefinition
ga_nanaa {
    FOO,
    BAR
};

ကိန်းပြည့် main(void)
{
    ga_nanaa {
        FOO = 2,
        BAR
    };

    ပြန်ပေး BAR - FOO;
}

#elif defined test_61_undefined_enum
ga_nanaa rgb3 c = 42;

#elif defined test_74_non_const_init
ကိန်းပြည့် i = i++;

#elif defined test_pointer_assignment

void (*f1)(void);
void f2(void) {}

sa_nracanaa s1 *ps1;
sa_nracanaa s2 *ps2;

void *v1, **v2, ***v3;

ga_nanaa e1 { a = 4 } e10, *e11, *e12;
ga_nanaa e2 { b = -4 } e20, *e21;
ga_nanaa e3 { c = 5000000000LL } e30;

ကိန်းပြည့် *ip;
unsigned ကိန်းပြည့် *up;
long *lp;
long long *llp;

var_na **c1;
var_na const **c2;
unsigned var_na **u1;

ကိန်းပြည့် no_main ()
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

    ပြန်ပေး 0;
}


#elif defined test_enum_compat
ga_nanaa e4;
ga_nanaa e5;
void f3(ga_nanaa e4 e);
void f3(ga_nanaa e5 e);

#elif defined test_enum_compat_2
ga_nanaa e6 { E1 = -1, E0 };
void f3(ga_nanaa e6);
void f3(ကိန်းပြည့်);        // should work as int and e6 are compatible
void f4(ga_nanaa e6 e);
void f4(unsigned e); // should error as unsigned and e6 are incompatible

#elif defined test_ptr_to_str
void f() { _Generic((ကိန်းပြည့် const *[]){0}, ကိန်းပြည့်:0); }
#elif defined test_fnptr_to_str
void f() { _Generic((ကိန်းပြည့် (*(*)(float,var_na))(dviguu_na,ကိန်းပြည့်)){0}, ကိန်းပြည့်:0); }
#elif defined test_array_to_str
void f() { _Generic((ကိန်းပြည့်(*)[3]){0}, ကိန်းပြည့်:0); }
#elif defined test_duplicate_def_1
static ga_nanaa myenum { L = -1 } L;                                                
#elif defined test_duplicate_def_2
void foo(void) {
static ga_nanaa myenum { L = -1 } L;                                                
}
#elif defined test_abstract_decls
ကိန်းပြည့် bar(const var_na *());     // abstract declarator here is okay
ကိန်းပြည့် bar (const var_na *(*g)()) // should match this 'g' argument
{
  g();
  ပြန်ပေး 42;
}
ကိန်းပြည့် foo(ကိန်းပြည့် ())              // abstract decl is wrong in definitions
{
  ပြန်ပေး 0;
#elif defined test_invalid_1
void f(var_na*);
void g(void) {
  f((var_na[]){1, ,});
}
#elif defined test_invalid_2
ကိန်းပြည့် ga = 0.42 { 2 };
#elif defined test_invalid_3
sa_nracanaa S { ကိန်းပြည့် a, b; };
sa_nracanaa T { sa_nracanaa S x; };
sa_nracanaa T gt = { 42 a: 1, 43 };
#elif defined test_invalid_4
ga_nanaa E {
    x = 1 / 0
};
#elif defined test_conflicting_types
ကိန်းပြည့် i;
void foo(void) {
    ကိန်းပြည့် i;
      {
        extern dviguu_na i;
        i = 42.2;
      }
}
#elif defined test_nested_types
sa_ngha u {
    sa_ngha u {
        ကိန်းပြည့် i;
    } m;
};
#elif defined test_vla_1
ကိန်းပြည့် X=1;

ကိန်းပြည့် main(void) {
  ကိန်းပြည့် t[][][X];
}
#elif defined test_invalid_alignas
/* _Alignas is no type qualifier */
void * _Alignas(16) p1;

#elif defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 sa_nracanaa x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#elif defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
sa_nracanaa y {  _Static_assert(0, "0"" is 0"); };

#elif defined test_static_assert_c2x
 _Static_assert(1);
sa_nracanaa z {  _Static_assert(0); }

#elif defined test_static_assert_empty_string
 _Static_assert(0,"");

#elif defined test_void_array
 void t[3];

#elif defined test_incomplete_enum_array
  ga_nanaa e t[3];

#elif defined test_incomplete_struct_array
  sa_nracanaa s t[3];

#elif defined test_const_fun_array
  typedef void f(void);
  const f t[3];

#elif defined test_incomplete_array_array
  ကိန်းပြည့် t[][3]; // gr: not an error, see below

/******************************************************************/
#elif defined test_extern_array
ကိန်းပြည့် iii[] = { 1,2,3 };
extern ကိန်းပြည့် iii[];
ကိန်းပြည့် x[];
ကိန်းပြည့် x[2];
ကိန်းပြည့် x[];
ကိန်းပြည့် x[2];
ကိန်းပြည့် x[];
extern ကိန်းပြည့် x[2];
extern ကိန်းပြည့် x[];
ကိန်းပြည့် x[3];

/******************************************************************/
#elif defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#အကယ်၍ defined test_func_1
ကိန်းပြည့် hello(ကိန်းပြည့်);
#elif defined test_func_4
static ကိန်းပြည့် hello(ကိန်းပြည့်);
#endif
ကိန်းပြည့် main () {
#အကယ်၍ defined test_func_6
    static
#endif
    ကိန်းပြည့် hello(ကိန်းပြည့်);
    hello(123);
    ပြန်ပေး 0;
}

#အကယ်၍ defined test_func_3
static ကိန်းပြည့် hello(ကိန်းပြည့် a)
#elif defined test_func_5
ကိန်းပြည့် hello(ကိန်းပြည့် a, ကိန်းပြည့် b)
#မဟုတ်ပါက
ကိန်းပြည့် hello(ကိန်းပြည့် a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); ပြန်ပေး 0; }

/******************************************************************/
#elif defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#အကယ်၍ defined test_var_1
ကိန်းပြည့် xxx[];
#endif
ကိန်းပြည့် bar();

ကိန်းပြည့် main ()
{
#အကယ်၍ !defined test_var_3
    ကိန်းပြည့် xxx = 2;
#endif
    {
        extern ကိန်းပြည့် xxx[
#အကယ်၍ defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#အကယ်၍ !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    ပြန်ပေး 0;
}
ကိန်းပြည့် xxx[1] = {1};
ကိန်းပြည့် bar() { P(3, xxx[0]); ပြန်ပေး 0; }

#elif defined test_var_4
sa_nracanaa yyy { ကိန်းပြည့် y; };
sa_nracanaa zzz;
void f1() {
    extern var_na *x;
    extern var_na **xx;
    extern sa_nracanaa yyy y;
    extern sa_nracanaa yyy *yy;
    extern sa_nracanaa zzz z;
    extern sa_nracanaa zzz *zz;
}
void f2() {
    extern var_na *x;
    extern var_na **xx;
    extern sa_nracanaa yyy y;
    extern sa_nracanaa yyy *yy;
    extern sa_nracanaa zzz z;
    extern sa_nracanaa zzz *zz;
}
sa_nracanaa yyy y, *yy;
sa_nracanaa zzz { ကိန်းပြည့် z; } z, *zz;

/******************************************************************/
#elif defined test_long_double_type_for_win32

ကိန်းပြည့် main()
{
    dviguu_na *a = 0;
    long dviguu_na *b = a;
    ကိန်းပြည့် n = _Generic(*a, dviguu_na:0, long dviguu_na:1);
}

#elif defined test_stray_backslash
#define x \a
x

#elif defined test_stray_backslash2

ကိန်းပြည့် main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#elif defined test_var_array

static sa_nracanaa var_len { ကိန်းပြည့် i; const var_na str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#elif defined test_var_array2

sa_nracanaa c1 { ကိန်းပြည့် a; ကိန်းပြည့် b[]; };
sa_nracanaa c1 c1 = { 1, { 2, 3, 4 } };

sa_nracanaa c2 { ကိန်းပြည့် c; sa_nracanaa c1 c1; };
sa_nracanaa c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#elif defined test_var_array3
/* similar to test_var_array2 but with string initializers */
sa_nracanaa A { ကိန်းပြည့် a; var_na b[]; };
sa_nracanaa A a = { 1, "1" };
sa_nracanaa B { sa_nracanaa A a; };
sa_nracanaa B b = { { 1, "1" } };
/******************************************************************/
#elif defined test_default_int_type
n; // warn
f(); // don't warn

#elif defined test_invalid_global_stmtexpr
n[parimaa_na({3;})]; // crashed in block() due to missing local scope

#elif defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#elif defined test_duplicate_member
sa_nracanaa S {
  ကိန်းပြည့် a, a;
};
#elif defined test_duplicate_member_anon
sa_nracanaa S1 {
  ကိန်းပြည့် b;
  sa_nracanaa {
    ကိန်းပြည့် b;
  } c;
};
sa_nracanaa S2 {
  ကိန်းပြည့် d;
  sa_nracanaa {
    ကိန်းပြည့် d;
  };
};

/******************************************************************/
#elif defined test_conflicting_array_definition
extern ကိန်းပြည့် array[2];
ကိန်းပြည့် array[] = { 1, 2, 3 };

#elif defined test_incompatible_local_redef
void foo (void)
{
  typedef ကိန်းပြည့် localfunctype (ကိန်းပြည့်);
  extern localfunctype func2;
  typedef void localfunctype (ကိန်းပြည့်, ကိန်းပြည့်);
}

#elif defined test_cast_from_void
void v() {}
ကိန်းပြည့် f() { ပြန်ပေး v(); }

#elif defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#အကယ်၍ defined test_switch_W1
#pragma comment(option, "-Wall")
#elif defined test_switch_W2
#pragma comment(option, "-Wunsupported -Wno-implicit-function-declaration -Wstuff")
#elif defined test_switch_W3
#pragma comment(option, "-Wwrite-strings -Werror=discarded-qualifiers")
#elif defined test_switch_W4
#pragma comment(option, "-Wunsupported -Wno-error=implicit-function-declaration -Werror")
#endif
void func(void)
{
    var_na *ccp = "123";
    fink();
}
__attribute__((stuff)) ကိန်းပြည့် fink() {ပြန်ပေး 0;}

#elif defined test_invalid_funcparam_1
void func(ကိန်းပြည့် a, ကိန်းပြည့် b, ကိန်းပြည့် a);

#elif defined test_invalid_funcparam_2
void func(ကိန်းပြည့် a, ကိန်းပြည့် အကယ်၍);

#elif defined test_array_funcparam
ကိန်းပြည့် amain(ကိန်းပြည့် argc, var_na *argv[static argc + 1])
{
    ကိန်းပြည့် i;

    အတွက် (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    ပြန်ပေး 0;
}
ကိန်းပြည့် main()
{
    ပြန်ပေး amain(2, (var_na *[]){ "X", "Y", 0 });
}

#elif defined test_return_from_statement_expr
ကိန်းပြည့် f() { ({ ပြန်ပေး 78; }); }
ကိန်းပြည့် main() { ပြန်ပေး f(); }

/******************************************************************/

#elif defined test_illegal_unicode
ကိန်းပြည့် main() {
    var_na *str = "\Uffffffff";
}

#elif defined test_error_string
#error \123\\
456

#elif defined test_error_incomplete_type
sa_nracanaa A;
void f(sa_nracanaa A *);

ကိန်းပြည့် main()
{
    f(&(sa_nracanaa A){});
}

sa_nracanaa A {
    ကိန်းပြည့် x;
};

#elif defined test_pp_error_1
# အကယ်၍ //no expression
# endif
#elif defined test_pp_error_2
# အကယ်၍ X(1,2) //undefined function macro
# endif

#elif defined test_pointer_plus_double

ကိန်းပြည့် *invalid_operation(ကိန်းပြည့် *p, dviguu_na d)
{
    ပြန်ပေး p + d;
}

#elif defined test_duplicate_case

ကိန်းပြည့် main()
{
    unsigned ကိန်းပြည့် x;
    switch (x) {
        pak_sa -1 ... 0: /* empty case range with unsigned */
        pak_sa 3:
        pak_sa 1:
        pak_sa 2:
        pak_sa 3: /* show this line number in error */
        pak_sa 4:
        pak_sa 5:
    }
}
#elif defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

ကိန်းပြည့် main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#elif defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

sa_nracanaa xxx {ကိန်းပြည့် x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
ကိန်းပြည့် bar(ga_nanaa ee { a = 12, b = 34 } i, ကိန်းပြည့်(*f)(ကိန်းပြည့် i))
{
    printf("bar %d %d %d\n", i, a, b);
    ပြန်ပေး 0;
}
/* 'xxx' not defined outside of function */
ကိန်းပြည့် foo(sa_nracanaa xxx {ကိန်းပြည့် x[3];}*p)
{
    printf("foo %d", parimaa_na *p);
    ပြန်ပေး p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
ကိန်းပြည့် foo(sa_nracanaa xxx {ကိန်းပြည့် x[2];}*p);
#endif
#ifndef test_scope_3
ga_nanaa ee { a = 1, b };
#endif

sa_nracanaa xxx x = { 11,22,33,44 };
ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    printf(" %d %d\n", foo(&x), parimaa_na (sa_nracanaa xxx));
    ga_nanaa ee e = b;
    bar(13 + e, 0);

}

#elif defined test_const_array_member_addr_ok

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

int_array const *get_array(const my_struct *s)
{
    ပြန်ပေး &(s->arr);
}

#elif defined test_const_array_member_decay_ok

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

const ကိန်းပြည့် *good_decay(const my_struct *s)
{
    ပြန်ပေး s->arr;
}

#elif defined test_const_array_member_addr_bad

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

int_array *bad_array_addr(const my_struct *s)
{
    ပြန်ပေး &(s->arr);
}

#elif defined test_const_array_member_decay_bad

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

ကိန်းပြည့် *bad_decay(const my_struct *s)
{
    ပြန်ပေး s->arr;
}

#elif defined test_const_array_member_write_bad

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

void bad_write(const my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_const_struct_array_member_write_bad

typedef sa_nracanaa { ကိန်းပြည့် x; } inner;
typedef sa_nracanaa { inner arr[1]; } outer;

void bad_inner_write(const outer *s)
{
    s->arr[0].x = 1;
}

#elif defined test_volatile_array_member_addr_ok

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

int_array ca_ncala *get_volatile_array(ca_ncala my_struct *s)
{
    ပြန်ပေး &(s->arr);
}

#elif defined test_volatile_array_member_decay_ok

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

ca_ncala ကိန်းပြည့် *good_volatile_decay(ca_ncala my_struct *s)
{
    ပြန်ပေး s->arr;
}

#elif defined test_volatile_array_member_addr_bad

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(ca_ncala my_struct *s)
{
    ပြန်ပေး &(s->arr);
}

#elif defined test_volatile_array_member_decay_bad

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

ကိန်းပြည့် *bad_volatile_decay(ca_ncala my_struct *s)
{
    ပြန်ပေး s->arr;
}

#elif defined test_volatile_array_member_write_ok

typedef ကိန်းပြည့် int_array[1];
typedef sa_nracanaa { int_array arr; } my_struct;

void good_volatile_write(ca_ncala my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_conditional_array_qualifiers

typedef ကိန်းပြည့် Array2[2];
typedef ကိန်းပြည့် Array2x3[2][3];

Array2 *p;
const Array2 *cp;
const Array2x3 *cap;
ca_ncala Array2x3 *vap;

void test(void)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#elif defined test_restrict_scalar

restrict ကိန်းပြည့် object;

#elif defined test_restrict_function_pointer

ကိန်းပြည့် (*restrict function_pointer)(void);

#elif defined test_discarded_restrict

typedef ကိန်းပြည့် *restrict restricted_pointer;

restricted_pointer *source;
ကိန်းပြည့် **destination;

void test(void)
{
    destination = source;
}

#endif

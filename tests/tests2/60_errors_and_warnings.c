цяло printf(const char*, ...);

#ако defined test_56_btype_excess_1
struct A {} цяло i;
#elif defined test_57_btype_excess_2
char цяло i;
#elif defined test_58_function_redefinition
цяло f(void) { върни 0; }
цяло f(void) { върни 1; }

#elif defined test_global_redefinition
цяло xxx = 1;
цяло xxx;
цяло xxx = 2;

#elif defined test_59_function_array
цяло (*fct)[42](цяло x);

#elif defined test_60_enum_redefinition
enum color { RED, GREEN, BLUE };
enum color { R, G, B };
enum color c;

#elif defined test_62_enumerator_redefinition
enum color { RED, GREEN, BLUE };
enum rgb { RED, G, B};
enum color c = RED;

#elif defined test_63_local_enumerator_redefinition
enum {
    FOO,
    BAR
};

цяло main(void)
{
    enum {
        FOO = 2,
        BAR
    };

    върни BAR - FOO;
}

#elif defined test_61_undefined_enum
enum rgb3 c = 42;

#elif defined test_74_non_const_init
цяло i = i++;

#elif defined test_pointer_assignment

void (*f1)(void);
void f2(void) {}

struct s1 *ps1;
struct s2 *ps2;

void *v1, **v2, ***v3;

enum e1 { a = 4 } e10, *e11, *e12;
enum e2 { b = -4 } e20, *e21;
enum e3 { c = 5000000000LL } e30;

цяло *ip;
unsigned цяло *up;
long *lp;
long long *llp;

char **c1;
char const **c2;
unsigned char **u1;

цяло no_main ()
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

    върни 0;
}


#elif defined test_enum_compat
enum e4;
enum e5;
void f3(enum e4 e);
void f3(enum e5 e);

#elif defined test_enum_compat_2
enum e6 { E1 = -1, E0 };
void f3(enum e6);
void f3(цяло);        // should work as int and e6 are compatible
void f4(enum e6 e);
void f4(unsigned e); // should error as unsigned and e6 are incompatible

#elif defined test_ptr_to_str
void f() { _Generic((цяло const *[]){0}, цяло:0); }
#elif defined test_fnptr_to_str
void f() { _Generic((цяло (*(*)(float,char))(double,цяло)){0}, цяло:0); }
#elif defined test_array_to_str
void f() { _Generic((цяло(*)[3]){0}, цяло:0); }
#elif defined test_duplicate_def_1
static enum myenum { L = -1 } L;                                                
#elif defined test_duplicate_def_2
void foo(void) {
static enum myenum { L = -1 } L;                                                
}
#elif defined test_abstract_decls
цяло bar(const char *());     // abstract declarator here is okay
цяло bar (const char *(*g)()) // should match this 'g' argument
{
  g();
  върни 42;
}
цяло foo(цяло ())              // abstract decl is wrong in definitions
{
  върни 0;
#elif defined test_invalid_1
void f(char*);
void g(void) {
  f((char[]){1, ,});
}
#elif defined test_invalid_2
цяло ga = 0.42 { 2 };
#elif defined test_invalid_3
struct S { цяло a, b; };
struct T { struct S x; };
struct T gt = { 42 a: 1, 43 };
#elif defined test_invalid_4
enum E {
    x = 1 / 0
};
#elif defined test_conflicting_types
цяло i;
void foo(void) {
    цяло i;
      {
        extern double i;
        i = 42.2;
      }
}
#elif defined test_nested_types
union u {
    union u {
        цяло i;
    } m;
};
#elif defined test_vla_1
цяло X=1;

цяло main(void) {
  цяло t[][][X];
}
#elif defined test_invalid_alignas
/* _Alignas is no type qualifier */
void * _Alignas(16) p1;

#elif defined test_static_assert

#define ONE 0
 _Static_assert(ONE == 0, "don't show me this");
 struct x{ _Static_assert(ONE == 1, "ONE is not 1"); };

#elif defined test_static_assert_2
 _Static_assert(1, "1"" is 1");
struct y {  _Static_assert(0, "0"" is 0"); };

#elif defined test_static_assert_c2x
 _Static_assert(1);
struct z {  _Static_assert(0); }

#elif defined test_static_assert_empty_string
 _Static_assert(0,"");

#elif defined test_void_array
 void t[3];

#elif defined test_incomplete_enum_array
  enum e t[3];

#elif defined test_incomplete_struct_array
  struct s t[3];

#elif defined test_const_fun_array
  typedef void f(void);
  const f t[3];

#elif defined test_incomplete_array_array
  цяло t[][3]; // gr: not an error, see below

/******************************************************************/
#elif defined test_extern_array
цяло iii[] = { 1,2,3 };
extern цяло iii[];
цяло x[];
цяло x[2];
цяло x[];
цяло x[2];
цяло x[];
extern цяло x[2];
extern цяло x[];
цяло x[3];

/******************************************************************/
#elif defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#ако defined test_func_1
цяло hello(цяло);
#elif defined test_func_4
static цяло hello(цяло);
#endif
цяло main () {
#ако defined test_func_6
    static
#endif
    цяло hello(цяло);
    hello(123);
    върни 0;
}

#ако defined test_func_3
static цяло hello(цяло a)
#elif defined test_func_5
цяло hello(цяло a, цяло b)
#иначе
цяло hello(цяло a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); върни 0; }

/******************************************************************/
#elif defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#ако defined test_var_1
цяло xxx[];
#endif
цяло bar();

цяло main ()
{
#ако !defined test_var_3
    цяло xxx = 2;
#endif
    {
        extern цяло xxx[
#ако defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#ако !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    върни 0;
}
цяло xxx[1] = {1};
цяло bar() { P(3, xxx[0]); върни 0; }

#elif defined test_var_4
struct yyy { цяло y; };
struct zzz;
void f1() {
    extern char *x;
    extern char **xx;
    extern struct yyy y;
    extern struct yyy *yy;
    extern struct zzz z;
    extern struct zzz *zz;
}
void f2() {
    extern char *x;
    extern char **xx;
    extern struct yyy y;
    extern struct yyy *yy;
    extern struct zzz z;
    extern struct zzz *zz;
}
struct yyy y, *yy;
struct zzz { цяло z; } z, *zz;

/******************************************************************/
#elif defined test_long_double_type_for_win32

цяло main()
{
    double *a = 0;
    long double *b = a;
    цяло n = _Generic(*a, double:0, long double:1);
}

#elif defined test_stray_backslash
#define x \a
x

#elif defined test_stray_backslash2

цяло main()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#elif defined test_var_array

static struct var_len { цяло i; const char str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#elif defined test_var_array2

struct c1 { цяло a; цяло b[]; };
struct c1 c1 = { 1, { 2, 3, 4 } };

struct c2 { цяло c; struct c1 c1; };
struct c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#elif defined test_var_array3
/* similar to test_var_array2 but with string initializers */
struct A { цяло a; char b[]; };
struct A a = { 1, "1" };
struct B { struct A a; };
struct B b = { { 1, "1" } };
/******************************************************************/
#elif defined test_default_int_type
n; // warn
f(); // don't warn

#elif defined test_invalid_global_stmtexpr
n[sizeof({3;})]; // crashed in block() due to missing local scope

#elif defined test_invalid_tokckill
f(){"12"3;} // second const token killed the value of the first

/******************************************************************/
#elif defined test_duplicate_member
struct S {
  цяло a, a;
};
#elif defined test_duplicate_member_anon
struct S1 {
  цяло b;
  struct {
    цяло b;
  } c;
};
struct S2 {
  цяло d;
  struct {
    цяло d;
  };
};

/******************************************************************/
#elif defined test_conflicting_array_definition
extern цяло array[2];
цяло array[] = { 1, 2, 3 };

#elif defined test_incompatible_local_redef
void foo (void)
{
  typedef цяло localfunctype (цяло);
  extern localfunctype func2;
  typedef void localfunctype (цяло, цяло);
}

#elif defined test_cast_from_void
void v() {}
цяло f() { върни v(); }

#elif defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#ако defined test_switch_W1
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
    char *ccp = "123";
    fink();
}
__attribute__((stuff)) цяло fink() {върни 0;}

#elif defined test_invalid_funcparam_1
void func(цяло a, цяло b, цяло a);

#elif defined test_invalid_funcparam_2
void func(цяло a, цяло ако);

#elif defined test_array_funcparam
цяло amain(цяло argc, char *argv[static argc + 1])
{
    цяло i;

    за (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    върни 0;
}
цяло main()
{
    върни amain(2, (char *[]){ "X", "Y", 0 });
}

#elif defined test_return_from_statement_expr
цяло f() { ({ върни 78; }); }
цяло main() { върни f(); }

/******************************************************************/

#elif defined test_illegal_unicode
цяло main() {
    char *str = "\Uffffffff";
}

#elif defined test_error_string
#error \123\\
456

#elif defined test_error_incomplete_type
struct A;
void f(struct A *);

цяло main()
{
    f(&(struct A){});
}

struct A {
    цяло x;
};

#elif defined test_pp_error_1
# ако //no expression
# endif
#elif defined test_pp_error_2
# ако X(1,2) //undefined function macro
# endif

#elif defined test_pointer_plus_double

цяло *invalid_operation(цяло *p, double d)
{
    върни p + d;
}

#elif defined test_duplicate_case

цяло main()
{
    unsigned цяло x;
    switch (x) {
        case -1 ... 0: /* empty case range with unsigned */
        case 3:
        case 1:
        case 2:
        case 3: /* show this line number in error */
        case 4:
        case 5:
    }
}
#elif defined test_normal_funcargs || defined test_reverse_funcargs

#ifdef test_reverse_funcargs
# pragma comment(option, "-freverse-funcargs")
#endif

цяло main()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#elif defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

struct xxx {цяло x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
цяло bar(enum ee { a = 12, b = 34 } i, цяло(*f)(цяло i))
{
    printf("bar %d %d %d\n", i, a, b);
    върни 0;
}
/* 'xxx' not defined outside of function */
цяло foo(struct xxx {цяло x[3];}*p)
{
    printf("foo %d", sizeof *p);
    върни p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
цяло foo(struct xxx {цяло x[2];}*p);
#endif
#ifndef test_scope_3
enum ee { a = 1, b };
#endif

struct xxx x = { 11,22,33,44 };
цяло main(цяло argc, char **argv)
{
    printf(" %d %d\n", foo(&x), sizeof (struct xxx));
    enum ee e = b;
    bar(13 + e, 0);

}

#elif defined test_const_array_member_addr_ok

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

int_array const *get_array(const my_struct *s)
{
    върни &(s->arr);
}

#elif defined test_const_array_member_decay_ok

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

const цяло *good_decay(const my_struct *s)
{
    върни s->arr;
}

#elif defined test_const_array_member_addr_bad

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_array_addr(const my_struct *s)
{
    върни &(s->arr);
}

#elif defined test_const_array_member_decay_bad

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

цяло *bad_decay(const my_struct *s)
{
    върни s->arr;
}

#elif defined test_const_array_member_write_bad

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

void bad_write(const my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_const_struct_array_member_write_bad

typedef struct { цяло x; } inner;
typedef struct { inner arr[1]; } outer;

void bad_inner_write(const outer *s)
{
    s->arr[0].x = 1;
}

#elif defined test_volatile_array_member_addr_ok

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

int_array volatile *get_volatile_array(volatile my_struct *s)
{
    върни &(s->arr);
}

#elif defined test_volatile_array_member_decay_ok

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

volatile цяло *good_volatile_decay(volatile my_struct *s)
{
    върни s->arr;
}

#elif defined test_volatile_array_member_addr_bad

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(volatile my_struct *s)
{
    върни &(s->arr);
}

#elif defined test_volatile_array_member_decay_bad

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

цяло *bad_volatile_decay(volatile my_struct *s)
{
    върни s->arr;
}

#elif defined test_volatile_array_member_write_ok

typedef цяло int_array[1];
typedef struct { int_array arr; } my_struct;

void good_volatile_write(volatile my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_conditional_array_qualifiers

typedef цяло Array2[2];
typedef цяло Array2x3[2][3];

Array2 *p;
const Array2 *cp;
const Array2x3 *cap;
volatile Array2x3 *vap;

void test(void)
{
    (1 ? p : cp)[0][0] = 1;
    (1 ? cp : p)[0][0] = 2;
    (1 ? cap : vap)[0][0][0] = 3;
    (1 ? vap : cap)[0][0][0] = 4;
}

#elif defined test_restrict_scalar

restrict цяло object;

#elif defined test_restrict_function_pointer

цяло (*restrict function_pointer)(void);

#elif defined test_discarded_restrict

typedef цяло *restrict restricted_pointer;

restricted_pointer *source;
цяло **destination;

void test(void)
{
    destination = source;
}

#endif

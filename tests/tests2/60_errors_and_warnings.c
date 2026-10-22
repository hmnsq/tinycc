整数 printf(const char*, ...);

#如果 defined test_56_btype_excess_1
struct A {} 整数 i;
#elif defined test_57_btype_excess_2
char 整数 i;
#elif defined test_58_function_redefinition
整数 f(void) { 返回 0; }
整数 f(void) { 返回 1; }

#elif defined test_global_redefinition
整数 xxx = 1;
整数 xxx;
整数 xxx = 2;

#elif defined test_59_function_array
整数 (*fct)[42](整数 x);

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

整数 主要(void)
{
    enum {
        FOO = 2,
        BAR
    };

    返回 BAR - FOO;
}

#elif defined test_61_undefined_enum
enum rgb3 c = 42;

#elif defined test_74_non_const_init
整数 i = i++;

#elif defined test_pointer_assignment

void (*f1)(void);
void f2(void) {}

struct s1 *ps1;
struct s2 *ps2;

void *v1, **v2, ***v3;

enum e1 { a = 4 } e10, *e11, *e12;
enum e2 { b = -4 } e20, *e21;
enum e3 { c = 5000000000LL } e30;

整数 *ip;
unsigned 整数 *up;
long *lp;
long long *llp;

char **c1;
char const **c2;
unsigned char **u1;

整数 no_main ()
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

    返回 0;
}


#elif defined test_enum_compat
enum e4;
enum e5;
void f3(enum e4 e);
void f3(enum e5 e);

#elif defined test_enum_compat_2
enum e6 { E1 = -1, E0 };
void f3(enum e6);
void f3(整数);        // should work as int and e6 are compatible
void f4(enum e6 e);
void f4(unsigned e); // should error as unsigned and e6 are incompatible

#elif defined test_ptr_to_str
void f() { _Generic((整数 const *[]){0}, 整数:0); }
#elif defined test_fnptr_to_str
void f() { _Generic((整数 (*(*)(float,char))(double,整数)){0}, 整数:0); }
#elif defined test_array_to_str
void f() { _Generic((整数(*)[3]){0}, 整数:0); }
#elif defined test_duplicate_def_1
static enum myenum { L = -1 } L;                                                
#elif defined test_duplicate_def_2
void foo(void) {
static enum myenum { L = -1 } L;                                                
}
#elif defined test_abstract_decls
整数 bar(const char *());     // abstract declarator here is okay
整数 bar (const char *(*g)()) // should match this 'g' argument
{
  g();
  返回 42;
}
整数 foo(整数 ())              // abstract decl is wrong in definitions
{
  返回 0;
#elif defined test_invalid_1
void f(char*);
void g(void) {
  f((char[]){1, ,});
}
#elif defined test_invalid_2
整数 ga = 0.42 { 2 };
#elif defined test_invalid_3
struct S { 整数 a, b; };
struct T { struct S x; };
struct T gt = { 42 a: 1, 43 };
#elif defined test_invalid_4
enum E {
    x = 1 / 0
};
#elif defined test_conflicting_types
整数 i;
void foo(void) {
    整数 i;
      {
        extern double i;
        i = 42.2;
      }
}
#elif defined test_nested_types
union u {
    union u {
        整数 i;
    } m;
};
#elif defined test_vla_1
整数 X=1;

整数 主要(void) {
  整数 t[][][X];
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
  整数 t[][3]; // gr: not an error, see below

/******************************************************************/
#elif defined test_extern_array
整数 iii[] = { 1,2,3 };
extern 整数 iii[];
整数 x[];
整数 x[2];
整数 x[];
整数 x[2];
整数 x[];
extern 整数 x[2];
extern 整数 x[];
整数 x[3];

/******************************************************************/
#elif defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#如果 defined test_func_1
整数 hello(整数);
#elif defined test_func_4
static 整数 hello(整数);
#endif
整数 主要 () {
#如果 defined test_func_6
    static
#endif
    整数 hello(整数);
    hello(123);
    返回 0;
}

#如果 defined test_func_3
static 整数 hello(整数 a)
#elif defined test_func_5
整数 hello(整数 a, 整数 b)
#否则
整数 hello(整数 a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); 返回 0; }

/******************************************************************/
#elif defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#如果 defined test_var_1
整数 xxx[];
#endif
整数 bar();

整数 主要 ()
{
#如果 !defined test_var_3
    整数 xxx = 2;
#endif
    {
        extern 整数 xxx[
#如果 defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#如果 !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    返回 0;
}
整数 xxx[1] = {1};
整数 bar() { P(3, xxx[0]); 返回 0; }

#elif defined test_var_4
struct yyy { 整数 y; };
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
struct zzz { 整数 z; } z, *zz;

/******************************************************************/
#elif defined test_long_double_type_for_win32

整数 主要()
{
    double *a = 0;
    long double *b = a;
    整数 n = _Generic(*a, double:0, long double:1);
}

#elif defined test_stray_backslash
#define x \a
x

#elif defined test_stray_backslash2

整数 主要()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#elif defined test_var_array

static struct var_len { 整数 i; const char str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#elif defined test_var_array2

struct c1 { 整数 a; 整数 b[]; };
struct c1 c1 = { 1, { 2, 3, 4 } };

struct c2 { 整数 c; struct c1 c1; };
struct c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#elif defined test_var_array3
/* similar to test_var_array2 but with string initializers */
struct A { 整数 a; char b[]; };
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
  整数 a, a;
};
#elif defined test_duplicate_member_anon
struct S1 {
  整数 b;
  struct {
    整数 b;
  } c;
};
struct S2 {
  整数 d;
  struct {
    整数 d;
  };
};

/******************************************************************/
#elif defined test_conflicting_array_definition
extern 整数 array[2];
整数 array[] = { 1, 2, 3 };

#elif defined test_incompatible_local_redef
void foo (void)
{
  typedef 整数 localfunctype (整数);
  extern localfunctype func2;
  typedef void localfunctype (整数, 整数);
}

#elif defined test_cast_from_void
void v() {}
整数 f() { 返回 v(); }

#elif defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#如果 defined test_switch_W1
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
__attribute__((stuff)) 整数 fink() {返回 0;}

#elif defined test_invalid_funcparam_1
void func(整数 a, 整数 b, 整数 a);

#elif defined test_invalid_funcparam_2
void func(整数 a, 整数 如果);

#elif defined test_array_funcparam
整数 amain(整数 argc, char *argv[static argc + 1])
{
    整数 i;

    为 (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    返回 0;
}
整数 主要()
{
    返回 amain(2, (char *[]){ "X", "Y", 0 });
}

#elif defined test_return_from_statement_expr
整数 f() { ({ 返回 78; }); }
整数 主要() { 返回 f(); }

/******************************************************************/

#elif defined test_illegal_unicode
整数 主要() {
    char *str = "\Uffffffff";
}

#elif defined test_error_string
#error \123\\
456

#elif defined test_error_incomplete_type
struct A;
void f(struct A *);

整数 主要()
{
    f(&(struct A){});
}

struct A {
    整数 x;
};

#elif defined test_pp_error_1
# 如果 //no expression
# endif
#elif defined test_pp_error_2
# 如果 X(1,2) //undefined function macro
# endif

#elif defined test_pointer_plus_double

整数 *invalid_operation(整数 *p, double d)
{
    返回 p + d;
}

#elif defined test_duplicate_case

整数 主要()
{
    unsigned 整数 x;
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

整数 主要()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#elif defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

struct xxx {整数 x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
整数 bar(enum ee { a = 12, b = 34 } i, 整数(*f)(整数 i))
{
    printf("bar %d %d %d\n", i, a, b);
    返回 0;
}
/* 'xxx' not defined outside of function */
整数 foo(struct xxx {整数 x[3];}*p)
{
    printf("foo %d", sizeof *p);
    返回 p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
整数 foo(struct xxx {整数 x[2];}*p);
#endif
#ifndef test_scope_3
enum ee { a = 1, b };
#endif

struct xxx x = { 11,22,33,44 };
整数 主要(整数 argc, char **argv)
{
    printf(" %d %d\n", foo(&x), sizeof (struct xxx));
    enum ee e = b;
    bar(13 + e, 0);

}

#elif defined test_const_array_member_addr_ok

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

int_array const *get_array(const my_struct *s)
{
    返回 &(s->arr);
}

#elif defined test_const_array_member_decay_ok

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

const 整数 *good_decay(const my_struct *s)
{
    返回 s->arr;
}

#elif defined test_const_array_member_addr_bad

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_array_addr(const my_struct *s)
{
    返回 &(s->arr);
}

#elif defined test_const_array_member_decay_bad

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

整数 *bad_decay(const my_struct *s)
{
    返回 s->arr;
}

#elif defined test_const_array_member_write_bad

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

void bad_write(const my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_const_struct_array_member_write_bad

typedef struct { 整数 x; } inner;
typedef struct { inner arr[1]; } outer;

void bad_inner_write(const outer *s)
{
    s->arr[0].x = 1;
}

#elif defined test_volatile_array_member_addr_ok

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

int_array volatile *get_volatile_array(volatile my_struct *s)
{
    返回 &(s->arr);
}

#elif defined test_volatile_array_member_decay_ok

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

volatile 整数 *good_volatile_decay(volatile my_struct *s)
{
    返回 s->arr;
}

#elif defined test_volatile_array_member_addr_bad

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(volatile my_struct *s)
{
    返回 &(s->arr);
}

#elif defined test_volatile_array_member_decay_bad

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

整数 *bad_volatile_decay(volatile my_struct *s)
{
    返回 s->arr;
}

#elif defined test_volatile_array_member_write_ok

typedef 整数 int_array[1];
typedef struct { int_array arr; } my_struct;

void good_volatile_write(volatile my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_conditional_array_qualifiers

typedef 整数 Array2[2];
typedef 整数 Array2x3[2][3];

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

restrict 整数 object;

#elif defined test_restrict_function_pointer

整数 (*restrict function_pointer)(void);

#elif defined test_discarded_restrict

typedef 整数 *restrict restricted_pointer;

restricted_pointer *source;
整数 **destination;

void test(void)
{
    destination = source;
}

#endif

целое printf(const char*, ...);

#если defined test_56_btype_excess_1
struct A {} целое i;
#elif defined test_57_btype_excess_2
char целое i;
#elif defined test_58_function_redefinition
целое f(void) { вернуть 0; }
целое f(void) { вернуть 1; }

#elif defined test_global_redefinition
целое xxx = 1;
целое xxx;
целое xxx = 2;

#elif defined test_59_function_array
целое (*fct)[42](целое x);

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

целое основной(void)
{
    enum {
        FOO = 2,
        BAR
    };

    вернуть BAR - FOO;
}

#elif defined test_61_undefined_enum
enum rgb3 c = 42;

#elif defined test_74_non_const_init
целое i = i++;

#elif defined test_pointer_assignment

void (*f1)(void);
void f2(void) {}

struct s1 *ps1;
struct s2 *ps2;

void *v1, **v2, ***v3;

enum e1 { a = 4 } e10, *e11, *e12;
enum e2 { b = -4 } e20, *e21;
enum e3 { c = 5000000000LL } e30;

целое *ip;
unsigned целое *up;
long *lp;
long long *llp;

char **c1;
char const **c2;
unsigned char **u1;

целое no_main ()
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

    вернуть 0;
}


#elif defined test_enum_compat
enum e4;
enum e5;
void f3(enum e4 e);
void f3(enum e5 e);

#elif defined test_enum_compat_2
enum e6 { E1 = -1, E0 };
void f3(enum e6);
void f3(целое);        // should work as int and e6 are compatible
void f4(enum e6 e);
void f4(unsigned e); // should error as unsigned and e6 are incompatible

#elif defined test_ptr_to_str
void f() { _Generic((целое const *[]){0}, целое:0); }
#elif defined test_fnptr_to_str
void f() { _Generic((целое (*(*)(float,char))(double,целое)){0}, целое:0); }
#elif defined test_array_to_str
void f() { _Generic((целое(*)[3]){0}, целое:0); }
#elif defined test_duplicate_def_1
static enum myenum { L = -1 } L;                                                
#elif defined test_duplicate_def_2
void foo(void) {
static enum myenum { L = -1 } L;                                                
}
#elif defined test_abstract_decls
целое bar(const char *());     // abstract declarator here is okay
целое bar (const char *(*g)()) // should match this 'g' argument
{
  g();
  вернуть 42;
}
целое foo(целое ())              // abstract decl is wrong in definitions
{
  вернуть 0;
#elif defined test_invalid_1
void f(char*);
void g(void) {
  f((char[]){1, ,});
}
#elif defined test_invalid_2
целое ga = 0.42 { 2 };
#elif defined test_invalid_3
struct S { целое a, b; };
struct T { struct S x; };
struct T gt = { 42 a: 1, 43 };
#elif defined test_invalid_4
enum E {
    x = 1 / 0
};
#elif defined test_conflicting_types
целое i;
void foo(void) {
    целое i;
      {
        extern double i;
        i = 42.2;
      }
}
#elif defined test_nested_types
union u {
    union u {
        целое i;
    } m;
};
#elif defined test_vla_1
целое X=1;

целое основной(void) {
  целое t[][][X];
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
  целое t[][3]; // gr: not an error, see below

/******************************************************************/
#elif defined test_extern_array
целое iii[] = { 1,2,3 };
extern целое iii[];
целое x[];
целое x[2];
целое x[];
целое x[2];
целое x[];
extern целое x[2];
extern целое x[];
целое x[3];

/******************************************************************/
#elif defined test_func_1 \
 || defined test_func_2 \
 || defined test_func_3 \
 || defined test_func_4 \
 || defined test_func_5 \
 || defined test_func_6
#если defined test_func_1
целое hello(целое);
#elif defined test_func_4
static целое hello(целое);
#endif
целое основной () {
#если defined test_func_6
    static
#endif
    целое hello(целое);
    hello(123);
    вернуть 0;
}

#если defined test_func_3
static целое hello(целое a)
#elif defined test_func_5
целое hello(целое a, целое b)
#иначе
целое hello(целое a)
#endif
{ printf("%s: a = %d\n", __FUNCTION__, a); вернуть 0; }

/******************************************************************/
#elif defined test_var_1 \
   || defined test_var_2 \
   || defined test_var_3
#define P(n,v) printf("%-5s: %d ; %d\n", __FUNCTION__, n, v)
#если defined test_var_1
целое xxx[];
#endif
целое bar();

целое основной ()
{
#если !defined test_var_3
    целое xxx = 2;
#endif
    {
        extern целое xxx[
#если defined test_var_3
        2
#endif
        ];
        P(1, xxx[0]);
        xxx[0] += 2;
    }
#если !defined test_var_3
    P(2, xxx);
#endif
    bar(123);
    вернуть 0;
}
целое xxx[1] = {1};
целое bar() { P(3, xxx[0]); вернуть 0; }

#elif defined test_var_4
struct yyy { целое y; };
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
struct zzz { целое z; } z, *zz;

/******************************************************************/
#elif defined test_long_double_type_for_win32

целое основной()
{
    double *a = 0;
    long double *b = a;
    целое n = _Generic(*a, double:0, long double:1);
}

#elif defined test_stray_backslash
#define x \a
x

#elif defined test_stray_backslash2

целое основной()
{
#define _S(x) #x
#define S(x) _S(x)
    printf("%sn\n", S(\\));
}

/******************************************************************/
#elif defined test_var_array

static struct var_len { целое i; const char str[]; } var_array[] =
{ { 1, "abcdefghijklmnopqrstuvwxyz" },
  { 2, "longlonglonglonglong" },
  { 3, "tst3" } };

#elif defined test_var_array2

struct c1 { целое a; целое b[]; };
struct c1 c1 = { 1, { 2, 3, 4 } };

struct c2 { целое c; struct c1 c1; };
struct c2 c2 = { 1, { 2, { 3, 4, 5 }}};

#elif defined test_var_array3
/* similar to test_var_array2 but with string initializers */
struct A { целое a; char b[]; };
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
  целое a, a;
};
#elif defined test_duplicate_member_anon
struct S1 {
  целое b;
  struct {
    целое b;
  } c;
};
struct S2 {
  целое d;
  struct {
    целое d;
  };
};

/******************************************************************/
#elif defined test_conflicting_array_definition
extern целое array[2];
целое array[] = { 1, 2, 3 };

#elif defined test_incompatible_local_redef
void foo (void)
{
  typedef целое localfunctype (целое);
  extern localfunctype func2;
  typedef void localfunctype (целое, целое);
}

#elif defined test_cast_from_void
void v() {}
целое f() { вернуть v(); }

#elif defined test_switch_W1 || defined test_switch_W2 \
   || defined test_switch_W3 || defined test_switch_W4
#если defined test_switch_W1
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
__attribute__((stuff)) целое fink() {вернуть 0;}

#elif defined test_invalid_funcparam_1
void func(целое a, целое b, целое a);

#elif defined test_invalid_funcparam_2
void func(целое a, целое если);

#elif defined test_array_funcparam
целое amain(целое argc, char *argv[static argc + 1])
{
    целое i;

    для (i = 0; i < argc; ++i)
        printf("arg[%d] = \"%s\"\n", i, argv[i]);
    вернуть 0;
}
целое основной()
{
    вернуть amain(2, (char *[]){ "X", "Y", 0 });
}

#elif defined test_return_from_statement_expr
целое f() { ({ вернуть 78; }); }
целое основной() { вернуть f(); }

/******************************************************************/

#elif defined test_illegal_unicode
целое основной() {
    char *str = "\Uffffffff";
}

#elif defined test_error_string
#error \123\\
456

#elif defined test_error_incomplete_type
struct A;
void f(struct A *);

целое основной()
{
    f(&(struct A){});
}

struct A {
    целое x;
};

#elif defined test_pp_error_1
# если //no expression
# endif
#elif defined test_pp_error_2
# если X(1,2) //undefined function macro
# endif

#elif defined test_pointer_plus_double

целое *invalid_operation(целое *p, double d)
{
    вернуть p + d;
}

#elif defined test_duplicate_case

целое основной()
{
    unsigned целое x;
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

целое основной()
{
    printf(" %d %d %d\n", printf("1"), printf("22"), printf("333"));
}

#elif defined test_scope_1 \
   || defined test_scope_2 \
   || defined test_scope_3

struct xxx {целое x[4];};

/* 'ee' not defined outside of function, 'i' not redefined */
целое bar(enum ee { a = 12, b = 34 } i, целое(*f)(целое i))
{
    printf("bar %d %d %d\n", i, a, b);
    вернуть 0;
}
/* 'xxx' not defined outside of function */
целое foo(struct xxx {целое x[3];}*p)
{
    printf("foo %d", sizeof *p);
    вернуть p->x[3];
}
#ifdef test_scope_2
/* incompatible redefinition */
целое foo(struct xxx {целое x[2];}*p);
#endif
#ifndef test_scope_3
enum ee { a = 1, b };
#endif

struct xxx x = { 11,22,33,44 };
целое основной(целое argc, char **argv)
{
    printf(" %d %d\n", foo(&x), sizeof (struct xxx));
    enum ee e = b;
    bar(13 + e, 0);

}

#elif defined test_const_array_member_addr_ok

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

int_array const *get_array(const my_struct *s)
{
    вернуть &(s->arr);
}

#elif defined test_const_array_member_decay_ok

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

const целое *good_decay(const my_struct *s)
{
    вернуть s->arr;
}

#elif defined test_const_array_member_addr_bad

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_array_addr(const my_struct *s)
{
    вернуть &(s->arr);
}

#elif defined test_const_array_member_decay_bad

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

целое *bad_decay(const my_struct *s)
{
    вернуть s->arr;
}

#elif defined test_const_array_member_write_bad

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

void bad_write(const my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_const_struct_array_member_write_bad

typedef struct { целое x; } inner;
typedef struct { inner arr[1]; } outer;

void bad_inner_write(const outer *s)
{
    s->arr[0].x = 1;
}

#elif defined test_volatile_array_member_addr_ok

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

int_array volatile *get_volatile_array(volatile my_struct *s)
{
    вернуть &(s->arr);
}

#elif defined test_volatile_array_member_decay_ok

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

volatile целое *good_volatile_decay(volatile my_struct *s)
{
    вернуть s->arr;
}

#elif defined test_volatile_array_member_addr_bad

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

int_array *bad_volatile_array_addr(volatile my_struct *s)
{
    вернуть &(s->arr);
}

#elif defined test_volatile_array_member_decay_bad

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

целое *bad_volatile_decay(volatile my_struct *s)
{
    вернуть s->arr;
}

#elif defined test_volatile_array_member_write_ok

typedef целое int_array[1];
typedef struct { int_array arr; } my_struct;

void good_volatile_write(volatile my_struct *s)
{
    s->arr[0] = 1;
}

#elif defined test_conditional_array_qualifiers

typedef целое Array2[2];
typedef целое Array2x3[2][3];

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

restrict целое object;

#elif defined test_restrict_function_pointer

целое (*restrict function_pointer)(void);

#elif defined test_discarded_restrict

typedef целое *restrict restricted_pointer;

restricted_pointer *source;
целое **destination;

void test(void)
{
    destination = source;
}

#endif

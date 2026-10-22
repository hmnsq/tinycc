#تعریف_کن M_C2I(a, ...)       a ## __VA_ARGS__
#تعریف_کن M_C(a, ...)         M_C2I(a, __VA_ARGS__)
#تعریف_کن M_C3I(a, b, ...)    a ## b ## __VA_ARGS__
#تعریف_کن M_C3(a, b, ...)     M_C3I(a ,b, __VA_ARGS__)

#تعریف_کن M_RETI_ARG2(a, b, ...)  b
#تعریف_کن M_RET_ARG2(...)         M_RETI_ARG2(__VA_ARGS__)
#تعریف_کن M_RETI_ARG27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa, ...)    aa
#تعریف_کن M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)

#تعریف_کن M_TOBOOLI_0                 1, 0,
#تعریف_کن M_BOOL(x)                   M_RET_ARG2(M_C(M_TOBOOLI_, x), 1, useless)

#تعریف_کن M_IFI_0(true_macro, ...)    __VA_ARGS__
#تعریف_کن M_IFI_1(true_macro, ...)    true_macro
#تعریف_کن M_IF(c)                     M_C(M_IFI_, M_BOOL(c))

#تعریف_کن M_FLAT(...)                 __VA_ARGS__
#تعریف_کن M_INVI_0                    1
#تعریف_کن M_INVI_1                    0
#تعریف_کن M_INV(x)                    M_C(M_INVI_, x)

#تعریف_کن M_ANDI_00                   0
#تعریف_کن M_ANDI_01                   0
#تعریف_کن M_ANDI_10                   0
#تعریف_کن M_ANDI_11                   1
#تعریف_کن M_AND(x,y)                  M_C3(M_ANDI_, x, y)

#تعریف_کن M_ORI_00                    0
#تعریف_کن M_ORI_01                    1
#تعریف_کن M_ORI_10                    1
#تعریف_کن M_ORI_11                    1
#تعریف_کن M_OR(x,y)                   M_C3(M_ORI_, x, y)

#تعریف_کن M_COMMA_P(...)              M_RET_ARG27(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, useless)

#تعریف_کن M_EMPTYI_DETECT(...)        0, 1,
#تعریف_کن M_EMPTYI_P_C1(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ ())
#تعریف_کن M_EMPTYI_P_C2(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__)
#تعریف_کن M_EMPTYI_P_C3(...)          M_COMMA_P(__VA_ARGS__ () )
#تعریف_کن M_خالی_P(...)              M_AND(M_EMPTYI_P_C1(__VA_ARGS__), M_INV(M_OR(M_OR(M_EMPTYI_P_C2(__VA_ARGS__), M_COMMA_P(__VA_ARGS__)),M_EMPTYI_P_C3(__VA_ARGS__))))
#تعریف_کن M_APPLY_FUNC2B(func, arg1, arg2)        \
  M_IF(M_خالی_P(arg2))(,func(arg1, arg2))
#تعریف_کن M_MAP2B_0(func, داده, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,...) \
  M_APPLY_FUNC2B(func, داده, a) M_APPLY_FUNC2B(func, داده, b) M_APPLY_FUNC2B(func, داده, c) \
  M_APPLY_FUNC2B(func, داده, d) M_APPLY_FUNC2B(func, داده, e) M_APPLY_FUNC2B(func, داده, f) \
  M_APPLY_FUNC2B(func, داده, g) M_APPLY_FUNC2B(func, داده, h) M_APPLY_FUNC2B(func, داده, i) \
  M_APPLY_FUNC2B(func, داده, j) M_APPLY_FUNC2B(func, داده, k) M_APPLY_FUNC2B(func, داده, l) \
  M_APPLY_FUNC2B(func, داده, m) M_APPLY_FUNC2B(func, داده, n) M_APPLY_FUNC2B(func, داده, o) \
  M_APPLY_FUNC2B(func, داده, p) M_APPLY_FUNC2B(func, داده, q) M_APPLY_FUNC2B(func, داده, r) \
  M_APPLY_FUNC2B(func, داده, s) M_APPLY_FUNC2B(func, داده, t) M_APPLY_FUNC2B(func, داده, u) \
  M_APPLY_FUNC2B(func, داده, v) M_APPLY_FUNC2B(func, داده, w) M_APPLY_FUNC2B(func, داده, x) \
  M_APPLY_FUNC2B(func, داده, y) M_APPLY_FUNC2B(func, داده, z)
#تعریف_کن M_MAP2B(f, ...) M_MAP2B_0(f, __VA_ARGS__, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , )
#تعریف_کن M_INIT_INIT(a)           ,a,

#تعریف_کن M_GET_روش(روش, روش_default, ...)                       \
  M_RET_ARG2 (M_MAP2B(M_C, M_C3(M_, روش, _), __VA_ARGS__), روش_default,)

#تعریف_کن M_TEST_روش_P(روش, oplist)                         \
  M_BOOL(M_GET_روش (روش, 0, M_FLAT oplist))

#تعریف_کن TRUE 1
#تعریف_کن TEST1(n)                                \
  M_IF(n)(ok,nok)
#تعریف_کن TEST2(op)                               \
  M_TEST_روش_P(INIT, op)
#تعریف_کن TEST3(op)                               \
  M_IF(M_TEST_روش_P(INIT, op))(ok, nok)
#تعریف_کن TEST4(op) \
  TEST1(TEST2(op))
#تعریف_کن KO(a) ((فراغ)1)

/* This checks that the various expansions that ultimately lead to
   something like 'KO(arg,arg)', where 'KO' comes from a macro
   expansion reducing from a large macro chain do not are regarded
   as funclike macro invocation of KO.  E.g. X93 and X94 expand to 'KO',
   but X95 must not consume the (a,b) arguments outside the M_IF()
   invocation to reduce the 'KO' macro to an invocation.  Instead
   X95 should reduce via M_IF(KO)(a,b) to 'a'. 
   
   The other lines here are variations on this scheme, with X1 to
   X6 coming from the bug report at
   http://lists.nongnu.org/archive/html/tinycc-devel/2017-07/msg00017.html */
X92 M_IF(KO)
X93 M_GET_روش(INIT, 0, INIT(KO))
X94 M_GET_روش(INIT, 0, M_FLAT (INIT(KO)))
X95 M_IF(M_GET_روش(INIT, 0, INIT(KO)))(a,b)
X96 M_IF(M_GET_روش(INIT, 0, M_FLAT (INIT(KO))))
X97 M_IF(M_GET_روش(INIT, 0, M_FLAT (INIT(KO))))(ok,nok)
X98 (M_TEST_روش_P(INIT, (INIT(KO))))(ok, nok)
X99 M_IF(M_TEST_روش_P(INIT, (INIT(KO))))(ok, nok)
// test begins
X1 TEST1(TRUE)          // ==> expect ok, get ok
// First test with a token which is not a macro
X2 TEST2((INIT(ok)))    // ==> expect 1, get 1
X3 TEST3((INIT(ok)))    // ==> expect ok, get ok
// Then test with a token which is a macro, but should not be expanded.
X4 TEST2((INIT(KO)))    // ==> expect 1, get 1
X5 TEST4(INIT(KO))
X6 TEST3((INIT(KO)))    // ==> expect ok, get "error: macro 'KO' used with too many args"

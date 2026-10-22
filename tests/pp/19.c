#تعریف_کرو M_C2I(a, ...)       a ## __VA_ARGS__
#تعریف_کرو M_C(a, ...)         M_C2I(a, __VA_ARGS__)
#تعریف_کرو M_C3I(a, b, ...)    a ## b ## __VA_ARGS__
#تعریف_کرو M_C3(a, b, ...)     M_C3I(a ,b, __VA_ARGS__)

#تعریف_کرو M_RETI_ARG2(a, b, ...)  b
#تعریف_کرو M_RET_ARG2(...)         M_RETI_ARG2(__VA_ARGS__)
#تعریف_کرو M_RETI_ARG27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa, ...)    aa
#تعریف_کرو M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)

#تعریف_کرو M_TOBOOLI_0                 1, 0,
#تعریف_کرو M_BOOL(x)                   M_RET_ARG2(M_C(M_TOBOOLI_, x), 1, useless)

#تعریف_کرو M_IFI_0(true_macro, ...)    __VA_ARGS__
#تعریف_کرو M_IFI_1(true_macro, ...)    true_macro
#تعریف_کرو M_IF(c)                     M_C(M_IFI_, M_BOOL(c))

#تعریف_کرو M_FLAT(...)                 __VA_ARGS__
#تعریف_کرو M_INVI_0                    1
#تعریف_کرو M_INVI_1                    0
#تعریف_کرو M_INV(x)                    M_C(M_INVI_, x)

#تعریف_کرو M_ANDI_00                   0
#تعریف_کرو M_ANDI_01                   0
#تعریف_کرو M_ANDI_10                   0
#تعریف_کرو M_ANDI_11                   1
#تعریف_کرو M_AND(x,y)                  M_C3(M_ANDI_, x, y)

#تعریف_کرو M_ORI_00                    0
#تعریف_کرو M_ORI_01                    1
#تعریف_کرو M_ORI_10                    1
#تعریف_کرو M_ORI_11                    1
#تعریف_کرو M_OR(x,y)                   M_C3(M_ORI_, x, y)

#تعریف_کرو M_COMMA_P(...)              M_RET_ARG27(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, useless)

#تعریف_کرو M_EMPTYI_DETECT(...)        0, 1,
#تعریف_کرو M_EMPTYI_P_C1(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ ())
#تعریف_کرو M_EMPTYI_P_C2(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__)
#تعریف_کرو M_EMPTYI_P_C3(...)          M_COMMA_P(__VA_ARGS__ () )
#تعریف_کرو M_خالی_خانے_P(...)              M_AND(M_EMPTYI_P_C1(__VA_ARGS__), M_INV(M_OR(M_OR(M_EMPTYI_P_C2(__VA_ARGS__), M_COMMA_P(__VA_ARGS__)),M_EMPTYI_P_C3(__VA_ARGS__))))
#تعریف_کرو M_APPLY_FUNC2B(func, arg1, arg2)        \
  M_IF(M_خالی_خانے_P(arg2))(,func(arg1, arg2))
#تعریف_کرو M_MAP2B_0(func, ڈیٹا, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,...) \
  M_APPLY_FUNC2B(func, ڈیٹا, a) M_APPLY_FUNC2B(func, ڈیٹا, b) M_APPLY_FUNC2B(func, ڈیٹا, c) \
  M_APPLY_FUNC2B(func, ڈیٹا, d) M_APPLY_FUNC2B(func, ڈیٹا, e) M_APPLY_FUNC2B(func, ڈیٹا, f) \
  M_APPLY_FUNC2B(func, ڈیٹا, g) M_APPLY_FUNC2B(func, ڈیٹا, h) M_APPLY_FUNC2B(func, ڈیٹا, i) \
  M_APPLY_FUNC2B(func, ڈیٹا, j) M_APPLY_FUNC2B(func, ڈیٹا, k) M_APPLY_FUNC2B(func, ڈیٹا, l) \
  M_APPLY_FUNC2B(func, ڈیٹا, m) M_APPLY_FUNC2B(func, ڈیٹا, n) M_APPLY_FUNC2B(func, ڈیٹا, o) \
  M_APPLY_FUNC2B(func, ڈیٹا, p) M_APPLY_FUNC2B(func, ڈیٹا, q) M_APPLY_FUNC2B(func, ڈیٹا, r) \
  M_APPLY_FUNC2B(func, ڈیٹا, s) M_APPLY_FUNC2B(func, ڈیٹا, t) M_APPLY_FUNC2B(func, ڈیٹا, u) \
  M_APPLY_FUNC2B(func, ڈیٹا, v) M_APPLY_FUNC2B(func, ڈیٹا, w) M_APPLY_FUNC2B(func, ڈیٹا, x) \
  M_APPLY_FUNC2B(func, ڈیٹا, y) M_APPLY_FUNC2B(func, ڈیٹا, z)
#تعریف_کرو M_MAP2B(f, ...) M_MAP2B_0(f, __VA_ARGS__, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , )
#تعریف_کرو M_INIT_INIT(a)           ,a,

#تعریف_کرو M_GET_طریقہ(طریقہ_2, طریقہ_default, ...)                       \
  M_RET_ARG2 (M_MAP2B(M_C, M_C3(M_, طریقہ_2, _), __VA_ARGS__), طریقہ_default,)

#تعریف_کرو M_TEST_طریقہ_P(طریقہ_2, oplist)                         \
  M_BOOL(M_GET_طریقہ (طریقہ_2, 0, M_FLAT oplist))

#تعریف_کرو TRUE 1
#تعریف_کرو TEST1(n)                                \
  M_IF(n)(ok,nok)
#تعریف_کرو TEST2(op)                               \
  M_TEST_طریقہ_P(INIT, op)
#تعریف_کرو TEST3(op)                               \
  M_IF(M_TEST_طریقہ_P(INIT, op))(ok, nok)
#تعریف_کرو TEST4(op) \
  TEST1(TEST2(op))
#تعریف_کرو KO(a) ((خالی)1)

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
X93 M_GET_طریقہ(INIT, 0, INIT(KO))
X94 M_GET_طریقہ(INIT, 0, M_FLAT (INIT(KO)))
X95 M_IF(M_GET_طریقہ(INIT, 0, INIT(KO)))(a,b)
X96 M_IF(M_GET_طریقہ(INIT, 0, M_FLAT (INIT(KO))))
X97 M_IF(M_GET_طریقہ(INIT, 0, M_FLAT (INIT(KO))))(ok,nok)
X98 (M_TEST_طریقہ_P(INIT, (INIT(KO))))(ok, nok)
X99 M_IF(M_TEST_طریقہ_P(INIT, (INIT(KO))))(ok, nok)
// test begins
X1 TEST1(TRUE)          // ==> expect ok, get ok
// First test with a token which is not a macro
X2 TEST2((INIT(ok)))    // ==> expect 1, get 1
X3 TEST3((INIT(ok)))    // ==> expect ok, get ok
// Then test with a token which is a macro, but should not be expanded.
X4 TEST2((INIT(KO)))    // ==> expect 1, get 1
X5 TEST4(INIT(KO))
X6 TEST3((INIT(KO)))    // ==> expect ok, get "error: macro 'KO' used with too many args"

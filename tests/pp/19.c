#परिभाषय M_C2I(a, ...)       a ## __VA_ARGS__
#परिभाषय M_C(a, ...)         M_C2I(a, __VA_ARGS__)
#परिभाषय M_C3I(a, b, ...)    a ## b ## __VA_ARGS__
#परिभाषय M_C3(a, b, ...)     M_C3I(a ,b, __VA_ARGS__)

#परिभाषय M_RETI_ARG2(a, b, ...)  b
#परिभाषय M_RET_ARG2(...)         M_RETI_ARG2(__VA_ARGS__)
#परिभाषय M_RETI_ARG27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa, ...)    aa
#परिभाषय M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)

#परिभाषय M_TOBOOLI_0                 1, 0,
#परिभाषय M_BOOL(x)                   M_RET_ARG2(M_C(M_TOBOOLI_, x), 1, useless)

#परिभाषय M_IFI_0(true_macro, ...)    __VA_ARGS__
#परिभाषय M_IFI_1(true_macro, ...)    true_macro
#परिभाषय M_IF(c)                     M_C(M_IFI_, M_BOOL(c))

#परिभाषय M_FLAT(...)                 __VA_ARGS__
#परिभाषय M_INVI_0                    1
#परिभाषय M_INVI_1                    0
#परिभाषय M_INV(x)                    M_C(M_INVI_, x)

#परिभाषय M_ANDI_00                   0
#परिभाषय M_ANDI_01                   0
#परिभाषय M_ANDI_10                   0
#परिभाषय M_ANDI_11                   1
#परिभाषय M_AND(x,y)                  M_C3(M_ANDI_, x, y)

#परिभाषय M_ORI_00                    0
#परिभाषय M_ORI_01                    1
#परिभाषय M_ORI_10                    1
#परिभाषय M_ORI_11                    1
#परिभाषय M_OR(x,y)                   M_C3(M_ORI_, x, y)

#परिभाषय M_COMMA_P(...)              M_RET_ARG27(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, useless)

#परिभाषय M_EMPTYI_DETECT(...)        0, 1,
#परिभाषय M_EMPTYI_P_C1(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ ())
#परिभाषय M_EMPTYI_P_C2(...)          M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__)
#परिभाषय M_EMPTYI_P_C3(...)          M_COMMA_P(__VA_ARGS__ () )
#परिभाषय M_रिक्तानि_P(...)              M_AND(M_EMPTYI_P_C1(__VA_ARGS__), M_INV(M_OR(M_OR(M_EMPTYI_P_C2(__VA_ARGS__), M_COMMA_P(__VA_ARGS__)),M_EMPTYI_P_C3(__VA_ARGS__))))
#परिभाषय M_APPLY_FUNC2B(func, arg1, arg2)        \
  M_IF(M_रिक्तानि_P(arg2))(,func(arg1, arg2))
#परिभाषय M_MAP2B_0(func, दत्त, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,...) \
  M_APPLY_FUNC2B(func, दत्त, a) M_APPLY_FUNC2B(func, दत्त, b) M_APPLY_FUNC2B(func, दत्त, c) \
  M_APPLY_FUNC2B(func, दत्त, d) M_APPLY_FUNC2B(func, दत्त, e) M_APPLY_FUNC2B(func, दत्त, f) \
  M_APPLY_FUNC2B(func, दत्त, g) M_APPLY_FUNC2B(func, दत्त, h) M_APPLY_FUNC2B(func, दत्त, i) \
  M_APPLY_FUNC2B(func, दत्त, j) M_APPLY_FUNC2B(func, दत्त, k) M_APPLY_FUNC2B(func, दत्त, l) \
  M_APPLY_FUNC2B(func, दत्त, m) M_APPLY_FUNC2B(func, दत्त, n) M_APPLY_FUNC2B(func, दत्त, o) \
  M_APPLY_FUNC2B(func, दत्त, p) M_APPLY_FUNC2B(func, दत्त, q) M_APPLY_FUNC2B(func, दत्त, r) \
  M_APPLY_FUNC2B(func, दत्त, s) M_APPLY_FUNC2B(func, दत्त, t) M_APPLY_FUNC2B(func, दत्त, u) \
  M_APPLY_FUNC2B(func, दत्त, v) M_APPLY_FUNC2B(func, दत्त, w) M_APPLY_FUNC2B(func, दत्त, x) \
  M_APPLY_FUNC2B(func, दत्त, y) M_APPLY_FUNC2B(func, दत्त, z)
#परिभाषय M_MAP2B(f, ...) M_MAP2B_0(f, __VA_ARGS__, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , )
#परिभाषय M_INIT_INIT(a)           ,a,

#परिभाषय M_GET_विधानम्(विधानम्, विधानम्_default, ...)                       \
  M_RET_ARG2 (M_MAP2B(M_C, M_C3(M_, विधानम्, _), __VA_ARGS__), विधानम्_default,)

#परिभाषय M_TEST_विधानम्_P(विधानम्, oplist)                         \
  M_BOOL(M_GET_विधानम् (विधानम्, 0, M_FLAT oplist))

#परिभाषय TRUE 1
#परिभाषय TEST1(n)                                \
  M_IF(n)(ok,nok)
#परिभाषय TEST2(op)                               \
  M_TEST_विधानम्_P(INIT, op)
#परिभाषय TEST3(op)                               \
  M_IF(M_TEST_विधानम्_P(INIT, op))(ok, nok)
#परिभाषय TEST4(op) \
  TEST1(TEST2(op))
#परिभाषय KO(a) ((शून्य)1)

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
X93 M_GET_विधानम्(INIT, 0, INIT(KO))
X94 M_GET_विधानम्(INIT, 0, M_FLAT (INIT(KO)))
X95 M_IF(M_GET_विधानम्(INIT, 0, INIT(KO)))(a,b)
X96 M_IF(M_GET_विधानम्(INIT, 0, M_FLAT (INIT(KO))))
X97 M_IF(M_GET_विधानम्(INIT, 0, M_FLAT (INIT(KO))))(ok,nok)
X98 (M_TEST_विधानम्_P(INIT, (INIT(KO))))(ok, nok)
X99 M_IF(M_TEST_विधानम्_P(INIT, (INIT(KO))))(ok, nok)
// test begins
X1 TEST1(TRUE)          // ==> expect ok, get ok
// First test with a token which is not a macro
X2 TEST2((INIT(ok)))    // ==> expect 1, get 1
X3 TEST3((INIT(ok)))    // ==> expect ok, get ok
// Then test with a token which is a macro, but should not be expanded.
X4 TEST2((INIT(KO)))    // ==> expect 1, get 1
X5 TEST4(INIT(KO))
X6 TEST3((INIT(KO)))    // ==> expect ok, get "error: macro 'KO' used with too many args"

#تعریف_کړه M_RETI_ARG27(x,y,z,aa, ...)    aa
#تعریف_کړه M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#تعریف_کړه M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#تعریف_کړه M_EMPTYI_DETECT(...)    0, 1,
#تعریف_کړه M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#تعریف_کړه EX
#تعریف_کړه تشه(x)
#تعریف_کړه fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#تعریف_کړه usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#تعریف_کړه ABC(x) ABC : x
#تعریف_کړه A(a,b,c) a ## b ## c
#تعریف_کړه B(a,b,c) A(a,b,c)
#تعریف_کړه C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#تعریف_کړه TEST(x) TEST : x
#تعریف_کړه K(a,b) a ## b
#تعریف_کړه L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

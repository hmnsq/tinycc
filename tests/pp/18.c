#وصف_ڪريو M_RETI_ARG27(x,y,z,aa, ...)    aa
#وصف_ڪريو M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#وصف_ڪريو M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#وصف_ڪريو M_EMPTYI_DETECT(...)    0, 1,
#وصف_ڪريو M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#وصف_ڪريو EX
#وصف_ڪريو خالي_جايون(x)
#وصف_ڪريو fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#وصف_ڪريو usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#وصف_ڪريو ABC(x) ABC : x
#وصف_ڪريو A(a,b,c) a ## b ## c
#وصف_ڪريو B(a,b,c) A(a,b,c)
#وصف_ڪريو C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#وصف_ڪريو TEST(x) TEST : x
#وصف_ڪريو K(a,b) a ## b
#وصف_ڪريو L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

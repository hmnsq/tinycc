#घोषणा M_RETI_ARG27(x,y,z,aa, ...)    aa
#घोषणा M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#घोषणा M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#घोषणा M_EMPTYI_DETECT(...)    0, 1,
#घोषणा M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#घोषणा EX
#घोषणा empty(x)
#घोषणा fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#घोषणा usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#घोषणा ABC(x) ABC : x
#घोषणा A(a,b,c) a ## b ## c
#घोषणा B(a,b,c) A(a,b,c)
#घोषणा C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#घोषणा TEST(x) TEST : x
#घोषणा K(a,b) a ## b
#घोषणा L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

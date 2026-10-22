#परिभाषय M_RETI_ARG27(x,y,z,aa, ...)    aa
#परिभाषय M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#परिभाषय M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#परिभाषय M_EMPTYI_DETECT(...)    0, 1,
#परिभाषय M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#परिभाषय EX
#परिभाषय रिक्तानि(x)
#परिभाषय fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#परिभाषय usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#परिभाषय ABC(x) ABC : x
#परिभाषय A(a,b,c) a ## b ## c
#परिभाषय B(a,b,c) A(a,b,c)
#परिभाषय C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#परिभाषय TEST(x) TEST : x
#परिभाषय K(a,b) a ## b
#परिभाषय L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

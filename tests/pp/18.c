#నిర్వచించు M_RETI_ARG27(x,y,z,aa, ...)    aa
#నిర్వచించు M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#నిర్వచించు M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#నిర్వచించు M_EMPTYI_DETECT(...)    0, 1,
#నిర్వచించు M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#నిర్వచించు EX
#నిర్వచించు ఖాళీలు(x)
#నిర్వచించు fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#నిర్వచించు usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#నిర్వచించు ABC(x) ABC : x
#నిర్వచించు A(a,b,c) a ## b ## c
#నిర్వచించు B(a,b,c) A(a,b,c)
#నిర్వచించు C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#నిర్వచించు TEST(x) TEST : x
#నిర్వచించు K(a,b) a ## b
#నిర్వచించు L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

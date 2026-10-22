#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_RETI_ARG27(x,y,z,aa, ...)    aa
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_RET_ARG27(...)        M_RETI_ARG27(__VA_ARGS__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_COMMA_P(...)          M_RET_ARG27(__VA_ARGS__, 1, 1, 0, useless)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_EMPTYI_DETECT(...)    0, 1,
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT __VA_ARGS__ () )
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਾਲੀ_ਥਾਵਾਂ(x)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ABC(x) ABC : x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ A(a,b,c) a ## b ## c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ B(a,b,c) A(a,b,c)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C(a,b,c) a b c
B(
    C(A,C(,,),),
    C(B(,,),B,B(,,)),
    C(B(,,),B(,,),C)
    )/* */(a b c)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST(x) TEST : x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ K(a,b) a ## b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ L(a,b) K( TE  a , b  ST )
L(,)(t e s t)

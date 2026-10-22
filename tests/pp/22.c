#घोषणा TRACE(a,b,c) X a X b X c X
#घोषणा rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#अगर rettrue(bla)
      ARG_2,
#अन्यथा
      ARG_2_wrong,
#पूर्ण_अगर
      ARG_3
);

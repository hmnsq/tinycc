#define TRACE(a,b,c) X a X b X c X
#define rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#ಯದಿ rettrue(bla)
      ARG_2,
#ಅನ್ಯಥಾ
      ARG_2_wrong,
#endif
      ARG_3
);

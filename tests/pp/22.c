#define TRACE(a,b,c) X a X b X c X
#define rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#إذا rettrue(bla)
      ARG_2,
#وإلا
      ARG_2_wrong,
#endif
      ARG_3
);

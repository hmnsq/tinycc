#define TRACE(a,b,c) X a X b X c X
#define rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#නම් rettrue(bla)
      ARG_2,
#නැතහොත්
      ARG_2_wrong,
#endif
      ARG_3
);

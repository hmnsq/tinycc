#define TRACE(a,b,c) X a X b X c X
#define rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#གལ་སྲིད rettrue(bla)
      ARG_2,
#དེ་མིན
      ARG_2_wrong,
#endif
      ARG_3
);

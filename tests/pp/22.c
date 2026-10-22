#define TRACE(a,b,c) X a X b X c X
#define rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#ប្រសិនបើ rettrue(bla)
      ARG_2,
#បើមិនដូច្នេះ
      ARG_2_wrong,
#endif
      ARG_3
);

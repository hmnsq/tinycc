#تعریف_کړه TRACE(a,b,c) X a X b X c X
#تعریف_کړه rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#إذا rettrue(bla)
      ARG_2,
#وإلا
      ARG_2_wrong,
#د_که_پای
      ARG_3
);

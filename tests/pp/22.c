#تعریف_کرو TRACE(a,b,c) X a X b X c X
#تعریف_کرو rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#إذا rettrue(bla)
      ARG_2,
#وإلا
      ARG_2_wrong,
#جے_انت
      ARG_3
);

#تعریف_کرو TRACE(a,b,c) X a X b X c X
#تعریف_کرو rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#اگر rettrue(bla)
      ARG_2,
#ورنہ
      ARG_2_wrong,
#اگر_ختم
      ARG_3
);

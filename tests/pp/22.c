#وصف_ڪريو TRACE(a,b,c) X a X b X c X
#وصف_ڪريو rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#إذا rettrue(bla)
      ARG_2,
#وإلا
      ARG_2_wrong,
#جيڪڏهن_پورو
      ARG_3
);

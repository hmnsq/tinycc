#परिभाषय TRACE(a,b,c) X a X b X c X
#परिभाषय rettrue(x) 1
A rettrue(bla) B
TRACE(
      ARG_1,
#यदि rettrue(bla)
      ARG_2,
#अन्यथा
      ARG_2_wrong,
#यदि_अन्तः
      ARG_3
);

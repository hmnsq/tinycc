X1 __COUNTER__
X2 __COUNTER__
#अगर __COUNTER__
X3 __COUNTER__
#पूर्ण_अगर
#घोषणा pass(x) x
#घोषणा a x __COUNTER__ y
#घोषणा a2 pass(__COUNTER__)
#घोषणा f(c) c __COUNTER__
#घोषणा apply(d) d d __COUNTER__ x2 f(d) y2 __COUNTER__
#घोषणा _paste(a,b) a ## b
#घोषणा paste(a,b) _paste(a,b)
#घोषणा _paste3(a,b,c) a ## b ## c
#घोषणा doublepaste(a,b) _paste3(a,b,b)
#घोषणा str(x) #x
X4 a
X5 f(a)
X6 f(b)
X7 f(__COUNTER__)
X8 apply(a)
X9 apply(f(a))
X10 apply(__COUNTER__)
X11 apply(a2)
X12 str(__COUNTER__)
X13 paste(x,__COUNTER__)
X14 _paste(x,__COUNTER__)
X15 doublepaste(x,__COUNTER__)

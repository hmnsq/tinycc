#تعریف_کړه D1(s, ...) s
#تعریف_کړه D2(s, ...) s D1(__VA_ARGS__)
#تعریف_کړه D3(s, ...) s D2(__VA_ARGS__)
#تعریف_کړه D4(s, ...) s D3(__VA_ARGS__)

D1(a)
D2(a, b)
D3(a, b, c)
D4(a, b, c, d)

x D4(a, b, c, d) y
x D4(a, b, c) y
x D4(a, b) y
x D4(a) y
x D4() y

#تعریف_کړه GNU_COMMA(X,Y...) X,##Y

x GNU_COMMA(A,B,C) y
x GNU_COMMA(A,B) y
x GNU_COMMA(A) y
x GNU_COMMA() y

#تعریف_کړه __sun_attr___noreturn__ __attribute__((__noreturn__))
#تعریف_کړه ___sun_attr_inner(__a) __sun_attr_##__a
#تعریف_کړه __sun_attr__(__a) ___sun_attr_inner __a
#تعریف_کړه __NORETURN __sun_attr__((__noreturn__))
__NORETURN
#تعریف_کړه X(...)
#تعریف_کړه Y(...)  1 __VA_ARGS__ 2
Y(X X() ())

#تعریف_کړه DDD(A, B) D_ ## B ## _D_ ## A
#تعریف_کړه CCC(X, ...) DDD(X,## __VA_ARGS__)
/* must be D_B_D_A (not D_B _D_A) */
CCC(A,B)

#define str(s) # s
#define xstr(s) str(s)
#define debug(s, t) printf("x" # s "= %d, x" # t "= %s", \
	x ## s, x ## t)
#define INCFILE(n) vers ## n
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define ତଳ_2 ତଳ_2 ", world"
debug(1, 2);
fputs(str(strncmp("abc\0d", "abc", '\4') // this goes away
	== 0) str(: @\n), s);
\#ଅନ୍ତର୍ଭାଵ xstr(INCFILE(2).h)
glue(ଉପର_2, ତଳ_2);
xglue(ଉପର_2, ତଳ_2)

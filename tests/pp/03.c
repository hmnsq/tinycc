#define str(s) # s
#define xstr(s) str(s)
#define debug(s, t) printf("x" # s "= %d, x" # t "= %s", \
	x ## s, x ## t)
#define INCFILE(n) vers ## n
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define أدنى_2 أدنى_2 ", world"
debug(1, 2);
fputs(str(strncmp("abc\0d", "abc", '\4') // this goes away
	== 0) str(: @\n), s);
\#ضمن xstr(INCFILE(2).h)
glue(أعلى_2, أدنى_2);
xglue(أعلى_2, أدنى_2)

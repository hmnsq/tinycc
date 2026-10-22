#define str(s) # s
#define xstr(s) str(s)
#define debug(s, t) म_लिखो("x" # s "= %d, x" # t "= %s", \
	x ## s, x ## t)
#define INCFILE(n) vers ## n
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define निचला_2 निचला_2 ", world"
debug(1, 2);
ख_माला_दो(str(म_भेदन("abc\0d", "abc", '\4') // this goes away
	== 0) str(: @\n), s);
\#अन्तर्भाव xstr(INCFILE(2).h)
glue(ऊपरी_2, निचला_2);
xglue(ऊपरी_2, निचला_2)

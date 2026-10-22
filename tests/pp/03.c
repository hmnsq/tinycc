#define str(s) # s
#define xstr(s) str(s)
#define debug(s, t) म_लिखो("x" # s "= %d, x" # t "= %s", \
	x ## s, x ## t)
#define INCFILE(n) vers ## n
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define तल्लो_2 तल्लो_2 ", world"
debug(1, 2);
ख_माला_दो(str(म_भेदन("abc\0d", "abc", '\4') // this goes away
	== 0) str(: @\n), s);
\#अन्तर्भाव xstr(INCFILE(2).h)
glue(माथिल्लो_2, तल्लो_2);
xglue(माथिल्लो_2, तल्लो_2)

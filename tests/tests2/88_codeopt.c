/* Check some way in where code suppression caused various
   miscompilations.  */
बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
प्रकार __SIZE_TYPE__ माप_प्रकार;

माप_प्रकार _brk_start, _brk_end;
व्योम * extend_brk(माप_प्रकार आकार, माप_प्रकार align)
{
    माप_प्रकार mask = align - 1;
    व्योम *ret = 0;

     करो {
	 अगर (__builtin_expect(!!(_brk_start == 0), 0))
	   करो {
	       म_लिखो("wrong1\n");
	   } जबतक (0);
     } जबतक (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (व्योम *)_brk_end;
     _brk_end += आकार;

     वापस ret;
}

अटल व्योम get_args (पूर्णांक a, पूर्णांक b)
{
  अगर (a != 1)
    म_लिखो("wrong2\n");
  अन्यथा
    म_लिखो("okay\n");
}

व्योम bla(व्योम)
{
  पूर्णांक __ret = 42;
  ({
    अगर (__builtin_expect(!!(0), 0)) {
      अगर (__builtin_expect(!!__ret, 0))
        म_लिखो("wrong3\n");
      पूर्णांक x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, माप(__ret));
}

पूर्णांक ext;

व्योम broken_jumpopt (पूर्णांक xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  म_लिखो("okay: %d %d\n", xxx, ext);
}

_Bool chk(अचिन्हित दीर्घ addr, अचिन्हित दीर्घ limit, अचिन्हित दीर्घ आकार)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  अगर (0)
    ret = 0 != (!!(addr > limit - आकार));
  वापस 0;
}

पूर्णांक मुख्य()
{
  व्योम *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  अगर (!r)
    म_लिखो("wrong4\n");
  अन्यथा
    म_लिखो("okay\n");
  bla();
  broken_jumpopt(42);
  वापस 0;
}

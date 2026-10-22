/* Check some way in where code suppression caused various
   miscompilations.  */
बाह्य पूर्णांक म_लिखो (स्थिरांक अक्षर *, ...);
प्रकारव्याख्या __SIZE_TYPE__ माप_प्रकार;

माप_प्रकार _brk_start, _brk_end;
शून्य * extend_brk(माप_प्रकार size, माप_प्रकार align)
{
    माप_प्रकार mask = align - 1;
    शून्य *ret = 0;

     करा {
	 जर (__builtin_expect(!!(_brk_start == 0), 0))
	   करा {
	       म_लिखो("wrong1\n");
	   } पर्यंत (0);
     } पर्यंत (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (शून्य *)_brk_end;
     _brk_end += size;

     परत ret;
}

स्थिर शून्य get_args (पूर्णांक a, पूर्णांक b)
{
  जर (a != 1)
    म_लिखो("wrong2\n");
  अन्यथा
    म_लिखो("okay\n");
}

शून्य bla(शून्य)
{
  पूर्णांक __ret = 42;
  ({
    जर (__builtin_expect(!!(0), 0)) {
      जर (__builtin_expect(!!__ret, 0))
        म_लिखो("wrong3\n");
      पूर्णांक x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, आकार(__ret));
}

पूर्णांक ext;

शून्य broken_jumpopt (पूर्णांक xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  म_लिखो("okay: %d %d\n", xxx, ext);
}

_Bool chk(अचिन्हित दीर्घ addr, अचिन्हित दीर्घ limit, अचिन्हित दीर्घ size)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  जर (0)
    ret = 0 != (!!(addr > limit - size));
  परत 0;
}

पूर्णांक main()
{
  शून्य *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  जर (!r)
    म_लिखो("wrong4\n");
  अन्यथा
    म_लिखो("okay\n");
  bla();
  broken_jumpopt(42);
  परत 0;
}

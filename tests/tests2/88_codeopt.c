/* Check some way in where code suppression caused various
   miscompilations.  */
बाह्य पूर्णाङ्क म_लिखो (अचर वर्ण *, ...);
प्रकारनिर्देश __SIZE_TYPE__ माप_प्रकार;

माप_प्रकार _brk_start, _brk_end;
शून्य * extend_brk(माप_प्रकार size, माप_प्रकार align)
{
    माप_प्रकार mask = align - 1;
    शून्य *ret = 0;

     गर {
	 यदि (__builtin_expect(!!(_brk_start == 0), 0))
	   गर {
	       म_लिखो("wrong1\n");
	   } जबसम्म (0);
     } जबसम्म (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (शून्य *)_brk_end;
     _brk_end += size;

     फर्काऊ ret;
}

स्थिर शून्य get_args (पूर्णाङ्क a, पूर्णाङ्क b)
{
  यदि (a != 1)
    म_लिखो("wrong2\n");
  अन्यथा
    म_लिखो("okay\n");
}

शून्य bla(शून्य)
{
  पूर्णाङ्क __ret = 42;
  ({
    यदि (__builtin_expect(!!(0), 0)) {
      यदि (__builtin_expect(!!__ret, 0))
        म_लिखो("wrong3\n");
      पूर्णाङ्क x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, परिमाण(__ret));
}

पूर्णाङ्क ext;

शून्य broken_jumpopt (पूर्णाङ्क xxx)
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
  यदि (0)
    ret = 0 != (!!(addr > limit - size));
  फर्काऊ 0;
}

पूर्णाङ्क main()
{
  शून्य *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  यदि (!r)
    म_लिखो("wrong4\n");
  अन्यथा
    म_लिखो("okay\n");
  bla();
  broken_jumpopt(42);
  फर्काऊ 0;
}

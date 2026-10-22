/* Check some way in where code suppression caused various
   miscompilations.  */
बाह्य पूर्णाङ्क printf (ध्रुव वर्ण *, ...);
प्रकारनिर्देश __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
शून्य * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    शून्य *ret = 0;

     करोहि {
	 सचे (__builtin_expect(!!(_brk_start == 0), 0))
	   करोहि {
	       printf("wrong1\n");
	   } याव (0);
     } याव (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (शून्य *)_brk_end;
     _brk_end += size;

     पटिनिवत्त ret;
}

स्थिर शून्य get_args (पूर्णाङ्क a, पूर्णाङ्क b)
{
  सचे (a != 1)
    printf("wrong2\n");
  अञ्ञथा
    printf("okay\n");
}

शून्य bla(शून्य)
{
  पूर्णाङ्क __ret = 42;
  ({
    सचे (__builtin_expect(!!(0), 0)) {
      सचे (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
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
  printf("okay: %d %d\n", xxx, ext);
}

_Bool chk(unsigned long addr, unsigned long limit, unsigned long size)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  सचे (0)
    ret = 0 != (!!(addr > limit - size));
  पटिनिवत्त 0;
}

पूर्णाङ्क main()
{
  शून्य *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  सचे (!r)
    printf("wrong4\n");
  अञ्ञथा
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  पटिनिवत्त 0;
}

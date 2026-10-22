/* Check some way in where code suppression caused various
   miscompilations.  */
خارجي صحيح printf (ثابت حرف *, ...);
تعريفنوع __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
فراغ * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    فراغ *ret = 0;

     ܥܒܕ {
	 ܐܢ (__builtin_expect(!!(_brk_start == 0), 0))
	   ܥܒܕ {
	       printf("wrong1\n");
	   } ܟܡܐ (0);
     } ܟܡܐ (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (فراغ *)_brk_end;
     _brk_end += size;

     ܦܢܐ ret;
}

ساكن فراغ get_args (صحيح a, صحيح b)
{
  ܐܢ (a != 1)
    printf("wrong2\n");
  ܐܚܪܢܐ
    printf("okay\n");
}

فراغ bla(فراغ)
{
  صحيح __ret = 42;
  ({
    ܐܢ (__builtin_expect(!!(0), 0)) {
      ܐܢ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      صحيح x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, حجم(__ret));
}

صحيح ext;

فراغ broken_jumpopt (صحيح xxx)
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
  ܐܢ (0)
    ret = 0 != (!!(addr > limit - size));
  ܦܢܐ 0;
}

صحيح main()
{
  فراغ *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  ܐܢ (!r)
    printf("wrong4\n");
  ܐܚܪܢܐ
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ܦܢܐ 0;
}

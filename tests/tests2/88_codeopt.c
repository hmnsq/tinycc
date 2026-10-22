/* Check some way in where code suppression caused various
   miscompilations.  */
வெளி முழு printf (மாறிலி எழுத்து *, ...);
வகைவரை __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
வெறுமை * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    வெறுமை *ret = 0;

     செய் {
	 எனில் (__builtin_expect(!!(_brk_start == 0), 0))
	   செய் {
	       printf("wrong1\n");
	   } போது (0);
     } போது (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (வெறுமை *)_brk_end;
     _brk_end += size;

     திரும்பு ret;
}

நிலையான வெறுமை get_args (முழு a, முழு b)
{
  எனில் (a != 1)
    printf("wrong2\n");
  இல்லையெனில்
    printf("okay\n");
}

வெறுமை bla(வெறுமை)
{
  முழு __ret = 42;
  ({
    எனில் (__builtin_expect(!!(0), 0)) {
      எனில் (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      முழு x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, அளவு(__ret));
}

முழு ext;

வெறுமை broken_jumpopt (முழு xxx)
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
  எனில் (0)
    ret = 0 != (!!(addr > limit - size));
  திரும்பு 0;
}

முழு முதன்மை()
{
  வெறுமை *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  எனில் (!r)
    printf("wrong4\n");
  இல்லையெனில்
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  திரும்பு 0;
}

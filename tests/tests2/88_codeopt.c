/* Check some way in where code suppression caused various
   miscompilations.  */
extern số_nguyên printf (const char *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 nếu (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } trong_khi (0);
     } trong_khi (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     trả_về ret;
}

static void get_args (số_nguyên a, số_nguyên b)
{
  nếu (a != 1)
    printf("wrong2\n");
  không_thì
    printf("okay\n");
}

void bla(void)
{
  số_nguyên __ret = 42;
  ({
    nếu (__builtin_expect(!!(0), 0)) {
      nếu (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      số_nguyên x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, sizeof(__ret));
}

số_nguyên ext;

void broken_jumpopt (số_nguyên xxx)
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
  nếu (0)
    ret = 0 != (!!(addr > limit - size));
  trả_về 0;
}

số_nguyên main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  nếu (!r)
    printf("wrong4\n");
  không_thì
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  trả_về 0;
}

/* Check some way in where code suppression caused various
   miscompilations.  */
extern 정수 printf (const char *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 만약 (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } 동안 (0);
     } 동안 (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     반환 ret;
}

static void get_args (정수 a, 정수 b)
{
  만약 (a != 1)
    printf("wrong2\n");
  아니면
    printf("okay\n");
}

void bla(void)
{
  정수 __ret = 42;
  ({
    만약 (__builtin_expect(!!(0), 0)) {
      만약 (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      정수 x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, sizeof(__ret));
}

정수 ext;

void broken_jumpopt (정수 xxx)
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
  만약 (0)
    ret = 0 != (!!(addr > limit - size));
  반환 0;
}

정수 main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  만약 (!r)
    printf("wrong4\n");
  아니면
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  반환 0;
}

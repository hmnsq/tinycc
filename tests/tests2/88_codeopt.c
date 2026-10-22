/* Check some way in where code suppression caused various
   miscompilations.  */
extern 整数 printf (const char *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 もし (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } ながら (0);
     } ながら (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     戻る ret;
}

static void get_args (整数 a, 整数 b)
{
  もし (a != 1)
    printf("wrong2\n");
  否则
    printf("okay\n");
}

void bla(void)
{
  整数 __ret = 42;
  ({
    もし (__builtin_expect(!!(0), 0)) {
      もし (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      整数 x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, sizeof(__ret));
}

整数 ext;

void broken_jumpopt (整数 xxx)
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
  もし (0)
    ret = 0 != (!!(addr > limit - size));
  戻る 0;
}

整数 メインページ()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  もし (!r)
    printf("wrong4\n");
  否则
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  戻る 0;
}

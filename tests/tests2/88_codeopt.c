/* Check some way in where code suppression caused various
   miscompilations.  */
extern පූර්ණ_සංඛ්‍යා printf (const var_na *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 නම් (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } අතරතුර (0);
     } අතරතුර (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     ආපසු ret;
}

static void get_args (පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b)
{
  නම් (a != 1)
    printf("wrong2\n");
  නැතහොත්
    printf("okay\n");
}

void bla(void)
{
  පූර්ණ_සංඛ්‍යා __ret = 42;
  ({
    නම් (__builtin_expect(!!(0), 0)) {
      නම් (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      පූර්ණ_සංඛ්‍යා x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, parimaa_na(__ret));
}

පූර්ණ_සංඛ්‍යා ext;

void broken_jumpopt (පූර්ණ_සංඛ්‍යා xxx)
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
  නම් (0)
    ret = 0 != (!!(addr > limit - size));
  ආපසු 0;
}

පූර්ණ_සංඛ්‍යා main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  නම් (!r)
    printf("wrong4\n");
  නැතහොත්
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ආපසු 0;
}

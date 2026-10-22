/* Check some way in where code suppression caused various
   miscompilations.  */
extern ကိန်းပြည့် printf (const var_na *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 အကယ်၍ (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } နေစဉ် (0);
     } နေစဉ် (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     ပြန်ပေး ret;
}

static void get_args (ကိန်းပြည့် a, ကိန်းပြည့် b)
{
  အကယ်၍ (a != 1)
    printf("wrong2\n");
  မဟုတ်ပါက
    printf("okay\n");
}

void bla(void)
{
  ကိန်းပြည့် __ret = 42;
  ({
    အကယ်၍ (__builtin_expect(!!(0), 0)) {
      အကယ်၍ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      ကိန်းပြည့် x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, parimaa_na(__ret));
}

ကိန်းပြည့် ext;

void broken_jumpopt (ကိန်းပြည့် xxx)
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
  အကယ်၍ (0)
    ret = 0 != (!!(addr > limit - size));
  ပြန်ပေး 0;
}

ကိန်းပြည့် main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  အကယ်၍ (!r)
    printf("wrong4\n");
  မဟုတ်ပါက
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ပြန်ပေး 0;
}

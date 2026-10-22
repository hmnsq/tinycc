/* Check some way in where code suppression caused various
   miscompilations.  */
extern ចំនួនគត់ printf (const var_na *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 ប្រសិនបើ (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } ខណៈពេល (0);
     } ខណៈពេល (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     ត្រឡប់ ret;
}

static void get_args (ចំនួនគត់ a, ចំនួនគត់ b)
{
  ប្រសិនបើ (a != 1)
    printf("wrong2\n");
  បើមិនដូច្នេះ
    printf("okay\n");
}

void bla(void)
{
  ចំនួនគត់ __ret = 42;
  ({
    ប្រសិនបើ (__builtin_expect(!!(0), 0)) {
      ប្រសិនបើ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      ចំនួនគត់ x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, parimaa_na(__ret));
}

ចំនួនគត់ ext;

void broken_jumpopt (ចំនួនគត់ xxx)
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
  ប្រសិនបើ (0)
    ret = 0 != (!!(addr > limit - size));
  ត្រឡប់ 0;
}

ចំនួនគត់ main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  ប្រសិនបើ (!r)
    printf("wrong4\n");
  បើមិនដូច្នេះ
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ត្រឡប់ 0;
}

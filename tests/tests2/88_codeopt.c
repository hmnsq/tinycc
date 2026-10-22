/* Check some way in where code suppression caused various
   miscompilations.  */
extern ཧྲིལ printf (const var_na *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 གལ་ཏེ (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } སྐབས (0);
     } སྐབས (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     ཕྱིར ret;
}

static void get_args (ཧྲིལ a, ཧྲིལ b)
{
  གལ་ཏེ (a != 1)
    printf("wrong2\n");
  དེ་མིན
    printf("okay\n");
}

void bla(void)
{
  ཧྲིལ __ret = 42;
  ({
    གལ་ཏེ (__builtin_expect(!!(0), 0)) {
      གལ་ཏེ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      ཧྲིལ x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, parimaa_na(__ret));
}

ཧྲིལ ext;

void broken_jumpopt (ཧྲིལ xxx)
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
  གལ་ཏེ (0)
    ret = 0 != (!!(addr > limit - size));
  ཕྱིར 0;
}

ཧྲིལ གཙོ()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  གལ་ཏེ (!r)
    printf("wrong4\n");
  དེ་མིན
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ཕྱིར 0;
}

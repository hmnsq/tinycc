/* Check some way in where code suppression caused various
   miscompilations.  */
extern puur_naa_nka printf (const var_na *, ...);
typedef __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
void * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    void *ret = 0;

     do {
	 ပေႃး (__builtin_expect(!!(_brk_start == 0), 0))
	   do {
	       printf("wrong1\n");
	   } ၶၢဝ်း (0);
     } ၶၢဝ်း (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (void *)_brk_end;
     _brk_end += size;

     ပွၵ်ႈ ret;
}

static void get_args (puur_naa_nka a, puur_naa_nka b)
{
  ပေႃး (a != 1)
    printf("wrong2\n");
  ပေႃးဢမ်ႇ
    printf("okay\n");
}

void bla(void)
{
  puur_naa_nka __ret = 42;
  ({
    ပေႃး (__builtin_expect(!!(0), 0)) {
      ပေႃး (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      puur_naa_nka x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, parimaa_na(__ret));
}

puur_naa_nka ext;

void broken_jumpopt (puur_naa_nka xxx)
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
  ပေႃး (0)
    ret = 0 != (!!(addr > limit - size));
  ပွၵ်ႈ 0;
}

puur_naa_nka main()
{
  void *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  ပေႃး (!r)
    printf("wrong4\n");
  ပေႃးဢမ်ႇ
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ပွၵ်ႈ 0;
}

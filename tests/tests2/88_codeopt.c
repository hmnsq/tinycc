/* Check some way in where code suppression caused various
   miscompilations.  */
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
ଶୂନ୍ୟ * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    ଶୂନ୍ୟ *ret = 0;

     କର {
	 ଯଦି (__builtin_expect(!!(_brk_start == 0), 0))
	   କର {
	       printf("wrong1\n");
	   } ଯେତେବେଳେ (0);
     } ଯେତେବେଳେ (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (ଶୂନ୍ୟ *)_brk_end;
     _brk_end += size;

     ଫେରନ୍ତୁ ret;
}

ସ୍ଥିର ଶୂନ୍ୟ get_args (ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
  ଯଦି (a != 1)
    printf("wrong2\n");
  ଅନ୍ୟଥା
    printf("okay\n");
}

ଶୂନ୍ୟ bla(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __ret = 42;
  ({
    ଯଦି (__builtin_expect(!!(0), 0)) {
      ଯଦି (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, ଆକାର(__ret));
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ext;

ଶୂନ୍ୟ broken_jumpopt (ପୂର୍ଣ୍ଣସଂଖ୍ୟା xxx)
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
  ଯଦି (0)
    ret = 0 != (!!(addr > limit - size));
  ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  ଶୂନ୍ୟ *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  ଯଦି (!r)
    printf("wrong4\n");
  ଅନ୍ୟଥା
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ଫେରନ୍ତୁ 0;
}

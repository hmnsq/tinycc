/* Check some way in where code suppression caused various
   miscompilations.  */
বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
প্রকারলেখ __SIZE_TYPE__ আকার_t;

আকার_t _brk_start, _brk_end;
শূন্য * extend_brk(আকার_t আকার_2, আকার_t align)
{
    আকার_t mask = align - 1;
    শূন্য *ret = 0;

     করো {
	 যদি (__builtin_expect(!!(_brk_start == 0), 0))
	   করো {
	       printf("wrong1\n");
	   } যখন (0);
     } যখন (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (শূন্য *)_brk_end;
     _brk_end += আকার_2;

     ফেরত ret;
}

স্থির শূন্য get_args (পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
  যদি (a != 1)
    printf("wrong2\n");
  অন্যথা
    printf("okay\n");
}

শূন্য bla(শূন্য)
{
  পূর্ণসংখ্যা __ret = 42;
  ({
    যদি (__builtin_expect(!!(0), 0)) {
      যদি (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      পূর্ণসংখ্যা x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, আকার(__ret));
}

পূর্ণসংখ্যা ext;

শূন্য broken_jumpopt (পূর্ণসংখ্যা xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  printf("okay: %d %d\n", xxx, ext);
}

_Bool chk(unsigned long addr, unsigned long limit, unsigned long আকার_2)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  যদি (0)
    ret = 0 != (!!(addr > limit - আকার_2));
  ফেরত 0;
}

পূর্ণসংখ্যা প্রধান()
{
  শূন্য *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  যদি (!r)
    printf("wrong4\n");
  অন্যথা
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ফেরত 0;
}

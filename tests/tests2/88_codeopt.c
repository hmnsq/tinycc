/* Check some way in where code suppression caused various
   miscompilations.  */
بیرونی صحیح printf (ثابت نویسه *, ...);
تعریفنوع __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
تهی * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    تهی *ret = 0;

     انجامبده {
	 اگر (__builtin_expect(!!(_brk_start == 0), 0))
	   انجامبده {
	       printf("wrong1\n");
	   } وقتی (0);
     } وقتی (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (تهی *)_brk_end;
     _brk_end += size;

     بازگشت ret;
}

ایستا تهی get_args (صحیح a, صحیح b)
{
  اگر (a != 1)
    printf("wrong2\n");
  وگرنه
    printf("okay\n");
}

تهی bla(تهی)
{
  صحیح __ret = 42;
  ({
    اگر (__builtin_expect(!!(0), 0)) {
      اگر (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      صحیح x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, اندازه(__ret));
}

صحیح ext;

تهی broken_jumpopt (صحیح xxx)
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
  اگر (0)
    ret = 0 != (!!(addr > limit - size));
  بازگشت 0;
}

صحیح اصلی()
{
  تهی *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  اگر (!r)
    printf("wrong4\n");
  وگرنه
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  بازگشت 0;
}

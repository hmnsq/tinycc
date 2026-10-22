/* Check some way in where code suppression caused various
   miscompilations.  */
বাহ্য পূর্ণাঙ্ক printf (ধ্রুৱ ৱর্ণ *, ...);
প্রকারনির্দেশ __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
শূন্য * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    শূন্য *ret = 0;

     কৰা {
	 যদি (__builtin_expect(!!(_brk_start == 0), 0))
	   কৰা {
	       printf("wrong1\n");
	   } যেতিয়ালৈ (0);
     } যেতিয়ালৈ (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (শূন্য *)_brk_end;
     _brk_end += size;

     ঘূৰাই ret;
}

স্থির শূন্য get_args (পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
{
  যদি (a != 1)
    printf("wrong2\n");
  অন্যথা
    printf("okay\n");
}

শূন্য bla(শূন্য)
{
  পূর্ণাঙ্ক __ret = 42;
  ({
    যদি (__builtin_expect(!!(0), 0)) {
      যদি (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      পূর্ণাঙ্ক x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, পরিমাণ(__ret));
}

পূর্ণাঙ্ক ext;

শূন্য broken_jumpopt (পূর্ণাঙ্ক xxx)
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
  যদি (0)
    ret = 0 != (!!(addr > limit - size));
  ঘূৰাই 0;
}

পূর্ণাঙ্ক main()
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
  ঘূৰাই 0;
}

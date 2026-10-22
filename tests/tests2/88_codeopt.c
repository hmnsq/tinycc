/* Check some way in where code suppression caused various
   miscompilations.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
ಶೂನ್ಯ * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    ಶೂನ್ಯ *ret = 0;

     ಕುರು {
	 ಯದಿ (__builtin_expect(!!(_brk_start == 0), 0))
	   ಕುರು {
	       printf("wrong1\n");
	   } ಯಾವತ್ (0);
     } ಯಾವತ್ (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (ಶೂನ್ಯ *)_brk_end;
     _brk_end += size;

     ಪ್ರತ್ಯಾಗಮ ret;
}

ಸ್ಥಿರ ಶೂನ್ಯ get_args (ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
  ಯದಿ (a != 1)
    printf("wrong2\n");
  ಅನ್ಯಥಾ
    printf("okay\n");
}

ಶೂನ್ಯ bla(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ __ret = 42;
  ({
    ಯದಿ (__builtin_expect(!!(0), 0)) {
      ಯದಿ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      ಪೂರ್ಣಾಙ್ಕ x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, ಪರಿಮಾಣ(__ret));
}

ಪೂರ್ಣಾಙ್ಕ ext;

ಶೂನ್ಯ broken_jumpopt (ಪೂರ್ಣಾಙ್ಕ xxx)
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
  ಯದಿ (0)
    ret = 0 != (!!(addr > limit - size));
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
  ಶೂನ್ಯ *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  ಯದಿ (!r)
    printf("wrong4\n");
  ಅನ್ಯಥಾ
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  ಪ್ರತ್ಯಾಗಮ 0;
}

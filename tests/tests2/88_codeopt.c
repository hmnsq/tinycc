/* Check some way in where code suppression caused various
   miscompilations.  */
خارجي صحيح لکھو (ثابت حرف *, ...);
تعريفنوع __SIZE_TYPE__ ناپ_t;

ناپ_t brk_شروع, brk_سرا;
فراغ * extend_brk(ناپ_t ناپ, ناپ_t align)
{
    ناپ_t نقاب = align - 1;
    فراغ *ret = 0;

     افعل {
	 إذا (__builtin_expect(!!(brk_شروع == 0), 0))
	   افعل {
	       لکھو("wrong1\n");
	   } طالما (0);
     } طالما (0);
     brk_سرا = (brk_سرا + نقاب) & ~نقاب;
     ret = (فراغ *)brk_سرا;
     brk_سرا += ناپ;

     أرجع ret;
}

ساكن فراغ get_دلیلاں (صحيح a, صحيح b)
{
  إذا (a != 1)
    لکھو("wrong2\n");
  وإلا
    لکھو("okay\n");
}

فراغ bla(فراغ)
{
  صحيح __ret = 42;
  ({
    إذا (__builtin_expect(!!(0), 0)) {
      إذا (__builtin_expect(!!__ret, 0))
        لکھو("wrong3\n");
      صحيح x = !!(__ret);
    }
    __ret;
  });
  get_دلیلاں(!!__ret, حجم(__ret));
}

صحيح ext;

فراغ broken_jumpopt (صحيح xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  لکھو("okay: %d %d\n", xxx, ext);
}

_Bool chk(بنانشانی لما addr, بنانشانی لما حد_بندی, بنانشانی لما ناپ)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  إذا (0)
    ret = 0 != (!!(addr > حد_بندی - ناپ));
  أرجع 0;
}

صحيح مکھ()
{
  فراغ *r;
  brk_شروع = 1024;
  brk_سرا = 1024;
  r = extend_brk (4096, 16);
  إذا (!r)
    لکھو("wrong4\n");
  وإلا
    لکھو("okay\n");
  bla();
  broken_jumpopt(42);
  أرجع 0;
}

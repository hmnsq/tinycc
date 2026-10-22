/* Check some way in where code suppression caused various
   miscompilations.  */
خارجي صحيح چاپ_کن (ثابت حرف *, ...);
تعريفنوع __SIZE_TYPE__ اندازه_t;

اندازه_t brk_شروع, brk_انتها;
فراغ * extend_brk(اندازه_t اندازه, اندازه_t align)
{
    اندازه_t ماسک = align - 1;
    فراغ *ret = 0;

     افعل {
	 إذا (__builtin_expect(!!(brk_شروع == 0), 0))
	   افعل {
	       چاپ_کن("wrong1\n");
	   } طالما (0);
     } طالما (0);
     brk_انتها = (brk_انتها + ماسک) & ~ماسک;
     ret = (فراغ *)brk_انتها;
     brk_انتها += اندازه;

     أرجع ret;
}

ساكن فراغ get_آرگومانها (صحيح a, صحيح b)
{
  إذا (a != 1)
    چاپ_کن("wrong2\n");
  وإلا
    چاپ_کن("okay\n");
}

فراغ bla(فراغ)
{
  صحيح __ret = 42;
  ({
    إذا (__builtin_expect(!!(0), 0)) {
      إذا (__builtin_expect(!!__ret, 0))
        چاپ_کن("wrong3\n");
      صحيح x = !!(__ret);
    }
    __ret;
  });
  get_آرگومانها(!!__ret, حجم(__ret));
}

صحيح ext;

فراغ broken_jumpopt (صحيح xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  چاپ_کن("okay: %d %d\n", xxx, ext);
}

_Bool chk(بیعلامت دراز addr, بیعلامت دراز حد, بیعلامت دراز اندازه)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  إذا (0)
    ret = 0 != (!!(addr > حد - اندازه));
  أرجع 0;
}

صحيح اصلی()
{
  فراغ *r;
  brk_شروع = 1024;
  brk_انتها = 1024;
  r = extend_brk (4096, 16);
  إذا (!r)
    چاپ_کن("wrong4\n");
  وإلا
    چاپ_کن("okay\n");
  bla();
  broken_jumpopt(42);
  أرجع 0;
}

/* Check some way in where code suppression caused various
   miscompilations.  */
خارجي صحيح چاپ_کړه (ثابت حرف *, ...);
تعريفنوع __SIZE_TYPE__ اندازه_t;

اندازه_t brk_پیل, brk_پای_ټکی;
فراغ * extend_brk(اندازه_t اندازه, اندازه_t align)
{
    اندازه_t ماسک = align - 1;
    فراغ *ret = 0;

     افعل {
	 إذا (__builtin_expect(!!(brk_پیل == 0), 0))
	   افعل {
	       چاپ_کړه("wrong1\n");
	   } طالما (0);
     } طالما (0);
     brk_پای_ټکی = (brk_پای_ټکی + ماسک) & ~ماسک;
     ret = (فراغ *)brk_پای_ټکی;
     brk_پای_ټکی += اندازه;

     أرجع ret;
}

ساكن فراغ get_دلیلونه (صحيح a, صحيح b)
{
  إذا (a != 1)
    چاپ_کړه("wrong2\n");
  وإلا
    چاپ_کړه("okay\n");
}

فراغ bla(فراغ)
{
  صحيح __ret = 42;
  ({
    إذا (__builtin_expect(!!(0), 0)) {
      إذا (__builtin_expect(!!__ret, 0))
        چاپ_کړه("wrong3\n");
      صحيح x = !!(__ret);
    }
    __ret;
  });
  get_دلیلونه(!!__ret, حجم(__ret));
}

صحيح ext;

فراغ broken_jumpopt (صحيح xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  چاپ_کړه("okay: %d %d\n", xxx, ext);
}

_Bool chk(بینښه اوږد addr, بینښه اوږد حد, بینښه اوږد اندازه)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  إذا (0)
    ret = 0 != (!!(addr > حد - اندازه));
  أرجع 0;
}

صحيح اصلي()
{
  فراغ *r;
  brk_پیل = 1024;
  brk_پای_ټکی = 1024;
  r = extend_brk (4096, 16);
  إذا (!r)
    چاپ_کړه("wrong4\n");
  وإلا
    چاپ_کړه("okay\n");
  bla();
  broken_jumpopt(42);
  أرجع 0;
}

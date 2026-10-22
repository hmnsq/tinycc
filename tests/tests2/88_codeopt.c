/* Check some way in where code suppression caused various
   miscompilations.  */
خارجي صحيح لکو (ثابت حرف *, ...);
تعريفنوع __SIZE_TYPE__ سائيز_t;

سائيز_t brk_شروعات, brk_پڇاڙي;
فراغ * extend_brk(سائيز_t سائيز, سائيز_t align)
{
    سائيز_t نقاب = align - 1;
    فراغ *ret = 0;

     افعل {
	 إذا (__builtin_expect(!!(brk_شروعات == 0), 0))
	   افعل {
	       لکو("wrong1\n");
	   } طالما (0);
     } طالما (0);
     brk_پڇاڙي = (brk_پڇاڙي + نقاب) & ~نقاب;
     ret = (فراغ *)brk_پڇاڙي;
     brk_پڇاڙي += سائيز;

     أرجع ret;
}

ساكن فراغ get_دليلون (صحيح a, صحيح b)
{
  إذا (a != 1)
    لکو("wrong2\n");
  وإلا
    لکو("okay\n");
}

فراغ bla(فراغ)
{
  صحيح __ret = 42;
  ({
    إذا (__builtin_expect(!!(0), 0)) {
      إذا (__builtin_expect(!!__ret, 0))
        لکو("wrong3\n");
      صحيح x = !!(__ret);
    }
    __ret;
  });
  get_دليلون(!!__ret, حجم(__ret));
}

صحيح ext;

فراغ broken_jumpopt (صحيح xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  لکو("okay: %d %d\n", xxx, ext);
}

_Bool chk(بنانشان ڊگهو addr, بنانشان ڊگهو حد_بندي, بنانشان ڊگهو سائيز)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  إذا (0)
    ret = 0 != (!!(addr > حد_بندي - سائيز));
  أرجع 0;
}

صحيح مکيه()
{
  فراغ *r;
  brk_شروعات = 1024;
  brk_پڇاڙي = 1024;
  r = extend_brk (4096, 16);
  إذا (!r)
    لکو("wrong4\n");
  وإلا
    لکو("okay\n");
  bla();
  broken_jumpopt(42);
  أرجع 0;
}

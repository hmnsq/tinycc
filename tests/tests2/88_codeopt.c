/* Check some way in where code suppression caused various
   miscompilations.  */
خارجی صحیح لکھو (ثابت حرف *, ...);
قسمتعریف __SIZE_TYPE__ سائز_t;

سائز_t brk_آغاز, brk_انتہا;
خالی * extend_brk(سائز_t سائز, سائز_t align)
{
    سائز_t نقاب = align - 1;
    خالی *ret = 0;

     کرو {
	 اگر (__builtin_expect(!!(brk_آغاز == 0), 0))
	   کرو {
	       لکھو("wrong1\n");
	   } جب (0);
     } جب (0);
     brk_انتہا = (brk_انتہا + نقاب) & ~نقاب;
     ret = (خالی *)brk_انتہا;
     brk_انتہا += سائز;

     واپس ret;
}

ساکن خالی get_دلائل (صحیح a, صحیح b)
{
  اگر (a != 1)
    لکھو("wrong2\n");
  ورنہ
    لکھو("okay\n");
}

خالی bla(خالی)
{
  صحیح __ret = 42;
  ({
    اگر (__builtin_expect(!!(0), 0)) {
      اگر (__builtin_expect(!!__ret, 0))
        لکھو("wrong3\n");
      صحیح x = !!(__ret);
    }
    __ret;
  });
  get_دلائل(!!__ret, حجم(__ret));
}

صحیح ext;

خالی broken_jumpopt (صحیح xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  لکھو("okay: %d %d\n", xxx, ext);
}

_Bool chk(غیرعلامتی طویل addr, غیرعلامتی طویل حد_بندی, غیرعلامتی طویل سائز)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  اگر (0)
    ret = 0 != (!!(addr > حد_بندی - سائز));
  واپس 0;
}

صحیح مین()
{
  خالی *r;
  brk_آغاز = 1024;
  brk_انتہا = 1024;
  r = extend_brk (4096, 16);
  اگر (!r)
    لکھو("wrong4\n");
  ورنہ
    لکھو("okay\n");
  bla();
  broken_jumpopt(42);
  واپس 0;
}

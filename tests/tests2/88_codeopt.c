/* Check some way in where code suppression caused various
   miscompilations.  */
ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ ਮਾਪ_t;

ਮਾਪ_t brk_ਸ਼ੁਰੂ, brk_ਸਿਰਾ;
ਖਾਲੀ * extend_brk(ਮਾਪ_t ਮਾਪ, ਮਾਪ_t align)
{
    ਮਾਪ_t ਨਕਾਬ = align - 1;
    ਖਾਲੀ *ret = 0;

     ਕਰੋ {
	 ਜੇ (__builtin_expect(!!(brk_ਸ਼ੁਰੂ == 0), 0))
	   ਕਰੋ {
	       ਲਿਖੋ("wrong1\n");
	   } ਜਦੋਂ (0);
     } ਜਦੋਂ (0);
     brk_ਸਿਰਾ = (brk_ਸਿਰਾ + ਨਕਾਬ) & ~ਨਕਾਬ;
     ret = (ਖਾਲੀ *)brk_ਸਿਰਾ;
     brk_ਸਿਰਾ += ਮਾਪ;

     ਵਾਪਸ ret;
}

ਸਥਿਰ ਖਾਲੀ get_ਦਲੀਲਾਂ (ਪੂਰਨ a, ਪੂਰਨ b)
{
  ਜੇ (a != 1)
    ਲਿਖੋ("wrong2\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ("okay\n");
}

ਖਾਲੀ bla(ਖਾਲੀ)
{
  ਪੂਰਨ __ret = 42;
  ({
    ਜੇ (__builtin_expect(!!(0), 0)) {
      ਜੇ (__builtin_expect(!!__ret, 0))
        ਲਿਖੋ("wrong3\n");
      ਪੂਰਨ x = !!(__ret);
    }
    __ret;
  });
  get_ਦਲੀਲਾਂ(!!__ret, ਆਕਾਰ(__ret));
}

ਪੂਰਨ ext;

ਖਾਲੀ broken_jumpopt (ਪੂਰਨ xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  ਲਿਖੋ("okay: %d %d\n", xxx, ext);
}

_Bool chk(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ addr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਹੱਦਬੰਦੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  ਜੇ (0)
    ret = 0 != (!!(addr > ਹੱਦਬੰਦੀ - ਮਾਪ));
  ਵਾਪਸ 0;
}

ਪੂਰਨ ਮੁੱਖ()
{
  ਖਾਲੀ *r;
  brk_ਸ਼ੁਰੂ = 1024;
  brk_ਸਿਰਾ = 1024;
  r = extend_brk (4096, 16);
  ਜੇ (!r)
    ਲਿਖੋ("wrong4\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ("okay\n");
  bla();
  broken_jumpopt(42);
  ਵਾਪਸ 0;
}

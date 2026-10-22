/* Check some way in where code suppression caused various
   miscompilations.  */
బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
రకనిర్వచనం __SIZE_TYPE__ కొలత_t;

కొలత_t brk_ప్రారంభం, brk_చివర;
శూన్య * extend_brk(కొలత_t కొలత, కొలత_t align)
{
    కొలత_t ముసుగు = align - 1;
    శూన్య *ret = 0;

     చేయి {
	 ఒకవేళ (__builtin_expect(!!(brk_ప్రారంభం == 0), 0))
	   చేయి {
	       రాయి("wrong1\n");
	   } అయితే (0);
     } అయితే (0);
     brk_చివర = (brk_చివర + ముసుగు) & ~ముసుగు;
     ret = (శూన్య *)brk_చివర;
     brk_చివర += కొలత;

     తిరిగి ret;
}

స్థిర శూన్య get_వాదనలు (పూర్ణాంకం a, పూర్ణాంకం b)
{
  ఒకవేళ (a != 1)
    రాయి("wrong2\n");
  లేకపోతే
    రాయి("okay\n");
}

శూన్య bla(శూన్య)
{
  పూర్ణాంకం __ret = 42;
  ({
    ఒకవేళ (__builtin_expect(!!(0), 0)) {
      ఒకవేళ (__builtin_expect(!!__ret, 0))
        రాయి("wrong3\n");
      పూర్ణాంకం x = !!(__ret);
    }
    __ret;
  });
  get_వాదనలు(!!__ret, పరిమాణం(__ret));
}

పూర్ణాంకం ext;

శూన్య broken_jumpopt (పూర్ణాంకం xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  రాయి("okay: %d %d\n", xxx, ext);
}

_Bool chk(గుర్తులేని దీర్ఘ addr, గుర్తులేని దీర్ఘ హద్దు, గుర్తులేని దీర్ఘ కొలత)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  ఒకవేళ (0)
    ret = 0 != (!!(addr > హద్దు - కొలత));
  తిరిగి 0;
}

పూర్ణాంకం ప్రధాన()
{
  శూన్య *r;
  brk_ప్రారంభం = 1024;
  brk_చివర = 1024;
  r = extend_brk (4096, 16);
  ఒకవేళ (!r)
    రాయి("wrong4\n");
  లేకపోతే
    రాయి("okay\n");
  bla();
  broken_jumpopt(42);
  తిరిగి 0;
}

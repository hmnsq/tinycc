/* Check some way in where code suppression caused various
   miscompilations.  */
બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
પ્રકારવ્યાખ્યા __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
શૂન્ય * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    શૂન્ય *ret = 0;

     કરો {
	 જો (__builtin_expect(!!(_brk_start == 0), 0))
	   કરો {
	       printf("wrong1\n");
	   } જ્યારે (0);
     } જ્યારે (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (શૂન્ય *)_brk_end;
     _brk_end += size;

     પાછા ret;
}

સ્થિર શૂન્ય get_args (પૂર્ણાંક a, પૂર્ણાંક b)
{
  જો (a != 1)
    printf("wrong2\n");
  નહીંતર
    printf("okay\n");
}

શૂન્ય bla(શૂન્ય)
{
  પૂર્ણાંક __ret = 42;
  ({
    જો (__builtin_expect(!!(0), 0)) {
      જો (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      પૂર્ણાંક x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, કદ(__ret));
}

પૂર્ણાંક ext;

શૂન્ય broken_jumpopt (પૂર્ણાંક xxx)
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
  જો (0)
    ret = 0 != (!!(addr > limit - size));
  પાછા 0;
}

પૂર્ણાંક મુખ્ય()
{
  શૂન્ય *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  જો (!r)
    printf("wrong4\n");
  નહીંતર
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  પાછા 0;
}

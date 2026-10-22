/* Check some way in where code suppression caused various
   miscompilations.  */
ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
തരനിർവചനം __SIZE_TYPE__ size_t;

size_t _brk_start, _brk_end;
ശൂന്യം * extend_brk(size_t size, size_t align)
{
    size_t mask = align - 1;
    ശൂന്യം *ret = 0;

     ചെയ്യുക {
	 എങ്കിൽ (__builtin_expect(!!(_brk_start == 0), 0))
	   ചെയ്യുക {
	       printf("wrong1\n");
	   } ആകുമ്പോൾ (0);
     } ആകുമ്പോൾ (0);
     _brk_end = (_brk_end + mask) & ~mask;
     ret = (ശൂന്യം *)_brk_end;
     _brk_end += size;

     തിരികെ ret;
}

സ്ഥിതം ശൂന്യം get_args (പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
  എങ്കിൽ (a != 1)
    printf("wrong2\n");
  അല്ലെങ്കിൽ
    printf("okay\n");
}

ശൂന്യം bla(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ __ret = 42;
  ({
    എങ്കിൽ (__builtin_expect(!!(0), 0)) {
      എങ്കിൽ (__builtin_expect(!!__ret, 0))
        printf("wrong3\n");
      പൂർണ്ണസംഖ്യ x = !!(__ret);
    }
    __ret;
  });
  get_args(!!__ret, വലുപ്പം(__ret));
}

പൂർണ്ണസംഖ്യ ext;

ശൂന്യം broken_jumpopt (പൂർണ്ണസംഖ്യ xxx)
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
  എങ്കിൽ (0)
    ret = 0 != (!!(addr > limit - size));
  തിരികെ 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
  ശൂന്യം *r;
  _brk_start = 1024;
  _brk_end = 1024;
  r = extend_brk (4096, 16);
  എങ്കിൽ (!r)
    printf("wrong4\n");
  അല്ലെങ്കിൽ
    printf("okay\n");
  bla();
  broken_jumpopt(42);
  തിരികെ 0;
}

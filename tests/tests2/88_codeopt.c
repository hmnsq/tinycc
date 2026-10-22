/* Check some way in where code suppression caused various
   miscompilations.  */
बाह्य पूर्णाङ्क प्रारूप_लिख (ध्रुव वर्ण *, ...);
प्रकारनिर्देश __SIZE_TYPE__ आकार_t;

आकार_t _brk_start, brk_अन्तः;
शून्य * extend_brk(आकार_t आकार, आकार_t align)
{
    आकार_t आवरणम् = align - 1;
    शून्य *ret = 0;

     कुरु {
	 यदि (__builtin_expect(!!(_brk_start == 0), 0))
	   कुरु {
	       प्रारूप_लिख("wrong1\n");
	   } यावत् (0);
     } यावत् (0);
     brk_अन्तः = (brk_अन्तः + आवरणम्) & ~आवरणम्;
     ret = (शून्य *)brk_अन्तः;
     brk_अन्तः += आकार;

     प्रत्यागम ret;
}

स्थिर शून्य get_तर्काः (पूर्णाङ्क a, पूर्णाङ्क b)
{
  यदि (a != 1)
    प्रारूप_लिख("wrong2\n");
  अन्यथा
    प्रारूप_लिख("okay\n");
}

शून्य bla(शून्य)
{
  पूर्णाङ्क __ret = 42;
  ({
    यदि (__builtin_expect(!!(0), 0)) {
      यदि (__builtin_expect(!!__ret, 0))
        प्रारूप_लिख("wrong3\n");
      पूर्णाङ्क x = !!(__ret);
    }
    __ret;
  });
  get_तर्काः(!!__ret, परिमाण(__ret));
}

पूर्णाङ्क ext;

शून्य broken_jumpopt (पूर्णाङ्क xxx)
{
  /* This was broken in 8227db3a2 by code suppression during suppressed
     code :) */
  ext = (xxx || 1) || ((xxx && 1) || 1);
  प्रारूप_लिख("okay: %d %d\n", xxx, ext);
}

_Bool chk(अचिह्नित दीर्घ addr, अचिह्नित दीर्घ सीमा, अचिह्नित दीर्घ आकार)
{
  _Bool ret;
  /* This just needs to compile, no runtime test.  (And it doesn't compile
     only with certain internal checking added that's not committed).  */
  यदि (0)
    ret = 0 != (!!(addr > सीमा - आकार));
  प्रत्यागम 0;
}

पूर्णाङ्क मुख्यम्()
{
  शून्य *r;
  _brk_start = 1024;
  brk_अन्तः = 1024;
  r = extend_brk (4096, 16);
  यदि (!r)
    प्रारूप_लिख("wrong4\n");
  अन्यथा
    प्रारूप_लिख("okay\n");
  bla();
  broken_jumpopt(42);
  प्रत्यागम 0;
}

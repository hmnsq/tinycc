#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   printf("#include test\n");

#എങ്കിൽ 1
#എങ്കിൽ 0
   printf("a\n");
#അല്ലെങ്കിൽ
   printf("b\n");
#endif
#അല്ലെങ്കിൽ
#എങ്കിൽ 0
   printf("c\n");
#അല്ലെങ്കിൽ
   printf("d\n");
#endif
#endif

#എങ്കിൽ 0
#എങ്കിൽ 1
   printf("e\n");
#അല്ലെങ്കിൽ
   printf("f\n");
#endif
#അല്ലെങ്കിൽ
#എങ്കിൽ 1
   printf("g\n");
#അല്ലെങ്കിൽ
   printf("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   printf("i\n");
#അല്ലെങ്കിൽ
   printf("j\n");
#endif
#അല്ലെങ്കിൽ
#ifdef DEF
   printf("k\n");
#അല്ലെങ്കിൽ
   printf("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   printf("m\n");
#അല്ലെങ്കിൽ
   printf("n\n");
#endif
#അല്ലെങ്കിൽ
#ifndef DEF
   printf("o\n");
#അല്ലെങ്കിൽ
   printf("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#എങ്കിൽ ONE
#എങ്കിൽ ZERO
   printf("q\n");
#അല്ലെങ്കിൽ
   printf("r\n");
#endif
#അല്ലെങ്കിൽ
#എങ്കിൽ ZERO
   printf("s\n");
#അല്ലെങ്കിൽ
   printf("t\n");
#endif
#endif

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
   म_लिखो("#include test\n");

#जर 1
#जर 0
   म_लिखो("a\n");
#अन्यथा
   म_लिखो("b\n");
#endif
#अन्यथा
#जर 0
   म_लिखो("c\n");
#अन्यथा
   म_लिखो("d\n");
#endif
#endif

#जर 0
#जर 1
   म_लिखो("e\n");
#अन्यथा
   म_लिखो("f\n");
#endif
#अन्यथा
#जर 1
   म_लिखो("g\n");
#अन्यथा
   म_लिखो("h\n");
#endif
#endif

#define DEF

#ifdef DEF
#ifdef DEF
   म_लिखो("i\n");
#अन्यथा
   म_लिखो("j\n");
#endif
#अन्यथा
#ifdef DEF
   म_लिखो("k\n");
#अन्यथा
   म_लिखो("l\n");
#endif
#endif

#ifndef DEF
#ifndef DEF
   म_लिखो("m\n");
#अन्यथा
   म_लिखो("n\n");
#endif
#अन्यथा
#ifndef DEF
   म_लिखो("o\n");
#अन्यथा
   म_लिखो("p\n");
#endif
#endif

#define ONE 1
#define ZERO 0

#जर ONE
#जर ZERO
   म_लिखो("q\n");
#अन्यथा
   म_लिखो("r\n");
#endif
#अन्यथा
#जर ZERO
   म_लिखो("s\n");
#अन्यथा
   म_लिखो("t\n");
#endif
#endif

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

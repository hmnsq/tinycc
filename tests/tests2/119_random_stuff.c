#अन्तर्भाव <stdio.h>

संरचना big_struct { अक्षर a[262144]; };

स्थिर स्थिरांक अक्षर str[] = "abcdefghijklmnopqrstuvwxyz";

शून्य tst_branch(शून्य)
{
  म_लिखो("tst_branch --");
  जा *&&a; 
  म_लिखो (" dummy");
a: ;
  म_लिखो(" --\n");
}

शून्य tst_void_ptr(शून्य *pv, पूर्णांक i) 
{
  i ? *pv : *pv; // dr106
}

शून्य tst_shift(शून्य)
{
  पूर्णांक i = 1;
  दीर्घ दीर्घ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#जर !defined(_WIN32)
#अन्तर्भाव <sys/mman.h>

शून्य tst_const_addr(शून्य)
{
  शून्य *addr = mmap ((शून्य *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  जर (addr != (शून्य *) -1) {
    *(पूर्णांक *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

संरचना zero_struct {};

संरचना zero_struct tst_zero_struct(शून्य)
{
  संरचना zero_struct ret;
  परत ret;
}

संरचना big_struct tst_big(संरचना big_struct tst)
{
   परत tst;
}

शून्य tst_adr (पूर्णांक (*fp)(अक्षर *, स्थिरांक अक्षर *, ...))
{
  अक्षर buf[10];
  (*fp)(buf, "%.0f", 5.0);
  म_लिखो("tst_adr %s\n", buf);
}

पूर्णांक tst(शून्य)
{
  दीर्घ दीर्घ मूल्य = 3;
  परत -मूल्य;
}

शून्य tst_compare(शून्य)
{
  /* This failed on risc64 */
  म_लिखो ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
संरचना S { पूर्णांक d:24; पूर्णांक f:14; } i, j;
#pragma pack()

शून्य tst_pack (शून्य)
{
  i.f = 5; j.f = 5;
  म_लिखो("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

शून्य tst_cast(शून्य)
{
  चिन्हित अक्षर c = (चिन्हित अक्षर) 0xaaaaaaaa;
  पूर्णांक r = (अचिन्हित लघु) c ^ (चिन्हित अक्षर) 0x99999999;
  म_लिखो ("schar to ushort cast: %x\n", r);
}

संरचना {
    पूर्णांक (*print)(स्थिरांक अक्षर *format, ...);
} tst_indir = {
    म_लिखो
};

शून्य tst_indir_func(शून्य)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

संरचना V {
  पूर्णांक x, y, z;
};

संरचना V vec(शून्य)
{
  परत (संरचना V) { 1, 2, 3 };
}

शून्य func(दशांश f, संरचना V v)
{
  म_लिखो("%g\n", f);
}

शून्य tst_struct_return_align(शून्य)
{
  दशांश d = 5.0f;
  func(d, vec());
}

पूर्णांक
main (शून्य)
{
  संरचना big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#जर !defined(_WIN32)
  tst_const_addr();
#endif
  tst_zero_struct();
  tst_big(big);
  tst_adr(&प्र_लिखो);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}

#समावेश <stdio.h>

काष्ठा big_struct { अक्षर a[262144]; };

अटल स्थिर अक्षर str[] = "abcdefghijklmnopqrstuvwxyz";

व्योम tst_branch(व्योम)
{
  म_लिखो("tst_branch --");
  जाओ *&&a; 
  म_लिखो (" dummy");
a: ;
  म_लिखो(" --\n");
}

व्योम tst_void_ptr(व्योम *pv, पूर्णांक i) 
{
  i ? *pv : *pv; // dr106
}

व्योम tst_shift(व्योम)
{
  पूर्णांक i = 1;
  दीर्घ दीर्घ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#अगर !defined(_WIN32)
#समावेश <sys/mman.h>

व्योम tst_const_addr(व्योम)
{
  व्योम *addr = mmap ((व्योम *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  अगर (addr != (व्योम *) -1) {
    *(पूर्णांक *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#पूर्ण_अगर

काष्ठा zero_struct {};

काष्ठा zero_struct tst_zero_struct(व्योम)
{
  काष्ठा zero_struct ret;
  वापस ret;
}

काष्ठा big_struct tst_big(काष्ठा big_struct tst)
{
   वापस tst;
}

व्योम tst_adr (पूर्णांक (*fp)(अक्षर *, स्थिर अक्षर *, ...))
{
  अक्षर buf[10];
  (*fp)(buf, "%.0f", 5.0);
  म_लिखो("tst_adr %s\n", buf);
}

पूर्णांक tst(व्योम)
{
  दीर्घ दीर्घ मूल्य = 3;
  वापस -मूल्य;
}

व्योम tst_compare(व्योम)
{
  /* This failed on risc64 */
  म_लिखो ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#आशय pack(1)
काष्ठा S { पूर्णांक d:24; पूर्णांक f:14; } i, j;
#आशय pack()

व्योम tst_pack (व्योम)
{
  i.f = 5; j.f = 5;
  म_लिखो("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

व्योम tst_cast(व्योम)
{
  चिन्हित अक्षर c = (चिन्हित अक्षर) 0xaaaaaaaa;
  पूर्णांक r = (अचिन्हित लघु) c ^ (चिन्हित अक्षर) 0x99999999;
  म_लिखो ("schar to ushort cast: %x\n", r);
}

काष्ठा {
    पूर्णांक (*print)(स्थिर अक्षर *format, ...);
} tst_indir = {
    म_लिखो
};

व्योम tst_indir_func(व्योम)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

काष्ठा V {
  पूर्णांक x, y, z;
};

काष्ठा V vec(व्योम)
{
  वापस (काष्ठा V) { 1, 2, 3 };
}

व्योम func(भग्न f, काष्ठा V v)
{
  म_लिखो("%g\n", f);
}

व्योम tst_struct_return_align(व्योम)
{
  भग्न d = 5.0f;
  func(d, vec());
}

पूर्णांक
मुख्य (व्योम)
{
  काष्ठा big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#अगर !defined(_WIN32)
  tst_const_addr();
#पूर्ण_अगर
  tst_zero_struct();
  tst_big(big);
  tst_adr(&प्र_लिखो);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}

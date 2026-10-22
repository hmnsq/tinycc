#अन्तर्भाव <stdio.h>

संरचना big_struct { वर्ण a[262144]; };

स्थिर अचर वर्ण str[] = "abcdefghijklmnopqrstuvwxyz";

शून्य tst_branch(शून्य)
{
  म_लिखो("tst_branch --");
  गच्छ *&&a; 
  म_लिखो (" dummy");
a: ;
  म_लिखो(" --\n");
}

शून्य tst_void_ptr(शून्य *pv, पूर्णाङ्क i) 
{
  i ? *pv : *pv; // dr106
}

शून्य tst_shift(शून्य)
{
  पूर्णाङ्क i = 1;
  दीर्घ दीर्घ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#यदि !defined(_WIN32)
#अन्तर्भाव <sys/mman.h>

शून्य tst_const_addr(शून्य)
{
  शून्य *addr = mmap ((शून्य *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  यदि (addr != (शून्य *) -1) {
    *(पूर्णाङ्क *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

संरचना zero_struct {};

संरचना zero_struct tst_zero_struct(शून्य)
{
  संरचना zero_struct ret;
  फर्काऊ ret;
}

संरचना big_struct tst_big(संरचना big_struct tst)
{
   फर्काऊ tst;
}

शून्य tst_adr (पूर्णाङ्क (*fp)(वर्ण *, अचर वर्ण *, ...))
{
  वर्ण buf[10];
  (*fp)(buf, "%.0f", 5.0);
  म_लिखो("tst_adr %s\n", buf);
}

पूर्णाङ्क tst(शून्य)
{
  दीर्घ दीर्घ मान = 3;
  फर्काऊ -मान;
}

शून्य tst_compare(शून्य)
{
  /* This failed on risc64 */
  म_लिखो ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
संरचना S { पूर्णाङ्क d:24; पूर्णाङ्क f:14; } i, j;
#pragma pack()

शून्य tst_pack (शून्य)
{
  i.f = 5; j.f = 5;
  म_लिखो("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

शून्य tst_cast(शून्य)
{
  चिन्हित वर्ण c = (चिन्हित वर्ण) 0xaaaaaaaa;
  पूर्णाङ्क r = (अचिन्हित लघु) c ^ (चिन्हित वर्ण) 0x99999999;
  म_लिखो ("schar to ushort cast: %x\n", r);
}

संरचना {
    पूर्णाङ्क (*print)(अचर वर्ण *format, ...);
} tst_indir = {
    म_लिखो
};

शून्य tst_indir_func(शून्य)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

संरचना V {
  पूर्णाङ्क x, y, z;
};

संरचना V vec(शून्य)
{
  फर्काऊ (संरचना V) { 1, 2, 3 };
}

शून्य func(भिन्न f, संरचना V v)
{
  म_लिखो("%g\n", f);
}

शून्य tst_struct_return_align(शून्य)
{
  भिन्न d = 5.0f;
  func(d, vec());
}

पूर्णाङ्क
main (शून्य)
{
  संरचना big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#यदि !defined(_WIN32)
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

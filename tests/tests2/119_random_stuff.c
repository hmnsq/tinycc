#अन्तर्भाव <stdio.h>

संरचना big_struct { वर्ण a[262144]; };

स्थिर ध्रुव वर्ण str[] = "abcdefghijklmnopqrstuvwxyz";

शून्य tst_branch(शून्य)
{
  प्रारूप_लिख("tst_branch --");
  गच्छ *&&a; 
  प्रारूप_लिख (" dummy");
a: ;
  प्रारूप_लिख(" --\n");
}

शून्य tst_void_ptr(शून्य *pv, पूर्णाङ्क i) 
{
  i ? *pv : *pv; // dr106
}

शून्य tst_सरणम्(शून्य)
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
#यदि_अन्तः

संरचना zero_struct {};

संरचना zero_struct tst_zero_struct(शून्य)
{
  संरचना zero_struct ret;
  प्रत्यागम ret;
}

संरचना big_struct tst_big(संरचना big_struct tst)
{
   प्रत्यागम tst;
}

शून्य tst_adr (पूर्णाङ्क (*fp)(वर्ण *, ध्रुव वर्ण *, ...))
{
  वर्ण buf[10];
  (*fp)(buf, "%.0f", 5.0);
  प्रारूप_लिख("tst_adr %s\n", buf);
}

पूर्णाङ्क tst(शून्य)
{
  दीर्घ दीर्घ मानम् = 3;
  प्रत्यागम -मानम्;
}

शून्य tst_compare(शून्य)
{
  /* This failed on risc64 */
  प्रारूप_लिख ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#निर्देशः pack(1)
संरचना S { पूर्णाङ्क d:24; पूर्णाङ्क f:14; } i, j;
#निर्देशः pack()

शून्य tst_pack (शून्य)
{
  i.f = 5; j.f = 5;
  प्रारूप_लिख("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

शून्य tst_cast(शून्य)
{
  चिह्नित वर्ण c = (चिह्नित वर्ण) 0xaaaaaaaa;
  पूर्णाङ्क r = (अचिह्नित ह्रस्व) c ^ (चिह्नित वर्ण) 0x99999999;
  प्रारूप_लिख ("schar to ushort cast: %x\n", r);
}

संरचना {
    पूर्णाङ्क (*print)(ध्रुव वर्ण *format, ...);
} tst_indir = {
    प्रारूप_लिख
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
  प्रत्यागम (संरचना V) { 1, 2, 3 };
}

शून्य func(भिन्न f, संरचना V v)
{
  प्रारूप_लिख("%g\n", f);
}

शून्य tst_struct_return_align(शून्य)
{
  भिन्न d = 5.0f;
  func(d, vec());
}

पूर्णाङ्क
मुख्यम् (शून्य)
{
  संरचना big_struct big;

  tst_branch();
  tst_सरणम्();
  tst_void_ptr(&big.a[0], 0);
#यदि !defined(_WIN32)
  tst_const_addr();
#यदि_अन्तः
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}

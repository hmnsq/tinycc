#അന്തര്ഭാവ <stdio.h>

ഘടന big_struct { അക്ഷരം a[262144]; };

സ്ഥിതം സ്ഥിരം അക്ഷരം str[] = "abcdefghijklmnopqrstuvwxyz";

ശൂന്യം tst_branch(ശൂന്യം)
{
  printf("tst_branch --");
  പോകുക *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

ശൂന്യം tst_void_ptr(ശൂന്യം *pv, പൂർണ്ണസംഖ്യ i) 
{
  i ? *pv : *pv; // dr106
}

ശൂന്യം tst_shift(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#എങ്കിൽ !defined(_WIN32)
#അന്തര്ഭാവ <sys/mman.h>

ശൂന്യം tst_const_addr(ശൂന്യം)
{
  ശൂന്യം *addr = mmap ((ശൂന്യം *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  എങ്കിൽ (addr != (ശൂന്യം *) -1) {
    *(പൂർണ്ണസംഖ്യ *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

ഘടന zero_struct {};

ഘടന zero_struct tst_zero_struct(ശൂന്യം)
{
  ഘടന zero_struct ret;
  തിരികെ ret;
}

ഘടന big_struct tst_big(ഘടന big_struct tst)
{
   തിരികെ tst;
}

ശൂന്യം tst_adr (പൂർണ്ണസംഖ്യ (*fp)(അക്ഷരം *, സ്ഥിരം അക്ഷരം *, ...))
{
  അക്ഷരം buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

പൂർണ്ണസംഖ്യ tst(ശൂന്യം)
{
  long long മൂല്യം = 3;
  തിരികെ -മൂല്യം;
}

ശൂന്യം tst_compare(ശൂന്യം)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
ഘടന S { പൂർണ്ണസംഖ്യ d:24; പൂർണ്ണസംഖ്യ f:14; } i, j;
#pragma pack()

ശൂന്യം tst_pack (ശൂന്യം)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

ശൂന്യം tst_cast(ശൂന്യം)
{
  signed അക്ഷരം c = (signed അക്ഷരം) 0xaaaaaaaa;
  പൂർണ്ണസംഖ്യ r = (unsigned short) c ^ (signed അക്ഷരം) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

ഘടന {
    പൂർണ്ണസംഖ്യ (*print)(സ്ഥിരം അക്ഷരം *format, ...);
} tst_indir = {
    printf
};

ശൂന്യം tst_indir_func(ശൂന്യം)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ഘടന V {
  പൂർണ്ണസംഖ്യ x, y, z;
};

ഘടന V vec(ശൂന്യം)
{
  തിരികെ (ഘടന V) { 1, 2, 3 };
}

ശൂന്യം func(ദശാംശം f, ഘടന V v)
{
  printf("%g\n", f);
}

ശൂന്യം tst_struct_return_align(ശൂന്യം)
{
  ദശാംശം d = 5.0f;
  func(d, vec());
}

പൂർണ്ണസംഖ്യ
പ്രധാന (ശൂന്യം)
{
  ഘടന big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#എങ്കിൽ !defined(_WIN32)
  tst_const_addr();
#endif
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}

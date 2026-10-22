#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂରଚନା big_struct { ଅକ୍ଷର a[262144]; };

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର str[] = "abcdefghijklmnopqrstuvwxyz";

ଶୂନ୍ୟ tst_branch(ଶୂନ୍ୟ)
{
  printf("tst_branch --");
  ଯାଅ *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

ଶୂନ୍ୟ tst_void_ptr(ଶୂନ୍ୟ *pv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା i) 
{
  i ? *pv : *pv; // dr106
}

ଶୂନ୍ୟ tst_shift(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ଯଦି !defined(_WIN32)
#ଅନ୍ତର୍ଭାଵ <sys/mman.h>

ଶୂନ୍ୟ tst_const_addr(ଶୂନ୍ୟ)
{
  ଶୂନ୍ୟ *addr = mmap ((ଶୂନ୍ୟ *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ଯଦି (addr != (ଶୂନ୍ୟ *) -1) {
    *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

ସଂରଚନା zero_struct {};

ସଂରଚନା zero_struct tst_zero_struct(ଶୂନ୍ୟ)
{
  ସଂରଚନା zero_struct ret;
  ଫେରନ୍ତୁ ret;
}

ସଂରଚନା big_struct tst_big(ସଂରଚନା big_struct tst)
{
   ଫେରନ୍ତୁ tst;
}

ଶୂନ୍ୟ tst_adr (ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*fp)(ଅକ୍ଷର *, ଅଚଳ ଅକ୍ଷର *, ...))
{
  ଅକ୍ଷର buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା tst(ଶୂନ୍ୟ)
{
  long long ମୂଲ୍ୟ = 3;
  ଫେରନ୍ତୁ -ମୂଲ୍ୟ;
}

ଶୂନ୍ୟ tst_compare(ଶୂନ୍ୟ)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
ସଂରଚନା S { ପୂର୍ଣ୍ଣସଂଖ୍ୟା d:24; ପୂର୍ଣ୍ଣସଂଖ୍ୟା f:14; } i, j;
#pragma pack()

ଶୂନ୍ୟ tst_pack (ଶୂନ୍ୟ)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

ଶୂନ୍ୟ tst_cast(ଶୂନ୍ୟ)
{
  signed ଅକ୍ଷର c = (signed ଅକ୍ଷର) 0xaaaaaaaa;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = (unsigned short) c ^ (signed ଅକ୍ଷର) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*print)(ଅଚଳ ଅକ୍ଷର *format, ...);
} tst_indir = {
    printf
};

ଶୂନ୍ୟ tst_indir_func(ଶୂନ୍ୟ)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ସଂରଚନା V {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, y, z;
};

ସଂରଚନା V vec(ଶୂନ୍ୟ)
{
  ଫେରନ୍ତୁ (ସଂରଚନା V) { 1, 2, 3 };
}

ଶୂନ୍ୟ func(ଦଶମିକ f, ସଂରଚନା V v)
{
  printf("%g\n", f);
}

ଶୂନ୍ୟ tst_struct_return_align(ଶୂନ୍ୟ)
{
  ଦଶମିକ d = 5.0f;
  func(d, vec());
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
  ସଂରଚନା big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#ଯଦି !defined(_WIN32)
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

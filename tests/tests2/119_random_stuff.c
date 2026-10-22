#অন্তর্ভাৱ <stdio.h>

সংরচনা big_struct { ৱর্ণ a[262144]; };

স্থির ধ্রুৱ ৱর্ণ str[] = "abcdefghijklmnopqrstuvwxyz";

শূন্য tst_branch(শূন্য)
{
  printf("tst_branch --");
  গচ্ছ *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

শূন্য tst_void_ptr(শূন্য *pv, পূর্ণাঙ্ক i) 
{
  i ? *pv : *pv; // dr106
}

শূন্য tst_shift(শূন্য)
{
  পূর্ণাঙ্ক i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#যদি !defined(_WIN32)
#অন্তর্ভাৱ <sys/mman.h>

শূন্য tst_const_addr(শূন্য)
{
  শূন্য *addr = mmap ((শূন্য *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  যদি (addr != (শূন্য *) -1) {
    *(পূর্ণাঙ্ক *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

সংরচনা zero_struct {};

সংরচনা zero_struct tst_zero_struct(শূন্য)
{
  সংরচনা zero_struct ret;
  ঘূৰাই ret;
}

সংরচনা big_struct tst_big(সংরচনা big_struct tst)
{
   ঘূৰাই tst;
}

শূন্য tst_adr (পূর্ণাঙ্ক (*fp)(ৱর্ণ *, ধ্রুৱ ৱর্ণ *, ...))
{
  ৱর্ণ buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

পূর্ণাঙ্ক tst(শূন্য)
{
  long long মান = 3;
  ঘূৰাই -মান;
}

শূন্য tst_compare(শূন্য)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
সংরচনা S { পূর্ণাঙ্ক d:24; পূর্ণাঙ্ক f:14; } i, j;
#pragma pack()

শূন্য tst_pack (শূন্য)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

শূন্য tst_cast(শূন্য)
{
  signed ৱর্ণ c = (signed ৱর্ণ) 0xaaaaaaaa;
  পূর্ণাঙ্ক r = (unsigned short) c ^ (signed ৱর্ণ) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

সংরচনা {
    পূর্ণাঙ্ক (*print)(ধ্রুৱ ৱর্ণ *format, ...);
} tst_indir = {
    printf
};

শূন্য tst_indir_func(শূন্য)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

সংরচনা V {
  পূর্ণাঙ্ক x, y, z;
};

সংরচনা V vec(শূন্য)
{
  ঘূৰাই (সংরচনা V) { 1, 2, 3 };
}

শূন্য func(ভিন্ন f, সংরচনা V v)
{
  printf("%g\n", f);
}

শূন্য tst_struct_return_align(শূন্য)
{
  ভিন্ন d = 5.0f;
  func(d, vec());
}

পূর্ণাঙ্ক
main (শূন্য)
{
  সংরচনা big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#যদি !defined(_WIN32)
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

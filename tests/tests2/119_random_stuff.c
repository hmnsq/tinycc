#অন্তর্ভাব <stdio.h>

কাঠামো big_struct { অক্ষর a[262144]; };

স্থির ধ্রুবক অক্ষর str[] = "abcdefghijklmnopqrstuvwxyz";

শূন্য tst_branch(শূন্য)
{
  printf("tst_branch --");
  যাও *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

শূন্য tst_void_ptr(শূন্য *pv, পূর্ণসংখ্যা i) 
{
  i ? *pv : *pv; // dr106
}

শূন্য tst_shift(শূন্য)
{
  পূর্ণসংখ্যা i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#যদি !defined(_WIN32)
#অন্তর্ভাব <sys/mman.h>

শূন্য tst_const_addr(শূন্য)
{
  শূন্য *addr = mmap ((শূন্য *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  যদি (addr != (শূন্য *) -1) {
    *(পূর্ণসংখ্যা *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

কাঠামো zero_struct {};

কাঠামো zero_struct tst_zero_struct(শূন্য)
{
  কাঠামো zero_struct ret;
  ফেরত ret;
}

কাঠামো big_struct tst_big(কাঠামো big_struct tst)
{
   ফেরত tst;
}

শূন্য tst_adr (পূর্ণসংখ্যা (*fp)(অক্ষর *, ধ্রুবক অক্ষর *, ...))
{
  অক্ষর buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

পূর্ণসংখ্যা tst(শূন্য)
{
  long long মান = 3;
  ফেরত -মান;
}

শূন্য tst_compare(শূন্য)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
কাঠামো S { পূর্ণসংখ্যা d:24; পূর্ণসংখ্যা f:14; } i, j;
#pragma pack()

শূন্য tst_pack (শূন্য)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

শূন্য tst_cast(শূন্য)
{
  signed অক্ষর c = (signed অক্ষর) 0xaaaaaaaa;
  পূর্ণসংখ্যা r = (unsigned short) c ^ (signed অক্ষর) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

কাঠামো {
    পূর্ণসংখ্যা (*print)(ধ্রুবক অক্ষর *format, ...);
} tst_indir = {
    printf
};

শূন্য tst_indir_func(শূন্য)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

কাঠামো V {
  পূর্ণসংখ্যা x, y, z;
};

কাঠামো V vec(শূন্য)
{
  ফেরত (কাঠামো V) { 1, 2, 3 };
}

শূন্য func(দশমিক f, কাঠামো V v)
{
  printf("%g\n", f);
}

শূন্য tst_struct_return_align(শূন্য)
{
  দশমিক d = 5.0f;
  func(d, vec());
}

পূর্ণসংখ্যা
প্রধান (শূন্য)
{
  কাঠামো big_struct big;

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

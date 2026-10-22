#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಂರಚನಾ big_struct { ವರ್ಣ a[262144]; };

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ str[] = "abcdefghijklmnopqrstuvwxyz";

ಶೂನ್ಯ tst_branch(ಶೂನ್ಯ)
{
  printf("tst_branch --");
  ಗಚ್ಛ *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

ಶೂನ್ಯ tst_void_ptr(ಶೂನ್ಯ *pv, ಪೂರ್ಣಾಙ್ಕ i) 
{
  i ? *pv : *pv; // dr106
}

ಶೂನ್ಯ tst_shift(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ಯದಿ !defined(_WIN32)
#ಅನ್ತರ್ಭಾವ <sys/mman.h>

ಶೂನ್ಯ tst_const_addr(ಶೂನ್ಯ)
{
  ಶೂನ್ಯ *addr = mmap ((ಶೂನ್ಯ *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ಯದಿ (addr != (ಶೂನ್ಯ *) -1) {
    *(ಪೂರ್ಣಾಙ್ಕ *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

ಸಂರಚನಾ zero_struct {};

ಸಂರಚನಾ zero_struct tst_zero_struct(ಶೂನ್ಯ)
{
  ಸಂರಚನಾ zero_struct ret;
  ಪ್ರತ್ಯಾಗಮ ret;
}

ಸಂರಚನಾ big_struct tst_big(ಸಂರಚನಾ big_struct tst)
{
   ಪ್ರತ್ಯಾಗಮ tst;
}

ಶೂನ್ಯ tst_adr (ಪೂರ್ಣಾಙ್ಕ (*fp)(ವರ್ಣ *, ಧ್ರುವ ವರ್ಣ *, ...))
{
  ವರ್ಣ buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

ಪೂರ್ಣಾಙ್ಕ tst(ಶೂನ್ಯ)
{
  long long ಮೌಲ್ಯ = 3;
  ಪ್ರತ್ಯಾಗಮ -ಮೌಲ್ಯ;
}

ಶೂನ್ಯ tst_compare(ಶೂನ್ಯ)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
ಸಂರಚನಾ S { ಪೂರ್ಣಾಙ್ಕ d:24; ಪೂರ್ಣಾಙ್ಕ f:14; } i, j;
#pragma pack()

ಶೂನ್ಯ tst_pack (ಶೂನ್ಯ)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

ಶೂನ್ಯ tst_cast(ಶೂನ್ಯ)
{
  signed ವರ್ಣ c = (signed ವರ್ಣ) 0xaaaaaaaa;
  ಪೂರ್ಣಾಙ್ಕ r = (unsigned short) c ^ (signed ವರ್ಣ) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ (*print)(ಧ್ರುವ ವರ್ಣ *format, ...);
} tst_indir = {
    printf
};

ಶೂನ್ಯ tst_indir_func(ಶೂನ್ಯ)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ಸಂರಚನಾ V {
  ಪೂರ್ಣಾಙ್ಕ x, y, z;
};

ಸಂರಚನಾ V vec(ಶೂನ್ಯ)
{
  ಪ್ರತ್ಯಾಗಮ (ಸಂರಚನಾ V) { 1, 2, 3 };
}

ಶೂನ್ಯ func(ಭಿನ್ನ f, ಸಂರಚನಾ V v)
{
  printf("%g\n", f);
}

ಶೂನ್ಯ tst_struct_return_align(ಶೂನ್ಯ)
{
  ಭಿನ್ನ d = 5.0f;
  func(d, vec());
}

ಪೂರ್ಣಾಙ್ಕ
main (ಶೂನ್ಯ)
{
  ಸಂರಚನಾ big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#ಯದಿ !defined(_WIN32)
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

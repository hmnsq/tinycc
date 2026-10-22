#ಅನ್ತರ್ಭಾವ <stdio.h>

ರಚನೆ big_struct { ಅಕ್ಷರ a[262144]; };

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ str[] = "abcdefghijklmnopqrstuvwxyz";

ಶೂನ್ಯ tst_branch(ಶೂನ್ಯ)
{
  ಬರೆ("tst_branch --");
  ಹೋಗು *&&a; 
  ಬರೆ (" dummy");
a: ;
  ಬರೆ(" --\n");
}

ಶೂನ್ಯ tst_void_ptr(ಶೂನ್ಯ *pv, ಪೂರ್ಣಾಂಕ i) 
{
  i ? *pv : *pv; // dr106
}

ಶೂನ್ಯ tst_ಸರಿಸು(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i = 1;
  ದೀರ್ಘ ದೀರ್ಘ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ಆದರೆ !defined(_WIN32)
#ಅನ್ತರ್ಭಾವ <sys/mman.h>

ಶೂನ್ಯ tst_const_addr(ಶೂನ್ಯ)
{
  ಶೂನ್ಯ *addr = mmap ((ಶೂನ್ಯ *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ಆದರೆ (addr != (ಶೂನ್ಯ *) -1) {
    *(ಪೂರ್ಣಾಂಕ *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#ಆದರೆ_ಅಂತ್ಯ

ರಚನೆ zero_struct {};

ರಚನೆ zero_struct tst_zero_struct(ಶೂನ್ಯ)
{
  ರಚನೆ zero_struct ret;
  ಹಿಂತಿರುಗಿ ret;
}

ರಚನೆ big_struct tst_big(ರಚನೆ big_struct tst)
{
   ಹಿಂತಿರುಗಿ tst;
}

ಶೂನ್ಯ tst_adr (ಪೂರ್ಣಾಂಕ (*fp)(ಅಕ್ಷರ *, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...))
{
  ಅಕ್ಷರ buf[10];
  (*fp)(buf, "%.0f", 5.0);
  ಬರೆ("tst_adr %s\n", buf);
}

ಪೂರ್ಣಾಂಕ tst(ಶೂನ್ಯ)
{
  ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ = 3;
  ಹಿಂತಿರುಗಿ -ಮೌಲ್ಯ;
}

ಶೂನ್ಯ tst_compare(ಶೂನ್ಯ)
{
  /* This failed on risc64 */
  ಬರೆ ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#ಸೂಚನೆ pack(1)
ರಚನೆ S { ಪೂರ್ಣಾಂಕ d:24; ಪೂರ್ಣಾಂಕ f:14; } i, j;
#ಸೂಚನೆ pack()

ಶೂನ್ಯ tst_pack (ಶೂನ್ಯ)
{
  i.f = 5; j.f = 5;
  ಬರೆ("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

ಶೂನ್ಯ tst_cast(ಶೂನ್ಯ)
{
  ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ c = (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ) 0xaaaaaaaa;
  ಪೂರ್ಣಾಂಕ r = (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ) c ^ (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ) 0x99999999;
  ಬರೆ ("schar to ushort cast: %x\n", r);
}

ರಚನೆ {
    ಪೂರ್ಣಾಂಕ (*print)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
} tst_indir = {
    ಬರೆ
};

ಶೂನ್ಯ tst_indir_func(ಶೂನ್ಯ)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ರಚನೆ V {
  ಪೂರ್ಣಾಂಕ x, y, z;
};

ರಚನೆ V vec(ಶೂನ್ಯ)
{
  ಹಿಂತಿರುಗಿ (ರಚನೆ V) { 1, 2, 3 };
}

ಶೂನ್ಯ func(ದಶಮಾಂಶ f, ರಚನೆ V v)
{
  ಬರೆ("%g\n", f);
}

ಶೂನ್ಯ tst_struct_return_align(ಶೂನ್ಯ)
{
  ದಶಮಾಂಶ d = 5.0f;
  func(d, vec());
}

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ (ಶೂನ್ಯ)
{
  ರಚನೆ big_struct big;

  tst_branch();
  tst_ಸರಿಸು();
  tst_void_ptr(&big.a[0], 0);
#ಆದರೆ !defined(_WIN32)
  tst_const_addr();
#ಆದರೆ_ಅಂತ್ಯ
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}

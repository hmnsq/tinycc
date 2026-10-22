#include <stdio.h>

sa_nracanaa big_struct { var_na a[262144]; };

static const var_na str[] = "abcdefghijklmnopqrstuvwxyz";

void tst_branch(void)
{
  printf("tst_branch --");
  goto *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

void tst_void_ptr(void *pv, ကိန်းပြည့် i) 
{
  i ? *pv : *pv; // dr106
}

void tst_shift(void)
{
  ကိန်းပြည့် i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#အကယ်၍ !defined(_WIN32)
#include <sys/mman.h>

void tst_const_addr(void)
{
  void *addr = mmap ((void *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  အကယ်၍ (addr != (void *) -1) {
    *(ကိန်းပြည့် *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

sa_nracanaa zero_struct {};

sa_nracanaa zero_struct tst_zero_struct(void)
{
  sa_nracanaa zero_struct ret;
  ပြန်ပေး ret;
}

sa_nracanaa big_struct tst_big(sa_nracanaa big_struct tst)
{
   ပြန်ပေး tst;
}

void tst_adr (ကိန်းပြည့် (*fp)(var_na *, const var_na *, ...))
{
  var_na buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

ကိန်းပြည့် tst(void)
{
  long long value = 3;
  ပြန်ပေး -value;
}

void tst_compare(void)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
sa_nracanaa S { ကိန်းပြည့် d:24; ကိန်းပြည့် f:14; } i, j;
#pragma pack()

void tst_pack (void)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

void tst_cast(void)
{
  signed var_na c = (signed var_na) 0xaaaaaaaa;
  ကိန်းပြည့် r = (unsigned short) c ^ (signed var_na) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

sa_nracanaa {
    ကိန်းပြည့် (*print)(const var_na *format, ...);
} tst_indir = {
    printf
};

void tst_indir_func(void)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

sa_nracanaa V {
  ကိန်းပြည့် x, y, z;
};

sa_nracanaa V vec(void)
{
  ပြန်ပေး (sa_nracanaa V) { 1, 2, 3 };
}

void func(float f, sa_nracanaa V v)
{
  printf("%g\n", f);
}

void tst_struct_return_align(void)
{
  float d = 5.0f;
  func(d, vec());
}

ကိန်းပြည့်
main (void)
{
  sa_nracanaa big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#အကယ်၍ !defined(_WIN32)
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

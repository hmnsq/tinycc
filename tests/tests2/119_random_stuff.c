#include <stdio.h>

struct big_struct { char a[262144]; };

static const char str[] = "abcdefghijklmnopqrstuvwxyz";

void tst_branch(void)
{
  printf("tst_branch --");
  goto *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

void tst_void_ptr(void *pv, цео i) 
{
  i ? *pv : *pv; // dr106
}

void tst_shift(void)
{
  цео i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ако !defined(_WIN32)
#include <sys/mman.h>

void tst_const_addr(void)
{
  void *addr = mmap ((void *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ако (addr != (void *) -1) {
    *(цео *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

struct zero_struct {};

struct zero_struct tst_zero_struct(void)
{
  struct zero_struct ret;
  врати ret;
}

struct big_struct tst_big(struct big_struct tst)
{
   врати tst;
}

void tst_adr (цео (*fp)(char *, const char *, ...))
{
  char buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

цео tst(void)
{
  long long value = 3;
  врати -value;
}

void tst_compare(void)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
struct S { цео d:24; цео f:14; } i, j;
#pragma pack()

void tst_pack (void)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

void tst_cast(void)
{
  signed char c = (signed char) 0xaaaaaaaa;
  цео r = (unsigned short) c ^ (signed char) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

struct {
    цео (*print)(const char *format, ...);
} tst_indir = {
    printf
};

void tst_indir_func(void)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

struct V {
  цео x, y, z;
};

struct V vec(void)
{
  врати (struct V) { 1, 2, 3 };
}

void func(float f, struct V v)
{
  printf("%g\n", f);
}

void tst_struct_return_align(void)
{
  float d = 5.0f;
  func(d, vec());
}

цео
main (void)
{
  struct big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#ако !defined(_WIN32)
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

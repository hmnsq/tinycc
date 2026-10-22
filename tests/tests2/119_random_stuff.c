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

void tst_void_ptr(void *pv, số_nguyên i) 
{
  i ? *pv : *pv; // dr106
}

void tst_shift(void)
{
  số_nguyên i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#nếu !defined(_WIN32)
#include <sys/mman.h>

void tst_const_addr(void)
{
  void *addr = mmap ((void *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  nếu (addr != (void *) -1) {
    *(số_nguyên *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

struct zero_struct {};

struct zero_struct tst_zero_struct(void)
{
  struct zero_struct ret;
  trả_về ret;
}

struct big_struct tst_big(struct big_struct tst)
{
   trả_về tst;
}

void tst_adr (số_nguyên (*fp)(char *, const char *, ...))
{
  char buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

số_nguyên tst(void)
{
  long long value = 3;
  trả_về -value;
}

void tst_compare(void)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
struct S { số_nguyên d:24; số_nguyên f:14; } i, j;
#pragma pack()

void tst_pack (void)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

void tst_cast(void)
{
  signed char c = (signed char) 0xaaaaaaaa;
  số_nguyên r = (unsigned short) c ^ (signed char) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

struct {
    số_nguyên (*print)(const char *format, ...);
} tst_indir = {
    printf
};

void tst_indir_func(void)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

struct V {
  số_nguyên x, y, z;
};

struct V vec(void)
{
  trả_về (struct V) { 1, 2, 3 };
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

số_nguyên
main (void)
{
  struct big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#nếu !defined(_WIN32)
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

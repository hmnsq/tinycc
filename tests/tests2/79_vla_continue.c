#include <stdio.h>

số_nguyên f(void)
{
  trả_về 5;
}

void test1()
{
  số_nguyên count = 10;
  void *addr[10];
  cho(;count--;) {
    số_nguyên a[f()];

    addr[count] = a;

    continue;
  }

  nếu(addr[9] == addr[0]) {
    printf("OK\n");
  } không_thì {
    printf("NOT OK\n");
  }
}

void test2()
{
  số_nguyên count = 10;
  void *addr[count];
  cho(;count--;) {
    số_nguyên a[f()];

    addr[count] = a;

    continue;
  }

  nếu(addr[9] == addr[0]) {
    printf("OK\n");
  } không_thì {
    printf("NOT OK\n");
  }
}

void test3()
{
  số_nguyên count = 10;
  void *addr[count];
  trong_khi(count--) {
      số_nguyên b[f()];
      nếu (count >= 0) {
          số_nguyên a[f()];

          addr[count] = a;

          continue;
      }
  }

  nếu(addr[9] == addr[0]) {
    printf("OK\n");
  } không_thì {
    printf("NOT OK\n");
  }
}

void test4()
{
  số_nguyên count = 10;
  void *addr[count];
  do {
    số_nguyên a[f()];

    addr[--count] = a;

    continue;
  } trong_khi (count);

  nếu(addr[9] == addr[0]) {
    printf("OK\n");
  } không_thì {
    printf("NOT OK\n");
  }
}

void test5()
{
  số_nguyên count = 10;
  số_nguyên a[f()];
  số_nguyên c[f()];

  c[0] = 42;

  cho(;count--;) {
    số_nguyên b[f()];
    số_nguyên i;
    cho (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  nếu (c[0] == 42) {
    printf("OK\n");
  } không_thì {
    printf("NOT OK\n");
  }
}

số_nguyên main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  trả_về 0;
}

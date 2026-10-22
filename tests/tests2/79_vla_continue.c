#include <stdio.h>

整数 f(void)
{
  返回 5;
}

void test1()
{
  整数 count = 10;
  void *addr[10];
  为(;count--;) {
    整数 a[f()];

    addr[count] = a;

    continue;
  }

  如果(addr[9] == addr[0]) {
    printf("OK\n");
  } 否则 {
    printf("NOT OK\n");
  }
}

void test2()
{
  整数 count = 10;
  void *addr[count];
  为(;count--;) {
    整数 a[f()];

    addr[count] = a;

    continue;
  }

  如果(addr[9] == addr[0]) {
    printf("OK\n");
  } 否则 {
    printf("NOT OK\n");
  }
}

void test3()
{
  整数 count = 10;
  void *addr[count];
  当(count--) {
      整数 b[f()];
      如果 (count >= 0) {
          整数 a[f()];

          addr[count] = a;

          continue;
      }
  }

  如果(addr[9] == addr[0]) {
    printf("OK\n");
  } 否则 {
    printf("NOT OK\n");
  }
}

void test4()
{
  整数 count = 10;
  void *addr[count];
  do {
    整数 a[f()];

    addr[--count] = a;

    continue;
  } 当 (count);

  如果(addr[9] == addr[0]) {
    printf("OK\n");
  } 否则 {
    printf("NOT OK\n");
  }
}

void test5()
{
  整数 count = 10;
  整数 a[f()];
  整数 c[f()];

  c[0] = 42;

  为(;count--;) {
    整数 b[f()];
    整数 i;
    为 (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  如果 (c[0] == 42) {
    printf("OK\n");
  } 否则 {
    printf("NOT OK\n");
  }
}

整数 主要(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  返回 0;
}

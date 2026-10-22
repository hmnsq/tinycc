#include <stdio.h>

จำนวนเต็ม f(void)
{
  คืน 5;
}

void test1()
{
  จำนวนเต็ม count = 10;
  void *addr[10];
  สำหรับ(;count--;) {
    จำนวนเต็ม a[f()];

    addr[count] = a;

    continue;
  }

  ถ้า(addr[9] == addr[0]) {
    printf("OK\n");
  } มิฉะนั้น {
    printf("NOT OK\n");
  }
}

void test2()
{
  จำนวนเต็ม count = 10;
  void *addr[count];
  สำหรับ(;count--;) {
    จำนวนเต็ม a[f()];

    addr[count] = a;

    continue;
  }

  ถ้า(addr[9] == addr[0]) {
    printf("OK\n");
  } มิฉะนั้น {
    printf("NOT OK\n");
  }
}

void test3()
{
  จำนวนเต็ม count = 10;
  void *addr[count];
  ขณะ(count--) {
      จำนวนเต็ม b[f()];
      ถ้า (count >= 0) {
          จำนวนเต็ม a[f()];

          addr[count] = a;

          continue;
      }
  }

  ถ้า(addr[9] == addr[0]) {
    printf("OK\n");
  } มิฉะนั้น {
    printf("NOT OK\n");
  }
}

void test4()
{
  จำนวนเต็ม count = 10;
  void *addr[count];
  do {
    จำนวนเต็ม a[f()];

    addr[--count] = a;

    continue;
  } ขณะ (count);

  ถ้า(addr[9] == addr[0]) {
    printf("OK\n");
  } มิฉะนั้น {
    printf("NOT OK\n");
  }
}

void test5()
{
  จำนวนเต็ม count = 10;
  จำนวนเต็ม a[f()];
  จำนวนเต็ม c[f()];

  c[0] = 42;

  สำหรับ(;count--;) {
    จำนวนเต็ม b[f()];
    จำนวนเต็ม i;
    สำหรับ (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ถ้า (c[0] == 42) {
    printf("OK\n");
  } มิฉะนั้น {
    printf("NOT OK\n");
  }
}

จำนวนเต็ม หลัก(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  คืน 0;
}

#include <stdio.h>

정수 f(void)
{
  반환 5;
}

void test1()
{
  정수 count = 10;
  void *addr[10];
  위해(;count--;) {
    정수 a[f()];

    addr[count] = a;

    continue;
  }

  만약(addr[9] == addr[0]) {
    printf("OK\n");
  } 아니면 {
    printf("NOT OK\n");
  }
}

void test2()
{
  정수 count = 10;
  void *addr[count];
  위해(;count--;) {
    정수 a[f()];

    addr[count] = a;

    continue;
  }

  만약(addr[9] == addr[0]) {
    printf("OK\n");
  } 아니면 {
    printf("NOT OK\n");
  }
}

void test3()
{
  정수 count = 10;
  void *addr[count];
  동안(count--) {
      정수 b[f()];
      만약 (count >= 0) {
          정수 a[f()];

          addr[count] = a;

          continue;
      }
  }

  만약(addr[9] == addr[0]) {
    printf("OK\n");
  } 아니면 {
    printf("NOT OK\n");
  }
}

void test4()
{
  정수 count = 10;
  void *addr[count];
  do {
    정수 a[f()];

    addr[--count] = a;

    continue;
  } 동안 (count);

  만약(addr[9] == addr[0]) {
    printf("OK\n");
  } 아니면 {
    printf("NOT OK\n");
  }
}

void test5()
{
  정수 count = 10;
  정수 a[f()];
  정수 c[f()];

  c[0] = 42;

  위해(;count--;) {
    정수 b[f()];
    정수 i;
    위해 (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  만약 (c[0] == 42) {
    printf("OK\n");
  } 아니면 {
    printf("NOT OK\n");
  }
}

정수 main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  반환 0;
}

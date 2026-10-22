#include <stdio.h>

целое f(void)
{
  вернуть 5;
}

void test1()
{
  целое count = 10;
  void *addr[10];
  для(;count--;) {
    целое a[f()];

    addr[count] = a;

    continue;
  }

  если(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test2()
{
  целое count = 10;
  void *addr[count];
  для(;count--;) {
    целое a[f()];

    addr[count] = a;

    continue;
  }

  если(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test3()
{
  целое count = 10;
  void *addr[count];
  пока(count--) {
      целое b[f()];
      если (count >= 0) {
          целое a[f()];

          addr[count] = a;

          continue;
      }
  }

  если(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test4()
{
  целое count = 10;
  void *addr[count];
  do {
    целое a[f()];

    addr[--count] = a;

    continue;
  } пока (count);

  если(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test5()
{
  целое count = 10;
  целое a[f()];
  целое c[f()];

  c[0] = 42;

  для(;count--;) {
    целое b[f()];
    целое i;
    для (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  если (c[0] == 42) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

целое основной(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  вернуть 0;
}

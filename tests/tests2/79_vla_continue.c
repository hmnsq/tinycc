#include <stdio.h>

ціле f(void)
{
  повернути 5;
}

void test1()
{
  ціле count = 10;
  void *addr[10];
  для(;count--;) {
    ціле a[f()];

    addr[count] = a;

    continue;
  }

  якщо(addr[9] == addr[0]) {
    printf("OK\n");
  } інакше {
    printf("NOT OK\n");
  }
}

void test2()
{
  ціле count = 10;
  void *addr[count];
  для(;count--;) {
    ціле a[f()];

    addr[count] = a;

    continue;
  }

  якщо(addr[9] == addr[0]) {
    printf("OK\n");
  } інакше {
    printf("NOT OK\n");
  }
}

void test3()
{
  ціле count = 10;
  void *addr[count];
  поки(count--) {
      ціле b[f()];
      якщо (count >= 0) {
          ціле a[f()];

          addr[count] = a;

          continue;
      }
  }

  якщо(addr[9] == addr[0]) {
    printf("OK\n");
  } інакше {
    printf("NOT OK\n");
  }
}

void test4()
{
  ціле count = 10;
  void *addr[count];
  do {
    ціле a[f()];

    addr[--count] = a;

    continue;
  } поки (count);

  якщо(addr[9] == addr[0]) {
    printf("OK\n");
  } інакше {
    printf("NOT OK\n");
  }
}

void test5()
{
  ціле count = 10;
  ціле a[f()];
  ціле c[f()];

  c[0] = 42;

  для(;count--;) {
    ціле b[f()];
    ціле i;
    для (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  якщо (c[0] == 42) {
    printf("OK\n");
  } інакше {
    printf("NOT OK\n");
  }
}

ціле main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  повернути 0;
}

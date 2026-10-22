#include <stdio.h>

цео f(void)
{
  врати 5;
}

void test1()
{
  цео count = 10;
  void *addr[10];
  за(;count--;) {
    цео a[f()];

    addr[count] = a;

    continue;
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } инако {
    printf("NOT OK\n");
  }
}

void test2()
{
  цео count = 10;
  void *addr[count];
  за(;count--;) {
    цео a[f()];

    addr[count] = a;

    continue;
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } инако {
    printf("NOT OK\n");
  }
}

void test3()
{
  цео count = 10;
  void *addr[count];
  док(count--) {
      цео b[f()];
      ако (count >= 0) {
          цео a[f()];

          addr[count] = a;

          continue;
      }
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } инако {
    printf("NOT OK\n");
  }
}

void test4()
{
  цео count = 10;
  void *addr[count];
  do {
    цео a[f()];

    addr[--count] = a;

    continue;
  } док (count);

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } инако {
    printf("NOT OK\n");
  }
}

void test5()
{
  цео count = 10;
  цео a[f()];
  цео c[f()];

  c[0] = 42;

  за(;count--;) {
    цео b[f()];
    цео i;
    за (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ако (c[0] == 42) {
    printf("OK\n");
  } инако {
    printf("NOT OK\n");
  }
}

цео main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  врати 0;
}

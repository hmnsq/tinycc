#include <stdio.h>

цяло f(void)
{
  върни 5;
}

void test1()
{
  цяло count = 10;
  void *addr[10];
  за(;count--;) {
    цяло a[f()];

    addr[count] = a;

    continue;
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test2()
{
  цяло count = 10;
  void *addr[count];
  за(;count--;) {
    цяло a[f()];

    addr[count] = a;

    continue;
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test3()
{
  цяло count = 10;
  void *addr[count];
  докато(count--) {
      цяло b[f()];
      ако (count >= 0) {
          цяло a[f()];

          addr[count] = a;

          continue;
      }
  }

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test4()
{
  цяло count = 10;
  void *addr[count];
  do {
    цяло a[f()];

    addr[--count] = a;

    continue;
  } докато (count);

  ако(addr[9] == addr[0]) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

void test5()
{
  цяло count = 10;
  цяло a[f()];
  цяло c[f()];

  c[0] = 42;

  за(;count--;) {
    цяло b[f()];
    цяло i;
    за (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ако (c[0] == 42) {
    printf("OK\n");
  } иначе {
    printf("NOT OK\n");
  }
}

цяло main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  върни 0;
}

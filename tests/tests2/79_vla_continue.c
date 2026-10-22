#include <stdio.h>

ཧྲིལ f(void)
{
  ལོག 5;
}

void test1()
{
  ཧྲིལ count = 10;
  void *addr[10];
  དོན་ལུ(;count--;) {
    ཧྲིལ a[f()];

    addr[count] = a;

    continue;
  }

  གལ་སྲིད(addr[9] == addr[0]) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

void test2()
{
  ཧྲིལ count = 10;
  void *addr[count];
  དོན་ལུ(;count--;) {
    ཧྲིལ a[f()];

    addr[count] = a;

    continue;
  }

  གལ་སྲིད(addr[9] == addr[0]) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

void test3()
{
  ཧྲིལ count = 10;
  void *addr[count];
  སྐབས(count--) {
      ཧྲིལ b[f()];
      གལ་སྲིད (count >= 0) {
          ཧྲིལ a[f()];

          addr[count] = a;

          continue;
      }
  }

  གལ་སྲིད(addr[9] == addr[0]) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

void test4()
{
  ཧྲིལ count = 10;
  void *addr[count];
  do {
    ཧྲིལ a[f()];

    addr[--count] = a;

    continue;
  } སྐབས (count);

  གལ་སྲིད(addr[9] == addr[0]) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

void test5()
{
  ཧྲིལ count = 10;
  ཧྲིལ a[f()];
  ཧྲིལ c[f()];

  c[0] = 42;

  དོན་ལུ(;count--;) {
    ཧྲིལ b[f()];
    ཧྲིལ i;
    དོན་ལུ (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  གལ་སྲིད (c[0] == 42) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

ཧྲིལ main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ལོག 0;
}

#include <stdio.h>

ཧྲིལ f(void)
{
  ཕྱིར 5;
}

void test1()
{
  ཧྲིལ count = 10;
  void *addr[10];
  ཆེད་དུ(;count--;) {
    ཧྲིལ a[f()];

    addr[count] = a;

    continue;
  }

  གལ་ཏེ(addr[9] == addr[0]) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

void test2()
{
  ཧྲིལ count = 10;
  void *addr[count];
  ཆེད་དུ(;count--;) {
    ཧྲིལ a[f()];

    addr[count] = a;

    continue;
  }

  གལ་ཏེ(addr[9] == addr[0]) {
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
      གལ་ཏེ (count >= 0) {
          ཧྲིལ a[f()];

          addr[count] = a;

          continue;
      }
  }

  གལ་ཏེ(addr[9] == addr[0]) {
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

  གལ་ཏེ(addr[9] == addr[0]) {
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

  ཆེད་དུ(;count--;) {
    ཧྲིལ b[f()];
    ཧྲིལ i;
    ཆེད་དུ (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  གལ་ཏེ (c[0] == 42) {
    printf("OK\n");
  } དེ་མིན {
    printf("NOT OK\n");
  }
}

ཧྲིལ གཙོ(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ཕྱིར 0;
}

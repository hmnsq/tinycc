#include <stdio.h>

ចំនួនគត់ f(void)
{
  ត្រឡប់ 5;
}

void test1()
{
  ចំនួនគត់ count = 10;
  void *addr[10];
  សម្រាប់(;count--;) {
    ចំនួនគត់ a[f()];

    addr[count] = a;

    continue;
  }

  ប្រសិនបើ(addr[9] == addr[0]) {
    printf("OK\n");
  } បើមិនដូច្នេះ {
    printf("NOT OK\n");
  }
}

void test2()
{
  ចំនួនគត់ count = 10;
  void *addr[count];
  សម្រាប់(;count--;) {
    ចំនួនគត់ a[f()];

    addr[count] = a;

    continue;
  }

  ប្រសិនបើ(addr[9] == addr[0]) {
    printf("OK\n");
  } បើមិនដូច្នេះ {
    printf("NOT OK\n");
  }
}

void test3()
{
  ចំនួនគត់ count = 10;
  void *addr[count];
  ខណៈពេល(count--) {
      ចំនួនគត់ b[f()];
      ប្រសិនបើ (count >= 0) {
          ចំនួនគត់ a[f()];

          addr[count] = a;

          continue;
      }
  }

  ប្រសិនបើ(addr[9] == addr[0]) {
    printf("OK\n");
  } បើមិនដូច្នេះ {
    printf("NOT OK\n");
  }
}

void test4()
{
  ចំនួនគត់ count = 10;
  void *addr[count];
  do {
    ចំនួនគត់ a[f()];

    addr[--count] = a;

    continue;
  } ខណៈពេល (count);

  ប្រសិនបើ(addr[9] == addr[0]) {
    printf("OK\n");
  } បើមិនដូច្នេះ {
    printf("NOT OK\n");
  }
}

void test5()
{
  ចំនួនគត់ count = 10;
  ចំនួនគត់ a[f()];
  ចំនួនគត់ c[f()];

  c[0] = 42;

  សម្រាប់(;count--;) {
    ចំនួនគត់ b[f()];
    ចំនួនគត់ i;
    សម្រាប់ (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ប្រសិនបើ (c[0] == 42) {
    printf("OK\n");
  } បើមិនដូច្នេះ {
    printf("NOT OK\n");
  }
}

ចំនួនគត់ main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ត្រឡប់ 0;
}

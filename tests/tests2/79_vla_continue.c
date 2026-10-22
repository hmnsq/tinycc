#include <stdio.h>

ကိန်းပြည့် f(void)
{
  ပြန်ပေး 5;
}

void test1()
{
  ကိန်းပြည့် count = 10;
  void *addr[10];
  အတွက်(;count--;) {
    ကိန်းပြည့် a[f()];

    addr[count] = a;

    continue;
  }

  အကယ်၍(addr[9] == addr[0]) {
    printf("OK\n");
  } မဟုတ်ပါက {
    printf("NOT OK\n");
  }
}

void test2()
{
  ကိန်းပြည့် count = 10;
  void *addr[count];
  အတွက်(;count--;) {
    ကိန်းပြည့် a[f()];

    addr[count] = a;

    continue;
  }

  အကယ်၍(addr[9] == addr[0]) {
    printf("OK\n");
  } မဟုတ်ပါက {
    printf("NOT OK\n");
  }
}

void test3()
{
  ကိန်းပြည့် count = 10;
  void *addr[count];
  နေစဉ်(count--) {
      ကိန်းပြည့် b[f()];
      အကယ်၍ (count >= 0) {
          ကိန်းပြည့် a[f()];

          addr[count] = a;

          continue;
      }
  }

  အကယ်၍(addr[9] == addr[0]) {
    printf("OK\n");
  } မဟုတ်ပါက {
    printf("NOT OK\n");
  }
}

void test4()
{
  ကိန်းပြည့် count = 10;
  void *addr[count];
  do {
    ကိန်းပြည့် a[f()];

    addr[--count] = a;

    continue;
  } နေစဉ် (count);

  အကယ်၍(addr[9] == addr[0]) {
    printf("OK\n");
  } မဟုတ်ပါက {
    printf("NOT OK\n");
  }
}

void test5()
{
  ကိန်းပြည့် count = 10;
  ကိန်းပြည့် a[f()];
  ကိန်းပြည့် c[f()];

  c[0] = 42;

  အတွက်(;count--;) {
    ကိန်းပြည့် b[f()];
    ကိန်းပြည့် i;
    အတွက် (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  အကယ်၍ (c[0] == 42) {
    printf("OK\n");
  } မဟုတ်ပါက {
    printf("NOT OK\n");
  }
}

ကိန်းပြည့် main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ပြန်ပေး 0;
}

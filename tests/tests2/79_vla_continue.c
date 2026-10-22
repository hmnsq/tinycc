#include <stdio.h>

int f(void)
{
  return 5;
}

void test1()
{
  int बिलांग_2 = 10;
  void *addr[10];
  for(;बिलांग_2--;) {
    int a[f()];

    addr[बिलांग_2] = a;

    continue;
  }

  if(addr[9] == addr[0]) {
    printf("OK\n");
  } else {
    printf("NOT OK\n");
  }
}

void test2()
{
  int बिलांग_2 = 10;
  void *addr[बिलांग_2];
  for(;बिलांग_2--;) {
    int a[f()];

    addr[बिलांग_2] = a;

    continue;
  }

  if(addr[9] == addr[0]) {
    printf("OK\n");
  } else {
    printf("NOT OK\n");
  }
}

void test3()
{
  int बिलांग_2 = 10;
  void *addr[बिलांग_2];
  while(बिलांग_2--) {
      int b[f()];
      if (बिलांग_2 >= 0) {
          int a[f()];

          addr[बिलांग_2] = a;

          continue;
      }
  }

  if(addr[9] == addr[0]) {
    printf("OK\n");
  } else {
    printf("NOT OK\n");
  }
}

void test4()
{
  int बिलांग_2 = 10;
  void *addr[बिलांग_2];
  do {
    int a[f()];

    addr[--बिलांग_2] = a;

    continue;
  } while (बिलांग_2);

  if(addr[9] == addr[0]) {
    printf("OK\n");
  } else {
    printf("NOT OK\n");
  }
}

void test5()
{
  int बिलांग_2 = 10;
  int a[f()];
  int c[f()];

  c[0] = 42;

  for(;बिलांग_2--;) {
    int b[f()];
    int i;
    for (i=0; i<f(); i++) {
      b[i] = बिलांग_2;
    }
  }

  if (c[0] == 42) {
    printf("OK\n");
  } else {
    printf("NOT OK\n");
  }
}

int main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  return 0;
}

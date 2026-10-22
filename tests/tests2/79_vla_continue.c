#include <stdio.h>

පූර්ණ_සංඛ්‍යා f(void)
{
  ආපසු 5;
}

void test1()
{
  පූර්ණ_සංඛ්‍යා count = 10;
  void *addr[10];
  සඳහා(;count--;) {
    පූර්ණ_සංඛ්‍යා a[f()];

    addr[count] = a;

    continue;
  }

  නම්(addr[9] == addr[0]) {
    printf("OK\n");
  } නැතහොත් {
    printf("NOT OK\n");
  }
}

void test2()
{
  පූර්ණ_සංඛ්‍යා count = 10;
  void *addr[count];
  සඳහා(;count--;) {
    පූර්ණ_සංඛ්‍යා a[f()];

    addr[count] = a;

    continue;
  }

  නම්(addr[9] == addr[0]) {
    printf("OK\n");
  } නැතහොත් {
    printf("NOT OK\n");
  }
}

void test3()
{
  පූර්ණ_සංඛ්‍යා count = 10;
  void *addr[count];
  අතරතුර(count--) {
      පූර්ණ_සංඛ්‍යා b[f()];
      නම් (count >= 0) {
          පූර්ණ_සංඛ්‍යා a[f()];

          addr[count] = a;

          continue;
      }
  }

  නම්(addr[9] == addr[0]) {
    printf("OK\n");
  } නැතහොත් {
    printf("NOT OK\n");
  }
}

void test4()
{
  පූර්ණ_සංඛ්‍යා count = 10;
  void *addr[count];
  do {
    පූර්ණ_සංඛ්‍යා a[f()];

    addr[--count] = a;

    continue;
  } අතරතුර (count);

  නම්(addr[9] == addr[0]) {
    printf("OK\n");
  } නැතහොත් {
    printf("NOT OK\n");
  }
}

void test5()
{
  පූර්ණ_සංඛ්‍යා count = 10;
  පූර්ණ_සංඛ්‍යා a[f()];
  පූර්ණ_සංඛ්‍යා c[f()];

  c[0] = 42;

  සඳහා(;count--;) {
    පූර්ණ_සංඛ්‍යා b[f()];
    පූර්ණ_සංඛ්‍යා i;
    සඳහා (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  නම් (c[0] == 42) {
    printf("OK\n");
  } නැතහොත් {
    printf("NOT OK\n");
  }
}

පූර්ණ_සංඛ්‍යා main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ආපසු 0;
}

#include <stdio.h>

ຈຳນວນເຕັມ f(void)
{
  ສົ່ງຄືນ 5;
}

void test1()
{
  ຈຳນວນເຕັມ count = 10;
  void *addr[10];
  ສຳລັບ(;count--;) {
    ຈຳນວນເຕັມ a[f()];

    addr[count] = a;

    continue;
  }

  ຖ້າ(addr[9] == addr[0]) {
    printf("OK\n");
  } ບໍ່ດັ່ງນັ້ນ {
    printf("NOT OK\n");
  }
}

void test2()
{
  ຈຳນວນເຕັມ count = 10;
  void *addr[count];
  ສຳລັບ(;count--;) {
    ຈຳນວນເຕັມ a[f()];

    addr[count] = a;

    continue;
  }

  ຖ້າ(addr[9] == addr[0]) {
    printf("OK\n");
  } ບໍ່ດັ່ງນັ້ນ {
    printf("NOT OK\n");
  }
}

void test3()
{
  ຈຳນວນເຕັມ count = 10;
  void *addr[count];
  ໃນຂະນະທີ່(count--) {
      ຈຳນວນເຕັມ b[f()];
      ຖ້າ (count >= 0) {
          ຈຳນວນເຕັມ a[f()];

          addr[count] = a;

          continue;
      }
  }

  ຖ້າ(addr[9] == addr[0]) {
    printf("OK\n");
  } ບໍ່ດັ່ງນັ້ນ {
    printf("NOT OK\n");
  }
}

void test4()
{
  ຈຳນວນເຕັມ count = 10;
  void *addr[count];
  do {
    ຈຳນວນເຕັມ a[f()];

    addr[--count] = a;

    continue;
  } ໃນຂະນະທີ່ (count);

  ຖ້າ(addr[9] == addr[0]) {
    printf("OK\n");
  } ບໍ່ດັ່ງນັ້ນ {
    printf("NOT OK\n");
  }
}

void test5()
{
  ຈຳນວນເຕັມ count = 10;
  ຈຳນວນເຕັມ a[f()];
  ຈຳນວນເຕັມ c[f()];

  c[0] = 42;

  ສຳລັບ(;count--;) {
    ຈຳນວນເຕັມ b[f()];
    ຈຳນວນເຕັມ i;
    ສຳລັບ (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ຖ້າ (c[0] == 42) {
    printf("OK\n");
  } ບໍ່ດັ່ງນັ້ນ {
    printf("NOT OK\n");
  }
}

ຈຳນວນເຕັມ main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ສົ່ງຄືນ 0;
}

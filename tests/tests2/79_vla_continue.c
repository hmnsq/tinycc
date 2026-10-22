#include <stdio.h>

puur_naa_nka f(void)
{
  ᮝᮜᮤ 5;
}

void test1()
{
  puur_naa_nka count = 10;
  void *addr[10];
  for(;count--;) {
    puur_naa_nka a[f()];

    addr[count] = a;

    continue;
  }

  ᮚᮦᮔ᮪(addr[9] == addr[0]) {
    printf("OK\n");
  } ᮜᮤᮚ {
    printf("NOT OK\n");
  }
}

void test2()
{
  puur_naa_nka count = 10;
  void *addr[count];
  for(;count--;) {
    puur_naa_nka a[f()];

    addr[count] = a;

    continue;
  }

  ᮚᮦᮔ᮪(addr[9] == addr[0]) {
    printf("OK\n");
  } ᮜᮤᮚ {
    printf("NOT OK\n");
  }
}

void test3()
{
  puur_naa_nka count = 10;
  void *addr[count];
  ᮞᮨᮓᮨᮜ(count--) {
      puur_naa_nka b[f()];
      ᮚᮦᮔ᮪ (count >= 0) {
          puur_naa_nka a[f()];

          addr[count] = a;

          continue;
      }
  }

  ᮚᮦᮔ᮪(addr[9] == addr[0]) {
    printf("OK\n");
  } ᮜᮤᮚ {
    printf("NOT OK\n");
  }
}

void test4()
{
  puur_naa_nka count = 10;
  void *addr[count];
  do {
    puur_naa_nka a[f()];

    addr[--count] = a;

    continue;
  } ᮞᮨᮓᮨᮜ (count);

  ᮚᮦᮔ᮪(addr[9] == addr[0]) {
    printf("OK\n");
  } ᮜᮤᮚ {
    printf("NOT OK\n");
  }
}

void test5()
{
  puur_naa_nka count = 10;
  puur_naa_nka a[f()];
  puur_naa_nka c[f()];

  c[0] = 42;

  for(;count--;) {
    puur_naa_nka b[f()];
    puur_naa_nka i;
    for (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ᮚᮦᮔ᮪ (c[0] == 42) {
    printf("OK\n");
  } ᮜᮤᮚ {
    printf("NOT OK\n");
  }
}

puur_naa_nka main(void)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  ᮝᮜᮤ 0;
}

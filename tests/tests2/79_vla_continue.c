#ضمن <stdio.h>

صحيح f(فراغ)
{
  החזר 5;
}

فراغ test1()
{
  صحيح count = 10;
  فراغ *addr[10];
  עבור(;count--;) {
    صحيح a[f()];

    addr[count] = a;

    استمر;
  }

  אם(addr[9] == addr[0]) {
    printf("OK\n");
  } אחרת {
    printf("NOT OK\n");
  }
}

فراغ test2()
{
  صحيح count = 10;
  فراغ *addr[count];
  עבור(;count--;) {
    صحيح a[f()];

    addr[count] = a;

    استمر;
  }

  אם(addr[9] == addr[0]) {
    printf("OK\n");
  } אחרת {
    printf("NOT OK\n");
  }
}

فراغ test3()
{
  صحيح count = 10;
  فراغ *addr[count];
  כלעוד(count--) {
      صحيح b[f()];
      אם (count >= 0) {
          صحيح a[f()];

          addr[count] = a;

          استمر;
      }
  }

  אם(addr[9] == addr[0]) {
    printf("OK\n");
  } אחרת {
    printf("NOT OK\n");
  }
}

فراغ test4()
{
  صحيح count = 10;
  فراغ *addr[count];
  עשה {
    صحيح a[f()];

    addr[--count] = a;

    استمر;
  } כלעוד (count);

  אם(addr[9] == addr[0]) {
    printf("OK\n");
  } אחרת {
    printf("NOT OK\n");
  }
}

فراغ test5()
{
  صحيح count = 10;
  صحيح a[f()];
  صحيح c[f()];

  c[0] = 42;

  עבור(;count--;) {
    صحيح b[f()];
    صحيح i;
    עבור (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  אם (c[0] == 42) {
    printf("OK\n");
  } אחרת {
    printf("NOT OK\n");
  }
}

صحيح main(فراغ)
{
  test1();
  test2();
  test3();
  test4();
  test5();

  החזר 0;
}

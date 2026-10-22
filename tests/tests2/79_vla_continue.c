#ضمن <stdio.h>

صحيح f(فراغ)
{
  ܦܢܐ 5;
}

فراغ test1()
{
  صحيح count = 10;
  فراغ *addr[10];
  لكل(;count--;) {
    صحيح a[f()];

    addr[count] = a;

    استمر;
  }

  ܐܢ(addr[9] == addr[0]) {
    printf("OK\n");
  } ܐܚܪܢܐ {
    printf("NOT OK\n");
  }
}

فراغ test2()
{
  صحيح count = 10;
  فراغ *addr[count];
  لكل(;count--;) {
    صحيح a[f()];

    addr[count] = a;

    استمر;
  }

  ܐܢ(addr[9] == addr[0]) {
    printf("OK\n");
  } ܐܚܪܢܐ {
    printf("NOT OK\n");
  }
}

فراغ test3()
{
  صحيح count = 10;
  فراغ *addr[count];
  ܟܡܐ(count--) {
      صحيح b[f()];
      ܐܢ (count >= 0) {
          صحيح a[f()];

          addr[count] = a;

          استمر;
      }
  }

  ܐܢ(addr[9] == addr[0]) {
    printf("OK\n");
  } ܐܚܪܢܐ {
    printf("NOT OK\n");
  }
}

فراغ test4()
{
  صحيح count = 10;
  فراغ *addr[count];
  ܥܒܕ {
    صحيح a[f()];

    addr[--count] = a;

    استمر;
  } ܟܡܐ (count);

  ܐܢ(addr[9] == addr[0]) {
    printf("OK\n");
  } ܐܚܪܢܐ {
    printf("NOT OK\n");
  }
}

فراغ test5()
{
  صحيح count = 10;
  صحيح a[f()];
  صحيح c[f()];

  c[0] = 42;

  لكل(;count--;) {
    صحيح b[f()];
    صحيح i;
    لكل (i=0; i<f(); i++) {
      b[i] = count;
    }
  }

  ܐܢ (c[0] == 42) {
    printf("OK\n");
  } ܐܚܪܢܐ {
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

  ܦܢܐ 0;
}

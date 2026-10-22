#include <stdio.h>
ចំនួនគត់ main() {
  printf("%d\n", (ចំនួនគត់)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (ចំនួនគត់)d);

  printf("%d\n", (ចំនួនគត់)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ចំនួនគត់)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#បើមិនដូច្នេះ
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

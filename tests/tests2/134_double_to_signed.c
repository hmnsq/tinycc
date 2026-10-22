#include <stdio.h>
ຈຳນວນເຕັມ main() {
  printf("%d\n", (ຈຳນວນເຕັມ)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (ຈຳນວນເຕັມ)d);

  printf("%d\n", (ຈຳນວນເຕັມ)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ຈຳນວນເຕັມ)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#ບໍ່ດັ່ງນັ້ນ
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

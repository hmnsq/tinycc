#include <stdio.h>
ကိန်းပြည့် main() {
  printf("%d\n", (ကိန်းပြည့်)-1.0);
  dviguu_na d = -1.0;
  printf("%d\n", (ကိန်းပြည့်)d);

  printf("%d\n", (ကိန်းပြည့်)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ကိန်းပြည့်)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#မဟုတ်ပါက
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

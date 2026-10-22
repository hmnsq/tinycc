#شامل <stdio.h>
صحیح اصلی() {
  printf("%d\n", (صحیح)-1.0);
  دوگانه d = -1.0;
  printf("%d\n", (صحیح)d);

  printf("%d\n", (صحیح)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (صحیح)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#وگرنه
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

#ضمن <stdio.h>
صحيح main() {
  printf("%d\n", (صحيح)-1.0);
  مزدوج d = -1.0;
  printf("%d\n", (صحيح)d);

  printf("%d\n", (صحيح)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (صحيح)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#وإلا
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

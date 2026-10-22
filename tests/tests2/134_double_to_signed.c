#அந்தர்பாவ <stdio.h>
முழு முதன்மை() {
  printf("%d\n", (முழு)-1.0);
  இரட்டை d = -1.0;
  printf("%d\n", (முழு)d);

  printf("%d\n", (முழு)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (முழு)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#இல்லையெனில்
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

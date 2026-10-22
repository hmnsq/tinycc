#अन्तर्भाव <stdio.h>
पूर्णाङ्क main() {
  printf("%d\n", (पूर्णाङ्क)-1.0);
  द्विगुण d = -1.0;
  printf("%d\n", (पूर्णाङ्क)d);

  printf("%d\n", (पूर्णाङ्क)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (पूर्णाङ्क)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#अञ्ञथा
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

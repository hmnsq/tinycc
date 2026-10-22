#અન્તર્ભાવ <stdio.h>
પૂર્ણાંક મુખ્ય() {
  printf("%d\n", (પૂર્ણાંક)-1.0);
  દ્વિગુણ d = -1.0;
  printf("%d\n", (પૂર્ણાંક)d);

  printf("%d\n", (પૂર્ણાંક)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (પૂર્ણાંક)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#નહીંતર
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

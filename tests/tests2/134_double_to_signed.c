#അന്തര്ഭാവ <stdio.h>
പൂർണ്ണസംഖ്യ പ്രധാന() {
  printf("%d\n", (പൂർണ്ണസംഖ്യ)-1.0);
  ഇരട്ട d = -1.0;
  printf("%d\n", (പൂർണ്ണസംഖ്യ)d);

  printf("%d\n", (പൂർണ്ണസംഖ്യ)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (പൂർണ്ണസംഖ്യ)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#അല്ലെങ്കിൽ
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

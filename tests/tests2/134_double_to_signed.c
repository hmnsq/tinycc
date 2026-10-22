#ಅನ್ತರ್ಭಾವ <stdio.h>
ಪೂರ್ಣಾಙ್ಕ main() {
  printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)-1.0);
  ದ್ವಿಗುಣ d = -1.0;
  printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)d);

  printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)-2147483648.0);
  d = -2147483648.0;
  printf("%d\n", (ಪೂರ್ಣಾಙ್ಕ)d);

#ifndef _WIN32
  printf("%llu\n", (unsigned long long)1e19);
#ಅನ್ಯಥಾ
  /* some msvc compiler won't compile tcc correctly in this ragard */
  printf("10000000000000000000\n");
#endif
}

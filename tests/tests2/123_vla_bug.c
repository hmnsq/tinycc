typedef __SIZE_TYPE__ size_t;
extern ចំនួនគត់ printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
ចំនួនគត់ g;
ចំនួនគត់ main()
{
  //char helpme[strlen(str) + 1];
  ចំនួនគត់ i = 0;
#ប្រសិនបើ 0
  ប្រសិនបើ (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#បើមិនដូច្នេះ
  សម្រាប់ (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          ប្រសិនបើ (g) {
              var_na buf[strlen(str) + 10];
              buf[0] = 0;
              goto do_cmd;
          }
          bha_nga;
      pak_sa 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          bha_nga;
      default:
          g++;
          printf("default: i = %d\n", i);
          bha_nga;
      }
  }
#endif
  ត្រឡប់ 0;
}

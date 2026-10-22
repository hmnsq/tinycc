typedef __SIZE_TYPE__ size_t;
extern ཧྲིལ printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
ཧྲིལ g;
ཧྲིལ main()
{
  //char helpme[strlen(str) + 1];
  ཧྲིལ i = 0;
#གལ་སྲིད 0
  གལ་སྲིད (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#དེ་མིན
  དོན་ལུ (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          གལ་སྲིད (g) {
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
  ལོག 0;
}

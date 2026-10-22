typedef __SIZE_TYPE__ size_t;
extern ကိန်းပြည့် printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
ကိန်းပြည့် g;
ကိန်းပြည့် main()
{
  //char helpme[strlen(str) + 1];
  ကိန်းပြည့် i = 0;
#အကယ်၍ 0
  အကယ်၍ (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#မဟုတ်ပါက
  အတွက် (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          အကယ်၍ (g) {
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
  ပြန်ပေး 0;
}

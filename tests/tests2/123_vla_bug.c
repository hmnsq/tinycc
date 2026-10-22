typedef __SIZE_TYPE__ size_t;
extern จำนวนเต็ม printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
จำนวนเต็ม g;
จำนวนเต็ม หลัก()
{
  //char helpme[strlen(str) + 1];
  จำนวนเต็ม i = 0;
#ถ้า 0
  ถ้า (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#มิฉะนั้น
  สำหรับ (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          ถ้า (g) {
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
  คืน 0;
}

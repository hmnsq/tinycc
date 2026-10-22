typedef __SIZE_TYPE__ size_t;
extern 整数 printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
整数 g;
整数 主要()
{
  //char helpme[strlen(str) + 1];
  整数 i = 0;
#如果 0
  如果 (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#否则
  为 (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          如果 (g) {
              char buf[strlen(str) + 10];
              buf[0] = 0;
              goto do_cmd;
          }
          break;
      case 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          break;
      default:
          g++;
          printf("default: i = %d\n", i);
          break;
      }
  }
#endif
  返回 0;
}

typedef __SIZE_TYPE__ size_t;
extern 정수 printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
정수 g;
정수 main()
{
  //char helpme[strlen(str) + 1];
  정수 i = 0;
#만약 0
  만약 (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#아니면
  위해 (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          만약 (g) {
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
  반환 0;
}

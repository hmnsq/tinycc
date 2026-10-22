typedef __SIZE_TYPE__ size_t;
extern целое printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
целое g;
целое основной()
{
  //char helpme[strlen(str) + 1];
  целое i = 0;
#если 0
  если (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#иначе
  для (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          если (g) {
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
  вернуть 0;
}

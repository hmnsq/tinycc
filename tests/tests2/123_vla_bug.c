typedef __SIZE_TYPE__ size_t;
extern số_nguyên printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
số_nguyên g;
số_nguyên main()
{
  //char helpme[strlen(str) + 1];
  số_nguyên i = 0;
#nếu 0
  nếu (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#không_thì
  cho (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          nếu (g) {
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
  trả_về 0;
}

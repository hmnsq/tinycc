typedef __SIZE_TYPE__ size_t;
extern ціле printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
ціле g;
ціле main()
{
  //char helpme[strlen(str) + 1];
  ціле i = 0;
#якщо 0
  якщо (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#інакше
  для (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          якщо (g) {
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
  повернути 0;
}

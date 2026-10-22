typedef __SIZE_TYPE__ size_t;
extern цео printf(const char*, ...);
extern size_t strlen(const char*);
char str[] = "blabla";
цео g;
цео main()
{
  //char helpme[strlen(str) + 1];
  цео i = 0;
#ако 0
  ако (g) {
      char buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#инако
  за (i = 0; i < 5; i++) {
      switch (i) {
      case 10:
          ако (g) {
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
  врати 0;
}

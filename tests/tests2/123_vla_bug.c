প্রকারনির্দেশ __SIZE_TYPE__ size_t;
বাহ্য পূর্ণাঙ্ক printf(ধ্রুব বর্ণ*, ...);
বাহ্য size_t strlen(ধ্রুব বর্ণ*);
বর্ণ str[] = "blabla";
পূর্ণাঙ্ক g;
পূর্ণাঙ্ক main()
{
  //char helpme[strlen(str) + 1];
  পূর্ণাঙ্ক i = 0;
#যদি 0
  যদি (g) {
      বর্ণ buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#অন্যথা
  প্রতি (i = 0; i < 5; i++) {
      বিকল্প (i) {
      পক্ষ 10:
          যদি (g) {
              বর্ণ buf[strlen(str) + 10];
              buf[0] = 0;
              গচ্ছ do_cmd;
          }
          ভঙ্গ;
      পক্ষ 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          ভঙ্গ;
      স্বভাব:
          g++;
          printf("default: i = %d\n", i);
          ভঙ্গ;
      }
  }
#endif
  প্রত্যাগম 0;
}

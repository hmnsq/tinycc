تعریفنوع __SIZE_TYPE__ size_t;
بیرونی صحیح printf(ثابت نویسه*, ...);
بیرونی size_t strlen(ثابت نویسه*);
نویسه str[] = "blabla";
صحیح g;
صحیح اصلی()
{
  //char helpme[strlen(str) + 1];
  صحیح i = 0;
#اگر 0
  اگر (g) {
      نویسه buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#وگرنه
  برای (i = 0; i < 5; i++) {
      انتخاب (i) {
      حالت 10:
          اگر (g) {
              نویسه buf[strlen(str) + 10];
              buf[0] = 0;
              برو do_cmd;
          }
          بشکن;
      حالت 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          بشکن;
      پیشفرض:
          g++;
          printf("default: i = %d\n", i);
          بشکن;
      }
  }
#endif
  بازگشت 0;
}

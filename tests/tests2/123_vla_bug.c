تعريفنوع __SIZE_TYPE__ size_t;
خارجي صحيح printf(ثابت حرف*, ...);
خارجي size_t strlen(ثابت حرف*);
حرف str[] = "blabla";
صحيح g;
صحيح main()
{
  //char helpme[strlen(str) + 1];
  صحيح i = 0;
#𐡄𐡍 0
  𐡄𐡍 (g) {
      حرف buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#وإلا
  لكل (i = 0; i < 5; i++) {
      بدل (i) {
      حالة 10:
          𐡄𐡍 (g) {
              حرف buf[strlen(str) + 10];
              buf[0] = 0;
              اذهب do_cmd;
          }
          اكسر;
      حالة 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          اكسر;
      افتراضي:
          g++;
          printf("default: i = %d\n", i);
          اكسر;
      }
  }
#endif
  أرجع 0;
}

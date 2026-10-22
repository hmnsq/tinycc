প্রকারলেখ __SIZE_TYPE__ আকার_t;
বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);
বাহ্যিক আকার_t strlen(ধ্রুবক অক্ষর*);
অক্ষর str[] = "blabla";
পূর্ণসংখ্যা g;
পূর্ণসংখ্যা প্রধান()
{
  //char helpme[strlen(str) + 1];
  পূর্ণসংখ্যা i = 0;
#যদি 0
  যদি (g) {
      অক্ষর buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#অন্যথা
  জন্য (i = 0; i < 5; i++) {
      নির্বাচন (i) {
      ক্ষেত্র 10:
          যদি (g) {
              অক্ষর buf[strlen(str) + 10];
              buf[0] = 0;
              যাও do_cmd;
          }
          বিরতি;
      ক্ষেত্র 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          বিরতি;
      পূর্বনির্ধারিত:
          g++;
          printf("default: i = %d\n", i);
          বিরতি;
      }
  }
#endif
  ফেরত 0;
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ size_t;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);
ବାହ୍ୟ size_t strlen(ଅଚଳ ଅକ୍ଷର*);
ଅକ୍ଷର str[] = "blabla";
ପୂର୍ଣ୍ଣସଂଖ୍ୟା g;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
  //char helpme[strlen(str) + 1];
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
#ଯଦି 0
  ଯଦି (g) {
      ଅକ୍ଷର buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#ଅନ୍ୟଥା
  ପାଇଁ (i = 0; i < 5; i++) {
      ବାଛ (i) {
      ସ୍ଥିତି 10:
          ଯଦି (g) {
              ଅକ୍ଷର buf[strlen(str) + 10];
              buf[0] = 0;
              ଯାଅ do_cmd;
          }
          ଭାଙ୍ଗ;
      ସ୍ଥିତି 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          ଭାଙ୍ଗ;
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
          g++;
          printf("default: i = %d\n", i);
          ଭାଙ୍ଗ;
      }
  }
#endif
  ଫେରନ୍ତୁ 0;
}

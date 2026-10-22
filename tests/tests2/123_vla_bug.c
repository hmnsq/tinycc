प्रकारनिर्देश __SIZE_TYPE__ size_t;
बाह्य पूर्णाङ्क printf(ध्रुव वर्ण*, ...);
बाह्य size_t strlen(ध्रुव वर्ण*);
वर्ण str[] = "blabla";
पूर्णाङ्क g;
पूर्णाङ्क main()
{
  //char helpme[strlen(str) + 1];
  पूर्णाङ्क i = 0;
#यदि 0
  यदि (g) {
      वर्ण buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#अन्यथा
  प्रति (i = 0; i < 5; i++) {
      विकल्प (i) {
      पक्ष 10:
          यदि (g) {
              वर्ण buf[strlen(str) + 10];
              buf[0] = 0;
              गच्छ do_cmd;
          }
          भङ्ग;
      पक्ष 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          भङ्ग;
      स्वभाव:
          g++;
          printf("default: i = %d\n", i);
          भङ्ग;
      }
  }
#endif
  प्रत्यागम 0;
}

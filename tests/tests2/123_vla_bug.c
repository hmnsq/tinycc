வகைவரை __SIZE_TYPE__ size_t;
வெளி முழு printf(மாறிலி எழுத்து*, ...);
வெளி size_t strlen(மாறிலி எழுத்து*);
எழுத்து str[] = "blabla";
முழு g;
முழு முதன்மை()
{
  //char helpme[strlen(str) + 1];
  முழு i = 0;
#எனில் 0
  எனில் (g) {
      எழுத்து buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#இல்லையெனில்
  க்கு (i = 0; i < 5; i++) {
      தேர்வு (i) {
      நிலை 10:
          எனில் (g) {
              எழுத்து buf[strlen(str) + 10];
              buf[0] = 0;
              செல் do_cmd;
          }
          நிறுத்து;
      நிலை 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          நிறுத்து;
      இயல்பு:
          g++;
          printf("default: i = %d\n", i);
          நிறுத்து;
      }
  }
#endif
  திரும்பு 0;
}

પ્રકારવ્યાખ્યા __SIZE_TYPE__ size_t;
બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર*, ...);
બાહ્ય size_t strlen(અચલ અક્ષર*);
અક્ષર str[] = "blabla";
પૂર્ણાંક g;
પૂર્ણાંક મુખ્ય()
{
  //char helpme[strlen(str) + 1];
  પૂર્ણાંક i = 0;
#જો 0
  જો (g) {
      અક્ષર buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#નહીંતર
  માટે (i = 0; i < 5; i++) {
      પસંદગી (i) {
      સ્થિતિ 10:
          જો (g) {
              અક્ષર buf[strlen(str) + 10];
              buf[0] = 0;
              જાઓ do_cmd;
          }
          તોડો;
      સ્થિતિ 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          તોડો;
      મૂળભૂત:
          g++;
          printf("default: i = %d\n", i);
          તોડો;
      }
  }
#endif
  પાછા 0;
}

തരനിർവചനം __SIZE_TYPE__ size_t;
ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);
ബാഹ്യ size_t strlen(സ്ഥിരം അക്ഷരം*);
അക്ഷരം str[] = "blabla";
പൂർണ്ണസംഖ്യ g;
പൂർണ്ണസംഖ്യ പ്രധാന()
{
  //char helpme[strlen(str) + 1];
  പൂർണ്ണസംഖ്യ i = 0;
#എങ്കിൽ 0
  എങ്കിൽ (g) {
      അക്ഷരം buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#അല്ലെങ്കിൽ
  വേണ്ടി (i = 0; i < 5; i++) {
      തിരഞ്ഞെടുപ്പ് (i) {
      അവസ്ഥ 10:
          എങ്കിൽ (g) {
              അക്ഷരം buf[strlen(str) + 10];
              buf[0] = 0;
              പോകുക do_cmd;
          }
          നിർത്തുക;
      അവസ്ഥ 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          നിർത്തുക;
      സ്ഥിരസ്ഥിതി:
          g++;
          printf("default: i = %d\n", i);
          നിർത്തുക;
      }
  }
#endif
  തിരികെ 0;
}

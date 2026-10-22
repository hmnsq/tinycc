typedef __SIZE_TYPE__ size_t;
extern puur_naa_nka printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
puur_naa_nka g;
puur_naa_nka main()
{
  //char helpme[strlen(str) + 1];
  puur_naa_nka i = 0;
#ᨀᨘ 0
  ᨀᨘ (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#ᨀᨘᨁ
  for (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          ᨀᨘ (g) {
              var_na buf[strlen(str) + 10];
              buf[0] = 0;
              goto do_cmd;
          }
          bha_nga;
      pak_sa 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          bha_nga;
      default:
          g++;
          printf("default: i = %d\n", i);
          bha_nga;
      }
  }
#endif
  ᨀᨘᨒ 0;
}

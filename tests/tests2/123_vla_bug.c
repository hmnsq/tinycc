typedef __SIZE_TYPE__ size_t;
extern පූර්ණ_සංඛ්‍යා printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
පූර්ණ_සංඛ්‍යා g;
පූර්ණ_සංඛ්‍යා main()
{
  //char helpme[strlen(str) + 1];
  පූර්ණ_සංඛ්‍යා i = 0;
#නම් 0
  නම් (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#නැතහොත්
  සඳහා (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          නම් (g) {
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
  ආපසු 0;
}

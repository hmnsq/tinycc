typedef __SIZE_TYPE__ size_t;
extern ຈຳນວນເຕັມ printf(const var_na*, ...);
extern size_t strlen(const var_na*);
var_na str[] = "blabla";
ຈຳນວນເຕັມ g;
ຈຳນວນເຕັມ main()
{
  //char helpme[strlen(str) + 1];
  ຈຳນວນເຕັມ i = 0;
#ຖ້າ 0
  ຖ້າ (g) {
      var_na buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#ບໍ່ດັ່ງນັ້ນ
  ສຳລັບ (i = 0; i < 5; i++) {
      switch (i) {
      pak_sa 10:
          ຖ້າ (g) {
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
  ສົ່ງຄືນ 0;
}

ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ size_t;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);
ಬಾಹ್ಯ size_t strlen(ಧ್ರುವ ವರ್ಣ*);
ವರ್ಣ str[] = "blabla";
ಪೂರ್ಣಾಙ್ಕ g;
ಪೂರ್ಣಾಙ್ಕ main()
{
  //char helpme[strlen(str) + 1];
  ಪೂರ್ಣಾಙ್ಕ i = 0;
#ಯದಿ 0
  ಯದಿ (g) {
      ವರ್ಣ buf[strlen(str) + 10];
      buf[0] = 0;
  }
alabel:
  printf("default: i = %d\n", i);
#ಅನ್ಯಥಾ
  ಪ್ರತಿ (i = 0; i < 5; i++) {
      ವಿಕಲ್ಪ (i) {
      ಪಕ್ಷ 10:
          ಯದಿ (g) {
              ವರ್ಣ buf[strlen(str) + 10];
              buf[0] = 0;
              ಗಚ್ಛ do_cmd;
          }
          ಭಙ್ಗ;
      ಪಕ್ಷ 1:
          printf("reached 3\n");
    do_cmd:
          printf("after do_cmd");
          ಭಙ್ಗ;
      ಸ್ವಭಾವ:
          g++;
          printf("default: i = %d\n", i);
          ಭಙ್ಗ;
      }
  }
#endif
  ಪ್ರತ್ಯಾಗಮ 0;
}

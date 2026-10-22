#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>

ಪೂರ್ಣಾಙ್ಕ compile_errors(ಶೂನ್ಯ)
{
#ಯದಿ TEST == 1
  {
    /* Not constant */
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#ಯದಿ TEST == 2
  {
    /* Not constant */
    ಸಂರಚನಾ{ಪೂರ್ಣಾಙ್ಕ c;}v;
    ಸ್ಥಿರ long i=((ವರ್ಣ*)&(v.c)-(ವರ್ಣ*)&v);
  }
#endif
#ಯದಿ TEST == 3
  {
    /* Not constant */
    ಸ್ಥಿರ ಧ್ರುವ short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    ಶೂನ್ಯ *p = &&l1 + ar[0];
    ಗಚ್ಛ *p;
   l1: ಪ್ರತ್ಯಾಗಮ 1;
   l2: ಪ್ರತ್ಯಾಗಮ 2;
  }
#endif
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ
main(ಶೂನ್ಯ)
{
}

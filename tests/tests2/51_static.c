#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क fred = 1234;
स्थिर पूर्णाङ्क joe;

शून्य henry()
{
   स्थिर पूर्णाङ्क fred = 4567;

   printf("%d\n", fred);
   fred++;
}

पूर्णाङ्क main()
{
   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

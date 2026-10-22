#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क fred = 1234;
स्थिर पूर्णाङ्क joe;

शून्य henry()
{
   स्थिर पूर्णाङ्क fred = 4567;

   म_लिखो("%d\n", fred);
   fred++;
}

पूर्णाङ्क main()
{
   म_लिखो("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   म_लिखो("%d\n", fred);
   fred = 8901;
   joe = 2345;
   म_लिखो("%d\n", fred);
   म_लिखो("%d\n", joe);

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

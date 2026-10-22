#अन्तर्भाव <stdio.h>

स्थिर पूर्णांक fred = 1234;
स्थिर पूर्णांक joe;

शून्य henry()
{
   स्थिर पूर्णांक fred = 4567;

   म_लिखो("%d\n", fred);
   fred++;
}

पूर्णांक main()
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

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

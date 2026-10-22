#अन्तर्भाव <stdio.h>

स्थिर पूर्णाङ्क fred = 1234;
स्थिर पूर्णाङ्क joe;

शून्य henry()
{
   स्थिर पूर्णाङ्क fred = 4567;

   प्रारूप_लिख("%d\n", fred);
   fred++;
}

पूर्णाङ्क मुख्यम्()
{
   प्रारूप_लिख("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   प्रारूप_लिख("%d\n", fred);
   fred = 8901;
   joe = 2345;
   प्रारूप_लिख("%d\n", fred);
   प्रारूप_लिख("%d\n", joe);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

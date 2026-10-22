#अन्तर्भाव <stdio.h>

संरचना point
{
   द्विगुण x;
   द्विगुण y;
};

संरचना point point_array[100];

पूर्णाङ्क main()
{
   पूर्णाङ्क my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   म_लिखो("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#समावेश <stdio.h>

काष्ठा point
{
   द्विगुन x;
   द्विगुन y;
};

काष्ठा point point_array[100];

पूर्णांक मुख्य()
{
   पूर्णांक my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   म_लिखो("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#അന്തര്ഭാവ <stdio.h>

ഘടന point
{
   ഇരട്ട x;
   ഇരട്ട y;
};

ഘടന point point_array[100];

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

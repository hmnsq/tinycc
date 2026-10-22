#شامل <stdio.h>

ساختار point
{
   دوگانه x;
   دوگانه y;
};

ساختار point point_array[100];

صحیح اصلی()
{
   صحیح my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

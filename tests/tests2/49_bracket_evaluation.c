#অন্তর্ভাব <stdio.h>

সংরচনা point
{
   দ্বিগুণ x;
   দ্বিগুণ y;
};

সংরচনা point point_array[100];

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

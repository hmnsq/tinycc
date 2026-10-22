#অন্তর্ভাব <stdio.h>

কাঠামো point
{
   দ্বিগুণ x;
   দ্বিগুণ y;
};

কাঠামো point point_array[100];

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

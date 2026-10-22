#include <stdio.h>

sa_nracanaa point
{
   dviguu_na x;
   dviguu_na y;
};

sa_nracanaa point point_array[100];

puur_naa_nka main()
{
   puur_naa_nka my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   ပွၵ်ႈ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂରଚନା point
{
   ଦ୍ୱିଗୁଣ x;
   ଦ୍ୱିଗୁଣ y;
};

ସଂରଚନା point point_array[100];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

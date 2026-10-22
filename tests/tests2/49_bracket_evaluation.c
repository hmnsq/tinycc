#அந்தர்பாவ <stdio.h>

கட்டமைப்பு point
{
   இரட்டை x;
   இரட்டை y;
};

கட்டமைப்பு point point_array[100];

முழு முதன்மை()
{
   முழு my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

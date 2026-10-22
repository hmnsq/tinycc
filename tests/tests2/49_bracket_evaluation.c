#અન્તર્ભાવ <stdio.h>

સંરચના point
{
   દ્વિગુણ x;
   દ્વિગુણ y;
};

સંરચના point point_array[100];

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

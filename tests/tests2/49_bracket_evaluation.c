#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಂರಚನಾ point
{
   ದ್ವಿಗುಣ x;
   ದ್ವಿಗುಣ y;
};

ಸಂರಚನಾ point point_array[100];

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ my_point = 10;

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

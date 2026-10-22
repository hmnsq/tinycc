#شامل <stdio.h>

صحیح اصلی()
{
   صحیح a[4][4];
   صحیح b = 0;
   صحیح x;
   صحیح y;

   برای (x = 0; x < 4; x++)
   {
      برای (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   برای (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      برای (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

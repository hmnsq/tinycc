#شامل <stdio.h>

صحیح اصلی()
{
   صحیح x, y, z;

   برای (x = 0; x < 2; x++)
   {
      برای (y = 0; y < 3; y++)
      {
         برای (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

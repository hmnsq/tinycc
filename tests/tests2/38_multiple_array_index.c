#ضمن <stdio.h>

صحيح main()
{
   صحيح a[4][4];
   صحيح b = 0;
   صحيح x;
   صحيح y;

   עבור (x = 0; x < 4; x++)
   {
      עבור (y = 0; y < 4; y++)
      {
         b++;
         a[x][y] = b;
      }
   }

   עבור (x = 0; x < 4; x++)
   {
      printf("x=%d: ", x);
      עבור (y = 0; y < 4; y++)
      {
         printf("%d ", a[x][y]);
      }
      printf("\n");
   }

   החזר 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

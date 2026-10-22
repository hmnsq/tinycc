#include <stdio.h>

ཧྲིལ གཙོ()
{
   ཧྲིལ x, y, z;

   ཆེད་དུ (x = 0; x < 2; x++)
   {
      ཆེད་དུ (y = 0; y < 3; y++)
      {
         ཆེད་དུ (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

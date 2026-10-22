#include <stdio.h>

ཧྲིལ array[16];

//Swap integer values by array indexes
void swap(ཧྲིལ a, ཧྲིལ b)
{
   ཧྲིལ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ཧྲིལ partition(ཧྲིལ left, ཧྲིལ right)
{
   ཧྲིལ pivotIndex = left;
   ཧྲིལ pivotValue = array[pivotIndex];
   ཧྲིལ index = left;
   ཧྲིལ i;

   swap(pivotIndex, right);
   ཆེད་དུ(i = left; i < right; i++)
   {
      གལ་ཏེ(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   ཕྱིར index;
}

//Quicksort the array
void quicksort(ཧྲིལ left, ཧྲིལ right)
{
   གལ་ཏེ(left >= right)
      ཕྱིར;

   ཧྲིལ index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

ཧྲིལ གཙོ()
{
   ཧྲིལ i;

   array[0] = 62;
   array[1] = 83;
   array[2] = 4;
   array[3] = 89;
   array[4] = 36;
   array[5] = 21;
   array[6] = 74;
   array[7] = 37;
   array[8] = 65;
   array[9] = 33;
   array[10] = 96;
   array[11] = 38;
   array[12] = 53;
   array[13] = 16;
   array[14] = 74;
   array[15] = 55;

   ཆེད་དུ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   ཆེད་དུ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ཕྱིར 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

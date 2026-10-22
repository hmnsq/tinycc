#include <stdio.h>

整数 array[16];

//Swap integer values by array indexes
void swap(整数 a, 整数 b)
{
   整数 tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
整数 partition(整数 left, 整数 right)
{
   整数 pivotIndex = left;
   整数 pivotValue = array[pivotIndex];
   整数 index = left;
   整数 i;

   swap(pivotIndex, right);
   ために(i = left; i < right; i++)
   {
      もし(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   戻る index;
}

//Quicksort the array
void quicksort(整数 left, 整数 right)
{
   もし(left >= right)
      戻る;

   整数 index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

整数 メインページ()
{
   整数 i;

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

   ために (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   ために (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   戻る 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

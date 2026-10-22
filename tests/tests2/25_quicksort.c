#include <stdio.h>

целое array[16];

//Swap integer values by array indexes
void swap(целое a, целое b)
{
   целое tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
целое partition(целое left, целое right)
{
   целое pivotIndex = left;
   целое pivotValue = array[pivotIndex];
   целое index = left;
   целое i;

   swap(pivotIndex, right);
   для(i = left; i < right; i++)
   {
      если(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   вернуть index;
}

//Quicksort the array
void quicksort(целое left, целое right)
{
   если(left >= right)
      вернуть;

   целое index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

целое основной()
{
   целое i;

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

   для (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   для (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   вернуть 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

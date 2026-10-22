#include <stdio.h>

정수 array[16];

//Swap integer values by array indexes
void swap(정수 a, 정수 b)
{
   정수 tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
정수 partition(정수 left, 정수 right)
{
   정수 pivotIndex = left;
   정수 pivotValue = array[pivotIndex];
   정수 index = left;
   정수 i;

   swap(pivotIndex, right);
   위해(i = left; i < right; i++)
   {
      만약(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   반환 index;
}

//Quicksort the array
void quicksort(정수 left, 정수 right)
{
   만약(left >= right)
      반환;

   정수 index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

정수 main()
{
   정수 i;

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

   위해 (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   위해 (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   반환 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#include <stdio.h>

ціле array[16];

//Swap integer values by array indexes
void swap(ціле a, ціле b)
{
   ціле tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ціле partition(ціле left, ціле right)
{
   ціле pivotIndex = left;
   ціле pivotValue = array[pivotIndex];
   ціле index = left;
   ціле i;

   swap(pivotIndex, right);
   для(i = left; i < right; i++)
   {
      якщо(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   повернути index;
}

//Quicksort the array
void quicksort(ціле left, ціле right)
{
   якщо(left >= right)
      повернути;

   ціле index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

ціле main()
{
   ціле i;

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

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

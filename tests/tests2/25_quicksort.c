#include <stdio.h>

số_nguyên array[16];

//Swap integer values by array indexes
void swap(số_nguyên a, số_nguyên b)
{
   số_nguyên tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
số_nguyên partition(số_nguyên left, số_nguyên right)
{
   số_nguyên pivotIndex = left;
   số_nguyên pivotValue = array[pivotIndex];
   số_nguyên index = left;
   số_nguyên i;

   swap(pivotIndex, right);
   cho(i = left; i < right; i++)
   {
      nếu(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   trả_về index;
}

//Quicksort the array
void quicksort(số_nguyên left, số_nguyên right)
{
   nếu(left >= right)
      trả_về;

   số_nguyên index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

số_nguyên main()
{
   số_nguyên i;

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

   cho (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   cho (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

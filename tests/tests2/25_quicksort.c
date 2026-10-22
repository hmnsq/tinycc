#include <stdio.h>

පූර්ණ_සංඛ්‍යා array[16];

//Swap integer values by array indexes
void swap(පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b)
{
   පූර්ණ_සංඛ්‍යා tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
පූර්ණ_සංඛ්‍යා partition(පූර්ණ_සංඛ්‍යා left, පූර්ණ_සංඛ්‍යා right)
{
   පූර්ණ_සංඛ්‍යා pivotIndex = left;
   පූර්ණ_සංඛ්‍යා pivotValue = array[pivotIndex];
   පූර්ණ_සංඛ්‍යා index = left;
   පූර්ණ_සංඛ්‍යා i;

   swap(pivotIndex, right);
   සඳහා(i = left; i < right; i++)
   {
      නම්(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   ආපසු index;
}

//Quicksort the array
void quicksort(පූර්ණ_සංඛ්‍යා left, පූර්ණ_සංඛ්‍යා right)
{
   නම්(left >= right)
      ආපසු;

   පූර්ණ_සංඛ්‍යා index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා i;

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

   සඳහා (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   සඳහා (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

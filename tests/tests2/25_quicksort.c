#include <stdio.h>

ကိန်းပြည့် array[16];

//Swap integer values by array indexes
void swap(ကိန်းပြည့် a, ကိန်းပြည့် b)
{
   ကိန်းပြည့် tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ကိန်းပြည့် partition(ကိန်းပြည့် left, ကိန်းပြည့် right)
{
   ကိန်းပြည့် pivotIndex = left;
   ကိန်းပြည့် pivotValue = array[pivotIndex];
   ကိန်းပြည့် index = left;
   ကိန်းပြည့် i;

   swap(pivotIndex, right);
   အတွက်(i = left; i < right; i++)
   {
      အကယ်၍(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   ပြန်ပေး index;
}

//Quicksort the array
void quicksort(ကိန်းပြည့် left, ကိန်းပြည့် right)
{
   အကယ်၍(left >= right)
      ပြန်ပေး;

   ကိန်းပြည့် index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

ကိန်းပြည့် main()
{
   ကိန်းပြည့် i;

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

   အတွက် (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   အတွက် (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

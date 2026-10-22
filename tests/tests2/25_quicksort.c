#include <stdio.h>

ចំនួនគត់ array[16];

//Swap integer values by array indexes
void swap(ចំនួនគត់ a, ចំនួនគត់ b)
{
   ចំនួនគត់ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ចំនួនគត់ partition(ចំនួនគត់ left, ចំនួនគត់ right)
{
   ចំនួនគត់ pivotIndex = left;
   ចំនួនគត់ pivotValue = array[pivotIndex];
   ចំនួនគត់ index = left;
   ចំនួនគត់ i;

   swap(pivotIndex, right);
   សម្រាប់(i = left; i < right; i++)
   {
      ប្រសិនបើ(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   ត្រឡប់ index;
}

//Quicksort the array
void quicksort(ចំនួនគត់ left, ចំនួនគត់ right)
{
   ប្រសិនបើ(left >= right)
      ត្រឡប់;

   ចំនួនគត់ index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

ចំនួនគត់ main()
{
   ចំនួនគត់ i;

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

   សម្រាប់ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   សម្រាប់ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ត្រឡប់ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

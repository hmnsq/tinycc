#include <stdio.h>

จำนวนเต็ม array[16];

//Swap integer values by array indexes
void swap(จำนวนเต็ม a, จำนวนเต็ม b)
{
   จำนวนเต็ม tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
จำนวนเต็ม partition(จำนวนเต็ม left, จำนวนเต็ม right)
{
   จำนวนเต็ม pivotIndex = left;
   จำนวนเต็ม pivotValue = array[pivotIndex];
   จำนวนเต็ม index = left;
   จำนวนเต็ม i;

   swap(pivotIndex, right);
   สำหรับ(i = left; i < right; i++)
   {
      ถ้า(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   คืน index;
}

//Quicksort the array
void quicksort(จำนวนเต็ม left, จำนวนเต็ม right)
{
   ถ้า(left >= right)
      คืน;

   จำนวนเต็ม index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

จำนวนเต็ม หลัก()
{
   จำนวนเต็ม i;

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

   สำหรับ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   สำหรับ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   คืน 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

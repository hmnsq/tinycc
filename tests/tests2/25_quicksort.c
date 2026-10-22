#include <stdio.h>

int array[16];

//Swap integer values by array indexes
void swap(int a, int b)
{
   int tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
int partition(int कालिवा, int कानान)
{
   int pivotIndex = कालिवा;
   int pivot_हालागा = array[pivotIndex];
   int index = कालिवा;
   int i;

   swap(pivotIndex, कानान);
   for(i = कालिवा; i < कानान; i++)
   {
      if(array[i] < pivot_हालागा)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(कानान, index);

   return index;
}

//Quicksort the array
void quicksort(int कालिवा, int कानान)
{
   if(कालिवा >= कानान)
      return;

   int index = partition(कालिवा, कानान);
   quicksort(कालिवा, index - 1);
   quicksort(index + 1, कानान);
}

int main()
{
   int i;

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

   for (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   for (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

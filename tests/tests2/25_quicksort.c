#include <stdio.h>

puur_naa_nka array[16];

//Swap integer values by array indexes
void swap(puur_naa_nka a, puur_naa_nka b)
{
   puur_naa_nka tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
puur_naa_nka partition(puur_naa_nka left, puur_naa_nka right)
{
   puur_naa_nka pivotIndex = left;
   puur_naa_nka pivotValue = array[pivotIndex];
   puur_naa_nka index = left;
   puur_naa_nka i;

   swap(pivotIndex, right);
   for(i = left; i < right; i++)
   {
      ᮚᮦᮔ᮪(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   ᮝᮜᮤ index;
}

//Quicksort the array
void quicksort(puur_naa_nka left, puur_naa_nka right)
{
   ᮚᮦᮔ᮪(left >= right)
      ᮝᮜᮤ;

   puur_naa_nka index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

puur_naa_nka main()
{
   puur_naa_nka i;

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

   ᮝᮜᮤ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

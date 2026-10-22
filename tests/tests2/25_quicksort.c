#அந்தர்பாவ <stdio.h>

முழு array[16];

//Swap integer values by array indexes
வெறுமை swap(முழு a, முழு b)
{
   முழு tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
முழு partition(முழு இடது, முழு வலது)
{
   முழு pivotIndex = இடது;
   முழு pivot_மதிப்பு = array[pivotIndex];
   முழு index = இடது;
   முழு i;

   swap(pivotIndex, வலது);
   க்கு(i = இடது; i < வலது; i++)
   {
      எனில்(array[i] < pivot_மதிப்பு)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(வலது, index);

   திரும்பு index;
}

//Quicksort the array
வெறுமை quicksort(முழு இடது, முழு வலது)
{
   எனில்(இடது >= வலது)
      திரும்பு;

   முழு index = partition(இடது, வலது);
   quicksort(இடது, index - 1);
   quicksort(index + 1, வலது);
}

முழு முதன்மை()
{
   முழு i;

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

   க்கு (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   க்கு (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

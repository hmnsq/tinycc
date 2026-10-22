#ضمن <stdio.h>

صحيح array[16];

//Swap integer values by array indexes
فراغ swap(صحيح a, صحيح b)
{
   صحيح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحيح partition(صحيح کيري, صحيح کانن)
{
   صحيح pivotIndex = کيري;
   صحيح pivot_نيلاي = array[pivotIndex];
   صحيح index = کيري;
   صحيح i;

   swap(pivotIndex, کانن);
   لكل(i = کيري; i < کانن; i++)
   {
      إذا(array[i] < pivot_نيلاي)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(کانن, index);

   أرجع index;
}

//Quicksort the array
فراغ quicksort(صحيح کيري, صحيح کانن)
{
   إذا(کيري >= کانن)
      أرجع;

   صحيح index = partition(کيري, کانن);
   quicksort(کيري, index - 1);
   quicksort(index + 1, کانن);
}

صحيح main()
{
   صحيح i;

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

   لكل (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   لكل (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

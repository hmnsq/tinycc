#شامل <stdio.h>

صحیح array[16];

//Swap integer values by array indexes
تهی swap(صحیح a, صحیح b)
{
   صحیح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحیح partition(صحیح چپ, صحیح راست)
{
   صحیح pivotIndex = چپ;
   صحیح pivot_مقدار = array[pivotIndex];
   صحیح index = چپ;
   صحیح i;

   swap(pivotIndex, راست);
   برای(i = چپ; i < راست; i++)
   {
      اگر(array[i] < pivot_مقدار)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(راست, index);

   بازگشت index;
}

//Quicksort the array
تهی quicksort(صحیح چپ, صحیح راست)
{
   اگر(چپ >= راست)
      بازگشت;

   صحیح index = partition(چپ, راست);
   quicksort(چپ, index - 1);
   quicksort(index + 1, راست);
}

صحیح اصلی()
{
   صحیح i;

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

   برای (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   برای (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   بازگشت 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

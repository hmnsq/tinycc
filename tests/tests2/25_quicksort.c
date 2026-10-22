#অন্তর্ভাব <stdio.h>

পূর্ণাঙ্ক array[16];

//Swap integer values by array indexes
শূন্য swap(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
{
   পূর্ণাঙ্ক tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
পূর্ণাঙ্ক partition(পূর্ণাঙ্ক বাম, পূর্ণাঙ্ক ডান)
{
   পূর্ণাঙ্ক pivotIndex = বাম;
   পূর্ণাঙ্ক pivot_মান = array[pivotIndex];
   পূর্ণাঙ্ক index = বাম;
   পূর্ণাঙ্ক i;

   swap(pivotIndex, ডান);
   প্রতি(i = বাম; i < ডান; i++)
   {
      যদি(array[i] < pivot_মান)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(ডান, index);

   প্রত্যাগম index;
}

//Quicksort the array
শূন্য quicksort(পূর্ণাঙ্ক বাম, পূর্ণাঙ্ক ডান)
{
   যদি(বাম >= ডান)
      প্রত্যাগম;

   পূর্ণাঙ্ক index = partition(বাম, ডান);
   quicksort(বাম, index - 1);
   quicksort(index + 1, ডান);
}

পূর্ণাঙ্ক main()
{
   পূর্ণাঙ্ক i;

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

   প্রতি (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   প্রতি (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   প্রত্যাগম 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

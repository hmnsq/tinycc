#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা array[16];

//Swap integer values by array indexes
শূন্য swap(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
   পূর্ণসংখ্যা tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
পূর্ণসংখ্যা partition(পূর্ণসংখ্যা বাম, পূর্ণসংখ্যা ডান)
{
   পূর্ণসংখ্যা pivot_সূচক = বাম;
   পূর্ণসংখ্যা pivot_মান = array[pivot_সূচক];
   পূর্ণসংখ্যা সূচক = বাম;
   পূর্ণসংখ্যা i;

   swap(pivot_সূচক, ডান);
   জন্য(i = বাম; i < ডান; i++)
   {
      যদি(array[i] < pivot_মান)
      {
         swap(i, সূচক);
         সূচক += 1;
      }
   }
   swap(ডান, সূচক);

   ফেরত সূচক;
}

//Quicksort the array
শূন্য quicksort(পূর্ণসংখ্যা বাম, পূর্ণসংখ্যা ডান)
{
   যদি(বাম >= ডান)
      ফেরত;

   পূর্ণসংখ্যা সূচক = partition(বাম, ডান);
   quicksort(বাম, সূচক - 1);
   quicksort(সূচক + 1, ডান);
}

পূর্ণসংখ্যা প্রধান()
{
   পূর্ণসংখ্যা i;

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

   জন্য (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   জন্য (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ফেরত 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

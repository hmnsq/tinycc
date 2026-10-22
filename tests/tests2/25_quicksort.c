#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା array[16];

//Swap integer values by array indexes
ଶୂନ୍ୟ swap(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ପୂର୍ଣ୍ଣସଂଖ୍ୟା partition(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ବାମ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଡାହାଣ)
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା pivotIndex = ବାମ;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା pivot_ମୂଲ୍ୟ = array[pivotIndex];
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା index = ବାମ;
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

   swap(pivotIndex, ଡାହାଣ);
   ପାଇଁ(i = ବାମ; i < ଡାହାଣ; i++)
   {
      ଯଦି(array[i] < pivot_ମୂଲ୍ୟ)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(ଡାହାଣ, index);

   ଫେରନ୍ତୁ index;
}

//Quicksort the array
ଶୂନ୍ୟ quicksort(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ବାମ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଡାହାଣ)
{
   ଯଦି(ବାମ >= ଡାହାଣ)
      ଫେରନ୍ତୁ;

   ପୂର୍ଣ୍ଣସଂଖ୍ୟା index = partition(ବାମ, ଡାହାଣ);
   quicksort(ବାମ, index - 1);
   quicksort(index + 1, ଡାହାଣ);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

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

   ପାଇଁ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   ପାଇଁ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ଫେରନ୍ତୁ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

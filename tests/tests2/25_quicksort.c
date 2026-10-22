#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ array[16];

//Swap integer values by array indexes
ಶೂನ್ಯ swap(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
   ಪೂರ್ಣಾಙ್ಕ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ಪೂರ್ಣಾಙ್ಕ partition(ಪೂರ್ಣಾಙ್ಕ ಎಡ, ಪೂರ್ಣಾಙ್ಕ ಬಲ)
{
   ಪೂರ್ಣಾಙ್ಕ pivotIndex = ಎಡ;
   ಪೂರ್ಣಾಙ್ಕ pivot_ಮೌಲ್ಯ = array[pivotIndex];
   ಪೂರ್ಣಾಙ್ಕ index = ಎಡ;
   ಪೂರ್ಣಾಙ್ಕ i;

   swap(pivotIndex, ಬಲ);
   ಪ್ರತಿ(i = ಎಡ; i < ಬಲ; i++)
   {
      ಯದಿ(array[i] < pivot_ಮೌಲ್ಯ)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(ಬಲ, index);

   ಪ್ರತ್ಯಾಗಮ index;
}

//Quicksort the array
ಶೂನ್ಯ quicksort(ಪೂರ್ಣಾಙ್ಕ ಎಡ, ಪೂರ್ಣಾಙ್ಕ ಬಲ)
{
   ಯದಿ(ಎಡ >= ಬಲ)
      ಪ್ರತ್ಯಾಗಮ;

   ಪೂರ್ಣಾಙ್ಕ index = partition(ಎಡ, ಬಲ);
   quicksort(ಎಡ, index - 1);
   quicksort(index + 1, ಬಲ);
}

ಪೂರ್ಣಾಙ್ಕ main()
{
   ಪೂರ್ಣಾಙ್ಕ i;

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

   ಪ್ರತಿ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   ಪ್ರತಿ (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

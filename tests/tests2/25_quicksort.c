#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ array[16];

//Swap integer values by array indexes
ಶೂನ್ಯ ಅದಲುಬದಲು_2(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
   ಪೂರ್ಣಾಂಕ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ಪೂರ್ಣಾಂಕ ವಿಭಜನೆ(ಪೂರ್ಣಾಂಕ ಎಡ, ಪೂರ್ಣಾಂಕ ಬಲ)
{
   ಪೂರ್ಣಾಂಕ ಅಚ್ಚು_ಸೂಚ್ಯಂಕ = ಎಡ;
   ಪೂರ್ಣಾಂಕ ಅಚ್ಚು_ಮೌಲ್ಯ = array[ಅಚ್ಚು_ಸೂಚ್ಯಂಕ];
   ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = ಎಡ;
   ಪೂರ್ಣಾಂಕ i;

   ಅದಲುಬದಲು_2(ಅಚ್ಚು_ಸೂಚ್ಯಂಕ, ಬಲ);
   ಗಾಗಿ(i = ಎಡ; i < ಬಲ; i++)
   {
      ಆದರೆ(array[i] < ಅಚ್ಚು_ಮೌಲ್ಯ)
      {
         ಅದಲುಬದಲು_2(i, ಸೂಚ್ಯಂಕ);
         ಸೂಚ್ಯಂಕ += 1;
      }
   }
   ಅದಲುಬದಲು_2(ಬಲ, ಸೂಚ್ಯಂಕ);

   ಹಿಂತಿರುಗಿ ಸೂಚ್ಯಂಕ;
}

//Quicksort the array
ಶೂನ್ಯ quicksort(ಪೂರ್ಣಾಂಕ ಎಡ, ಪೂರ್ಣಾಂಕ ಬಲ)
{
   ಆದರೆ(ಎಡ >= ಬಲ)
      ಹಿಂತಿರುಗಿ;

   ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ = ವಿಭಜನೆ(ಎಡ, ಬಲ);
   quicksort(ಎಡ, ಸೂಚ್ಯಂಕ - 1);
   quicksort(ಸೂಚ್ಯಂಕ + 1, ಬಲ);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಪೂರ್ಣಾಂಕ i;

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

   ಗಾಗಿ (i = 0; i < 16; i++)
      ಬರೆ("%d ", array[i]);

   ಬರೆ("\n");

   quicksort(0, 15);

   ಗಾಗಿ (i = 0; i < 16; i++)
      ಬರೆ("%d ", array[i]);

   ಬರೆ("\n");

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

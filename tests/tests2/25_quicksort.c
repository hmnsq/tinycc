#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ array[16];

//Swap integer values by array indexes
ശൂന്യം swap(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
   പൂർണ്ണസംഖ്യ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
പൂർണ്ണസംഖ്യ partition(പൂർണ്ണസംഖ്യ ഇടത്, പൂർണ്ണസംഖ്യ വലത്)
{
   പൂർണ്ണസംഖ്യ pivotIndex = ഇടത്;
   പൂർണ്ണസംഖ്യ pivot_മൂല്യം = array[pivotIndex];
   പൂർണ്ണസംഖ്യ index = ഇടത്;
   പൂർണ്ണസംഖ്യ i;

   swap(pivotIndex, വലത്);
   വേണ്ടി(i = ഇടത്; i < വലത്; i++)
   {
      എങ്കിൽ(array[i] < pivot_മൂല്യം)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(വലത്, index);

   തിരികെ index;
}

//Quicksort the array
ശൂന്യം quicksort(പൂർണ്ണസംഖ്യ ഇടത്, പൂർണ്ണസംഖ്യ വലത്)
{
   എങ്കിൽ(ഇടത് >= വലത്)
      തിരികെ;

   പൂർണ്ണസംഖ്യ index = partition(ഇടത്, വലത്);
   quicksort(ഇടത്, index - 1);
   quicksort(index + 1, വലത്);
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ i;

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

   വേണ്ടി (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   വേണ്ടി (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

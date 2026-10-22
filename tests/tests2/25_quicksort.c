#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક array[16];

//Swap integer values by array indexes
શૂન્ય swap(પૂર્ણાંક a, પૂર્ણાંક b)
{
   પૂર્ણાંક tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
પૂર્ણાંક partition(પૂર્ણાંક ડાબું, પૂર્ણાંક જમણું)
{
   પૂર્ણાંક pivotIndex = ડાબું;
   પૂર્ણાંક pivot_કિંમત = array[pivotIndex];
   પૂર્ણાંક index = ડાબું;
   પૂર્ણાંક i;

   swap(pivotIndex, જમણું);
   માટે(i = ડાબું; i < જમણું; i++)
   {
      જો(array[i] < pivot_કિંમત)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(જમણું, index);

   પાછા index;
}

//Quicksort the array
શૂન્ય quicksort(પૂર્ણાંક ડાબું, પૂર્ણાંક જમણું)
{
   જો(ડાબું >= જમણું)
      પાછા;

   પૂર્ણાંક index = partition(ડાબું, જમણું);
   quicksort(ડાબું, index - 1);
   quicksort(index + 1, જમણું);
}

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક i;

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

   માટે (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   માટે (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

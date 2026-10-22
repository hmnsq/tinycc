#समावेश <stdio.h>

पूर्णांक array[16];

//Swap integer values by array indexes
व्योम swap(पूर्णांक a, पूर्णांक b)
{
   पूर्णांक tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
पूर्णांक partition(पूर्णांक बायाँ, पूर्णांक दायाँ)
{
   पूर्णांक pivot_सूचकांक = बायाँ;
   पूर्णांक pivot_मूल्य = array[pivot_सूचकांक];
   पूर्णांक सूचकांक = बायाँ;
   पूर्णांक i;

   swap(pivot_सूचकांक, दायाँ);
   क्रम(i = बायाँ; i < दायाँ; i++)
   {
      अगर(array[i] < pivot_मूल्य)
      {
         swap(i, सूचकांक);
         सूचकांक += 1;
      }
   }
   swap(दायाँ, सूचकांक);

   वापस सूचकांक;
}

//Quicksort the array
व्योम quicksort(पूर्णांक बायाँ, पूर्णांक दायाँ)
{
   अगर(बायाँ >= दायाँ)
      वापस;

   पूर्णांक सूचकांक = partition(बायाँ, दायाँ);
   quicksort(बायाँ, सूचकांक - 1);
   quicksort(सूचकांक + 1, दायाँ);
}

पूर्णांक मुख्य()
{
   पूर्णांक i;

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

   क्रम (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   quicksort(0, 15);

   क्रम (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

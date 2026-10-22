#अन्तर्भाव <stdio.h>

पूर्णाङ्क array[16];

//Swap integer values by array indexes
शून्य swap(पूर्णाङ्क a, पूर्णाङ्क b)
{
   पूर्णाङ्क tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
पूर्णाङ्क partition(पूर्णाङ्क बायाँ, पूर्णाङ्क दायाँ)
{
   पूर्णाङ्क pivotIndex = बायाँ;
   पूर्णाङ्क pivot_मान = array[pivotIndex];
   पूर्णाङ्क index = बायाँ;
   पूर्णाङ्क i;

   swap(pivotIndex, दायाँ);
   लागि(i = बायाँ; i < दायाँ; i++)
   {
      यदि(array[i] < pivot_मान)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(दायाँ, index);

   फर्काऊ index;
}

//Quicksort the array
शून्य quicksort(पूर्णाङ्क बायाँ, पूर्णाङ्क दायाँ)
{
   यदि(बायाँ >= दायाँ)
      फर्काऊ;

   पूर्णाङ्क index = partition(बायाँ, दायाँ);
   quicksort(बायाँ, index - 1);
   quicksort(index + 1, दायाँ);
}

पूर्णाङ्क main()
{
   पूर्णाङ्क i;

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

   लागि (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   quicksort(0, 15);

   लागि (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

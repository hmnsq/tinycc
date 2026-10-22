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
पूर्णाङ्क partition(पूर्णाङ्क डावा, पूर्णाङ्क उजवा)
{
   पूर्णाङ्क pivotIndex = डावा;
   पूर्णाङ्क pivot_मूल्य = array[pivotIndex];
   पूर्णाङ्क index = डावा;
   पूर्णाङ्क i;

   swap(pivotIndex, उजवा);
   प्रति(i = डावा; i < उजवा; i++)
   {
      यदि(array[i] < pivot_मूल्य)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(उजवा, index);

   प्रत्यागम index;
}

//Quicksort the array
शून्य quicksort(पूर्णाङ्क डावा, पूर्णाङ्क उजवा)
{
   यदि(डावा >= उजवा)
      प्रत्यागम;

   पूर्णाङ्क index = partition(डावा, उजवा);
   quicksort(डावा, index - 1);
   quicksort(index + 1, उजवा);
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

   प्रति (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   प्रति (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

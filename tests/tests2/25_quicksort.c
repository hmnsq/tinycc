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
पूर्णाङ्क partition(पूर्णाङ्क वामः, पूर्णाङ्क दक्षिणः)
{
   पूर्णाङ्क pivotIndex = वामः;
   पूर्णाङ्क pivot_मानम् = array[pivotIndex];
   पूर्णाङ्क index = वामः;
   पूर्णाङ्क i;

   swap(pivotIndex, दक्षिणः);
   अत्थाय(i = वामः; i < दक्षिणः; i++)
   {
      सचे(array[i] < pivot_मानम्)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(दक्षिणः, index);

   पटिनिवत्त index;
}

//Quicksort the array
शून्य quicksort(पूर्णाङ्क वामः, पूर्णाङ्क दक्षिणः)
{
   सचे(वामः >= दक्षिणः)
      पटिनिवत्त;

   पूर्णाङ्क index = partition(वामः, दक्षिणः);
   quicksort(वामः, index - 1);
   quicksort(index + 1, दक्षिणः);
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

   अत्थाय (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   अत्थाय (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

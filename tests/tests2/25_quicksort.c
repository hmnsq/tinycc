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
   पूर्णाङ्क pivot_सूचकांक = वामः;
   पूर्णाङ्क pivot_मानम् = array[pivot_सूचकांक];
   पूर्णाङ्क सूचकांक = वामः;
   पूर्णाङ्क i;

   swap(pivot_सूचकांक, दक्षिणः);
   प्रति(i = वामः; i < दक्षिणः; i++)
   {
      यदि(array[i] < pivot_मानम्)
      {
         swap(i, सूचकांक);
         सूचकांक += 1;
      }
   }
   swap(दक्षिणः, सूचकांक);

   प्रत्यागम सूचकांक;
}

//Quicksort the array
शून्य quicksort(पूर्णाङ्क वामः, पूर्णाङ्क दक्षिणः)
{
   यदि(वामः >= दक्षिणः)
      प्रत्यागम;

   पूर्णाङ्क सूचकांक = partition(वामः, दक्षिणः);
   quicksort(वामः, सूचकांक - 1);
   quicksort(सूचकांक + 1, दक्षिणः);
}

पूर्णाङ्क मुख्यम्()
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
      प्रारूप_लिख("%d ", array[i]);

   प्रारूप_लिख("\n");

   quicksort(0, 15);

   प्रति (i = 0; i < 16; i++)
      प्रारूप_लिख("%d ", array[i]);

   प्रारूप_लिख("\n");

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

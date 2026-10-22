#अन्तर्भाव <stdio.h>

पूर्णांक array[16];

//Swap integer values by array indexes
शून्य swap(पूर्णांक a, पूर्णांक b)
{
   पूर्णांक tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
पूर्णांक partition(पूर्णांक डावा, पूर्णांक उजवा)
{
   पूर्णांक pivotIndex = डावा;
   पूर्णांक pivot_मूल्य = array[pivotIndex];
   पूर्णांक index = डावा;
   पूर्णांक i;

   swap(pivotIndex, उजवा);
   साठी(i = डावा; i < उजवा; i++)
   {
      जर(array[i] < pivot_मूल्य)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(उजवा, index);

   परत index;
}

//Quicksort the array
शून्य quicksort(पूर्णांक डावा, पूर्णांक उजवा)
{
   जर(डावा >= उजवा)
      परत;

   पूर्णांक index = partition(डावा, उजवा);
   quicksort(डावा, index - 1);
   quicksort(index + 1, उजवा);
}

पूर्णांक main()
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

   साठी (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   quicksort(0, 15);

   साठी (i = 0; i < 16; i++)
      म_लिखो("%d ", array[i]);

   म_लिखो("\n");

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

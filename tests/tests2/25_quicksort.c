#అన్తర్భావ <stdio.h>

పూర్ణాంకం array[16];

//Swap integer values by array indexes
శూన్య మార్పిడి_2(పూర్ణాంకం a, పూర్ణాంకం b)
{
   పూర్ణాంకం tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
పూర్ణాంకం విభజన(పూర్ణాంకం ఎడమ, పూర్ణాంకం కుడి)
{
   పూర్ణాంకం ఇరుసు_సూచీ = ఎడమ;
   పూర్ణాంకం ఇరుసు_విలువ = array[ఇరుసు_సూచీ];
   పూర్ణాంకం సూచీ = ఎడమ;
   పూర్ణాంకం i;

   మార్పిడి_2(ఇరుసు_సూచీ, కుడి);
   కొరకు(i = ఎడమ; i < కుడి; i++)
   {
      ఒకవేళ(array[i] < ఇరుసు_విలువ)
      {
         మార్పిడి_2(i, సూచీ);
         సూచీ += 1;
      }
   }
   మార్పిడి_2(కుడి, సూచీ);

   తిరిగి సూచీ;
}

//Quicksort the array
శూన్య quicksort(పూర్ణాంకం ఎడమ, పూర్ణాంకం కుడి)
{
   ఒకవేళ(ఎడమ >= కుడి)
      తిరిగి;

   పూర్ణాంకం సూచీ = విభజన(ఎడమ, కుడి);
   quicksort(ఎడమ, సూచీ - 1);
   quicksort(సూచీ + 1, కుడి);
}

పూర్ణాంకం ప్రధాన()
{
   పూర్ణాంకం i;

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

   కొరకు (i = 0; i < 16; i++)
      రాయి("%d ", array[i]);

   రాయి("\n");

   quicksort(0, 15);

   కొరకు (i = 0; i < 16; i++)
      రాయి("%d ", array[i]);

   రాయి("\n");

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

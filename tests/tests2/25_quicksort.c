#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ array[16];

//Swap integer values by array indexes
ਖਾਲੀ ਅਦਲਾ_ਬਦਲੀ_2(ਪੂਰਨ a, ਪੂਰਨ b)
{
   ਪੂਰਨ tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
ਪੂਰਨ ਹਿੱਸੇ_ਕਰੋ(ਪੂਰਨ ਖੱਬਾ, ਪੂਰਨ ਸੱਜਾ)
{
   ਪੂਰਨ ਧੁਰਾ_ਸੂਚਕਾਂਕ = ਖੱਬਾ;
   ਪੂਰਨ ਧੁਰਾ_ਮੁੱਲ = array[ਧੁਰਾ_ਸੂਚਕਾਂਕ];
   ਪੂਰਨ ਸੂਚਕਾਂਕ = ਖੱਬਾ;
   ਪੂਰਨ i;

   ਅਦਲਾ_ਬਦਲੀ_2(ਧੁਰਾ_ਸੂਚਕਾਂਕ, ਸੱਜਾ);
   ਲਈ(i = ਖੱਬਾ; i < ਸੱਜਾ; i++)
   {
      ਜੇ(array[i] < ਧੁਰਾ_ਮੁੱਲ)
      {
         ਅਦਲਾ_ਬਦਲੀ_2(i, ਸੂਚਕਾਂਕ);
         ਸੂਚਕਾਂਕ += 1;
      }
   }
   ਅਦਲਾ_ਬਦਲੀ_2(ਸੱਜਾ, ਸੂਚਕਾਂਕ);

   ਵਾਪਸ ਸੂਚਕਾਂਕ;
}

//Quicksort the array
ਖਾਲੀ quicksort(ਪੂਰਨ ਖੱਬਾ, ਪੂਰਨ ਸੱਜਾ)
{
   ਜੇ(ਖੱਬਾ >= ਸੱਜਾ)
      ਵਾਪਸ;

   ਪੂਰਨ ਸੂਚਕਾਂਕ = ਹਿੱਸੇ_ਕਰੋ(ਖੱਬਾ, ਸੱਜਾ);
   quicksort(ਖੱਬਾ, ਸੂਚਕਾਂਕ - 1);
   quicksort(ਸੂਚਕਾਂਕ + 1, ਸੱਜਾ);
}

ਪੂਰਨ ਮੁੱਖ()
{
   ਪੂਰਨ i;

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

   ਲਈ (i = 0; i < 16; i++)
      ਲਿਖੋ("%d ", array[i]);

   ਲਿਖੋ("\n");

   quicksort(0, 15);

   ਲਈ (i = 0; i < 16; i++)
      ਲਿਖੋ("%d ", array[i]);

   ਲਿਖੋ("\n");

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

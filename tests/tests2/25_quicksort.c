#ضمن <stdio.h>

صحيح array[16];

//Swap integer values by array indexes
فراغ مٽا_سٽا_2(صحيح a, صحيح b)
{
   صحيح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحيح حصا_ڪريو(صحيح کاٻو, صحيح ساڄو)
{
   صحيح محور_اشاريو = کاٻو;
   صحيح محور_قدر = array[محور_اشاريو];
   صحيح اشاريو = کاٻو;
   صحيح i;

   مٽا_سٽا_2(محور_اشاريو, ساڄو);
   لكل(i = کاٻو; i < ساڄو; i++)
   {
      إذا(array[i] < محور_قدر)
      {
         مٽا_سٽا_2(i, اشاريو);
         اشاريو += 1;
      }
   }
   مٽا_سٽا_2(ساڄو, اشاريو);

   أرجع اشاريو;
}

//Quicksort the array
فراغ quicksort(صحيح کاٻو, صحيح ساڄو)
{
   إذا(کاٻو >= ساڄو)
      أرجع;

   صحيح اشاريو = حصا_ڪريو(کاٻو, ساڄو);
   quicksort(کاٻو, اشاريو - 1);
   quicksort(اشاريو + 1, ساڄو);
}

صحيح مکيه()
{
   صحيح i;

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

   لكل (i = 0; i < 16; i++)
      لکو("%d ", array[i]);

   لکو("\n");

   quicksort(0, 15);

   لكل (i = 0; i < 16; i++)
      لکو("%d ", array[i]);

   لکو("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

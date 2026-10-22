#ضمن <stdio.h>

صحيح array[16];

//Swap integer values by array indexes
فراغ جابجا_2(صحيح a, صحيح b)
{
   صحيح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحيح افراز(صحيح چپ, صحيح راست)
{
   صحيح محور_شاخص = چپ;
   صحيح محور_مقدار = array[محور_شاخص];
   صحيح شاخص = چپ;
   صحيح i;

   جابجا_2(محور_شاخص, راست);
   لكل(i = چپ; i < راست; i++)
   {
      إذا(array[i] < محور_مقدار)
      {
         جابجا_2(i, شاخص);
         شاخص += 1;
      }
   }
   جابجا_2(راست, شاخص);

   أرجع شاخص;
}

//Quicksort the array
فراغ quicksort(صحيح چپ, صحيح راست)
{
   إذا(چپ >= راست)
      أرجع;

   صحيح شاخص = افراز(چپ, راست);
   quicksort(چپ, شاخص - 1);
   quicksort(شاخص + 1, راست);
}

صحيح اصلی()
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
      چاپ_کن("%d ", array[i]);

   چاپ_کن("\n");

   quicksort(0, 15);

   لكل (i = 0; i < 16; i++)
      چاپ_کن("%d ", array[i]);

   چاپ_کن("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

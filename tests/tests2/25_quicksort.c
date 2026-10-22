#ضمن <stdio.h>

صحيح array[16];

//Swap integer values by array indexes
فراغ بدلون_2(صحيح a, صحيح b)
{
   صحيح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحيح برخه_کول(صحيح کیڼ, صحيح ښی)
{
   صحيح محور_شاخص = کیڼ;
   صحيح محور_ارزښت = array[محور_شاخص];
   صحيح شاخص = کیڼ;
   صحيح i;

   بدلون_2(محور_شاخص, ښی);
   لكل(i = کیڼ; i < ښی; i++)
   {
      إذا(array[i] < محور_ارزښت)
      {
         بدلون_2(i, شاخص);
         شاخص += 1;
      }
   }
   بدلون_2(ښی, شاخص);

   أرجع شاخص;
}

//Quicksort the array
فراغ quicksort(صحيح کیڼ, صحيح ښی)
{
   إذا(کیڼ >= ښی)
      أرجع;

   صحيح شاخص = برخه_کول(کیڼ, ښی);
   quicksort(کیڼ, شاخص - 1);
   quicksort(شاخص + 1, ښی);
}

صحيح اصلي()
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
      چاپ_کړه("%d ", array[i]);

   چاپ_کړه("\n");

   quicksort(0, 15);

   لكل (i = 0; i < 16; i++)
      چاپ_کړه("%d ", array[i]);

   چاپ_کړه("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

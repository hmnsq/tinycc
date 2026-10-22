#ضمن <stdio.h>

صحيح array[16];

//Swap integer values by array indexes
فراغ وٹاندرا_2(صحيح a, صحيح b)
{
   صحيح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحيح حصے_کرو(صحيح بایاں, صحيح دایاں)
{
   صحيح دھرا_اشاریہ = بایاں;
   صحيح دھرا_قدر = array[دھرا_اشاریہ];
   صحيح اشاریہ = بایاں;
   صحيح i;

   وٹاندرا_2(دھرا_اشاریہ, دایاں);
   لكل(i = بایاں; i < دایاں; i++)
   {
      إذا(array[i] < دھرا_قدر)
      {
         وٹاندرا_2(i, اشاریہ);
         اشاریہ += 1;
      }
   }
   وٹاندرا_2(دایاں, اشاریہ);

   أرجع اشاریہ;
}

//Quicksort the array
فراغ quicksort(صحيح بایاں, صحيح دایاں)
{
   إذا(بایاں >= دایاں)
      أرجع;

   صحيح اشاریہ = حصے_کرو(بایاں, دایاں);
   quicksort(بایاں, اشاریہ - 1);
   quicksort(اشاریہ + 1, دایاں);
}

صحيح مکھ()
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
      لکھو("%d ", array[i]);

   لکھو("\n");

   quicksort(0, 15);

   لكل (i = 0; i < 16; i++)
      لکھو("%d ", array[i]);

   لکھو("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

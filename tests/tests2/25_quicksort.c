#شامل <stdio.h>

صحیح array[16];

//Swap integer values by array indexes
خالی تبادلہ_2(صحیح a, صحیح b)
{
   صحیح tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
صحیح تقسیم(صحیح بایاں, صحیح دایاں)
{
   صحیح محور_اشاریہ = بایاں;
   صحیح محور_قدر = array[محور_اشاریہ];
   صحیح اشاریہ = بایاں;
   صحیح i;

   تبادلہ_2(محور_اشاریہ, دایاں);
   برائے(i = بایاں; i < دایاں; i++)
   {
      اگر(array[i] < محور_قدر)
      {
         تبادلہ_2(i, اشاریہ);
         اشاریہ += 1;
      }
   }
   تبادلہ_2(دایاں, اشاریہ);

   واپس اشاریہ;
}

//Quicksort the array
خالی quicksort(صحیح بایاں, صحیح دایاں)
{
   اگر(بایاں >= دایاں)
      واپس;

   صحیح اشاریہ = تقسیم(بایاں, دایاں);
   quicksort(بایاں, اشاریہ - 1);
   quicksort(اشاریہ + 1, دایاں);
}

صحیح مین()
{
   صحیح i;

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

   برائے (i = 0; i < 16; i++)
      لکھو("%d ", array[i]);

   لکھو("\n");

   quicksort(0, 15);

   برائے (i = 0; i < 16; i++)
      لکھو("%d ", array[i]);

   لکھو("\n");

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

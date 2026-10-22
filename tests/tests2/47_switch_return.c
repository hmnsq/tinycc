#ضمن <stdio.h>

فراغ fred(صحيح x)
{
   بدل (x)
   {
      حالة 1: printf("1\n"); إرجاع;
      حالة 2: printf("2\n"); اكسر;
      حالة 3: printf("3\n"); إرجاع;
   }

   printf("out\n");
}

صحيح الرئيسية()
{
   fred(1);
   fred(2);
   fred(3);

   إرجاع 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

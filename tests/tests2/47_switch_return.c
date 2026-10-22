#ضمن <stdio.h>

فراغ fred(صحيح x)
{
   بدل (x)
   {
      حالة 1: printf("1\n"); أرجع;
      حالة 2: printf("2\n"); اكسر;
      حالة 3: printf("3\n"); أرجع;
   }

   printf("out\n");
}

صحيح main()
{
   fred(1);
   fred(2);
   fred(3);

   أرجع 0;
}    

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

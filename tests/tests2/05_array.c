#ضمن <stdio.h>

صحيح main() 
{
   صحيح Count;
   صحيح Array[10];

   لكل (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   لكل (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ܦܢܐ 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :

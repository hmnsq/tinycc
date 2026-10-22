#ضمن <stdio.h>

صحيح main() 
{
   صحيح Count;
   صحيح Array[10];

   עבור (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   עבור (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   החזר 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :

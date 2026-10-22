#ضمن <stdio.h>

صحيح main()
{
   صحيح a;
   حرف b;

   a = 0;
   طالما (a < 2)
   {
      printf("%d", a++);
      اكسر;

      b = 'A';
      طالما (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

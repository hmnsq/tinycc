#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح Count;

   لكل (Count = 1; Count <= 20; Count++)
   {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   ܦܢܐ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

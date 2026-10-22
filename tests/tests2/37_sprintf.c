#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح کيراءن_3;

   لكل (کيراءن_3 = 1; کيراءن_3 <= 20; کيراءن_3++)
   {
      sprintf(Buf, "->%02d<-\n", کيراءن_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

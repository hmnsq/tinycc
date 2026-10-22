#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح عدد_3;

   لكل (عدد_3 = 1; عدد_3 <= 20; عدد_3++)
   {
      sprintf(Buf, "->%02d<-\n", عدد_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح گنتی_3;

   لكل (گنتی_3 = 1; گنتی_3 <= 20; گنتی_3++)
   {
      sprintf(Buf, "->%02d<-\n", گنتی_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

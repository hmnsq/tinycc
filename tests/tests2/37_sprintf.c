#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح سانى_3;

   لكل (سانى_3 = 1; سانى_3 <= 20; سانى_3++)
   {
      sprintf(Buf, "->%02d<-\n", سانى_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

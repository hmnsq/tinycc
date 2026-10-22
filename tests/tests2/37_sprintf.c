#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح كدي_3;

   لكل (كدي_3 = 1; كدي_3 <= 20; كدي_3++)
   {
      sprintf(Buf, "->%02d<-\n", كدي_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

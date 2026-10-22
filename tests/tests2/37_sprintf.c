#ضمن <stdio.h>

صحيح main()
{
   حرف Buf[100];
   صحيح ژماردن_3;

   لكل (ژماردن_3 = 1; ژماردن_3 <= 20; ژماردن_3++)
   {
      sprintf(Buf, "->%02d<-\n", ژماردن_3);
      printf("%s", Buf);
   }

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

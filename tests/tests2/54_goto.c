#അന്തര്ഭാവ <stdio.h>

ശൂന്യം fred()
{
   printf("In fred()\n");
   പോകുക done;
   printf("In middle\n");
done:
   printf("At end\n");
}

ശൂന്യം joe()
{
   പൂർണ്ണസംഖ്യ b = 5678;

   printf("In joe()\n");

   {
      പൂർണ്ണസംഖ്യ c = 1234;
      printf("c = %d\n", c);
      പോകുക outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

ശൂന്യം henry()
{
   പൂർണ്ണസംഖ്യ a;

   printf("In henry()\n");
   പോകുക inner;

   {
      പൂർണ്ണസംഖ്യ b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   fred();
   joe();
   henry();

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

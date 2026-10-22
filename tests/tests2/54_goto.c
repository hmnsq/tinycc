#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਖਾਲੀ fred()
{
   ਲਿਖੋ("In fred()\n");
   ਜਾਓ ਪੂਰਾ;
   ਲਿਖੋ("In middle\n");
ਪੂਰਾ:
   ਲਿਖੋ("At end\n");
}

ਖਾਲੀ joe()
{
   ਪੂਰਨ b = 5678;

   ਲਿਖੋ("In joe()\n");

   {
      ਪੂਰਨ c = 1234;
      ਲਿਖੋ("c = %d\n", c);
      ਜਾਓ outer;
      ਲਿਖੋ("uh-oh\n");
   }

outer:    

   ਲਿਖੋ("done\n");
}

ਖਾਲੀ henry()
{
   ਪੂਰਨ a;

   ਲਿਖੋ("In henry()\n");
   ਜਾਓ inner;

   {
      ਪੂਰਨ b;
inner:    
      b = 1234;
      ਲਿਖੋ("b = %d\n", b);
   }

   ਲਿਖੋ("done\n");
}

ਪੂਰਨ ਮੁੱਖ()
{
   fred();
   joe();
   henry();

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

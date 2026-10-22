#અન્તર્ભાવ <stdio.h>

શૂન્ય fred()
{
   printf("In fred()\n");
   જાઓ done;
   printf("In middle\n");
done:
   printf("At end\n");
}

શૂન્ય joe()
{
   પૂર્ણાંક b = 5678;

   printf("In joe()\n");

   {
      પૂર્ણાંક c = 1234;
      printf("c = %d\n", c);
      જાઓ outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

શૂન્ય henry()
{
   પૂર્ણાંક a;

   printf("In henry()\n");
   જાઓ inner;

   {
      પૂર્ણાંક b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

પૂર્ણાંક મુખ્ય()
{
   fred();
   joe();
   henry();

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

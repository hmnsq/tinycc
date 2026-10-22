#अन्तर्भाव <stdio.h>

शून्य fred()
{
   printf("In fred()\n");
   गच्छ done;
   printf("In middle\n");
done:
   printf("At end\n");
}

शून्य joe()
{
   पूर्णाङ्क b = 5678;

   printf("In joe()\n");

   {
      पूर्णाङ्क c = 1234;
      printf("c = %d\n", c);
      गच्छ outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

शून्य henry()
{
   पूर्णाङ्क a;

   printf("In henry()\n");
   गच्छ inner;

   {
      पूर्णाङ्क b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

पूर्णाङ्क main()
{
   fred();
   joe();
   henry();

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

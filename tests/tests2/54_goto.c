#ಅನ್ತರ್ಭಾವ <stdio.h>

ಶೂನ್ಯ fred()
{
   printf("In fred()\n");
   ಗಚ್ಛ done;
   printf("In middle\n");
done:
   printf("At end\n");
}

ಶೂನ್ಯ joe()
{
   ಪೂರ್ಣಾಙ್ಕ b = 5678;

   printf("In joe()\n");

   {
      ಪೂರ್ಣಾಙ್ಕ c = 1234;
      printf("c = %d\n", c);
      ಗಚ್ಛ outer;
      printf("uh-oh\n");
   }

outer:    

   printf("done\n");
}

ಶೂನ್ಯ henry()
{
   ಪೂರ್ಣಾಙ್ಕ a;

   printf("In henry()\n");
   ಗಚ್ಛ inner;

   {
      ಪೂರ್ಣಾಙ್ಕ b;
inner:    
      b = 1234;
      printf("b = %d\n", b);
   }

   printf("done\n");
}

ಪೂರ್ಣಾಙ್ಕ main()
{
   fred();
   joe();
   henry();

   ಪ್ರತ್ಯಾಗಮ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

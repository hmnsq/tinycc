#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
   പൂർണ്ണസംഖ്യ a;
   അക്ഷരം b;

   a = 0;
   ആകുമ്പോൾ (a < 2)
   {
      printf("%d", a++);
      നിർത്തുക;

      b = 'A';
      ആകുമ്പോൾ (b < 'C')
      {
         printf("%c", b++);
      }
      printf("e");
   }
   printf("\n");

   തിരികെ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

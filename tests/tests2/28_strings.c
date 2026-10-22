#شامل <stdio.h>
#شامل <string.h>

صحیح مین()
{
   حرف a[10];

   strcpy(a, "hello");
   لکھو("%s\n", a);

   strncpy(a, "gosh", 2);
   لکھو("%s\n", a);

   لکھو("%d\n", strcmp(a, "apple") > 0);
   لکھو("%d\n", strcmp(a, "goere") > 0);
   لکھو("%d\n", strcmp(a, "zebra") < 0);

   لکھو("%d\n", لڑی_لمبائی(a));

   strcat(a, "!");
   لکھو("%s\n", a);

   لکھو("%d\n", لڑی_موازنہ(a, "apple", 2) > 0);
   لکھو("%d\n", لڑی_موازنہ(a, "goere", 2) == 0);
   لکھو("%d\n", لڑی_موازنہ(a, "goerg", 2) == 0);
   لکھو("%d\n", لڑی_موازنہ(a, "zebra", 2) < 0);

   لکھو("%s\n", strchr(a, 'o'));
   لکھو("%s\n", strrchr(a, 'l'));
   لکھو("%d\n", strrchr(a, 'x') == تہی);

   memset(&a[1], 'r', 4);
   لکھو("%s\n", a);

   حافظہ_نقل(&a[2], a, 2);
   لکھو("%s\n", a);

   لکھو("%d\n", memcmp(a, "apple", 4) > 0);
   لکھو("%d\n", memcmp(a, "grgr", 4) == 0);
   لکھو("%d\n", memcmp(a, "zebra", 4) < 0);

   واپس 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

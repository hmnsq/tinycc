#ضمن <stdio.h>
#ضمن <string.h>

صحيح مکيه()
{
   حرف a[10];

   strcpy(a, "hello");
   لکو("%s\n", a);

   strncpy(a, "gosh", 2);
   لکو("%s\n", a);

   لکو("%d\n", strcmp(a, "apple") > 0);
   لکو("%d\n", strcmp(a, "goere") > 0);
   لکو("%d\n", strcmp(a, "zebra") < 0);

   لکو("%d\n", لڙي_ڊيگهه(a));

   strcat(a, "!");
   لکو("%s\n", a);

   لکو("%d\n", لڙي_ڀيٽ(a, "apple", 2) > 0);
   لکو("%d\n", لڙي_ڀيٽ(a, "goere", 2) == 0);
   لکو("%d\n", لڙي_ڀيٽ(a, "goerg", 2) == 0);
   لکو("%d\n", لڙي_ڀيٽ(a, "zebra", 2) < 0);

   لکو("%s\n", strchr(a, 'o'));
   لکو("%s\n", strrchr(a, 'l'));
   لکو("%d\n", strrchr(a, 'x') == عدم);

   memset(&a[1], 'r', 4);
   لکو("%s\n", a);

   يادگيري_نقل(&a[2], a, 2);
   لکو("%s\n", a);

   لکو("%d\n", memcmp(a, "apple", 4) > 0);
   لکو("%d\n", memcmp(a, "grgr", 4) == 0);
   لکو("%d\n", memcmp(a, "zebra", 4) < 0);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

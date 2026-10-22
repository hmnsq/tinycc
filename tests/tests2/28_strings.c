#ضمن <stdio.h>
#ضمن <string.h>

صحيح اصلي()
{
   حرف a[10];

   strcpy(a, "hello");
   چاپ_کړه("%s\n", a);

   strncpy(a, "gosh", 2);
   چاپ_کړه("%s\n", a);

   چاپ_کړه("%d\n", strcmp(a, "apple") > 0);
   چاپ_کړه("%d\n", strcmp(a, "goere") > 0);
   چاپ_کړه("%d\n", strcmp(a, "zebra") < 0);

   چاپ_کړه("%d\n", مزي_اوږدوالی(a));

   strcat(a, "!");
   چاپ_کړه("%s\n", a);

   چاپ_کړه("%d\n", مزي_پرتله(a, "apple", 2) > 0);
   چاپ_کړه("%d\n", مزي_پرتله(a, "goere", 2) == 0);
   چاپ_کړه("%d\n", مزي_پرتله(a, "goerg", 2) == 0);
   چاپ_کړه("%d\n", مزي_پرتله(a, "zebra", 2) < 0);

   چاپ_کړه("%s\n", strchr(a, 'o'));
   چاپ_کړه("%s\n", strrchr(a, 'l'));
   چاپ_کړه("%d\n", strrchr(a, 'x') == عدم);

   memset(&a[1], 'r', 4);
   چاپ_کړه("%s\n", a);

   حافظه_نقل(&a[2], a, 2);
   چاپ_کړه("%s\n", a);

   چاپ_کړه("%d\n", memcmp(a, "apple", 4) > 0);
   چاپ_کړه("%d\n", memcmp(a, "grgr", 4) == 0);
   چاپ_کړه("%d\n", memcmp(a, "zebra", 4) < 0);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
